#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float c, f, i;
	
	printf("\n Enter the input value in centimeters: ");
	scanf("%f", &c);
	
	i = c/2.54f; 
	f = i/12; 
	
	printf("\n\n The results are: \n\n	%f feet\n	%f inch\n\n", f, i);
	
	system("pause");
	return 0;
}
