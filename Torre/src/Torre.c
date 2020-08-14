/*
 ============================================================================
 Name        : Torre.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void hanoi(int disco, char orig, char dest, char aux) {

	if (disco == 1)
		printf("Move disco %d de %c para %c\n", disco, orig, dest);
	else {
		hanoi(disco - 1, orig, aux, dest);
		printf("Move disco %d de %c para %c\n", disco, orig, dest);
		hanoi(disco - 1, aux, dest, orig);
	}

}

int main(void) {

	setbuf(stdout, NULL);
	printf("** Torre de Hanoi **\n");
	int n;
	char sair;

	do {

		do {
			printf("\nDigite o numero de discos: ");
			fflush(stdin);
			scanf("%d", &n);
			if (n > 10)
				printf("\nLimite de discos excedido!(10)\n");
		} while (n > 10);

		printf("\n");

		hanoi(n, 'A', 'B', 'C');

		printf("\nNumero de movimentos otimos: %.0f\n\n", pow(2, n) - 1);

		printf("Deseja sair? (s/n): ");
		fflush(stdin);
		scanf("%c", &sair);

	} while (sair == 'n');

	printf("\nVoce saiu do programa.");

	return 0;
}
