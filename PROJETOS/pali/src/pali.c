/*
 ============================================================================
 Name        : pali.c
 Author      : Jo�o Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome() {
	char string[100], string2[100];
	int tam, i, j;
	printf("Digite uma frase: ");
	fflush(stdin);
	gets(string);
	tam = strlen(string);
	for (i = tam - 1, j = 0; i >= 0; i--, j++)
	string2[j] = string[i];
	string2[j] = '\0';
	for (i = 0; string[i] == string2[i]; i++);
	i--;
	if (i == tam) {
	return 1;
	}else return 0;
}
int main(void) {
	setbuf(stdout, NULL);
	int a;
	a=palindrome();
	if(a==1){
	printf("� palindrome!");
	}
	else{
	printf("N�o � palindrome!");
	}
	return 0;
}
