#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isMaxDigits(int n);
int isMinDigits(int n);

int main(int argc, char *argv[]) {
	int n, max, min; 
	char c;
	
	do {
		printf("Enter a non-negative integer: ");
		fflush(stdin);
	} while ((scanf("%d%c", &n, &c) != 2 || c != '\n') || n <= 0);
	
	max = isMaxDigits(n);
	min = isMinDigits(n);
	
	printf("Maximum digits: %d\n", max);
	printf("Minimum digits: %d\n", min);
	
	return 0;
}

int isMaxDigits(int n) {
	int remainder, max;
	
	remainder = n % 10; 
	n = n / 10;
	max = remainder;
	
	while (n > 0) {
		remainder = n % 10; 
		n = n / 10;
		
		if (remainder > max) {
			max = remainder;
		}
	}
	
	return max;
}

int isMinDigits(int n) {
	int remainder, min;
	
	remainder = n % 10;  
	n = n / 10;
	min = remainder;
	
	while (n > 0) {
		remainder = n % 10;  
		n = n / 10;
	
		if (remainder < min) {
			min = remainder;
		}
	}
	
	return min;
}
