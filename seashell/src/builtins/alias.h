#ifndef __BUILTIN_ALIAS_H
#define __BUILTIN_ALIAS_H

#include <stdbool.h>

typedef struct Alias {
    char *name;           // Alias name (e.g., "ls")
    char *command;        // Command expansion (e.g., "ls -la")
    struct Alias *next;   // Pointer for a linked list of aliases
} Alias;

// Function prototypes
void add_alias(const char *name, const char *command);
void remove_alias(const char *name);
char *find_alias(const char *name);
bool is_alias(const char *name);
void print_aliases(void);
void free_aliases(void);

// execute alias function (takes run_command() function pointer, command, args, and n_args)
void execute_alias(void (*run_command)(char *), char *command, char **args, int n_args);

#endif /* __BUILTIN_ALIAS	_H */
