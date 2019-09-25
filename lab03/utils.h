#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 11
#define SENTINEL '\?'

int fill_buffer(FILE*, char*);
int fill_buffer_pair(FILE*, char*, int);
int isop(char);
int isidentifier(char*);
