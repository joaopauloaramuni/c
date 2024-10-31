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

int StrLen(char *orig)
{
	int cont = 0;
	while(*orig++)cont++;
	return cont;
}

int main()
{

	setbuf(stdout, NULL);
	char ch[20];
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(ch);
	printf("A palavra %s tem %d caracteres.",ch,StrLen(ch));
	return 0;
}
