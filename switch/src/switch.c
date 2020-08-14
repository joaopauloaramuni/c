/*
 ============================================================================
 Name        : switch.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	int dia;
	setbuf(stdout,NULL);
	printf("Switch\n");
	printf("\nDigite o dia ");
	fflush(stdin);
	scanf("%d",&dia);

	switch(dia){
	case 0: printf("Domingo\n");
	break;
	case 1: printf("Segunda\n");
	break;
	case 2: printf("Terça\n");
	break;
	case 3: printf("Quarta\n");
	break;
	case 4: printf("Quinta\n");
	break;
	case 5: printf("Sexta\n");
	break;
	case 6: printf("Sabado\n");
	break;
	default:printf("Opção inválida\n");
	break;
	}

	return 0;
}
