#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char* lTrim(char s[]) {
	int i = 0;
	
	while (s[i] == ' ') {
		i++;
	}
	
	if (i > 0) {
		strcpy(&s[0], &s[i]);
	}
	
	return s;
}

char* rTrim(char s[]) {
	int i = strlen(s) - 1;
	
	while (s[i] == ' ') {
		i--;
	}
	
	s[i + 1] = '\0';
	
	return s;
}

char* trim(char s[]) {
	rTrim(lTrim(s));
	
	char* ptr = strstr(s, "  ");
	
	while (ptr != NULL) {
		strcpy(ptr, ptr + 1);
		ptr = strstr(s, "  ");
	}
	
	return s;
}

char* nameStr(char s[]) {
	trim(s);
	strlwr(s);
	
	for (int i = 0; i < strlen(s); i++) {
		if (i == 0 || (i > 0 && s[i - 1] == ' ')) {
			s[i] = toupper(s[i]);
		}
	}
	
	return s;
}

char* countWords(char* s) {
	int count = 0;
	
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
			count++;
		}
	}
	
	printf("Count words: %d\n", count);
}

char* countIntegers(char s[]) {
	int count = 0;
	
	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i]) && (i == 0 || !isdigit(s[i - 1]))) {
			count++;
		}
	}
	
	printf("Count integers: %d\n", count);
} 

int main(int argc, char *argv[]) {
	char s[21];
	int cnt = 0;
	
	printf("Enter string s: ");
	gets(s);
	trim(s);
	
	printf("After extra blanks are remove: ");
	puts(s);
	nameStr(s);
	
	printf("After convert it to a name: ");
	puts(s);
	
	countWords(s);
	countIntegers(s);
	
	system("pause");
	return 0;
}
