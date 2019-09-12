#include <stdio.h>
#include <stdlib.h>

#define MAX_ID_LEN 128

int isop(char);
int isidentifier(char*);

int main() {

	char buffer[MAX_ID_LEN], ch;

	FILE* fp = NULL;
	fopen_s(&fp, "test.txt", "r");

	if (fp == NULL) {
		printf("Error while opening the file\n");
		return -1;
	}

	printf("The keywords and identifiers are:\n");

	int i, lines; i = lines = 0;
	while ((ch = fgetc(fp)) != EOF) {
		if (isop(ch)) {
			printf("%c is an operator.\n", ch);

			if (i != 0) {
				buffer[i] = '\0';
				i = 0;
				if (isidentifier(buffer))
					printf("%s is an indentifier.\n", buffer);
			}
		}
		else if (isalnum(ch))
			buffer[i++] = ch;
		else if ((ch == ' ' || ch == '\n') && (i != 0)) {
			buffer[i] = '\0';
			i = 0;

			if (isidentifier(buffer))
				printf("%s is an identifier.\n", buffer);
			if (ch == '\n')
				lines++;
		}
	}
	printf("There are %d line(s) in the given file.\n", lines+1);

	fclose(fp);
	
	system("pause");
	return 0;
}

int isop(char tok)
{
	char* ops = "!^+-*/%=";
	for (char* c = ops; *c != '\0'; ++c) {
		if (*c == tok)
			return 1;
	}
	return 0;
}

int isidentifier(char *input)
{
	// check first character condition
	if (!isalpha((unsigned char)input[0]))
		return 0;

	char* iter = input + 1;

	// check whole string
	while (iter != NULL && *iter != '\0')
	{
		if (isalpha(*iter) || *iter == '_')
			++iter;
		else
		{
			return 0;
		}
	}
	return 1;
}