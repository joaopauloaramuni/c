/*
 ============================================================================
 Name        : lenght.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int StrLen(char *orig, int cont) {

	return (*orig++) ? cont++, StrLen(orig, cont) : cont;
}

int main() {
	setbuf(stdout, NULL);
	char ch[20];
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(ch);

	printf("Tamanho: %d", StrLen(ch, 0));

	return 0;
}
