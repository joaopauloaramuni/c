/*
 ============================================================================
 Name        : Pow_Recursivo.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int powrec(int base, int expo) {
	if (expo == 0) {
		return 1;
	} else if (expo == 1) {
		return base;
	} else {
		return (base * powrec(base, expo - 1));
	}

}

int main(void) {

	setbuf(stdout, NULL);
	int x, y;

	printf("** Expoente Recursivo **\n\n");
	printf("Digite a base e o expoente: ");
	fflush(stdin);
	scanf("%d%d", &x, &y);

	printf("\nResultado da Exponencial: %d",powrec(x, y));

	return 0;
}
