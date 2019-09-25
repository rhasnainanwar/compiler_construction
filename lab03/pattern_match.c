#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>


#define BUFFER_SIZE 128


int ismatch(char*);
void single_buffer_regex(FILE*);


int main() {
	FILE* fp = NULL;
	fp = fopen("para.txt", "r");

	if (fp == NULL) {
		printf("Error while opening the file\n");
		return -1;
	}
	printf("Matches of words starting wtih M or T:\n");
	single_buffer_regex(fp);
}


int ismatch(char *input){
	char * pattern = "^[m|t|M|T]";
	regex_t regex;
	int out;

    out = regcomp(&regex, pattern, 0);
    if(out){
    	fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    out = regexec(&regex, input, 0, NULL, 0);

    regfree(&regex);
    if( !out )
        return 1;
    return 0;
}


void single_buffer_regex(FILE* fp){
	char buffer[BUFFER_SIZE], ch;
	int indx = 0;

	while ((ch = fgetc(fp)) != EOF && ch != '\0') {
		if(isspace(ch) || ch == '\0'){

			buffer[indx] = '\0'; // make the input string-like

			if(strlen(buffer) > 1 && ismatch(buffer))
				printf("%s\n", buffer);

			indx = 0;
		}
		else {
			buffer[indx] = ch;
			indx++;
		}
	}
}