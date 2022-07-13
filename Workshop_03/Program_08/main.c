#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double makeDouble(int iPart, int faction);

int main(int argc, char *argv[]) {
	int iPart, faction;
	char c;
	
	do {
		printf("Enter interal part: ");
		fflush(stdin);
	} while (scanf("%d%c", &iPart, &c) != 2 || c != '\n');

	do {
		printf("Enter faction: ");
		fflush(stdin);
	} while ((scanf("%d%c", &faction, &c) != 2 || c != '\n') || faction < 0);
	
	printf("%lf\n", makeDouble(iPart, faction));
	
	return 0;
}

double makeDouble(int iPart, int faction) {
	double doubleFaction;
	
	doubleFaction = faction; // faction = 119;
	
	while (doubleFaction >= 1) {
		doubleFaction = doubleFaction / 10;
	} 
	if (iPart < 0) {
		return iPart - doubleFaction;
	}
	else {
		return iPart + doubleFaction;
	}
}
