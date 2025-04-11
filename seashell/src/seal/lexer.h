#ifndef __SEAL_LEXER_H
#define __SEAL_LEXER_H

#include <stdbool.h>

typedef enum CommandTag {
	TAG_COMMAND,
	TAG_PIPE,
	TAG_CONCAT,
	TAG_REDIRECT,
	/*TAG_REDIRECT_APPEND,*/
	/*TAG_REDIRECT_WRITE,*/ // For future implementation
	/*TAG_REDIRECT_READ,*/
	TAG_ARG,
	TAG_STRING_ARG,
} Tag;

typedef struct CommandToken {
	Tag tag;
	char *value;
	bool to_be_freed;
} CmdToken;

int command_lexer(char *line, CmdToken **tokens, int max_tokens);

void free_cmd_tokens(CmdToken **tokens);

#endif /* __SEAL_LEXER	_H */
