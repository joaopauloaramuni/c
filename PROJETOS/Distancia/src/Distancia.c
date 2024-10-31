/*
 ============================================================================
 Name        : Distancia.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void distancia(int *x0,int *y0,int *x1,int *y1, int *distan){

	*distan = sqrt(pow((*x1 - *x0), 2) + pow((*y1 - *y0), 2));

}
int main(void) {

	setbuf(stdout, NULL);

	int x0, y0, x1, y1, dist;

	printf("** DISTANCIA **\n\n");

	printf("Digite as coordenadas de um ponto (x0,y0) ");
	fflush(stdin);
	scanf("%d%d", &x0, &y0);

	printf("Digite as coordenadas de outro ponto (x1,y1) ");
	fflush(stdin);
	scanf("%d%d", &x1, &y1);

	distancia(&x0,&y0,&x1,&y1,&dist);

	printf("Distancia entre os pontos: %d", dist);

	return 0;
}
