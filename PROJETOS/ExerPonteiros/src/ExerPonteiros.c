/*
 ============================================================================
 Name        : ExerPonteiros.c
 Author      : Jo�o Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char* lestring(char *ptr)
{
	return(ptr);
}


int main() {
	char str[100];
	setbuf(stdout,NULL);
	printf("Digite a String: ");
	fflush(stdin);
	gets(str);
	printf("Endere�o da String: %s\n",lestring(str));
	return 0;
}
