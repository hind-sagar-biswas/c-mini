#ifndef __LOADRC_H
#define __LOADRC_H

#include <stdbool.h>

void load_rc_file(void (*run_command)(char *), const char *filename, bool custom);

#endif /* __LOADRC_H */
