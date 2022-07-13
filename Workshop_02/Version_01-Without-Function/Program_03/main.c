#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x, S;
	
	S = 0;
	
	do 
	{
		printf("Number: ");
		scanf("%d", &x);
		
		if (x != 0)
		{
			S = S + x;
		} 
	} while (x != 0);
	
	printf("S = %d\n", S);
	
	system("pause");
	return 0;
}
