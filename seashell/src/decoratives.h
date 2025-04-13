#ifndef __DECORATIVES_H
#define __DECORATIVES_H

#include "constants.h"

typedef struct HelpMessage {
	char label[25];
	char message[512];
} HelpMessage;

void print_help(void);
void print_banner(void);
void welcome_message(void);
void print_help_message(HelpMessage* message);

#endif /* __DECORATIVES_H */
