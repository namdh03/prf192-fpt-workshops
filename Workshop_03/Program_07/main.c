#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sumDigits(int n);

int main(int argc, char *argv[]) {
	int n = -1, count, res;
	char c;
	
	do {	
		printf("Enter a nonnegative integer: ");
		count = scanf("%d%c", &n, &c);
		fflush(stdin);
		
		if (n >= 0) {
//			system("cls");
			res = sumDigits(n);
			printf("Sum of %d decimal digits is %d\n\n", n, res);
		}
	} while (count != 2 || c != '\n' || n >= 0);
	
	return 0;
}

int sumDigits(int n) {
	int remainder, sum = 0;
	
//	n = 119; 
	do {
		remainder = n % 10; // remainder = 9 
		n = n / 10; // n = 11
		sum += remainder; // sum = 11
	} while (n > 0);
	
	return sum;
}
