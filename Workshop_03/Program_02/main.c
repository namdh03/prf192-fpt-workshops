#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int validDate(int d, int m, int y) {
	int maxd = 31; // max day of months 1, 3, 5, 7, 8, 10, 12
	
	if (d < 1 || d > 31 || m < 1 || m > 12) {
		return 0;
	}	
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		maxd = 30;
	}
	else if (m == 2) {
		// leep year?
		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
			maxd = 29;
		}
		else {
			maxd = 28;
		}
	}
	
	return d <= maxd;
}

int main(int argc, char *argv[]) {
	int d, m, y;
	char c;
	
	do {
		printf("Enter the data of a day: ");
		fflush(stdin);
	} while (scanf("%d%d%d%c", &d, &m, &y, &c) != 4 || c != '\n');
	
	if (validDate(d, m, y)) {
		printf("Valid date\n");
	}
	else {
		printf("Invalid date\n");
	}
	
	return 0;
}
