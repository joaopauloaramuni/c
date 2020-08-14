/*
 ============================================================================
 Name        : Calculadora.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
/*Calcula o quadrado de x*/
void square (float x)
{
	printf("O quadrado e %.0f\n",(x*x));
	printf("A subtracao e %.0f\n",(x-x));
	printf("A soma e %.0f\n",(x+x));
	printf("A divisao e %.0f\n",(x/x));
}
int main ()
{
	setbuf(stdout,NULL);
	float num;
	printf("Entre com um numero: ");
	fflush(stdin);
	scanf("%f",&num);
	printf("\n\n");
	square(num);
	return 0;
}
