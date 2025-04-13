#ifndef __SEAL_PARSER_H
#define __SEAL_PARSER_H

#include "lexer.h"
#include "./../constants.h"

typedef enum CommandFlow {
	FLOW_PIPE,
	FLOW_CONCAT,
	FLOW_REDIRECT,
	FLOW_END,
} CommandFlow;

typedef enum CommandType {
	CMD_EXTERNAL,
	CMD_BUILTIN,
	CMD_ALIAS,
} CommandType;

typedef struct Command {
	char *command;
	char *args[MAX_COMMANDS];
	int n_args;
	CommandFlow flow;
	CommandType type;
} Command;


int parse_cmd_tokens(CmdToken **tokens, Command **commands);
void free_commands(Command **commands);

#endif /* __SEAL_PARSER	_H */
