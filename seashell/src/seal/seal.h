#ifndef __SEAL_H
#define __SEAL_H

#include "lexer.h"
#include "parser.h"

int prepare_commands(char *line, CmdToken **tokens, Command **commands, int limit);
void free_prepared_commands(CmdToken **tokens, Command **commands);

#endif /* __SEAL	_H */
