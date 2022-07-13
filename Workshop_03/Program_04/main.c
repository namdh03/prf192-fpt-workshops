#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double factorial();

int main(int argc, char *argv[]) {
	int a;
	char c;
	double reuslt;
	
	do {
		printf("Enter a (a > 0): ");
		fflush(stdin);
	} while ((scanf("%d%c", &a, &c) != 2 || c != '\n') || a <= 0);
	
	reuslt = factorial(a);
	printf("The factorial of %d is %.0lf\n", a, reuslt);
	
	return 0;
}

double factorial(int a) {
	double fact = 1;
	
	for (int i = 2; i <= a; i++) {
		fact = fact * i;
	}
	
	return fact;
}
