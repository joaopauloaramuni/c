/*
 ============================================================================
 Name        : Fatorial_Normal.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float normal(float x) {

	float fat = 1;

	while (x != 1) {

		fat = fat * x;
		x = x - 1;
	}

	return fat;

	/*
	 Utilizando for:

	 int fat(int n){

	 int i, fat;

	 fat = 1;

	 for(i=1; i<=n;i++){
	 fat = fat*i;
	 }

	 for(i=n; i>=1;i--){
	 fat = fat*i;
	 }

	 return fat;

	 }

	 int main(void) {
	 int n=5;

	 printf("Fatoria: %d\n", fat(n));

	 return EXIT_SUCCESS;
	 }

	 */
}

int main(void) {

	setbuf(stdout, NULL);

	float x;
	printf("** Fatorial Normal **\n\n");
	printf("Digite um número: ");
	fflush(stdin);
	scanf("%f", &x);

	printf("fatorial de %.0f: %.0f", x, normal(x));

	return 0;
}
