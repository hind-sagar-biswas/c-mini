#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./lexer.h"

bool is_separator(char c) { return c == ' ' || c == '\t'; }

bool is_alone(char prev, char next) {
	if (!is_separator(prev)) return false;
	if (!is_separator(next) && next != '\0') return false;
	return true;
}

bool is_pipe(char prev, char c, char next) { return is_alone(prev, next) && c == '|'; }
bool is_redir(char prev, char c, char next) { return is_alone(prev, next) && c == '>'; }
bool is_concat(char prev, char c1, char c2, char next) { return is_alone(prev, next) && c1 == '&' && c2 == '&'; }

void make_cmd_token(CmdToken **tokens, int *i, Tag tag, const char *value) {
	tokens[*i] = malloc(sizeof(CmdToken));
	if (tokens[*i] == NULL) {
		fprintf(stderr, "ERROR: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tokens[*i]->tag = tag;
	tokens[*i]->value = (value != NULL) ? strdup(value) : NULL;
	tokens[*i]->to_be_freed = (value != NULL);
	(*i)++;
}

int command_lexer(char *line, CmdToken **tokens, int max_tokens) {
  int i = 0, c = 0, len = strlen(line);
  if (len > 0) {
    char prev = ' ';
    while (c < len && line[c] != '\0' && i < max_tokens - 1) {
      char ch = line[c];

      if (is_separator(line[c])) {
	c++;
	prev = ' ';
	continue;
      }

      if (i && is_pipe(prev, ch, line[c + 1])) {
	make_cmd_token(tokens, &i, TAG_PIPE, NULL);
	prev = '|';
	c++;
	continue;
      }
      if (i && is_redir(prev, ch, line[c + 1])) {
	make_cmd_token(tokens, &i, TAG_REDIRECT, NULL);
	prev = '>';
	c++;
	continue;
      }
      if (i && line[c + 1] != '\0' && is_concat(prev, ch, line[c + 1], line[c + 2])) {
	make_cmd_token(tokens, &i, TAG_CONCAT, NULL);
	prev = '&';
	c += 2;
	continue;
      }

      if (ch == '"') {
	c++;
	int start = c;
	while (c < len && (line[c] != '"' || line[c - 1] == '\\')) c++;
	if (c >= len) {
	  fprintf(stderr, "Unterminated quote\n");
	  return 1;
	}
	int token_len = c - start;
	// Allocate a new string that includes the quotes.
	char *qstr = malloc(token_len + 3); // opening, closing quotes and null terminator
	if (!qstr) { perror("malloc"); exit(EXIT_FAILURE); }
	qstr[0] = '"';
	memcpy(qstr + 1, line + start, token_len);
	qstr[token_len + 1] = '"';
	qstr[token_len + 2] = '\0';
	make_cmd_token(tokens, &i, TAG_STRING_ARG, qstr);
	free(qstr);
	prev = '"';
	c++;
	continue;
      }

      int start = c;
        while (c < len && !is_separator(line[c]) &&
               line[c] != '|' && line[c] != '>' && line[c] != '&' && line[c] != '"') {
            c++;
        }
        int token_len = c - start;
        if (token_len > 0) {
	  char *word = malloc(token_len + 1);
	  if (!word) { perror("malloc"); exit(EXIT_FAILURE); }
	  memcpy(word, line + start, token_len);
	  word[token_len] = '\0';
	  Tag tag = (i == 0 || (tokens[i-1]->tag == TAG_REDIRECT ||
				tokens[i-1]->tag == TAG_PIPE ||
				tokens[i-1]->tag == TAG_CONCAT))
			? TAG_COMMAND
			: TAG_ARG;
	  make_cmd_token(tokens, &i, tag, word);
	  free(word);
        }
        prev = (c > 0) ? line[c-1] : ' ';    }
  }
  tokens[i] = NULL;
  return !i;
}

void free_cmd_tokens(CmdToken **tokens) {
  for (int i = 0; tokens[i] != NULL; i++) {
    if (tokens[i]->to_be_freed) free(tokens[i]->value);
    free(tokens[i]);
  }
}
