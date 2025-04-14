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

HelpMessage options[] = {
  {"-h, --help", "Show this message, then exit."},
  {"-v, --version", "Show the version number, then exit."},
  {"-i, --info", "Run the shell with welcome message `info`."},
  {"-r, --rc <file>", "Run the shell with the given rc file. Defaults to ~/.cslrc"},
  {"..files", "Executes the given files in order, then exits."},
};

HelpMessage commands[] = {
  {"cd <path>", "Change the current working directory."},
  {"pwd", "Print the current working directory."},
  {"cls", "Clear the screen."},
  {"info", "Print information about the shell."},
  {"alias", "List all aliases."},
  {"alias <name>", "Print the value of an alias."},
  {"alias <name> <command>", "Create an alias."},
  {"unalias <name>", "Remove an alias."},
  {"= <expression>", "Evaluate a mathematical expression."},
  {"exit", "Exit the shell."},
};

void print_banner(void) {
  for (int i = 0; banner[i] != NULL; i++) {
    printf(" %s\n", banner[i]);
  }
}

void print_help_message(HelpMessage* message) {
  printf("  %-25s %s\n", message->label, message->message);
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
  printf("\nUsage: seashell [options] <..files>\n");

  printf("Options:\n");
  for (int i = 0; i < 4; i++) print_help_message(&options[i]);

  printf("Commands:\n");
  for (int i = 0; i < 9; i++) print_help_message(&commands[i]);
}
