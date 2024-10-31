/*
 ============================================================================
 Name        : for.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	setbuf(stdout,NULL);
	int cont;
	for(cont=1;cont<=5;cont++)
		printf("Numero:%d\n ",cont);
	return 0;
}
