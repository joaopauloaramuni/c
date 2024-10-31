/*
 ============================================================================
 Name        : ListaCi.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct lista {
	char dado;
	struct lista *prox;
};
typedef struct lista TLista;

TLista* inicializa() {
	return NULL;
}

void imprime(TLista *lista, TLista *aux) {

	/*do {
		printf("%c", aux->dado);
		aux = aux->prox;
	} while (aux != lista);
	//imprime CEMUF
	*/
	/*if (aux->prox == lista) {
		printf("%c", aux->dado);
	} else {
		imprime(lista, aux->prox);
		printf("%c", aux->dado);
	//imprime FUMEC
	}*/

	(aux->prox == lista) ? : imprime(lista, aux->prox),printf("%c", aux->dado);
}

int verifica(TLista *lista) {
	return lista == NULL;
}

TLista* insere(char letra, TLista *lista) {

	TLista *aux;
	aux = (TLista*) malloc(sizeof(TLista));
	aux->dado = letra;

	if (lista) {
		TLista *aux2 = lista;
		aux->prox = lista;
		do {
			aux2 = aux2->prox;
		} while (aux2->prox != lista);
		aux2->prox = aux;
	} else
		aux->prox = aux;

	return aux;
}

TLista* busca(TLista *lista, char letra, TLista *aux) {
	/*if ((lista->dado == letra) || (lista->prox == aux)) {
	 return lista;
	 } else {
	 return busca(lista->prox, letra, aux);
	 }*/

	return (lista->dado == letra) || (lista->prox == aux) ? lista : busca(lista->prox, letra, aux);
}
TLista* remover(TLista *lista, char letra) {

	TLista * aux = lista->prox, *aux2;

	if (lista->prox == lista) {
		free(lista);
		return inicializa();
	} else {
		do {
			if (aux->prox->dado == letra) {
				aux2 = aux->prox;
				free(aux2);
				aux->prox = aux->prox->prox;
			}
			aux = aux->prox;
		} while (aux->dado != lista->prox->dado);
	}
	return aux;
}

int main(void) {

	setbuf(stdout, NULL);
	TLista *lista;

	lista = insere('F', inicializa());
	lista = insere('U', lista);
	lista = insere('M', lista);
	lista = insere('E', lista);
	lista = insere('C', lista);

	if (busca(lista, 'X', lista)->dado == 'X') {
		printf("Achou!\n");
		lista = remover(lista, 'X');
	} else
		printf("Não Achou!\n");

	if (verifica(lista)) {
		printf("A lista está vazia\n");
	} else
		printf("A lista não está vazia\n");

	imprime(lista, lista);

	return 0;
}
