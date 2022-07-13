#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numberOne, numberTwo, temporary;
	
	do 
	{
		printf("Enter the number one: ");
		scanf("%d", &numberOne);
		
		printf("Enter the number two: ");
		scanf("%d", &numberTwo);
		
		fflush(stdin);
		
		temporary = numberOne;
		numberOne = numberTwo;
		numberTwo = temporary;
		
		if (numberOne == 0 || numberTwo == 0) 
		{
			system("pause");
			return 0;
		}
		
		printf("Number one: %d\tNumber two: %d\n\n", numberOne, numberTwo);
	} while (numberOne != 0 && numberTwo != 0);
}
