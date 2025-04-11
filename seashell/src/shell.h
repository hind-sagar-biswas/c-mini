#ifndef __SHELL_H
#define __SHELL_H

#include "seal/parser.h"
#include <stdbool.h>

#define PROMPT_SYMBOL "\033[92m└─\033[95;1m$\033[0m "
#define HISTORY_LENGTH 1024
#define MAX_CMD_LENGTH 4096
#define HOSTNAME_LENGTH 256
#define PROMPT_LENGTH 512
#define MAX_ARGS 1024
#define TOKEN_SEPARATOR " \t"

void run_shell(void);
void initialize_shell(bool silent);
void refresh_prompt(void);

int excecute(char *cmd, char **args);
int execute_piped_commands(Command **commands, int count);

#endif /* __SHELL_H */
