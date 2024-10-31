/*
 ============================================================================
 Name        : Pilha.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "pilha.h"

int main(void) {
	TPilha *pilha;

	pilha = inicializa();

	push(pilha,'F');
	push(pilha,'U');
	push(pilha,'M');
	push(pilha,'E');
	push(pilha,'C');

	imprimerec(pilha->topo);

	pop(pilha);
	pop(pilha);
	pop(pilha);

	printf("\n");
	imprimerec(pilha->topo);

	return 0;
}
