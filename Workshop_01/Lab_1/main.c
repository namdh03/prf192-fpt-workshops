#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float width, height, perimeter, area;
	
	printf("Enter the width of the rectangle: ");
	scanf("%f", &width);
	printf("Enter the height of the rectangle: ");
	scanf("%f", &height);
	
	perimeter = (width + height) * 2;
	area = width * height;
	
	printf("The perimeter of a rectangle is %0.2f\n", perimeter);
	printf("The area of a rectangle is %0.2f\n", area);
	
	return 0;
}
