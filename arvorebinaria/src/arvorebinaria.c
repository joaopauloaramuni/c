#include "arvore.h"

int main(void) {
	TArv *t;

	t=arv_criavazia();

	/*t=arv_cria('h',
			arv_cria('f',
					arv_cria('c', arv_criavazia(), arv_criavazia()),
					arv_cria('g', arv_criavazia(), arv_criavazia())),
			arv_cria('p',
					arv_cria('k', arv_criavazia(), arv_criavazia()),
					arv_cria('s', arv_criavazia(),arv_criavazia()))
	);*/

	t = inserir(t,'h');
	t = inserir(t,'p');
	t = inserir(t,'f');
	t = inserir(t,'g');
	t = inserir(t,'k');
	t = inserir(t,'c');
	t = inserir(t,'s');

	//printf("%c\n", t->dir->esq->dado);

	imprime(t);

	printf("\nvazia --> %d\n", arv_vazia(t));

	return EXIT_SUCCESS;
}

