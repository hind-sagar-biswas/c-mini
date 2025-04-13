#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./parser.h"
#include "./../builtins/builtins.h"
#include "./../builtins/alias.h"

static bool is_terminal_token(CmdToken* token) {
  return token == NULL || token->tag == TAG_PIPE || token->tag == TAG_CONCAT || token->tag == TAG_REDIRECT;
}

static CommandType get_command_type(char* command) {
  if (is_builtin(command)) return CMD_BUILTIN;
  if (is_alias(command)) return CMD_ALIAS;
  return CMD_EXTERNAL;
}

int parse_cmd_tokens(CmdToken** tokens, Command** commands) {
  int i = 0, t = 0;

  while (tokens[t] != NULL) {
    if (tokens[t]->tag == TAG_COMMAND) {
      commands[i] = malloc(sizeof(Command));
      commands[i]->command = tokens[t]->value;
      commands[i]->args[0] = commands[i]->command;
      commands[i]->type = get_command_type(commands[i]->command);
    }
    t++;

    int a = 1;
    while (tokens[t] != NULL) {
      if (is_terminal_token(tokens[t])) break;
      commands[i]->args[a] = tokens[t]->value;
      a++;
      t++;
    }
    commands[i]->args[a] = NULL;
    commands[i]->n_args = a;

    if (tokens[t] == NULL) {
      commands[i]->flow = FLOW_END;
      t--;
    }
    else switch (tokens[t]->tag) {
    case TAG_PIPE:
      commands[i]->flow = FLOW_PIPE;
      break;
    case TAG_CONCAT:
      commands[i]->flow = FLOW_CONCAT;
      break;
    case TAG_REDIRECT:
      commands[i]->flow = FLOW_REDIRECT;
      break;
    default:
      commands[i]->flow = FLOW_END;
      break;
    }

    t++;
    i++;
  }
  commands[i] = NULL;
  return i;
}

void free_commands(Command** commands) {
  for (int i = 0; commands[i] != NULL; i++) {
    free(commands[i]);
  }
}
