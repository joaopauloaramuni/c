#include <stdio.h>
#include <stdlib.h>

typedef struct lista TLista2;

struct lista{
	char dado;
	TLista2 *prox;
	TLista2 *ant;
};

TLista2* inicializa(void){
	return NULL;
}

int verifica(TLista2 *lista){
	return (lista == NULL);
}

TLista2* insere(TLista2 *lista, char ch){
	TLista2 *aux;
	aux = (TLista2*) malloc(sizeof(TLista2));
	aux->dado = ch;
	aux->prox = lista;
	aux->ant = inicializa();

	if(lista)
		lista->ant = aux;

	return aux;
}
void imprime(TLista2 *lista){
	TLista2 *aux;

	aux = lista;

	while(aux){
		printf("%c\n", aux->dado);
		aux = aux->prox;
	}
}
void imprimerec(TLista2 *lista){

	if(!verifica(lista)){
		imprimerec(lista->prox);
		printf("%c\n", lista->dado);
	}
}

int busca(TLista2 *lista, char letra) {

	//ITERATIVO
	 /*do{
		if(lista->dado == letra)
		return lista;
		lista = lista->prox;
	}while(lista);

	return lista;*/

	//RECURSIVO
	/*
	if(!lista || lista->dado == letra){
		return lista;
	}else
		return busca(lista->prox,letra);
	*/

	//RECURSIVO TERNÁRIO
	//return (!lista || lista->dado == letra) ? lista : busca(lista->prox,letra);

	//RECURSIVO LÓGICO
	return (lista) && ((lista->dado == letra) || (busca(lista->prox,letra)));
}
TLista2* removeinicio(TLista2 *lista) {

	free(lista);
	return lista = lista->prox;

}
TLista2* removequalquer(TLista2 *lista, char letra) {
	TLista2* aux;
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
int main(void) {

	setbuf(stdout, NULL);

	TLista2 *lista2x;

	lista2x = inicializa();
	lista2x = insere(lista2x, 'F');
	lista2x = insere(lista2x, 'U');
	lista2x = insere(lista2x, 'M');
	lista2x = insere(lista2x, 'E');
	lista2x = insere(lista2x, 'C');

	/*if (busca(lista2x,'F')) {
		printf("Achou!\n\n");
	} else
		printf("Não Achou!\n\n");
	 */
	busca(lista2x,'X') ? printf("Achou!\n\n") : printf("Não Achou!\n\n");

	printf("%c\n", lista2x->prox->prox->prox->ant->ant->dado);
	printf("---------------------------\n");
	imprime(lista2x);
	printf("---------------------------\n");
	imprimerec(lista2x);

	printf("\n---------------------------\n");
	imprimerec(removequalquer(lista2x, 'C'));

	return 0;
}
