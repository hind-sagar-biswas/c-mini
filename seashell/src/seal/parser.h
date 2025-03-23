#ifndef __SEAL_PARSER_H
#define __SEAL_PARSER_H

#include "lexer.h"

#define MAX_COMMANDS 1024

typedef enum CommandFlow {
	FLOW_PIPE,
	FLOW_CONCAT,
	FLOW_REDIRECT,
	FLOW_END,
} CommandFlow;

typedef struct Command {
	char *command;
	char *args[MAX_COMMANDS];
	int n_args;
	CommandFlow flow;
} Command;

bool is_terminal_token(CmdToken *token);

int parse_cmd_tokens(CmdToken **tokens, Command **commands);

void free_commands(Command **commands);

#endif /* __SEAL_PARSER	_H */
