/*
 ============================================================================
 Name        : strcpy.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

//Memória RAM - Static, Stack, Heap

#include <stdio.h>
#include <stdlib.h>

void StrCpy(char *dest, char *orig) {

	while (*orig) {
		*dest = *orig;
		dest++;
		orig++;
	}
	*dest = '\0';

}

void StrCat(char *str1, char *str2) {
	while (*str1)str1++;
	StrCpy(str1, str2);
}

int StrLen(char *orig) {
	int cont = 0;
	while (*orig++)cont++;
	return cont;
}

int main() {
	setbuf(stdout, NULL);
	char ch[20] = "face", ch2[20];
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(ch2);
	StrCpy(ch, ch2);
	printf("%s\n", ch);
	StrCat(ch, ch2);
	printf("%s\n", ch);
	printf("%d", StrLen(ch));
	return 0;
}
