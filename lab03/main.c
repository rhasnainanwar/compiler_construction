#include "input_buffering.c"

int main() {
	FILE* fp = NULL;
	fp = fopen("test.txt", "r");

	if (fp == NULL) {
		printf("Error while opening the file\n");
		return -1;
	}
	printf("Running Task 1:\n");
	single_buffer(fp);

	rewind(fp);
	printf("\nRunning Task 2: \n");
	buffer_pair(fp);

	fclose(fp);
}
