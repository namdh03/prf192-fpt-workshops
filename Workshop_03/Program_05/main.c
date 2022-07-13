#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fibonacci(int n) {
	int firstNumb = 1, secondNumb = 1;
	int fib = 1;
	
	for (int i = 3; i <= n; i++) {
		fib = firstNumb + secondNumb;
		firstNumb = secondNumb;
		secondNumb = fib;
	}
	
	return fib;
}

int main(int argc, char *argv[]) {
	int n, res;
	char c;
	
	do {
		system("cls");
		printf("Enter the n position: ");
		fflush(stdin);
	} while ((scanf("%d%c", &n, &c) != 2 || c != '\n') || n <= 0);
	
	res = fibonacci(n);
	
	printf("The %d position in Fibonacci sequence is %d\n", n, res);
	
	return 0;
}
