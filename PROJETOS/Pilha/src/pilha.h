/*
 * pilha.h
 *
 *  Created on: 25/05/2011
 *      Author: 1A213731363
 */

#ifndef PILHA_H_
#define PILHA_H_

#include <stdio.h>
#include <stdlib.h>

struct lista {
	char dado;
	struct lista *prox;
};
typedef struct lista TLista;


struct pilha{
	TLista *topo;
};
typedef struct pilha TPilha;

TPilha* inicializa(){
	TPilha* pilha;
	pilha = (TPilha*)malloc(sizeof(TPilha));
	pilha->topo = NULL;
	return pilha;
}

TLista* insere(char letra, TLista *lista) {

	TLista *aux;

	aux = (TLista*) malloc(sizeof(TLista));
	aux -> dado = letra;
	aux -> prox = lista;

	return aux;
}

void imprimerec(TLista *lista){

	/*
	Imprime Recursivo

	if(lista){
	imprimerec(lista->prox);
	printf("%c", lista->dado);
	}

	*/

	//Imprime Recursivo com Ternário
	lista ? imprimerec(lista->prox),printf("%c", lista->dado) : 0;

}
void push(TPilha *pilha,char ch){
	pilha->topo = insere(ch,pilha->topo);
}

TLista* removeinicio(TLista *lista) {

	free(lista);
	return lista = lista->prox;

}

void pop(TPilha* pilha){
	pilha->topo = removeinicio(pilha->topo);

}
#endif /* PILHA_H_ */
