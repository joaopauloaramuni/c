/*
 ============================================================================
 Name        : fatorial.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int fat(int n) {
	if (n)
		return n * fat(n - 1);
	else
		return 1; //Caso conhecido n = 0 - Fatorial de 0 eh 1

	/*
	 Ex: Fatorial de 5
	 fat(5)= 5 * fat (4)
	 fat(4)= 4 * fat (3)
	 fat(3)= 3 * fat (2)
	 fat(2)= 2 * fat (1)
	 fat(1)= 1 * fat (0)
	 fat(0) = return 1 (pois fatorial de 0 eh 1 e 0 e falso no teste)
	 Entao volta..

	 fat(1)= 1 * fat (0)
	 fat(1)= 1 * 1 = 1
	 fat(2)= 2 * fat (1)
	 fat(2)= 2 * 1 = 2
	 fat(3)= 3 * fat(2)
	 fat(3)= 3 * 2 = 6
	 fat(4)= 4 * fat(3)
	 fat(4)= 4 * 6 = 24
	 fat(5)= 5 * fat(4)
	 fat(5)= 5 * 24 = 120

	 */
}

int main() {
	setbuf(stdout, NULL);
	int n;
	printf("** Fatorial **\n\n");
	printf("Digite um valor para n: ");
	scanf("%d", &n);
	printf("\nO fatorial de %d e %d", n, fat(n));
	return 0;

}
