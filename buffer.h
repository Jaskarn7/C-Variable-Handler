#ifndef __BUFFER_FILE_H_
#define __BUFFER_FILE_H_

#include <stdio.h>

int getNextChar(FILE *);
void putToBuffer(int);
void clearBuffer(void);

#endif