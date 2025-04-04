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
#include "./builtins.h"
#include "./decoratives.h"

#include "./seal/lexer.h"
#include "./seal/parser.h"
#include "./seal/seal.h"

char prompt[PROMPT_LENGTH];

int main(int argc, char *argv[]) {
	bool silent = false;

	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
				print_help();
				exit(0);
			} else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
				printf("Seashell v%s\n", VERSION);
				exit(0);
			} else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--silent") == 0) silent = true;
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

void run_shell(void) {
	char *line;
	CmdToken *tokens[MAX_ARGS];
	Command *commands[MAX_COMMANDS];
	
	while (true) {
		fprintf(stdout, "%s\n", prompt);
		if ((line = linenoise(PROMPT_SYMBOL)) == NULL) break;

		int args_read = prepare_commands(line, tokens, commands, MAX_COMMANDS);

		if (args_read == 0) {
			linenoiseFree(line);
			continue;
		}

		int c = 0;
		while (true) {
			char *cmd = commands[c]->command;
			char **cmd_args = commands[c]->args;

			if (is_builtin(cmd)) execute_builtin(cmd, (cmd_args + 1), args_read - 1);
			else excecute(cmd, cmd_args);
			
			if (commands[c]->flow == FLOW_END) break;
			else c++;
		}
		free_prepared_commands(tokens, commands);

		linenoiseHistoryAdd(line);
		linenoiseFree(line);
	}
}

void refresh_prompt(void) {
	char *user;
	char hostname[HOSTNAME_LENGTH];
	char *cwd = get_cwd();
	char final_cwd[PATH_LENGTH];

	user = getenv("USER");
	if (!user) {
		struct passwd *pw = getpwuid(getuid());
		user = (pw) ? pw->pw_name : "guest";
	}

	if (gethostname(hostname, HOSTNAME_LENGTH) != 0) {
		perror("gethostname failed");
		exit(1);
	}

	final_cwd[0] = '\0';

	char *home = getenv("HOME");
	if (home && cwd && strncmp(cwd, home, strlen(home)) == 0) {
		snprintf(final_cwd, sizeof(final_cwd), "~%s", cwd + strlen(home));
		if (final_cwd[1] == '\0') strcpy(final_cwd, "~");
	} else {
		strncpy(final_cwd, cwd, sizeof(final_cwd) - 1);
		final_cwd[sizeof(final_cwd) - 1] = '\0';
	}

	snprintf(prompt, PROMPT_LENGTH, "\033[92m┌──(\033[95;1m%s㉿%s\033[92m)-[\033[97;1m%s\033[92m]\033[0m", user, hostname, final_cwd);
}

int excecute(char *cmd, char **args) {
	int status;
	pid_t pid = fork();

	if (pid < 0) {
		fprintf(stdout, "Fork failed\n");
		return -1;
	}

	if (!pid) {
		execvp(cmd, args);
	} else {
		if (waitpid(pid, &status, 0) != pid) {
			fprintf(stdout, "Waitpid failed\n");
			return -1;
		}
	}

	return status;
}

