#ifndef __BUILTINS_H
#define __BUILTINS_H

#include <unistd.h>
#include "./../constants.h"

typedef enum Builtin {
	CD,
	PWD,
	CLS,
	ALIAS,
	UNALIAS,
	EXIT,
	INVALID
} Builtin;

int is_builtin(char *cmd);

void refresh_cwd(void);
static void builtin_impl_cd(char **args, size_t n_args);
static void builtin_impl_cls(char **args, size_t n_args);
static void builtin_impl_pwd(char **args, size_t n_args);
static void builtin_impl_exit(char **args, size_t n_args);
static void builtin_impl_alias(char **args, size_t n_args);
static void builtin_impl_unalias(char **args, size_t n_args);
void execute_builtin(char *cmd, char **args, size_t n_args);

char* get_cwd(void);

static Builtin builtin_code(char *cmd);

#endif /* __BUILTINS_H */
