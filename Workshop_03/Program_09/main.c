#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int gcd(int a, int b) {
//	while (a)
//}

int gcd(int a, int b);
int lcm(int a, int b);

int main(int argc, char *argv[]) {
	int a, b, d, m;
	char c;
	
//	do {
//		printf("Enter two positive integers: ");
//		fflush(stdin);
//	} while ((scanf("%d%d%c", &a, &b, &c) != 3 || c != '\n') || (a <= 0 || b <= 0));


	do {
		printf("Enter a = ");
		fflush(stdin);
	} while ((scanf("%d%c", &a, &c) != 2 || c != '\n') || a <= 0);
	
	do {
		printf("Enter b = ");
		fflush(stdin);
	} while ((scanf("%d%c", &b, &c) != 2 || c != '\n') || b <= 0);
	
	d = gcd(a, b);
	m = lcm(a, b);
	
	printf("The greatest common divisor: %d\n", d);
	printf("The least common multiple: %d\n", m);
	
	return 0;
}

int gcd(int a, int b) {  
	while (a != b) {
		if (a > b) {
			a -= b;
		}
    	else {
    		b -= a;
		}
	}
		
	return a;
}

int lcm(int a, int b) { 
	return a*b / gcd(a, b);
}
