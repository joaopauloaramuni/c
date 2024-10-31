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
void Mult (float x,float y)
{
	printf("O quadrado de %.0f por %.0f é %.0f\n",x,y,(x*y));
}
void Div (float x, float y)
{
	printf("A divisao de %.0f por %.0f é %.0f\n",x,y,(x/y));
}
void Soma (float x, float y)
{
	printf("A soma de %.0f e %.0f por %.0f\n",x,y,(x+y));
}
void Sub (float x,float y)
{
	printf("A subtracao de %.0f por %.0f é %.0f\n",x,y,(x-y));
}
int main ()
{
	setbuf(stdout,NULL);
	float num1,num2;

	printf("Entre com X ");
	fflush(stdin);
	scanf("%f",&num1);

	printf("Entre com Y ");
	fflush(stdin);
	scanf("%f",&num2);

	printf("\n");

	Mult(num1,num2);
	Div(num1,num2);
	Soma(num1,num2);
	Sub(num1,num2);

	return 0;
}
