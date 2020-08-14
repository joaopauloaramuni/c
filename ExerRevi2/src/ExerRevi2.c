/*
 ============================================================================
 Name        : ExerRevi2.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
void imprime5x(int x)
{
	printf("Este é o seu valor: %d\n",x);
	printf("Este é o seu valor: %d\n",x);
	printf("Este é o seu valor: %d\n",x);
	printf("Este é o seu valor: %d\n",x);
	printf("Este é o seu valor: %d\n",x);
}
int main() {
	setbuf(stdout,NULL);
	int valor;
	printf("Entre com o valor inteiro: ");
	fflush(stdin);
	scanf("%d",&valor);
	imprime5x(valor);
	return 0;
}

