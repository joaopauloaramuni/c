/*
 ============================================================================
 Name        : MENU.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	setbuf(stdout,NULL);
	int i,op;
	char str[100];
	op=1;
	printf("MENU DE OPCOES\n\n");
	printf("Digite 1 para NUMERO DE LETRAS.\n");
	printf("Digite 2 para PALAVRA AO CONTRARIO.\n");
	printf("Digite 3 para OPCOES ANTERIORES.\n");
	printf("Digite 4 para SAIR.\n\n");
	while(op==1 || op==2 || op==3){
	do{
	printf("Opcao: ");
	fflush(stdin);
	scanf("%d",&op);
	if(op!=1 && op!=2 && op!=3 && op!=4){
		printf("\n");
		printf("Opcao incorreta, por favor digite uma das opcoes acima.\n\n");}
	}
	while(op!=1 && op!=2 && op!=3 && op!=4);


	if(op==1){
		printf("\n");
		printf("NUMERO DE LETRAS\n\n");
		printf("Digite a palavra: ");
		fflush(stdin);
		gets(str);

		for (i=0;str[i];i++){
		}
		printf("\n");
		printf("A palavra %s tem %d letras.\n\n",str,i);
	}

	else if(op==2){

		printf("\n");
		printf("PALAVRA AO CONTRARIO\n\n");
		printf("Digite a palavra: ");
		fflush(stdin);
		gets(str);

		for (i=0;str[i];i++){
		}
		i=i-1;
		printf("\n");
		printf("A palavra ao contrario é: ");
		while(i>=0){
		printf("%c",str[i]);
		i=i-1;
		}
		printf("\n\n");
	}
	else if(op==3){
		printf("\n");
		printf("OPCOES ANTERIORES\n\n");
		printf("Digite uma palavra: ");
		fflush(stdin);
		gets(str);

		for (i=0;str[i];i++){
		}
		printf("\n");
		printf("A palavra %s tem %d letras.\n\n",str,i);
		i=i-1;
		printf("A palavra ao contrario é: ");
		while(i>=0){
		printf("%c",str[i]);
		i=i-1;
		}
		printf("\n\n");
	}
	else{
		printf("\n");
		printf("SAIR\n\n");
		printf("Voce saiu do programa.");}

	}

	return 0;
}
