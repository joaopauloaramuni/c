#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore TArv;

struct arvore{
	char dado;
	TArv* esq;
	TArv* dir;
};

TArv* arv_criavazia(){
	return NULL;
}
int arv_vazia(TArv *arv){
	return !arv;
}
TArv* arv_cria(char ch, TArv *esq, TArv *dir){
	TArv *aux;

	aux = (TArv*)malloc(sizeof(TArv));
	aux->dado = ch;
	aux->esq = esq;
	aux->dir = dir;

	return aux;

}
void imprime(TArv* arv){
	if(!arv_vazia(arv)){
		printf("(%c",arv->dado);
		imprime(arv->esq);
		imprime(arv->dir);
		printf(")");
	}

}
TArv* inserir(TArv* raiz, char ch) {
	if (!raiz) {
		raiz = arv_cria(ch,arv_criavazia(),arv_criavazia());
	} else {
		if (ch < raiz->dado)
			raiz->esq = inserir(raiz->esq,ch);
		else
			raiz->dir = inserir(raiz->dir,ch);
	}
	return raiz;
}

#endif /* ARVORE_H_ */
