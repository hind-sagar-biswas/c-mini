#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./builtins.h"
#include "./alias.h"
#include "./../shell.h"

char CWD[PATH_LENGTH];

static void (*BUILTIN_TABLE[]) (char** args, size_t n_args) = {
  [CD] = builtin_impl_cd,
  [PWD] = builtin_impl_pwd,
  [CLS] = builtin_impl_cls,
  [EXIT] = builtin_impl_exit,
  [ALIAS] = builtin_impl_alias,
  [UNALIAS] = builtin_impl_unalias,
};

char* get_cwd(void) {
  return CWD;
}

void execute_builtin(char* cmd, char** args, size_t n_args) {
  BUILTIN_TABLE[builtin_code(cmd)](args, n_args);
}

int is_builtin(char* cmd) {
  return builtin_code(cmd) != INVALID;
}

void refresh_cwd(void) {
  if (getcwd(CWD, sizeof(CWD)) == NULL) {
    fprintf(stderr, "Error: Could not read working dir");
    exit(1);
  }
}

static void builtin_impl_cd(char** args, size_t n_args) {
  char* new_dir = *args;
  /*for (int i = 1; i < n_args; i++) {*/
  /* fprintf(stdout, "CD: %s ", args[i]);*/
  /*}*/
  if (chdir(new_dir) != 0) {
    fprintf(stderr, "Error: Could not change directory");
    exit(1);
  }
  refresh_cwd();
  refresh_prompt();
}

static void builtin_impl_pwd(char** args, size_t n_args) {
  fprintf(stdout, "%s\n", CWD);
}

static void builtin_impl_cls(char** args, size_t n_args) {
  system("clear");
}

static void builtin_impl_alias(char** args, size_t n_args) {
  if (n_args == 0) {
    print_aliases();
    return;
  }

  char* alias_name = args[0];
  if (n_args == 1) {
    char* expanded = find_alias(alias_name);
    if (expanded) printf("%s='%s'\n", alias_name, expanded);
    else fprintf(stderr, "Alias not found: %s\n", alias_name);
    return;
  }

  size_t total_length = 0;
  for (size_t i = 1; i < n_args; i++) {
    total_length += strlen(args[i]) + 1;
  }
  char* alias_command = malloc(total_length + 1);
  if (!alias_command) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  alias_command[0] = '\0';
  for (size_t i = 1; i < n_args; i++) {
    strcat(alias_command, args[i]);
    if (i < n_args - 1)
      strcat(alias_command, " ");
  }

  add_alias(alias_name, alias_command);
  free(alias_command);
}

static void builtin_impl_unalias(char** args, size_t n_args) {
  if (n_args == 0) {
    fprintf(stderr, "unalias: Too few arguments\n");
    return;
  }
  remove_alias(args[0]);
}

static void builtin_impl_exit(char** args, size_t n_args) {
  free_aliases();
  fprintf(stdout, "Goodbye!\n");
  exit(0);
}

static Builtin builtin_code(char* cmd) {
  if (!strncmp(cmd, "cd", 2)) {
    return CD;
  }
  else if (!strncmp(cmd, "pwd", 3)) {
    return PWD;
  }
  else if (!strncmp(cmd, "cls", 3)) {
    return CLS;
  }
  else if (!strncmp(cmd, "exit", 4)) {
    return EXIT;
  }
  else if (!strncmp(cmd, "alias", 5)) {
    return ALIAS;
  }
  else if (!strncmp(cmd, "unalias", 7)) {
    return UNALIAS;
  }
  else {
    return INVALID;
  }
}

