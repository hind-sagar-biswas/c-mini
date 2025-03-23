#ifndef __SEAL_LEXER_H
#define __SEAL_LEXER_H

typedef enum CommandTag {
	TAG_COMMAND,
	TAG_PIPE,
	TAG_CONCAT,
	TAG_REDIRECT,
	TAG_ARG,
	TAG_STRING_ARG,
} Tag;

typedef struct CommandToken {
	Tag tag;
	char *value;
	bool to_be_freed;
} CmdToken;

bool is_separator(char c);
bool is_alone(char prev, char next);
bool is_pipe(char prev, char c, char next);
bool is_redir(char prev, char c, char next);
bool is_concat(char prev, char c1, char c2, char next);

int command_lexer(char *line, CmdToken **tokens, int max_tokens);

void make_cmd_token(CmdToken **tokens, int *i, Tag tag, const char *value);
void free_cmd_tokens(CmdToken **tokens);

#endif /* __SEAL_LEXER	_H */
