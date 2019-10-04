#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define MAX_PROD 10

void check_recursion(char [MAX_PROD][MAX_SIZE], int);
void fix_recursion(char [MAX_SIZE], char, char, char);

int main(){

	char grammar[MAX_PROD][MAX_SIZE], c;
	int num_prods;

	printf("Enter the number of productions: ");
	scanf("%d", &num_prods);
	while((c = getchar()) != '\n' && c != EOF);

	printf("Enter the grammar productions line by line as A->BC|a:\n");
	for(int i = 0; i < num_prods; i++){
		fgets(grammar[i], MAX_SIZE, stdin);
		// remove trailing line-break
		strtok(grammar[i], "\n");
	}

	check_recursion(grammar, num_prods);

	return 0;
}


void fix_recursion(char production[MAX_SIZE], char non_terminal, char alpha, char beta){
	printf("Production without left recursion:\n");  
	printf("%c->%c%c\'", non_terminal, beta, non_terminal);
	printf("\n%c\'->%c%c\'|~\n", non_terminal, alpha, non_terminal);
}


void check_recursion(char grammar[MAX_PROD][MAX_SIZE], int num){
	char left, alpha;
	int offset;

	for(int i = 0; i < num; i++){
		printf("\nProduction: %s\n", grammar[i]);
		offset = 3; // offset gives production start, after ->
		left = grammar[i][0];

		while(offset < strlen(grammar[i])){
			if(left == grammar[i][offset]){
				printf("This production is left-recursive.\n");

				int index = offset;
				while(grammar[i][index]!='|' && index < strlen(grammar[i]))
					index++;
				fix_recursion(grammar[i], left, grammar[i][offset+1], grammar[i][index+1]);
				break;
			}
			while(grammar[i][offset]!='|' && offset < strlen(grammar[i]))
				offset++;

			offset++;
		}

		if(offset >= strlen(grammar[i]))
			printf("This production is not left-recursive.\n");
	}
}