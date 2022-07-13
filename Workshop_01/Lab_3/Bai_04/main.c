#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int iResult, a, b, c, d, e;
	
	printf("\n Enter 6 integer numbers: ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	iResult = a - b - c - d;
	printf("\niResult = %d", iResult);
	
	iResult = a - b + c - d;
	printf("\niResult = %d", iResult);
	
	iResult = a + b / c / d;
	printf("\niResult = %d", iResult);
	
	iResult = a + b / c * d;
	printf("\niResult = %d", iResult);
	
	iResult = a / b * c * d;
	printf("\niResult = %d", iResult);
	
	iResult = a % b / c * d;
	printf("\niResult = %d", iResult);
	
	iResult = a % b % c % d;
	printf("\niResult = %d", iResult);
	
	iResult = a - (b - c) - d;
	printf("\niResult = %d", iResult);
	
	iResult = (a - (b - c)) - d;
	printf("\niResult = %d", iResult);
	
	iResult = a - ((b - c) - d);
	printf("\niResult = %d", iResult);
	
	iResult = a % (b % c) * d * e;
	printf("\niResult = %d", iResult);
	
	iResult = a + (b - c) * d - e;
	printf("\niResult = %d", iResult);
	
	iResult = (a + b) * c + d * e;
	printf("\niResult = %d", iResult);
	
	iResult = (a + b) * (c / d) % e;
	printf("\niResult = %d\n", iResult);
	
	system("pause");
	return 0;
}
