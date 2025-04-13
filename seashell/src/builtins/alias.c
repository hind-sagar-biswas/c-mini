// alias.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "alias.h"

static Alias* alias_list = NULL;

void add_alias(const char* name, const char* command) {
    Alias* cur = alias_list;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            free(cur->command);
            cur->command = strdup(command);
            return;
        }
        cur = cur->next;
    }

    Alias* new_alias = malloc(sizeof(Alias));
    if (!new_alias) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_alias->name = strdup(name);
    new_alias->command = strdup(command);
    new_alias->next = alias_list;
    alias_list = new_alias;
}

void remove_alias(const char* name) {
    Alias** cur = &alias_list;
    while (*cur != NULL) {
        if (strcmp((*cur)->name, name) == 0) {
            Alias* to_delete = *cur;
            *cur = to_delete->next;
            free(to_delete->name);
            free(to_delete->command);
            free(to_delete);
            return;
        }
        cur = &((*cur)->next);
    }
    fprintf(stderr, "Alias not found: %s\n", name);
}

char* find_alias(const char* name) {
    Alias* cur = alias_list;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0)
            return cur->command;
        cur = cur->next;
    }
    return NULL;
}

bool is_alias(const char* name) {
    Alias* cur = alias_list;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) return true;
        cur = cur->next;
    }
    return false;
}

void print_aliases(void) {
    Alias* cur = alias_list;
    while (cur != NULL) {
        printf("%s='%s'\n", cur->name, cur->command);
        cur = cur->next;
    }
}

int execute_alias(void (*run_command)(char*), char* command, char** args, int n_args) {
    static int alias_expansion_depth = 0;

    if (alias_expansion_depth > 0) return alias_expansion_depth;

    /*fprintf(stdout, "Alias: %s\n", command);*/

    char* expanded = find_alias(command);
    if (expanded == NULL) return 0;

    // join expanded and args to create a new command string
    int total_length = strlen(expanded) + 1; // add one for white space
    for (int i = 0; i < n_args; i++) total_length += strlen(args[i]) + 1; // add one for white space

    char* new_command = malloc(total_length * sizeof(char));
    if (!new_command) perror("malloc"), exit(EXIT_FAILURE);

    strcpy(new_command, expanded);
    for (int i = 0; i < n_args; i++) {
        strcat(new_command, " ");
        strcat(new_command, args[i]);
    }
    new_command[total_length - 1] = '\0';

    alias_expansion_depth++;
    run_command(new_command);
    alias_expansion_depth--;
    free(new_command);

    return alias_expansion_depth;
}

void free_aliases(void) {
    Alias* cur = alias_list;
    while (cur != NULL) {
        Alias* next = cur->next;
        free(cur->name);
        free(cur->command);
        free(cur);
        cur = next;
    }
}
