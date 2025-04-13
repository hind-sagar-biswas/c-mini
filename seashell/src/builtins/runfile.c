#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "./runfile.h"

void execute_file(void (*run_command)(char *), char *filepath, bool silent) {
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        if (!silent) fprintf(stderr, "Error opening file: `%s`. Make sure the file exists\n", filepath);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *trimmed = line;
        while (isspace((unsigned char)*trimmed)) {
            trimmed++;
        }

        if (trimmed[0] == '#' || trimmed[0] == '\0' || trimmed[0] == '\n')
            continue;

        size_t len = strlen(trimmed);
        if (len > 0 && trimmed[len - 1] == '\n') {
            trimmed[len - 1] = '\0';
        }

        run_command(trimmed);
    }

    fclose(fp);
}
