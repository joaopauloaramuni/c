/*
 ============================================================================
 Name        : barulhim.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

  long int i;
  printf("\a");
  for (i=0; i<100000000;i++);
  printf("\a");
  return 0;
}
