#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int check;
char character;
int cnt = 0;

void isMenu(int* op);
void handleMenu(int op);
void addStudent(char names[][50], int* cnt);
void removeStudent(char names[][50], int* cnt);
void searchStudent(char names[][50], int cnt);
void listAscending(char names[][50], int cnt);

int main(int argc, char *argv[]) {
	int op;
	
	do {
		system("cls");
		isMenu(&op);
		handleMenu(op);
		printf("\n");
	} while (op >= 1 && op <= 4);
	
	return 0;
}

void listAscending(char names[][50], int cnt) {
	char tmp[31];
	
	for (int i = 0; i < cnt - 1; i++) {
		for (int j = 0; j < cnt - 1 - i; j++) {
			if (strcmp(names[j], names[j + 1]) > 0) {
				strcpy(tmp, names[j]);
				strcpy(names[j], names[j + 1]);
				strcpy(names[j + 1], tmp);
			}
		}
	}
	
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j < strlen(names[i]); j++) {
			if (names[i][j] == ' ') {
				j++;
			}
			else if (names[i][j] >= 'A' && names[i][j]  <= 'Z') {
				names[i][j] += 32;
			}
		}
	}
	
	printf("\nStudent list:\n");
	for (int i = 0; i < cnt; i++) {
		printf("%d: %s\n", i + 1, names[i]);
	}
}

void searchStudent(char names[][50], int cnt) {
	char name[50];
	int res = 0;
	
	printf("Enter name of student: ");
	scanf("%[^\n]", name);
	strupr(name);
	
	for (int i = 0; i < cnt; i++) {
		if (stricmp(names[i], name) == 0) {
			printf("%d: %s\n", i + 1, names[i]);
			res++;
		}
	}
	
	if (res == 0) {
		printf("List empty\n");
	}
}

void removeStudent(char names[][50], int* cnt) {
	char name[50];
	int res = 0;
	
	listAscending(names, *cnt);
	
	printf("Enter name of student: ");
	scanf("%[^\n]", name);
	strupr(name);
	
	for (int i = 0; i <= *cnt; i++) {
		if (stricmp(names[i], name) == 0) {
			for (int j = i; j < *cnt - 1; j++) {
				strcpy(names[j], names[j + 1]);
			}
			res++;
			(*cnt)--;
		}
	}
	
	if (res == 0) {
		printf("Remove fail\n");
	}
}

void addStudent(char names[][50], int* cnt) {
	char name[50];
	char a[20][50];
	char tmp[100] = "\0";
	int n = 0;
	
	printf("Enter name of student: ");
	scanf("%[^\n]", name);
	strupr(name);
	
	char* token = strtok(name, " ");
	while (token != NULL) {
		strcpy(a[n++], token);
		token = strtok(NULL, " ");
	}
	
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			strcat(tmp, a[i]);
		}
		else {
			strcat(strcat(tmp, " "), a[i]);
		}
	}
	
	strcpy(names[*cnt], tmp);
	(*cnt)++;
}

void handleMenu(int op) {
	char names[100][50];
		
	switch (op) {
		case 1:
			addStudent(names, &cnt);
			printf("\nPress any key to continue . . .\n");
			getchar();
			getchar();
			break;
			
		case 2:
			if (cnt == 0) {
				printf("List empty\n");
			}
			else {
				removeStudent(names, &cnt);
			}
			printf("\nPress any key to continue . . .\n");
			getchar();
			getchar();
			break;
		
		case 3:
			searchStudent(names, cnt);
			printf("\nPress any key to continue . . .\n");
			getchar();
			getchar();
			break;
			
		case 4:
			if (cnt == 0) {
				printf("List empty\n");
			}
			else {
				listAscending(names, cnt);
			}
			printf("\nPress any key to continue . . .\n");
			getchar();
			break;
	}
}

void isMenu(int* op) {
	do {
		printf("1 - Add a student\n");
		printf("2 - Remove a student\n");
		printf("3 - Search a student\n");
		printf("4 - Print the list in ascending order\n");
		printf("5 - Quit\n");
		printf("Your choice: ");
		check = scanf("%d%c", op, &character);
		fflush(stdin);
	} while (check != 2 || character != '\n' || *op > 5 || *op < 1);
}
