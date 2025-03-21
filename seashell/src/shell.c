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
	char *args[MAX_ARGS];
	
	while ((line = linenoise(prompt)) != NULL) {
		int args_read = tokenize(line, args, MAX_ARGS);

		if (args_read == 0) {
			linenoiseFree(line);
			continue;
		}

		char *cmd = args[0];
		char **cmd_args = args;

		if (is_builtin(cmd)) execute_builtin(cmd, (cmd_args + 1), args_read - 1);
		else excecute(cmd, cmd_args);

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

	snprintf(prompt, PROMPT_LENGTH, "\033[95;1m%s㉿%s [\033[97;1m%s\033[95;1m] %s \033[0m", user, hostname, final_cwd, PROMPT_SYMBOL);
}

int tokenize(char *line, char **args, int max_args) {
	int i = 0;
	char *token = strtok(line, TOKEN_SEPARATOR);
	while (token != NULL && i < (max_args - 1)) {
		args[i++] = token;
		token = strtok(NULL, TOKEN_SEPARATOR);
	}
	args[i] = NULL;
	return i;
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

