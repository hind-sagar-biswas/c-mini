#include <stdbool.h>
#include "seal.h"

int prepare_commands(char* line, CmdToken** tokens, Command** commands, int limit) {
	command_lexer(line, tokens, limit);
	return parse_cmd_tokens(tokens, commands);
}

void free_prepared_commands(CmdToken** tokens, Command** commands) {
	free_cmd_tokens(tokens);
	free_commands(commands);
}
