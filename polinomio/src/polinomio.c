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
	int coef;
	int expo;
	struct lista *prox;
};

typedef struct lista TLista;

TLista* insere(int coef, int expo, TLista *lista) {

	TLista *aux;
	aux = (TLista*) malloc(sizeof(TLista));
	aux->coef = coef;
	aux->expo = expo;

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

int verifica(TLista *lista) {
	return lista == NULL;
}
void imprime(TLista *lista, TLista *aux) {
	char ch = '+';
	if (aux->coef < 0) {
		ch = ' ';
	}
	if (aux->prox == lista) {
		if (aux->expo != 0)
			printf("%c%dx^%d ", ch, aux->coef, aux->expo);
		else
			printf("%c%d", ch, aux->coef);
	} else {
		imprime(lista, aux->prox);
		if (aux->expo != 0)
			printf("%c%dx^%d ", ch, aux->coef, aux->expo);
		else
			printf("%c%d", ch, aux->coef);
	}

}

TLista* inicializa(void) {

	return NULL;
}

TLista* ordena(TLista* lista) {
	TLista* aux;
	aux = lista;
	do {

		if (lista->expo < lista->prox->expo) {
			aux->coef = lista->prox->coef;
			aux->expo = lista->prox->expo;
			aux->prox->coef = lista->coef;
			aux->prox->expo = lista->expo;

		}
		lista = lista->prox;
		aux = aux->prox;

	} while (aux != lista);

	return aux;
}
int main(void) {

	setbuf(stdout, NULL);
	int opcao = 0, expo = 0, coef = 0;
	TLista *lista;
	lista = inicializa();

	printf("Polinômio\n");
	do {
		printf("\nMenu\n");
		printf("1-Inserir Dado\n");
		printf("2-Imprimir Polinômio\n");
		printf("3-Imprimir Polinômio Ordenado\n");
		printf("0-Sair\n");
		printf("\nOpção: ");
		fflush(stdin);
		scanf("%d", &opcao);

		switch (opcao) {
		case 1:
			printf("\nDigite o coeficiente: ");
			fflush(stdin);
			scanf("%d", &coef);
			printf("Digite o expoente: ");
			fflush(stdin);
			scanf("%d", &expo);
			lista = insere(coef, expo, lista);
			printf("\nDado inserido com sucesso.\n");
			break;
		case 2:
			if (!verifica(lista)) {
				printf("\nPolinômio: ");
				imprime(lista, lista);
				printf("\n");
			} else
				printf("Não existe expressão.\n");
			break;
		case 3:
			if (!verifica(lista)) {
				printf("\nPolinômio: ");
				imprime(ordena(lista), ordena(lista));
				printf("\n");
			} else
				printf("Não existe expressão.\n");
			break;
		case 0:
			//Sair
			break;
		default:
			printf("Opção inválida.");
			break;
		}
	} while (opcao != 0);
	//Fim da Aplicação
	return 0;
}
