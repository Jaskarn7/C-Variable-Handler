#include "variableHandler.h"
#include "buffer.h"

char data_types[][MAX_SIZE] = {"void", "char", "int", "float", "double"};
char variablesContainer[MAX_VARIABLES][MAX_SIZE] = {0};
int variablesCounter = 0;

int checkForDataType(char *word)
{
	int size = sizeof(data_types) / sizeof(data_types[0]);

	for (int i = 0; i < size; ++i) {
		if (strcmp(data_types[i], word) == 0)
			return 1;
	}
	return 0;
}

int convertVariable(char *word)
{
	int changes = 0;
	char *ptr = word;

	while (*ptr != '\0') {
		if (*ptr == '_') {
			*word = toupper(*(++ptr));
			++changes;
		}
		else {
			*word = *ptr;
		}
		++word;
		++ptr;
	}
	*word = '\0';
	
	return changes;
}

void storeVariable(char *word)
{
        strcpy(variablesContainer[variablesCounter++], word);
        return;
}

void printVariables(void)
{
	printf("---------------------------------------\n");
        printf("Total Variables: %d\n", variablesCounter);
        for (int i = 0; i < variablesCounter; ++i)
                printf("Variable #%02d: %s\n", i + 1, variablesContainer[i]);
	printf("---------------------------------------\n\n");
        return;
}

int checkWordForVariable(char *word)
{
	for (int i = 0; i < variablesCounter; ++i)
		if (strcmp(variablesContainer[i], word) == 0)
			return 1;
	return 0;
}

void outputToFile(char *inputFile, char *outputFile)
{
        FILE *ifp = fopen(inputFile, "r");
        FILE *ofp = stdout;
        if (outputFile != NULL)
                ofp = fopen(outputFile, "w");
        
	char word[MAX_SIZE] = {0};
        int c = 0;
	clearBuffer();
        while (!feof(ifp)) {
                c = getNextChar(ifp);
		while (isalpha(c) == 0 && !feof(ifp)) {
			fprintf(ofp, "%c", c);
			c = getNextChar(ifp);
		}
		putToBuffer(c);
		getWord(ifp, word);
		if (checkWordForVariable(word) == 1)
			convertVariable(word);
		fprintf(ofp, "%s", word);
        }

	outToLoop:
        fclose(ifp);
        fclose(ofp);
        return;        
}