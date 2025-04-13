#ifndef __SHELL_H
#define __SHELL_H

#include "seal/parser.h"
#include "constants.h"
#include <stdbool.h>


void run_shell(void);
void run_command(char *line);
void initialize_shell(bool silent, bool custom_rc);
void refresh_prompt(void);

int execute(char *cmd, char **args);
int execute_piped_commands(Command **commands, int count);

#endif /* __SHELL_H */
