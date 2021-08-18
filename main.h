#ifndef __MAIN_FILE_H_
#define __MAIN_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 21
#define MAX_VARIABLES 1024
#define DEBUG(n) printf("DEBUG: %d\n", ( n ));

void getWord(FILE *, char *);
void getHelp(void);

#endif