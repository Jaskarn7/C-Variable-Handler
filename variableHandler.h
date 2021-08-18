#ifndef __VARIABLE_HANDLER_H_
#define __VARIABLE_HANDLER_H_

#include "main.h"

int checkForDataType(char *);
int convertVariable(char *);
void storeVariable(char *);
void printVariables(void);
int checkWordForVariable(char *);
void outputToFile(char *, char *);

#endif