#include <stdio.h>

#include "./decoratives.h"

char* banner[] = {
  "            _.---._",
  "        .'\"\".'/|\\`.\"\"'.",
  "       :  .' / | \\ `.  :",
  "       '.'  /  |  \\  `.'",
  "        `. /   |   \\ .'",
  "          `-.__|__.-'",
  "                     _          _ _ ",
  "                    | |        | | |",
  "  ___  ___  __ _ ___| |__   ___| | |",
  " / __|/ _ \\/ _` / __| '_ \\ / _ \\ | |",
  " \\__ \\  __/ (_| \\__ \\ | | |  __/ | |",
  " |___/\\___|\\__,_|___/_| |_|\\___|_|_|",
  "                                    ",
  NULL,
};

void print_banner(void) {
  for (int i = 0; banner[i] != NULL; i++) {
    printf(" %s\n", banner[i]);
  }
}

void welcome_message(void) {
  print_banner();
  printf("Welcome to %s v%s\n", APP_NAME, APP_VERSION);
  printf("\n");
  printf("AUTHOR:\t%s\n", AUTHOR_NAME);
  printf("EMAIL:\t%s\n", AUTHOR_EMAIL);
  printf("\n");
}

void print_help(void) {
  printf("\nUsage: seashell [-h] [-v] [-s] <..files>\n");
  printf("Options:\n");
  printf("\t-h, --help\t- Show this message, then exit.\n");
  printf("\t-v, --version\t- Show the version number, then exit.\n");
  printf("\t-i, --info\t- Run %s with welcome message `info`.\n", APP_NAME);
  printf("\t..files\t\t- Execute the given files.\n");
  printf("Commands:\n");
  printf("\tcd <path>\t\t- Change the current working directory.\n");
  printf("\tpwd\t\t\t- Print the current working directory.\n");
  printf("\tcls\t\t\t- Clear the screen.\n");
  printf("\tinfo\t\t\t- Show information about the shell.\n");
  printf("\talias\t\t\t- Show aliases.\n");
  printf("\talias <name>\t\t- Show a specific alias.\n");
  printf("\talias <name> <command>\t- Add or update an alias.\n");
  printf("\tunalias <name>\t\t- Remove an alias.\n");
  printf("\texit\t\t\t- Exit the shell.");
}
