/*
 ============================================================================
 Name        : hanoi.c
 Author      : Joao Paulo Aramuni
 Version     : hanoi 2.0
 Copyright   : Your copyright notice
 Description : hanoi in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A hanoi(disc - 1, orig, aux, dest)
#define B hanoi(disc - 1, aux, dest, orig)
#define C printf("Move disco %d de %c para %c\n", disc, orig, dest)

void hanoi(int disc, char orig, char dest, char aux) {
	(disc != 1) ? A, C, B : C;
}

int main(void) {

	setbuf(stdout, NULL);
	int num;
	printf("** Torres de Hanoi **\n");
	printf("\nDigite o número de discos: ");
	fflush(stdin);
	scanf("%d", &num);
	printf("\n");
	hanoi(num, 'A', 'B', 'C');
	float num2 = num;
	printf("\nNúmero de movimentos ótimos: %.0f\n", pow(2, num2) - 1);
	return 0;
}
