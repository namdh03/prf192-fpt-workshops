#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double calculateExpression(double num1, char op, double num2) {
	double result;
	
	switch (op) {
		case '+':
			result = num1 + num2;
			break;
				
		case '-':
			result = num1 - num2;
			break;
			
		case '*':
			result = num1 * num2;
			break;
			
		case '/':
			if (num2 == 0) {
				printf("Cannot divide by zero\n");
			}
			else {
				result = num1 / num2;	
			}
			break;
			
		default:
			printf("Op is not supported\n");
	}
	
	return result;
}

int main(int argc, char *argv[]) {
	double num1, num2, result;
	char op;
	
	printf("Enter an expression (+ - * /): ");
	scanf("%lf%c%lf", &num1, &op, &num2);
	
	result = calculateExpression(num1, op, num2);
	
	printf("Result: %.2lf\n", result);
		
	system("pause");
	return 0;
}

