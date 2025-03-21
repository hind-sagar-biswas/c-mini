#ifndef __SHELL_H
#define __SHELL_H

#include <stdbool.h>

#define PROMPT_SYMBOL "$"
#define HISTORY_LENGTH 1024
#define MAX_CMD_LENGTH 4096
#define HOSTNAME_LENGTH 256
#define PROMPT_LENGTH 512
#define MAX_ARGS 1024
#define TOKEN_SEPARATOR " \t"

void run_shell(void);
void initialize_shell(bool silent);
void refresh_prompt(void);

int tokenize(char* line, char **args, int max_args);
int excecute(char *cmd, char **args);

#endif /* __SHELL_H */
