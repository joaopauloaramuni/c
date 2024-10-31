/*
 * lista.h
 *
 *  Created on: 23/05/2011
 *      Author: rafael
 */


#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_H_
#define LISTA_H_


struct lista {
	char dado;
	struct lista *prox;
};
typedef struct lista TLista;


struct fila{
	TLista *ini;
	TLista *fim;
};
typedef struct fila TFila;

TFila* inicializa(){
	TFila* fila;
	fila = (TFila*) malloc(sizeof(TFila));
	fila->ini = fila->fim = NULL;
	return fila;
}

void insere(TFila* fila, char ch){
	TLista* aux;
	aux = (TLista*)malloc(sizeof(TLista));
	aux->dado = ch;

	//inverte o sentido do prox
	aux->prox = NULL;

	if(fila->fim != NULL)
		fila->fim->prox = aux;
	else
		fila->ini = aux;

	fila->fim = aux;

}

void imprimerec(TLista *lista){

	/*

	Imprime Iterativo

	TLista *aux;

	aux = fila->ini;

	while(aux != NULL){
		printf("fila --> %c\n", aux->dado);
		aux = aux->prox;
	}

	Imprime Recursivo

	if(lista){
	printf("%c", lista->dado);
	imprimerec(lista->prox);
	}

	*/

	//Imprime Recursivo com Ternário
	lista ? printf("%c", lista->dado),imprimerec(lista->prox) : 0;

}


#endif /* LISTA_H_ */








