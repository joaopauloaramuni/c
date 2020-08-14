#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam=0;

struct endereco {
	char rua[30];
	int numero;
	char complem[30];
	long int cep;
	char bairro[15];
	char cidade[15];
	char estado[3];
};
typedef struct endereco TEnd;
typedef struct cliente TCli;

struct cliente{
	char nome[60];
	long int tel;
	TEnd end;
	TCli *prox;
};

void imprimeCli(TCli *ptr){
	int i;

	for(i=0; i < tam ; i++){
		printf("%d --> %s\n",i, ptr[i].nome);
		printf("%d --> %ld\n",i, ptr[i].tel);
		printf("%d --> %s\n",i, ptr[i].end.rua);
		printf("%d --> %d\n",i, ptr[i].end.numero);
	}
}

void cadastroCli(TCli *ptr){

/*	strcpy(ptr[tam].nome, "Rafael Nunes2");
	ptr[tam].tel = 91233242;
	strcpy(ptr[tam].end.rua, "Rua Cobre2");
	ptr[tam].end.numero = 202;
	tam++;*/
	printf("Digite nome: ");
	fflush(stdin);
	gets(ptr[tam].nome);

	printf("Digite tel: ");
	fflush(stdin);
	scanf("%ld", &ptr[tam].tel);

	printf("Digite nome da rua: ");
	fflush(stdin);
	gets(ptr[tam].end.rua);

	printf("Digite numero da rua: ");
	fflush(stdin);
	scanf("%d", &ptr[tam].end.numero);

	tam++;
}


int main(void) {
	setbuf(stdout, NULL);

	//TCli cliente[3];

	//void* malloc(size_t);

	// Estático PONTO .
	//Dinâmico SETA ->

	TCli *cli1;
	TCli *cli2;

	cli1 = (TCli*)malloc(50*sizeof(TCli));

	strcpy(cli1->nome,"JP");
	cli1->tel = 97979797;
	strcpy(cli1->end.rua,"Rua Cobre");

	//printf("%s\n",cli1->nome);
	//printf("%ld\n",cli1->tel);
	//printf("%s\n",cli1->end.rua);

	cli2 = (TCli*)malloc(50*sizeof(TCli));

	strcpy(cli2->nome,"JP");
	cli2->tel = 97979797;
	strcpy(cli2->end.rua,"Rua Cobre");

	//Ligar os dois Clientes
	cli1->prox = cli2;
	cli2->prox = NULL;

	TCli *aux;
	for(aux = cli1;aux != NULL ; aux=aux->prox){
	printf("%s\n",aux->nome);
	printf("%ld\n",aux->tel);
	printf("%s\n",aux->end.rua);
	}

	/*cadastroCli(cliente);
	cadastroCli(cliente);
	cadastroCli(cliente);

	imprimeCli(cliente);*/


	return EXIT_SUCCESS;
}
