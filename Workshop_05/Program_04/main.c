#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char character;

int isMenu();
void handleMenu(int op);
void quadraticEquation();
int isQuadraticEquation(double a, double b, double c, double* x1, double* x2);
void bankDeposit();

int main(int argc, char *argv[]) {
	int op;
	
	do {
		op = isMenu(op);
		handleMenu(op);
	} while (op == 1 || op == 2);
	
	return 0;
}

void bankDeposit() {
	int d, n, count;
	float r, P;
	
	do {
		printf("Enter your deposit (a positive number): ");
		count = scanf("%d%c", &d, &character);
		fflush(stdin);
	} while(count != 2 || character != '\n' || d < 1);
	
	do {
		printf("Enter your yearly rate (a positive number but less than or equal to 0.1): ");
		count = scanf("%f%c", &r, &character);
		fflush(stdin);
	} while(count != 2 || character != '\n' || r < 0 || r > 1);
	
	do {
		printf("Enter your number of years (a positive integer): ");
		count = scanf("%d%c", &n, &character);
		fflush(stdin);
	} while(count != 2 || character != '\n' || n < 1);
	
	P = d * pow((1+r), n);
	
	printf("Your amount after this duration is %f\n\n", P);
}

int isQuadraticEquation(double a, double b, double c, double* x1, double* x2) {
	double delta;
	
	if (a == 0) {
		return 0;
	}
	else {
		delta = pow(b, 2) - 4 * a * c;
		
		if (delta < 0) {
			return 0;
		}
		else if (delta == 0) {
			*x1 = -b / 2 * a; 
			return 1;
		}
		else {
			*x1 = (-b + sqrt(delta)) / 2*a;
			*x2 = (-b - sqrt(delta)) / 2*a;
			return 2;
		}
	}
}

void quadraticEquation() {
	double a, b, c, x1, x2;
	int count, res;
	
	printf("The quadratic equation has format ax^2 + bX + c\n");
	do {
		printf("Enter a: ");
		count = scanf("%lf%c", &a, &character);
		fflush(stdin);
	} while (count != 2 || character != '\n');
	
	do {
		printf("Enter b: ");
		count = scanf("%lf%c", &b, &character);
		fflush(stdin);
	} while (count != 2 || character != '\n');
	
	do {
		printf("Enter c: ");
		count = scanf("%lf%c", &c, &character);
		fflush(stdin);
	} while (count != 2 || character != '\n');
	
	res = isQuadraticEquation(a, b, c, &x1, &x2);
	if(res == 0) {
		printf("No solution!\n\n");
	}
	else if (res == 1) {
		printf("X = %.2lf\n\n", x1);
	}
	else {
		printf("X1 = %.2lf and X2 = %.2lf\n\n", x1, x2);
	}
}

void handleMenu(int op) {
	switch (op) {
		case 1:
			quadraticEquation();
			printf("Press enter to countinue . . .\n");
			getchar();
			break;
			
		case 2:
			bankDeposit();
			printf("Press enter to countinue . . .\n");
			getchar();
			break;
			
		case 3:
			break;
	}
}

int isMenu(int op) {
	int count;
	
	do {
		system("cls");
		printf("1 - Quadratic equation\n");
		printf("2 - Bank deposit problem\n");
		printf("3 - Quit\n");
		printf("Choose an operation: ");
		count = scanf("%d%c", &op, &character);
		fflush(stdin);
	} while (count != 2 || character != '\n' || op > 3 || op < 1);
	
	return op;
}
