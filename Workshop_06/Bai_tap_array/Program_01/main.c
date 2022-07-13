#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int check;
char character;

int* inputArray(int* a, int* size);
void outputArray(int* a, int* size);
int sumOfEven(int* a, int* size);
int countFrequency(int* a, int* size, int x);
void sortArray(int* a, int* size);
void swap(int* i, int* j);

int main(int argc, char *argv[]) {
	int* a;
	int size, sum, x, count;
	
	a = inputArray(a, &size);
	
	printf("\nOutput array: ");
	outputArray(a, &size);
	
	sum = sumOfEven(a, &size);
	printf("\nSum of elements at even positions in array is %d\n", sum);
	
	do {
		printf("Enter the number to count frequency in that array: ");
		check = scanf("%d%c", &x, &character);
		fflush(stdin);
	} while (check != 2 || character != '\n');
	
	count = countFrequency(a, &size, x);
	if (count > 0) {
		printf("The number of occurrences of %d in array is %d\n", x, count);
	}
	else {
		printf("%d is not found\n", x);
	}
	
	sortArray(a, &size);
	outputArray(a, &size);
	
	return 0;
}

void swap(int* i, int* j) {
	int tmp;
	
	tmp = *i;
	*i = *j;
	*j = tmp;
}

void sortArray(int* a, int* size) { 
	for (int i = 0; i < *size - 1; i++) { 
		for (int j = i + 1; j < *size; j++) { 
			if (i % 2 == 0 && j % 2 == 0) { 
				if (a[i] < a[j]) { 
					swap(&a[i], &a[j]);
				}
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				if (a[i] > a[j]) {
					swap(&a[i], &a[j]);
				}
			}
		}
	}
}

int countFrequency(int *a, int* size, int x) {
	int count = 0;
	
	for (int i = 0; i < *size; i++) {
		if (a[i] == x) {
			count++;
		}
	}
	
	return count;
}

int sumOfEven(int *a, int* size) {
	int sum = 0;
	
	for (int i = 0; i < *size; i++) {
		if (i % 2 ==0) {
			sum += a[i];
		}
	}
	
	return sum;
}

void outputArray(int *a, int* size) {
	for (int i = 0; i < *size; i++) {
		printf("%d ", a[i]);
	}
}

int* inputArray(int *a, int* size) {
	do {
		printf("Enter the amount of elements in array: ");
		check = scanf("%d%c", size, &character);
		fflush(stdin);
	} while (check != 2 || character != '\n' || *size <= 0);
	
	a = (int*)calloc(*size, sizeof(int));
	
	for (int i = 0; i < *size; i++) {
		do {
			printf("a[%d]: ", i);
			check = scanf("%d%c", &a[i], &character);
			fflush(stdin); 
		} while (check != 2 || character != '\n'); 
	}
	
	return a;
}
