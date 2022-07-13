#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char character;

int inputIncome(int income) {
	do {
		printf("Your income of this year: ");	
		fflush(stdin);
	} while ((scanf("%d%c", &income, &character) != 2 || character != '\n') || income < 0);
	
	return income;
}

int inputDependents(int n) {
	do {
		printf("Number of dependent: ");
	} while ((scanf("%d%c", &n, &character) != 2 || character != '\n') || n < 0);
	
	return n;
}

int isIncomeTax(double ti) {
	int incomeTax;
	
	if (ti <= 0) {
		incomeTax = 0;
	}
	else if (ti <= 5000000 && ti > 0) { // 5.000.000 * 5% = 250.000d (0; 5.000.000]
		incomeTax = ti * 5 / 100;
	}
	else if (ti >= 5000001 && ti <= 10000000) { // 5.000.000 * 10% = 500.000d [5.000.001; 10.000.000]
		incomeTax = 5000000 * 5 / 100 + (ti - 5000000) * 10 / 100;
	}
	else if (ti >= 10000001 && ti <= 18000000) { // 8.000.000 * 15% = 1.200.000d
		incomeTax = 5000000 * 5 / 100 + 5000000 * 10 / 100 + (ti - 10000000) * 15 / 100;
	}
	else if (ti > 18000000) { // 2.000.000 * 20% = 400.000d
		incomeTax = 5000000 * 5 / 100 + 5000000 * 10 / 100 + 8000000 * 15 / 100 + (ti - 18000000) * 20 / 100;
	}
	
	return incomeTax;
}

int main(int argc, char *argv[]) {
	int income, n;
	int pa, pd, tf, incomeTax;
	double ti;
	
	income = inputIncome(income);
	n = inputDependents(n);
	
	pa = 9000000;
	pd = 3600000;
	tf = 12 * (pa + n * pd);
	ti = income - tf;
	if (ti <= 0) ti = 0;
	
	incomeTax = isIncomeTax(ti);
	
	printf("Tax-free income: %d\n", tf);
	printf("Taxable income: %.0lf\n", ti);
	printf("Income tax: %d\n", incomeTax);
	
	system("pause");
	return 0;
}
