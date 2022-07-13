#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int getRelPos(double x, double y, double r) {
	double distance;
	
	distance = sqrt(pow(x, 2) + pow(y, 2));
	
	if (distance > r) {
		return -1;
	}
	else if (distance == r) {
		return 0;
	}
	else {
		return 1;
	}
}

int main(int argc, char *argv[]) {
	double x, y, r;
	char c;
	
	do {
		printf("X = ");
		fflush(stdin);
	} while (scanf("%lf%c", &x, &c) != 2 || c != '\n');
	
	do {
		printf("Y = ");
		fflush(stdin);
	} while (scanf("%lf%c", &y, &c) != 2 || c != '\n');
	
	do {
		printf("r = ");
		fflush(stdin);
	} while ((scanf("%lf%c", &r, &c) != 2 || c != '\n') || r < 0);
	
	
	if (getRelPos(x, y, r) == -1) {
		printf("The point is out of the circle\n");
	}
	else if (getRelPos(x, y, r) == 0) {
		printf("The point is on the circle\n");
	}
	else {
		printf("The point is in the circle\n");
	}
	return 0;
}
