#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char c;

int isMenu(int op);
void handleMenu(int op);
void fibonacciSequence();
void printFibo(int n);
void checkDate();
int isDate(int dd, int mm, int yy);

int main(int argc, char *argv[]) {
	int op;
	
	op = isMenu(op);
	handleMenu(op);
	
	return 0;
}

int isDate(int dd, int mm, int yy) {
	int maxDD = 31;
	
	if ((dd <= 0 || dd > 31) || (mm <= 0 || mm > 12) || yy <= 0) {
		return 0;
	}
	
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
		maxDD = 30;
	}
	else if (mm == 2) {
		if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) {
			maxDD = 29;
		}
		else {
			maxDD = 28;
		}
	}
	
	return dd <= maxDD;
}

void checkDate() {
	int dd, mm, yy, acc;
	
	printf("Enter date with (DD MM YY) format: ");
	scanf("%d%d%d", &dd, &mm, &yy);
	fflush(stdin);
	
	acc = isDate(dd, mm, yy);
	
	if (acc == 0) {
		printf("This date is not valid\n\n");
	}
	else {
		printf("This date is valid\n\n");
	}
}

void printFibo(int n) {
	double f1 = 1, f2 = 1, next;
	
	printf("%.0lf ", f1);
    for (int i = 1; i < n; i++) {
        printf("%.0lf ", f2);
        
        next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    printf("\n\n");
}

void fiboSequence() {
	int n, count = 0;
	
	do {
		printf("Enter a positive integral number: ");
		count = scanf("%d%c", &n, &c);
		fflush(stdin);
	} while (count != 2 || c != '\n' || n < 1);
	
	printFibo(n);
}

void handleMenu(int op) {
	switch (op) {
		case 1:
			fiboSequence();
			printf("Press enter to continue . . .\n");
			getchar();
			op = isMenu(op);
			handleMenu(op);
			break;
			
		case 2:
			checkDate();
			printf("Press enter to continue . . .\n");
			getchar();
			op = isMenu(op);
			handleMenu(op);
			break;
			
		case 3:
			return 0;
	}
}

int isMenu(int op) {
	int count = 0;
	
	do {
		system("cls");
		printf("1 - Fibonacci sequence\n");
		printf("2 - Check a date\n");
		printf("3 - Quit\n");
		printf("Choose an operation: ");
		count = scanf("%d%c", &op, &c);
		fflush(stdin);
	} while (count != 2 || c != '\n' || op < 1 || op > 3);
}
