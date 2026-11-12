/*
 ============================================================================
 Name        : testesPtrs.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void pointer(char *ptr, int *ptr2, char str[100], int x) {
	printf("%s - %d - %s - %d\n", ptr, *ptr2, str, x);
}
int main(void) {

	int x = 10, y = 20;
	int *ptr;
	ptr = &x;

	//endereco de x
	printf("Endereco de x %p\n", &x);

	//conteudo de ptr
	printf("Conteudo de ptr %p\n", ptr);

	//conteudo de x
	printf("Conteudo de x %d\n", x);

	//conteudo do end armazenado por ptr
	printf("Dado guardado em x atraves de ptr %d\n", *ptr);

	//endereco de ptr
	printf("Endereco de ptr %p\n", &ptr);

	char str[100] = "xubaca";
	char str2[100] = "xeruca";

	pointer(str, &x, str2, y);

	return 0;
}
