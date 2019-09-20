#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ID_LEN 128
#define BUFFER_SIZE 11

int fill_buffer(FILE*, char*);
int isop(char);
int isidentifier(char*);