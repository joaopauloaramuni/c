/*
 ============================================================================
 Name        : MDC.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mdc(int a, int b) {

	if (a == 0) {
		return b;

	} else if (b == 0) {
		return a;

	} else {
		return mdc(b, a % b);
	}

}

int main(void) {

	setbuf(stdout, NULL);

	int x, y;

	printf("** MDC **\n\n");
	printf("Digite dois numeros: ");
	fflush(stdin);
	scanf("%d%d", &x, &y);

	printf("%d", mdc(x, y));

	return 0;
}
