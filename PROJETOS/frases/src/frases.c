/*
 ============================================================================
 Name        : frases.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	setbuf(stdout,NULL);
	char string[100]; /*String ate 99 caracteres*/
	int i, cont;
	printf("\n\nDigite uma frase: ");
	fflush(stdin);
	gets(string); /*Le a string*/
	printf("\n\nFrase digitida:\n%s",string);
	cont = 0;
	for (i=0;string[i]!='\0';i++)/*poderia ser tambem apenas string[i];
								   pois !='\0' é verdadeiro e string[i]
								   tambem é verdadeiro*/
	{
		if (string[i]=='c')/*Se for a letra 'c'*/
			cont = cont +1; /*Incremeta o contador de caracteres*/
	}
	printf("\nNumero de caracteres c = %d",cont);
	return 0;
}
