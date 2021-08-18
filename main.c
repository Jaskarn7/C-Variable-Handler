/**
 * This is the main file of the program which contains the main function and handles everything
 * This file also contain getWord and getHelp functions
 * To compile the program use: gcc main.c buffer.c variableHandler.c
 * 
 *         (C) 2021 Jaskarn Singh
*/

#include "main.h"
#include "buffer.h"
#include "variableHandler.h"

int main(int argc, char *argv[])
{
	int cntr = 1, printVariableOption = 0;
	char word[MAX_SIZE] = {0};
	char inputFile[MAX_SIZE] = {0}, outputFile[MAX_SIZE] = {0};
	int tmp = 0;

	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "-d") == 0) {
			printVariableOption = 1;
			tmp = 1;
		}
		else if (strcmp(argv[i], "-f") == 0) {
			strcpy(inputFile, argv[++i]);
		}
		else if (strcmp(argv[i], "-o") == 0)
			strcpy(outputFile, argv[++i]);
		else if (strcmp(argv[i], "-h") == 0) {
			getHelp();
			return 0;
		}
	}


	// Loop for storing all variables in an array of string
	FILE *fp = fopen(inputFile, "r");
	if (inputFile[0] == '\0' || (fp = fopen(inputFile, "r")) == NULL) {
		printf("\nUsage: <Program.exe> [-d] -f InputFile.c [-o OutputFile.c]\n\nUse \"-h\" for help\n");
		return 0;
	}
	while (!feof(fp)) {
		getWord(fp, word);
		if (checkForDataType(word) == 1) {
			getWord(fp, word);
			if (strcmp("main", word) != 0) {
				storeVariable(word);
			}
		}
	}
	fclose(fp);

	if (printVariableOption == 1)
		printVariables();
	outputToFile(inputFile, (outputFile[0] == '\0' ? NULL : outputFile));

	return 0;
}

void getWord(FILE *fp, char *word)
{
	int c = getNextChar(fp);
	while (!isalpha(c) && c != EOF) {
		c = fgetc(fp);
	}
	while (isalpha(c) || c == '_') {
		*word++ = c;
		c = fgetc(fp);
	}
	*word = '\0';
	putToBuffer(c);
	return;
}

void getHelp(void)
{
	printf("\nUsage: <Program.exe> [-d] -f <InputFile> [-o <OutputFile>]\n");
	printf("\nOPTIONS:\n");
	printf("-d: Used to display all variables in the input file\n");
	printf("-f: Used to define input file. e.g.: program.exe -d -f file.c\n");
	printf("-o: Used to define where to redirect the changes (default is standard output). e.g.: program.exe -d -f file.c -o output.c");
	printf("\n");
	return;	
}