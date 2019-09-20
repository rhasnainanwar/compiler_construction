#include <stdio.h>
#include <stdlib.h>

int main() {

	char op;

	printf("Enter a character here: ");
	scanf_s("%c", &op);

	switch (op) {
	case '+':
		printf("Addition\n");
		break;
	case '-':
		printf("Subtraction\n");
		break;
	case '*':
		printf("Multiplication\n");
		break;
	case '/':
		printf("Division\n");
		break;
	case '%':
		printf("Modulus\n");
		break;
	default:
		printf("Invalid!\n");
	}

	system("pause");
	return 0;
}