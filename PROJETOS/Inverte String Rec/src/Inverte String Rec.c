/*
 ============================================================================
 Name        : Inverte String Rec.c
 Author      : Joao Paulo Aramuni
 Version     :
 Copyright   : Your copyright notice
 Description : Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <windows.h>

//Função para verificar tamanho da String - Recursiva
int tamStr(char *str, int cont) {
	return (*str++) ? cont++, tamStr(str, cont) : --cont;
}

//Função para imprimir caracteres da String
void imprimeStr(char str) {
	printf("%c", str);
}

//Função para inverter String - Recursiva
void inverteStr(char *str, int i) {

	(i) ? imprimeStr(str[i]), inverteStr(str, --i) : imprimeStr(str[i]);
}

int main(void) {
	setbuf(stdout, NULL);
	printf("** Inverte String **\n\n");
	char str[100];
	printf("Digite a String: ");
	fflush(stdin);
	gets(str);
	printf("String invertida: ");
	inverteStr(str, tamStr(str, 0));
	printf("\n\nPressione ENTER para sair...");
	getchar();
	MessageBox(NULL, "Fim da Aplicação!", "Inverte String", MB_ICONWARNING| MB_OK);

	return 0;
}
