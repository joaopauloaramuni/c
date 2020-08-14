/*
 ============================================================================
 Name        : exerciciocharint.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	char str[100]="teste";
	int i,vet[100]={10,15,30,45};
	i=0;
	while(vet[i]){
		printf("A posicao do numero %d tem o conteudo %d\n",i,vet[i]);
		i++;

	}
	printf("\n");

	for (i=0;str[i];i++) {
		printf("A posicao da palavra %d tem conteudo %c\n",i,str[i]);
	}

	return 0;
}
