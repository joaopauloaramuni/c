/*
 ============================================================================
 Name        : Ponteiros.c
 Author      : Jo�o Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	int y = 35;
	int *ptr;

	ptr = &y; //Ptr � uma vari�vel que n�o guarda dados, apenas endere�os.

	printf("Dado guardado em y %d\n",y);
	printf("Endere�o de y na RAM %p\n",&y);
	printf("Dado guardado em ptr %p\n",ptr);
	printf("Dado guardado em y atraves ptr %d\n",*ptr);


	return 0;
}
