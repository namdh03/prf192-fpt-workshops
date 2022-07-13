#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int numberOne, numberTwo;

void swapValue(int numberOne, int numberTwo) {
	int temporary;
	
	temporary = numberOne;
	numberOne = numberTwo;
	numberTwo = temporary;
	
//	printf("Number one: %d\tNumber two: %d\n\n", numberOne, numberTwo);
}

int main(int argc, char *argv[]) {	
	do {
		printf("Enter the number one: ");
		scanf("%d", &numberOne);
		
		printf("Enter the number two: ");
		scanf("%d", &numberTwo);
		
		if (numberOne == 0 || numberTwo == 0) {
			system("pause");
			return 0;
	    }
	    
	    swapValue(numberOne, numberTwo);
	    
	    printf("Number one: %d\tNumber two: %d\n\n", numberOne, numberTwo);
	} while (numberOne != 0 && numberTwo != 0);
}
