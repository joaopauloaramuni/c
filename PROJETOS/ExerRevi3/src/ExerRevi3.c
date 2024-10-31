/*
 ============================================================================
 Name        : ExerRevi3.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int gerahash(int arg1, int arg2){
	int chave;
	chave = arg1 % arg2;
	return (chave);

}
int main() {
	setbuf(stdout,NULL);
	int y;
	int x;
	printf("Entre com o valor inteiro: ");
	fflush(stdin);
	scanf("%d",&y);
	x=13;
	printf("Nao importa o valor que vc digitar, o resultado sera sempre um valor entre 0 e 12, veja: %d",gerahash(y,x));
	return 0;
}
