/*
 ============================================================================
 Name        : ExerRevi4.c
 Author      : João Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcResto(int x,int y){

	return (x % y);
}
float calcMult(float x,float y){

	return (x*y);
}
float calcDiv(float x,float y){

	return (x/y);
}
float calcSub(float x,float y){

	return (x-y);
}
float calcSoma(float x,float y){

	return (x+y);
}
float calcPot(float x,float y){

	return (pow(x,y));
}
float calcRaiz(float x){

    return (sqrt(x));
}
int main ()
{
	setbuf(stdout,NULL);
	float num1,num2;
	int nu1,nu2;

	printf("RAIZ QUADRADA\n");
	printf("Entre com o numero: ");
	fflush(stdin);
	scanf("%f",&num1);
	printf("A raiz quadrada é: %.0f\n",calcRaiz(num1));
	printf("\n");

	printf("POTENCIA\n");
	printf("Entre com a base: ");
	fflush(stdin);
	scanf("%f",&num1);
	printf("Entre com o expoente: ");
	fflush(stdin);
	scanf("%f",&num2);
	printf("O resultado é: %.0f\n",calcPot(num1,num2));
	printf("\n");

	printf("SOMA\n");
	printf("Entre com o primeiro numero: ");
	fflush(stdin);
	scanf("%f",&num1);
	printf("Entre com o segundo numero: ");
	fflush(stdin);
	scanf("%f",&num2);
	printf("O resultado é: %.0f\n",calcSoma(num1,num2));
	printf("\n");

	printf("SUBTRAÇÃO\n");
	printf("Entre com o primeiro numero: ");
	fflush(stdin);
	scanf("%f",&num1);
	printf("Entre com o segundo numero: ");
	fflush(stdin);
	scanf("%f",&num2);
	printf("O resultado é: %.0f\n",calcSub(num1,num2));
	printf("\n");

	printf("DIVISÃO\n");
	printf("Entre com o primeiro numero: ");
	fflush(stdin);
	scanf("%f",&num1);
	printf("Entre com o segundo numero: ");
	fflush(stdin);
	scanf("%f",&num2);
	printf("O resultado é: %.0f\n",calcDiv(num1,num2));
	printf("\n");

	printf("MULTIPLICAÇÃO\n");
	printf("Entre com o primeiro numero: ");
	fflush(stdin);
	scanf("%f",&num1);
	printf("Entre com o segundo numero: ");
	fflush(stdin);
	scanf("%f",&num2);
	printf("O resultado é: %.0f\n",calcMult(num1,num2));
	printf("\n");

	printf("RESTO\n");
	printf("Entre com o primeiro numero: ");
	fflush(stdin);
	scanf("%d",&nu1);
	printf("Entre com o segundo numero: ");
	fflush(stdin);
	scanf("%d",&nu2);
	printf("O resto é: %.0d\n",calcResto(nu1,nu2));
	printf("\n");

	return 0;
}
