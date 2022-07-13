#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double num1, num2, result;
	char op;
	
	printf("Enter an expression (+ - * /): ");
	scanf("%lf%c%lf", &num1, &op, &num2);
	
	switch (op)
	{
		case '+':
			result = num1 + num2;
			printf("Result: %.2lf", result);
			break;
				
		case '-':
			result = num1 - num2;
			printf("Result: %.2lf", result);
			break;
			
		case '*':
			result = num1 * num2;
			printf("Result: %.2lf", result);
			break;
			
		case '/':
			if (num2 == 0)
			{
				printf("Cannot divide by zero");
			}
			else
			{
				result = num1 / num2;
			    printf("Result: %.2lf", result);	
			}
			break;
			
		default:
			printf("Op is not supported");
	}
	
	getchar();
	getchar();
	getchar();
	return 0;
}
