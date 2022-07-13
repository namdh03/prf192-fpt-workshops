#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isSum() {
	int x = 0, S = 0;
	char c;
	
	do {
		printf("Number: ");
		fflush(stdin);
		
		if (x != 0) {
			S = S + x;
		}
	} while ((scanf("%d%c", &x, &c) != 2 || c != '\n') || x != 0);
	
	return S;
}

int main(int argc, char *argv[]) {
	int S;
	
	S = isSum();
	
	printf("S = %d\n", S);
	
	system("pause");
	return 0;
}
