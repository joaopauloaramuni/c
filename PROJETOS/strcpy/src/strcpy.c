/*
 ============================================================================
 Name        : strcpy.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void StrCpy(char *dest, char *orig) {

	while (*orig){
		*dest = *orig;
		dest++;
		orig++;
	}
	*dest='\0';

}

int main() {
	setbuf(stdout, NULL);
	char ch[20], ch2[20];
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(ch2);
	StrCpy(ch, ch2);
	printf("%s", ch);
	return 0;
}
