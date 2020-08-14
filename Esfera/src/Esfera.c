/*
 ============================================================================
 Name        : Esfera.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14

void area(float *r, float *A) {

	*A = (4 * pi) * (pow(*r, 2));
}

void volume(float *r, float *B) {

	*B = ((4 * pi) * pow(*r, 3)) / 3;
}

int main(void) {

	setbuf(stdout, NULL);
	float raio, a, b;
	printf("** ESFERA **\n\n");
	printf("Digite o valor do raio da circunferencia: ");
	fflush(stdin);
	scanf("%f", &raio);

	printf("\n");

	area(&raio, &a);
	volume(&raio, &b);

	printf("Area: %f\n", a);
	printf("Volume: %f", b);

	return 0;
}
