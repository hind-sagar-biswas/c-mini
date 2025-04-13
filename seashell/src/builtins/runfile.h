#ifndef __BUILTIN_RUNFILE_H
#define __BUILTIN_RUNFILE_H

#include <stdbool.h>

#include "./../constants.h"

void execute_file(void (*run_command)(char *), char *filepath, bool silent);

#endif /* __BUILTIN_RUNFILE	_H */
