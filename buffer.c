#include "buffer.h"

int buff = 0;

int getNextChar(FILE *fp)
{
	if (buff != '\0') {
		int tmp = (int) buff;
		buff = '\0';
		return tmp;
	}
	return fgetc(fp);
}

void putToBuffer(int c)
{
	buff = c;
	return;
}

void clearBuffer(void)
{
	buff = '\0';
	return;
}
