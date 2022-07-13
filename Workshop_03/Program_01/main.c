#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isPrimes(int n) {
	int result = 1;
	
	if (n < 2) {
		return 0;
	}
	
	for (int i = 2; i <= sqrt(n) && result == 1; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return result;
} 

void printPrimes(int n) {
	for (int i = 2; i <= n; i++) {
		if (isPrimes(i) == 1) {
			printf("%d ", i);
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	char c;
	
	do {
		system("cls");
		printf("Enter a positive integer n (n >= 2): ");
		fflush(stdin);
	} while ((scanf("%d%c", &n, &c) != 2 || c != '\n') || n < 2);
	
	printPrimes(n);
	
	return 0;
}
