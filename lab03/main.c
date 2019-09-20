#include "input_buffering.c"

int main() {
	FILE* fp = NULL;
	fp = fopen("test.txt", "r");

	if (fp == NULL) {
		printf("Error while opening the file\n");
		return -1;
	}

	single_buffer(fp);
}
