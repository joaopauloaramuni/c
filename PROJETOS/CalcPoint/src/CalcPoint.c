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

void mult(float *ptr, float *ptr2, float *z)
{
	*z=(*ptr * *ptr2);
}

void sub(float *ptr, float *ptr2, float *z)
{
	*z=(*ptr - *ptr2);
}

void adi(float *ptr,float *ptr2, float *z)
{
	*z=(*ptr + *ptr2);
}

void divi(float *ptr, float *ptr2, float *z)
{
	*z=(*ptr / *ptr2);
}

int main() {

	setbuf(stdout,NULL);
	float x,y,z;

	printf("Calculadora\n\n");

	printf("Digite x: ");
	fflush(stdin);
	scanf("%f",&x);

	printf("Digite y: ");
	fflush(stdin);
	scanf("%f",&y);

	printf("\n");

	mult(&x,&y,&z);
	printf("Multiplicacao: %.2f\n",z);
	sub(&x,&y,&z);
	printf("Subtracao: %.2f\n",z);
	adi(&x,&y,&z);
	printf("Adicao: %.2f\n",z);
	divi(&x,&y,&z);
	printf("Divisao: %.2f\n",z);

	return 0;
}
