/*
 ============================================================================
 Name        : parouimpar.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PAR 2
int parouimpar(int x){
		return x%PAR;
}

int main() {
	setbuf(stdout,NULL);
	int num;
	printf("** Par ou Impar? **\n");
	printf("\n");
	printf("Entre com um numero: ");
	fflush(stdin);
	scanf("%d",&num);
		if(parouimpar(num)==0){
			printf("%d é um numero par!",num);}
		else{
			printf("%d é um Numero impar!",num);}
	return 0;
}
