#include <stdio.h>

#include "./decoratives.h"

char *banner[] = {
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
  printf("Welcome to Sea-(C)-shell v%s\n", VERSION);
  printf("\n");
  printf("AUTHOR:\tHind Biswas\n");
  printf("EMAIL:\thindsbhk@gmail.com; ug2302016@cse.pstu.ac.bd\n");
  printf("\n");
}

void print_help(void) {
  printf("usage: seashell [-h] [-v] [-s]\n");
  printf("Options:\n");
  printf("\t-h, --help\t- Show this message, then exit.\n");
  printf("\t-v, --version\t- Show the version number, then exit.\n");
  printf("\t-s, --silent\t- Run Sea-(C)-shell without welcome message.\n");
  printf("Commands:\n");
  printf("\tcd <path>\t- Change the current working directory.\n");
  printf("\tpwd\t\t- Print the current working directory.\n");
  printf("\tcls\t\t- Clear the screen.\n");
  printf("\texit\t\t- Exit the shell.");
}
