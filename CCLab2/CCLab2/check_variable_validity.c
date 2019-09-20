#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LEN 256

int isidentifier(char*);

int main() {
	
	char* input[MAX_STRING_LEN];

	printf("Enter a string here: ");
	fgets(input, MAX_STRING_LEN, stdin);
	strtok(input, "\n"); // remove tailing new-line

	if (isidentifier(input))
		printf("VALID\n");
	else
		printf("INVALID\n");

	system("pause");
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