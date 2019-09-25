#include "utils.h"

int fill_buffer(FILE* fp, char* buffer) {
	char ch;
	int count = -1;
	while ((ch = fgetc(fp)) != EOF && ch != '\0') {
		buffer[++count] = ch;
		if (count == BUFFER_SIZE)
			break;
	}

	if(ch == EOF || ch == '\0')
		buffer[count] = '\0';

	if(count > 0)
		return count;
	return 0;
}

int fill_buffer_pair(FILE* fp, char* buffer, int curr) {
	char ch;
	int count = 0, offset;

	if(curr)
		offset = 0;
	else
		offset = BUFFER_SIZE;
	
	while ((ch = fgetc(fp)) != EOF && ch != '\0') {
		buffer[offset+count] = ch;
		++count;
		if (count == BUFFER_SIZE-1)
			break;
	}

	if(feof(fp))
		buffer[offset+count] = '\0';
	else
		buffer[offset+count] = SENTINEL;

	return 1 - curr;
}

int isop(char tok)
{
	char* ops = "!^+-*/%=";
	char* c;
	for(c = ops; *c != '\0'; ++c) {
		if (*c == tok)
			return 1;
	}
	return 0;
}

int isidentifier(char *input)
{
	// check first character condition
	if (!isalpha((unsigned char)input[0]) && input[0] != '_')
		return 0;

	char* iter = input + 1;

	// check whole string
	while (iter != NULL && *iter != '\0')
	{
		if (isalpha(*iter) || *iter == '_')
			++iter;
		else
			return 0;
	}
	return 1;
}