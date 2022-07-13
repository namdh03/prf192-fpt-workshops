#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char c;

int isMenu(int option);
int handleMenu(int option);
void processPrimes();
int isPrime(int* x);
void printDigits();
int minDigits(int x);
int maxDigits(int x);

int main(int argc, char *argv[]) {
	int option;

	option =  isMenu(option);
	handleMenu(option);
	
	return 0;
}

int maxDigits(int x) {
	int remainder, max = 0;
	
	do {
		remainder = x % 10;
		x = x / 10;
		
		if (remainder > max) {
			max = remainder;
		}
	} while (x > 0);
	
	return max;
}

int minDigits(int x) {
	int remainder, min = 9;
	
	do {
		remainder = x % 10;
		x = x / 10;
		
		if (remainder < min) {
			min = remainder;
		}
	} while (x > 0);
	
	return min;
}

void printDigits() {
	int x, count, min, max;
	
	do {
		printf("Enter a positive number: ");
		count = scanf("%d%c", &x, &c);
		fflush(stdin);
	} while (count != 2 || c != '\n' || x <= 0);
	
	min = minDigits(x);
	printf("The minimum that digit is %d\n", min);
	
	max = maxDigits(x);
	printf("The maximum that digit is %d\n", max);
}

int	isPrime(int* x) {
	int result = 1;
	
	if (*x == 1) {
		return 0;
	}
	
	for (int i = 2; i <= sqrt(*x); i++) {
		if (*x % i == 0) {
			return 0;
		}
	}
	
	return result;
}

void processPrimes() {
	int x, count, acc;
	
	do {
		printf("Enter a positive number: ");
		count = scanf("%d%c", &x, &c);
		fflush(stdin);
	} while (count != 2 || c != '\n' || x <= 0);
	
	acc = isPrime(&x);
	
	if (acc == 0) {
		printf("%d is not a prime number\n", x);
	}
	else {
		printf("%d is a prime number\n", x);
	}
}

int handleMenu(int option) {
	switch (option) {
		case 1:
			system("color 1");
			processPrimes();
			printf("\nPress enter to continue . . .\n");
			getchar();
			system("color 7");
			option = isMenu(option);
			handleMenu(option);
			break;
			
		case 2:
			system("color 2");
			printDigits();
			printf("\nPress enter to continue . . .\n");
			getchar();
			system("color 7");
			option = isMenu(option);
			handleMenu(option);
			break;
			
		case 3:
			system("color F");
			return 0;
	}
}

int isMenu(int option) {
	int count; 
	
	do {
		system("cls");
		system("color F");
		printf("1 - Process primes\n");
		printf("2 - Print min, max digit in an integer\n");
		printf("3 - Quit\n");
		printf("\nSelect an operation: ");
		count = scanf("%d%c", &option, &c);
		fflush(stdin);
	} while (count != 2 || c != '\n' || option > 3 || option < 1);
	
	return option;
}
