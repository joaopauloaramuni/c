/*
 ============================================================================
 Name        : strcpy.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/
#include "lista.h"

int main(void) {

	TFila *filax;

	filax = inicializa();

	insere(filax,'F');
	insere(filax,'U');
	insere(filax,'M');
	insere(filax,'E');
	insere(filax,'C');

	imprimerec(filax->ini);

	return 0;
}
