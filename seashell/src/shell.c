#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "./../lib/linenoise/linenoise.h"

#include "./shell.h"
#include "./builtins/builtins.h"
#include "./builtins/alias.h"
#include "./decoratives.h"

#include "./seal/lexer.h"
#include "./seal/parser.h"
#include "./seal/seal.h"

char prompt[PROMPT_LENGTH];

int main(int argc, char* argv[]) {
	bool silent = false;

	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
				print_help();
				exit(0);
			}
			else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
				printf("Seashell v%s\n", VERSION);
				exit(0);
			}
			else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--silent") == 0) silent = true;
		}
	}

	initialize_shell(silent);
	run_shell();
	return 0;
}

void initialize_shell(bool silent) {

	if (!silent) welcome_message();

	refresh_cwd();
	refresh_prompt();

	if (!linenoiseHistorySetMaxLen(HISTORY_LENGTH)) {
		fprintf(stderr, "History set max length failed\n");
		exit(1);
	}
}

void run_command(char* line) {
	CmdToken* tokens[MAX_ARGS];
	Command* commands[MAX_COMMANDS];

	int args_read = prepare_commands(line, tokens, commands, MAX_COMMANDS);

	if (args_read == 0) {
		linenoiseFree(line);
		return;
	}

	// fprintf(stdout, "%s args read: %d\n", line, args_read);

	int c = 0;
	while (commands[c] != NULL) {
		char* cmd = commands[c]->command;
		char** cmd_args = commands[c]->args;

		if (commands[c]->flow == FLOW_PIPE) {
			int pipe_count = 1;
			while (c + pipe_count < args_read && commands[c + pipe_count]->flow == FLOW_PIPE) {
				pipe_count++;
				/*fprintf(stdout, "%d %s\n", c, commands[c]->command);*/
			}
			execute_piped_commands(commands + c, pipe_count);
			c += pipe_count + 1;
			continue;
		}
		else {
			/*for (int i = 0; i < commands[c]->n_args; i++) {*/
			/*	fprintf(stdout, "%d %s\n", i, commands[c]->args[i]);*/
			/*}*/
			if (commands[c]->type == CMD_BUILTIN) execute_builtin(cmd, (cmd_args + 1), commands[c]->n_args - 1);
			else if (commands[c]->type == CMD_ALIAS) execute_alias(run_command, cmd, cmd_args + 1, commands[c]->n_args - 1);
			else excecute(cmd, cmd_args);
		}

		if (commands[c]->flow == FLOW_END) break;
		else c++;
	}
	free_prepared_commands(tokens, commands);
}

void run_shell(void) {
	char* line;

	while (true) {
		fprintf(stdout, "%s\n", prompt);
		if ((line = linenoise(PROMPT_SYMBOL)) == NULL) break;

		run_command(line);

		linenoiseHistoryAdd(line);
		linenoiseFree(line);
	}
}

void refresh_prompt(void) {
	char* user;
	char hostname[HOSTNAME_LENGTH];
	char* cwd = get_cwd();
	char final_cwd[PATH_LENGTH];

	user = getenv("USER");
	if (!user) {
		struct passwd* pw = getpwuid(getuid());
		user = (pw) ? pw->pw_name : "guest";
	}

	if (gethostname(hostname, HOSTNAME_LENGTH) != 0) {
		perror("gethostname failed");
		exit(1);
	}

	final_cwd[0] = '\0';

	char* home = getenv("HOME");
	if (home && cwd && strncmp(cwd, home, strlen(home)) == 0) {
		snprintf(final_cwd, sizeof(final_cwd), "~%s", cwd + strlen(home));
		if (final_cwd[1] == '\0') strcpy(final_cwd, "~");
	}
	else {
		strncpy(final_cwd, cwd, sizeof(final_cwd) - 1);
		final_cwd[sizeof(final_cwd) - 1] = '\0';
	}

	snprintf(prompt, PROMPT_LENGTH, "\033[92m┌──(\033[95;1m%s㉿%s\033[92m)-[\033[97;1m%s\033[92m]\033[0m", user, hostname, final_cwd);
}

int excecute(char* cmd, char** args) {
	int status;
	pid_t pid = fork();

	if (pid < 0) {
		fprintf(stdout, "Fork failed\n");
		return -1;
	}

	if (!pid) {
		execvp(cmd, args);
	}
	else {
		if (waitpid(pid, &status, 0) != pid) {
			fprintf(stdout, "Waitpid failed\n");
			return -1;
		}
	}

	return status;
}

int execute_piped_commands(Command** commands, int pipe_count) {
	// Number of commands is one more than the number of pipes.
	int process_count = pipe_count + 1;
	int pipes[pipe_count][2];
	pid_t pids[process_count];

	// Create exactly 'pipe_count' pipes.
	for (int i = 0; i < pipe_count; i++) {
		if (pipe(pipes[i]) == -1) {
			fprintf(stderr, "Error creating pipes\n");
			for (int j = 0; j < i; j++) {
				close(pipes[j][0]);
				close(pipes[j][1]);
			}
			return -1;
		}
	}

	// Fork a process for each command.
	for (int i = 0; i < process_count; i++) {
		pids[i] = fork();
		if (pids[i] == -1) {
			fprintf(stderr, "Error creating process\n");
			for (int j = 0; j < pipe_count; j++) {
				close(pipes[j][0]);
				close(pipes[j][1]);
			}
			return -1;
		}
		if (pids[i] == 0) {
			// Child process.
			// If first command, only redirect stdout to write end of first pipe.
			if (i == 0) {
				dup2(pipes[0][1], STDOUT_FILENO);
			}
			// If last command, only redirect stdin to read end of last pipe.
			else if (i == process_count - 1) {
				dup2(pipes[i - 1][0], STDIN_FILENO);
			}
			// For intermediate commands, connect stdin to previous pipe read end
			// and stdout to current pipe write end.
			else {
				dup2(pipes[i - 1][0], STDIN_FILENO);
				dup2(pipes[i][1], STDOUT_FILENO);
			}
			// Close all pipe file descriptors in the child.
			for (int j = 0; j < pipe_count; j++) {
				close(pipes[j][0]);
				close(pipes[j][1]);
			}
			// Execute the command.
			if (commands[i]->type == CMD_BUILTIN) {
				execute_builtin(commands[i]->command, (char**)(commands[i]->args + 1), commands[i]->n_args - 1);
				exit(EXIT_SUCCESS);
			}
			else if (commands[i]->type == CMD_ALIAS) {
				execute_alias(run_command, commands[i]->command, commands[i]->args + 1, commands[i]->n_args - 1);
				exit(EXIT_SUCCESS);
			}
			else {
				execvp(commands[i]->command, commands[i]->args);
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
	}

	// Parent process: close all pipes as they are no longer needed.
	for (int i = 0; i < pipe_count; i++) {
		close(pipes[i][0]);
		close(pipes[i][1]);
	}

	// Wait for all child processes to finish.
	for (int i = 0; i < process_count; i++) {
		waitpid(pids[i], NULL, 0);
	}

	return 0;
}

