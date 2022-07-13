#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char c;

int isMenu();
void handleMenu(int op);
void checkDate();
int isDate(int dd, int mm, int yy);
void checkCharacter();
void printCharacter(char c1, char c2);

int main(int argc, char *argv[]) {
	int op;
	
	do {
		op = isMenu(op);
		handleMenu(op);
	} while (op == 1 || op == 2);
	
	return 0;
}

void printCharacter(char c1, char c2) {
	char temp;
	
	if (c1 > c2) {
		temp = c1;
		c1 = c2;
		c2 = temp;
	}
	
	for (int code = c2; code >= c1; code--) {
		printf("%c \t %d \t %Xh\n", code, code, code, code);
	}
	
	printf("\n");
}

void checkCharacter() {
	char c1, c2;
	
	printf("Input: ");
	scanf("%c%*c%c%*c", &c1, &c2);
	fflush(stdin);
	
	printCharacter(c1, c2);
}

int isDate(int dd, int mm, int yy) {
	int maxDD = 31;
	
	if (dd < 0 || dd > 31 || mm < 0 || mm > 12 || yy < 0) {
		return 0;
	}
	
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
		maxDD = 30;
	}
	else if (mm == 2) {
		if (yy % 400 == 0 || (yy % 4 == 0 && yy != 100)) {
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
	
	printf("Enter values of date, month, year: ");
	scanf("%d%d%d%*c", &dd, &mm, &yy);
	
	if (isDate(dd, mm, yy)) {
		printf("This date is valid\n\n");
	}
	else {
		printf("This date is not valid\n\n");
	}
}

void handleMenu(int op) {
	switch (op) {
		case 1:
			checkDate();
			printf("Press enter to countinue . . .\n");
			getchar();
			break;
			
		case 2:
			checkCharacter();
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
		printf("1 - Processing date data\n");
		printf("2 - Character data\n");
		printf("3 - Quit\n");
		printf("Choose an operation: ");
		count = scanf("%d%c", &op, &c);
		fflush(stdin);
	} while (count != 2 || c != '\n' || op > 3 || op < 1);
	
	return op;
}
