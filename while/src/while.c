/*
 ============================================================================
 Name        : while.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int cont;
	cont=0;
	while(cont<5){
		printf("Numero:%d\n ",cont+1);
		cont=cont+1; //Pode ser tambem neste caso, cont++
	}

	return 0;
}
