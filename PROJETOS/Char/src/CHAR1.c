/*
 ============================================================================
 Name        : CHAR.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int xulambs(char letra) //Recebe char devolve int
{
return letra;
}

int main()
{
	setbuf(stdout,NULL);
	char le1;

	printf("Entre com o caracter: ");
    fflush(stdin);
	scanf("%c",&le1);
	printf("\n");
	printf("O carater digitado: %c na tabela ASCII é %d",le1,xulambs(le1));
	return 0;
}
