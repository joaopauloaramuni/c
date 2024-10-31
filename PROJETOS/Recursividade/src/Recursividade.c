/*
 ============================================================================
 Name        : Recursividade.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int fatorial(int c) {
	if (c == 0 || c == 1)
		return (1);
	else
		return (c * fatorial(c - 1));
}

/* Recursividade Simples
 *
 * 1º se caso base de parada
 *
 * 2º entao retorna 1
 *
 * 3º senão divida o problema em partes
 *    menores usando uma chamada recursiva
 *    à própria função.
 *
 * Não existem laços forçados ou interações forçadas (while, for) apenas IF
 */

/*
 Ex: Fatorial de 5
 fat(5)= 5 * fat (4)
 fat(4)= 4 * fat (3)
 fat(3)= 3 * fat (2)
 fat(2)= 2 * fat (1)
 fat(1)= 1 * fat (0)
 fat(0) = return 1
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

int fib(int n) {
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (fib(n - 1) + fib(n - 2));
}

/*   Sequencia de Fibonacci 0 1 1 2 3 5 8 13 21...
 * fib(0) fib(1) fib(2) fib(3) fib(4) fib(5) fib(6)...
 *   0      1    1+0=1  1+1=2  2+1=3  3+2=5  5+3=8...
 */

int main(void) {

	setbuf(stdout, NULL);
	int x;
	printf("** Recursividade **\n\n");
	printf("Digite um número: ");
	fflush(stdin);
	scanf("%d", &x);

	printf("\nFatorial de %d é %d\n", x, fatorial(x));

	printf("\nFibonacci de %d é %d", x, fib(x));

	return 0;
}
