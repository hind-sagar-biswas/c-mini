#include <stdio.h>
#include <stdlib.h>
#include "loadrc.h"
#include "builtins/runfile.h"


void load_rc_file(void (*run_command)(char *)) {
  char *home = getenv("HOME");
  if (!home) {
    fprintf(stderr, "HOME environment variable not set.\n");
    return;
  }

  char rc_path[PATH_LENGTH];
  snprintf(rc_path, sizeof(rc_path), "%s/.cslrc", home);

  execute_file(run_command, rc_path, true);
}
