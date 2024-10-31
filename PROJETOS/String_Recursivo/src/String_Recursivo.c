/*
 ============================================================================
 Name        : String_Recursivo.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

 int pali(char str[100], int tam) {

 if (tam <= 1) {
 return 1;
 } else if (str[0] == str[tam - 1]) {
 return pali(str + 1, tam - 2);
 } else
 return 0;
 }

 */

int pali(char str[100], int tam) {

	return (tam <= 1) || (*str == str[tam - 1] && pali(str + 1, tam - 2));

}

int main(void) {

	setbuf(stdout, NULL);
	char string[100];
	int tam;
	printf("** Palindrome Recursivo **\n\n");
	printf("Digite uma palavra: ");
	fflush(stdin);
	gets(string);

	tam = strlen(string);

	if (pali(string, tam) == 1) {
		printf("É Palindrome!");
	} else
		printf("Não é Palindrome!");

	return 0;
}
