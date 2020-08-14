/*
 ============================================================================
 Name        : Struct.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct endereco TEnd; //Apelido
typedef struct cliente TCli; //Apelido

struct endereco {

	char rua[30];
	int numero;
	char complem[30];
	long int cep;
	char bairro[15];
	char cidade[15];
	char estado[3];
};
struct cliente {

	char nome[30];
	long int tel;
	TEnd end;

};

int main() {

	setbuf(stdout,NULL);
	//tipo   variavel
	TClip total;

	strcpy(total.nome,"Joao");
	total.tel = 88888888;
	strcpy(total.end.rua,"Rua qualquer");
	total.end.numero = 100;

	printf("%s ",total.nome);
	printf("Tel: %ld\n",total.tel);
	printf("End: %s ",total.end.rua);
	printf("%d\n",total.end.numero);

	return 0;
}
