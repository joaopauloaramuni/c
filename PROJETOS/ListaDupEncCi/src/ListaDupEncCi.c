/*
 ============================================================================
 Name        : Lista.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista TLista;

struct lista {
	char dado;
	TLista *prox;
	TLista *ant;
};

TLista* inicializa(void){
	return NULL;
}

TLista* insere(char letra, TLista *lista) {
	TLista *aux;
	aux = (TLista*) malloc(sizeof(TLista));
	aux->dado = letra;

	if (!lista){
		aux->prox = aux;
		aux->ant = aux;
	} else {
		TLista* cont = lista->prox;
		TLista* cont2 = lista->ant;

		do {
			cont = cont->prox;
			cont2 = cont2->ant;
		} while (cont->dado != lista->prox->dado);

		aux->prox = cont;
		aux->ant = cont2;

		lista->prox = aux;
		lista->ant = aux;
	}
	return aux;
}

void imprimir(TLista *lista, TLista *cont) {
	do {
		printf("%c", cont->dado);
		cont = cont->prox;
	} while (cont != lista);

}

void imprime(TLista *lista) {
	while(lista){
		printf("\n%c", lista->dado);
		lista = lista->prox;
	}
}

TLista* busca(TLista *lista, char letra, TLista *aux){
	if ((lista->dado == letra) || (lista->prox == aux)){
		return lista;
	} else {
		return busca(lista->prox, letra, aux);
	}
}

TLista* removedado(TLista *lista, char letra){
	TLista *aux = lista->prox, *del;

	if (lista->prox == lista){
		free(lista);
		return inicializa();
	} else {
		do {
			//printf("\n---\n %c - %c \n---\n", aux->prox->dado, letra);
			if (aux->prox->dado == letra){
				del = aux->prox;
				aux->prox = aux->prox->prox;
				free(del);
			}
			aux = aux->prox;
		} while (aux->dado != lista->prox->dado);
	}
	return aux;
}

int main(void) {
	TLista *lista;
	setbuf(stdout, NULL);

	lista = inicializa();
	lista = insere('F', lista);
	lista = insere('U', lista);
	lista = insere('M', lista);
	lista = insere('E', lista);
	lista = insere('C', lista);

	//printf("%c", lista->prox->dado);

	imprimir(lista->prox, lista);

	imprime(lista);

	if(busca(lista, 'F', lista)->dado == 'F'){
		printf("\n\nLetra Encontrada - %c", busca(lista, 'F', lista)->dado);
	} else {
		printf("\n\nLetra Não Encontrada");
	}

	printf("\n\n---- Remove Dado ----");

	/*lista = removedado(lista, 'F');
	if (lista){
		printf("\nDado removido com sucesso!\n");
		imprimir(lista, lista);
	} else {
		printf("\nLista Vazia");
	}*/

	return 0;
}
