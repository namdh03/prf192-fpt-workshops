#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int count;
char c;

void input(int a[][100], int* row, int* column);
void output(int a[][100], int* row, int* column);
void sortArray(int a[][100], int* row, int* column);
void swap(int* i, int* j);
int binarySearch(int a[][100], int x, int row, int column);
void sortEvenOdd(int a[][100], int* row, int* column);

int main(int argc, char *argv[]) {
	int a[100][100];
	int row, column;
	int x;
	
	input(a, &row, &column);
	
	sortArray(a, &row, &column);
	
	printf("Sort array: \n");
	output(a, &row, &column);
	
	do {
		printf("Enter the element that you need find: ");
		count = scanf("%d%c", &x, &c);
	} while (count != 2 || c != '\n');
	
	binarySearch(a, x, row, column);
	
	printf("Sort even and odd: \n");
	sortEvenOdd(a, &row, &column);
	output(a, &row, &column);
	
	return 0;
}

void sortEvenOdd(int a[][100], int* row, int* column) { 
	for (int k = 0; k < *row; k++) {
		for (int i = 0; i < *column; i++) {
			for (int j = 0; j < *column - 1 - i; j++) {
				if (k % 2 == 0) {
					if (a[k][j] > a[k][j + 1]) {
						swap(&a[k][j], &a[k][j + 1]);
					}
				}
				else {
					if (a[k][j] < a[k][j + 1]) {
						swap(&a[k][j], &a[k][j + 1]);
					}
				}
			}
		}
	}
}

int binarySearch(int a[][100], int x, int row, int column) {
	int count = 0;
	
	for (int i = 0; i < row; i++) {
    	for (int j = 0; j < column; j++) {
			if (a[i][j] == x) {
				printf("%d is found at row %d - column %d\n", x, i, j);
        		count++;
			}
    	}	
	}
	
	if (count == 0) {
		printf("%d is not found\n", x);
	}
}

void swap(int* i, int* j) {
	int tmp;
	
	tmp = *i;
	*i = *j;
	*j = tmp;
}

void sortArray(int a[][100], int* row, int* column) {
	for (int i = 0; i < *row * *column - 1; i++) {
		for (int j = 0; j < *row * *column - 1 - i; j++) {
			if (a[j / *column][j % *column] > a[(j + 1) / *column][(j + 1) % *column]) {
				swap(&a[j / *column][j % *column], &a[(j + 1) / *column][(j + 1) % *column]);
			}
		}
	}
}

void output(int a[][100], int* row, int* column) {
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *column; j++) {
			printf("%-5d ", a[i][j]);
		}
		printf("\n");
	}
}

void input(int a[][100], int* row, int* column) {
	do {
		printf("Enter row of array: ");
		count = scanf("%d%c", &*row, &c);
		fflush(stdin);
	} while (count != 2 || c != '\n' || *row < 0);
	
	do {
		printf("Enter column of array: ");
		count = scanf("%d%c", &*column, &c);
		fflush(stdin);
	} while (count != 2 || c != '\n' || *column < 0);
	
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *column; j++) {
			do {
				printf("a[%d][%d] = ", i, j);
				count = scanf("%d%c", &a[i][j], &c);
				fflush(stdin);	
			} while (count != 2 || c != '\n');
		}
	}	
}
