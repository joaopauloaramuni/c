/*
 ============================================================================
 Name        : strcpy.c
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

TLista* insere(char letra, TLista *lista) {

	TLista *aux;

	aux = (TLista*) malloc(sizeof(TLista));
	aux -> dado = letra;
	aux -> prox = lista;

	return aux;
}

/*void imprime(TLista *lista){
 TLista *aux;

 aux = lista;

 while(aux != NULL){
 printf("%c\n",aux->dado);
 aux = aux -> prox;
 }

 }*/

void imprimerec(TLista *lista) {

	if (lista) {
		//CEMUF printf("%c\n",lista->dado);
		imprimerec(lista->prox);
		printf("%c\n", lista->dado);

	}
}

TLista* inicializa(void) {

	return NULL;
}

int verifica(TLista *lista) {

	return lista == NULL;

}
/*
 int verifica2(TLista *lista) {

 if (lista == NULL) {
 return 1;
 } else
 return 0;
 }

 main:

 if (verifica2(lista)) {
 printf("\nA lista está vazia");
 } else
 printf("\nA lista não está vazia");
 */

TLista* procura(char letra, TLista *lista) {

	//Recursivo
	if ((lista == NULL) || (lista->dado == letra))
		return lista;
	else
		return procura(letra, lista->prox);

	/*
	 Iterativo
	 TLista *aux;
	 for (aux = lista; aux != NULL; aux = aux -> prox) {
	 if (aux->dado == letra) {
	 return aux;
	 }
	 }
	 return aux;
	 */
}
TLista* removeinicio(TLista *lista) {

	free(lista);
	return lista = lista->prox;

}
TLista* removequalquer(TLista *lista, char letra) {
	TLista* aux;
	if (lista) {
		if (lista->dado == letra) {
			return removeinicio(lista);
		} else if (lista->prox) {
			if (lista->prox->dado == letra) {
				aux = lista->prox;
				lista->prox = lista->prox->prox;
				free(aux);
			} else
				removequalquer(lista->prox, letra);
		}
	}
	return lista;
}
/*
 TLista* removequalquer(TLista *lista, char letra) {
 if (lista) {
 removequalquer(lista->prox, letra);
 if (lista->prox) {
 if (lista->prox->dado == letra) {
 free(removequalquer(lista->prox, letra));
 lista->prox = lista->prox->prox;
 }
 }
 }
 return lista;
 }
 */
TLista* liberarec(TLista* lista) {
	if (lista) {
		return liberarec(lista->prox);
		free(lista);
	}
	return lista;

}
/*TLista* libera(TLista* lista){

 while(lista){
 lista = lista->prox;
 free(lista);
 }
 return lista;
 }*/

int main(void) {
	setbuf(stdout, NULL);

	/* Tlista *no1;
	 Tlista *no2;
	 Tlista *no3;

	 no1 = (Tlista*) malloc(sizeof(Tlista));
	 no1 -> dado = 'F';
	 no1 -> prox = NULL;

	 no2 = (Tlista*) malloc(sizeof(Tlista));
	 no2 -> dado = 'U';
	 no2 -> prox = no1;

	 no3 = (Tlista*) malloc(sizeof(Tlista));
	 no3 -> dado = 'M';
	 no3 -> prox = no2;

	 printf("%c  -  %c  - %c\n", no3->dado, no3->prox->dado,no3->prox->prox->dado);

	 */

	TLista *lista;

	lista = insere('F', inicializa());
	lista = insere('U', lista);
	lista = insere('M', lista);
	lista = insere('E', lista);
	lista = insere('C', lista);

	imprimerec(lista);

	if (verifica(lista)) {
		printf("\nA lista está vazia");
	} else
		printf("\nA lista não está vazia");

	char letra;

	printf("\n\nDigite a letra a ser procurada: ");
	fflush(stdin);
	scanf("%c", &letra);

	if (procura(letra, lista)) {
		printf("Achou\n");
	} else
		printf("Não Achou\n");

	//imprimerec(removeinicio(letra, lista));
	printf("\n");

	imprimerec(removequalquer(lista, letra));

	if (verifica(liberarec(lista))) {
		printf("\nA lista está vazia");
	}

	return 0;
}
