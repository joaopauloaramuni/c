#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam = 0;

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

struct cliente {
	char nome[60];
	char tel[20];
	TEnd end;
};

TCli *cli1;

void dinamica() {

	char no[20];
	printf("Digite o nome: ");
	fflush(stdin);
	gets(no);
	strcpy(cli1->nome, no);

	char tele[20];
	printf("Digite o telefone: ");
	fflush(stdin);
	gets(tele);
	strcpy(cli1->tel, tele);

	char ende[20];
	printf("Digite a rua: ");
	fflush(stdin);
	gets(ende);
	strcpy(cli1->end.rua, ende);

	printf("%s\n", cli1->nome);
	printf("%s\n", cli1->tel);
	printf("%s\n", cli1->end.rua);

}

char sair() {

	char resp;

	printf("Deseja outro cadastro? s ou n ");
	fflush(stdin);
	scanf("%c", &resp);

	printf("\n");

	return (resp);
}

int main(void) {
	setbuf(stdout, NULL);
	printf("** Cadastro **\n");

	printf("Digite o tamanho: ");
	scanf("%d", &tam);
	cli1 = (TCli*) malloc(tam * sizeof(TCli));

	do {

		dinamica();

	} while (sair() == 's');

	printf("\n");
	printf("Voce saiu do programa.");

	return EXIT_SUCCESS;
}
