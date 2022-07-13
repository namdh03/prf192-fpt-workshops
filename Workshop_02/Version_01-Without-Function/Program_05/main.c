#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ENTER 10 // '\n'

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char ch;
	int vowels = 0, consonants = 0, others = 0;
	
	printf("Enter a string of characters: ");
	
	do {
		ch = getchar();
		ch = toupper(ch);
		
		if (ch >= 'A' && ch <= 'Z') {
			switch (ch) {
				case 'A':
					vowels++;
					break;
					
				case 'E':
					vowels++;
					break;
					
				case 'I':
					vowels++;
					break;
					
				case 'O':
					vowels++;
					break;
					
				case 'U':
					vowels++;
					break;
					
				default:
					consonants++;
			}
		}
		else {
			others++;
			if (ch == ENTER) {
				others--;
			}
		}
	} while (ch != ENTER);
	
	printf("The number of vowels: %d\n", vowels);
	printf("The number of consonants: %d\n", consonants);
	printf("The number of others: %d\n", others);
	
	system("pause");
	return 0;
}
