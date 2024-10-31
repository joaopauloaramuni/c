/*
 ============================================================================
 Name        : getchar.c
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
	char Ch;
	Ch=getchar();
	do {
		printf("Digite uma opção: ");
		fflush(stdin);
		Ch=getchar();
	}
	while (Ch!='q' && Ch!-'Q');

	return 0;
}

