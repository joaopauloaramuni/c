/*
 ============================================================================
 Name        : getch.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <conio.h>
int main ()
{
	setbuf(stdout,NULL);
	char Ch;
	Ch=getch();
	printf ("Voce pressionou a tecla %c",Ch);
	return(0);
}
