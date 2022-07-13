#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int pa, pd, income, n, tf, incomeTax;
	double ti;
	
	printf("Your income of this year: ");
	scanf("%d", &income);
	
	printf("Number of dependent: ");
	scanf("%d", &n);
	
	pa = 9000000;
	pd = 3600000;
	tf = 12 * (pa + n * pd);
	ti = income - tf;
	
	if (ti <= 0) 
	{
		ti = 0;
		incomeTax = 0;
	}
	else if (ti <= 5000000 && ti > 0) // 5.000.000 * 5% = 250.000d (0; 5.000.000] 
	{
		incomeTax = ti * 5 / 100;
	}
	else if (ti >= 5000001 && ti <= 10000000) // 5.000.000 * 10% = 500.000d [5.000.001; 10.000.000]
	{
		incomeTax = 5000000 * 5 / 100 + (ti - 5000000) * 10 / 100;
	}
	else if (ti >= 10000001 && ti <= 18000000) // 8.000.000 * 15% = 1.200.000d
	{
		incomeTax = 5000000 * 5 / 100 + 5000000 * 10 / 100 + (ti - 10000000) * 15 / 100;
	}
	else if (ti > 18000000) // 2.000.000 * 20% = 400.000d
	{// 250.000 + 500.000 + 1.200.000 + 28.240.000
		incomeTax = 5000000 * 5 / 100 + 5000000 * 10 / 100 + 8000000 * 15 / 100 + (ti - 18000000) * 20 / 100;
	}
	
	printf("Tax-free income: %d\n", tf);
	printf("Taxable income: %.0lf\n", ti);
	printf("Income tax: %d\n", incomeTax);
	
	system("pause");
	return 0;
}
