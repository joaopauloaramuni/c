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
float Mult (float x,float y)
{
	return (x*y);
}
float Div (float x, float y)
{
	return (x/y);
}
float Soma (float x, float y)
{
	return (x+y);
}
float Sub (float x,float y)
{
	return (x-y);
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

/*	A=Mult(num1,num2);
	D=Div(num1,num2);
	S1=Soma(num1,num2);
	S2=Sub(num1,num2);
	Pode-se guardar o resultado
	do processamento das funções
	dentro de variáveis*/

	printf("A multiplicação de X = %.0f por Y = %.0f e %.0f\n",num1,num2,Mult(num1,num2));
	printf("A divisão de X = %.0f por Y = %.0f e %.0f\n",num1,num2,Div(num1,num2));
	printf("A soma de X = %.0f por Y = %.0f e %.0f\n",num1,num2,Soma(num1,num2));
	printf("A subtração de X = %.0f por Y = %.0f e %.0f\n",num1,num2,Sub(num1,num2));

	return 0;
}
