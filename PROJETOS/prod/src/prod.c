/*
 ============================================================================
 Name        : prod.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int prod (int x,int y)
{
    return (x*y);
}

int main ()
{
    int saida;
    saida = prod(12,7);
    printf ("A saida e: %d\n",saida);
    return 0;
}
