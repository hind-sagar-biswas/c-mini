#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./builtins.h"
#include "./shell.h"

char CWD[PATH_LENGTH];

void (*BUILTIN_TABLE[]) (char **args, size_t n_args) = {
	[CD] = builtin_impl_cd,
	[PWD] = builtin_impl_pwd,
	[CLS] = builtin_impl_cls,
	[EXIT] = builtin_impl_exit,
};

char *get_cwd(void) {
  return CWD;
}


void execute_builtin(char *cmd, char **args, size_t n_args) {
  BUILTIN_TABLE[builtin_code(cmd)](args, n_args);
}

int is_builtin(char *cmd) {
  return builtin_code(cmd) != INVALID;
}

Builtin builtin_code(char *cmd) {
  if (!strncmp(cmd, "cd", 2)) {
    return CD;
  } else if (!strncmp(cmd, "pwd", 3)) {
    return PWD;
  } else if (!strncmp(cmd, "cls", 3)) {
    return CLS;
  } else if (!strncmp(cmd, "exit", 4)) {
    return EXIT;
  } else {
    return INVALID;
  }
}

void refresh_cwd(void) {
  if (getcwd(CWD, sizeof(CWD)) == NULL) {
    fprintf(stderr, "Error: Could not read working dir");
    exit(1);
  }
}

void builtin_impl_cd(char **args, size_t n_args) {
  char *new_dir = *args;
  if (chdir(new_dir) != 0) {
    fprintf(stderr, "Error: Could not change directory");
    exit(1);
  }
  refresh_cwd();
  refresh_prompt();
}

void builtin_impl_pwd(char **args, size_t n_args) {
  fprintf(stdout, "%s\n", CWD);
}

void builtin_impl_cls(char **args, size_t n_args) {
  system("clear");
}

void builtin_impl_exit(char **args, size_t n_args) {
  fprintf(stdout, "Goodbye!\n");
  exit(0);
}
