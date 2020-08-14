/*
 ============================================================================
 Name        : Calculadora_De_Limites.c
 Author      : João Paulo Aramuni, Rafael Lott e Klelvin Carvalho
 Version     :
 Copyright   : Your copyright notice
 Description : Calculadora de Limites, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a, b, c, x, grau, a2, b2, c2, grau2, grauseg, grau2seg, num, den;
int num2, den2;

void limite1() {

	printf("\n");

	printf("** y=ax+b **\n\n");

	printf("Digite o valor de a: ");
	fflush(stdin);
	scanf("%f", &a);

	printf("Digite o valor de b: ");
	fflush(stdin);
	scanf("%f", &b);

	printf("\n");
	printf("Função: y=%.0fx+%.0f\n\n", a, b);

	printf("Digite o valor à qual x ira tender: ");
	fflush(stdin);
	scanf("%f", &x);

	printf("\n");
	printf(
			"O valor do limite quando x tender a %.0f na função y=%.0fx+%.0f e: %.0f\n\n",
			x, a, b, a * x + b);
}

void limiteinf() {

	//Limite para funcoes de qualquer grau

	printf("\n");

	printf("Digite o maior grau de x: ");
	fflush(stdin);
	scanf("%f", &grau);

	printf("Digite o menor grau de x: ");
	fflush(stdin);
	scanf("%f", &grauseg);

	printf("\n");
	printf("** y=ax%.0f+bx%.0f+c **\n\n", grau, grauseg);

	printf("Digite o valor de a: ");
	fflush(stdin);
	scanf("%f", &a);

	printf("Digite o valor de b: ");
	fflush(stdin);
	scanf("%f", &b);

	printf("Digite o valor de c: ");
	fflush(stdin);
	scanf("%f", &c);

	printf("\n");
	printf("Funcao: y=%.0fx%.0f+%.0fx%.0f+%.0f\n\n", a, grau, b, grauseg, c);

	printf("Digite o valor a qual x ira tender: ");
	fflush(stdin);
	scanf("%f", &x);

	printf("\n");
	printf(
			"O valor do limite quando x tender a %.0f na função y=%.0fx%.0f+%.0fx+%.0f e: %.0f\n\n",
			x, a, grau, b, c, a * pow(x, grau) + b * pow(x, grauseg) + c);
}

void br() {

	int briot = 1, cont = 0;
	while (briot) {

		//Teoria de Briot Ruffini

		printf("\n");
		printf("** Briot-Ruffini **\n\n");

		if ((grau == 2 && grauseg == 1) || (grau == 3 && grauseg == 2)
				|| (grau2 == 4 && grau2seg == 1) || (grau2 == 3 && b2 == 0)) {

			//Briot Ruffini no Numerador

			if (b < 0)
				printf("Numerador: %.0fx%.0f%.0fx%.0f+%.0f\n\n", a, grau, b,
						grauseg, c);
			else
				printf("Numerador: %.0fx%.0f+%.0fx%.0f+%.0f\n\n", a, grau, b,
						grauseg, c);

			printf("**(x-a)**\n\n");

			if (x >= 0) {
				printf("O numerador sera dividido por: (x-%.0f)\n\n", x);

			} else
				printf("O numerador sera dividido por: (x+%.0f)\n\n", -x);

			if (grau == 2 && grauseg == 1) {

				printf("%.0f |  %.0f  %.0f   | %.0f\n", x, a, b, c);
				printf("  |  %.0f  %.0f  | %.0f\n\n", a, (a * x) + b,
						((((a * x) + b) * x) + c));
				if ((a * x) + b < 0) {
					if (x >= 0) {
						printf("Resultado: (x%.0f)*(x-%.0f)\n", ((a * x) + b),
								x);
					} else {

						printf("Resultado: (x%.0f)*(x-%.0f)\n", ((a * x) + b),
								-x);
					}
				} else {

					if (x >= 0) {
						printf("Resultado: (x+%.0f)*(x-%.0f)\n", ((a * x) + b),
								x);
					} else {

						printf("Resultado: (x+%.0f)*(x-%.0f)\n", ((a * x) + b),
								-x);
					}
				}

				printf("\n");

			}
			if (grau == 3 && grauseg == 2) {

				if (b < 0)
					printf("Completando: %.0fx%.0f%.0fx%.0f+0x1+%.0f\n\n", a,
							grau, b, grauseg, c);
				else
					printf("Completando: %.0fx%.0f+%.0fx%.0f+0x1+%.0f\n\n", a,
							grau, b, grauseg, c);
				printf("%.0f |  %.0f  %.0f  0  | %.0f\n", x, a, b, c);
				printf("   |  %.0f  %.0f  %.0f | %.0f\n\n", a, (a * x) + b,
						(((a * x) + b) * x) + 0,
						(((((a * x) + b) * x) + 0) * x) + c);
				if ((a * x) + b < 0) {
					if (x >= 0) {
						printf("Resultado: (%.0fx%.0f%.0fx+%.0f)*(x-%.0f)\n",
								a, grau - 1, (a * x) + b, (((a * x) + b) * x)
										+ 0, x);
					} else {

						printf("Resultado: (%.0fx%.0f%.0fx+%.0f)*(x+%.0f)\n",
								a, grau - 1, (a * x) + b, (((a * x) + b) * x)
										+ 0, -x);
					}
				} else {

					if (x >= 0) {
						printf("Resultado: (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",
								a, grau - 1, (a * x) + b, (((a * x) + b) * x)
										+ 0, x);
					} else {

						printf("Resultado: (%.0fx%.0f+%.0fx+%.0f)*(x+%.0f)\n",
								a, grau - 1, (a * x) + b, (((a * x) + b) * x)
										+ 0, -x);
					}
				}

				printf("\n");
			}

			//Briot Ruffini no Denominador

			if (b2 < 0 && c2 >= 0)
				printf("Denominador: %.0fx%.0f%.0fx%.0f+%.0f\n\n", a2, grau2,
						b2, grau2seg, c2);

			else if (b2 < 0 && c2 < 0)
				printf("Denominador: %.0fx%.0f%.0fx%.0f%.0f\n\n", a2, grau2,
						b2, grau2seg, c2);

			else if (b2 >= 0 && c2 < 0)
				printf("Denominador: %.0fx%.0f+%.0fx%.0f%.0f\n\n", a2, grau2,
						b2, grau2seg, c2);
			else if (b2 >= 0 && c2 >= 0)
				printf("Denominador: %.0fx%.0f+%.0fx%.0f+%.0f\n\n", a2, grau2,
						b2, grau2seg, c2);

			printf("**(x-a)**\n\n");

			if (x >= 0) {
				printf("O denominador sera dividido por: (x-%.0f)\n\n", x);
			} else
				printf("O denominador sera dividido por: (x+%.0f)\n\n", -x);

			if (grau2 == 3 && b2 == 0) {

				if (c2 < 0)
					printf("Completando: %.0fx%.0f+0x2+0x1%.0f\n\n", a2, grau2,
							c2);
				else
					printf("Completando: %.0fx%.0f+0x2+0x1+%.0f\n\n", a2,
							grau2, c2);

				printf("%.0f  |  %.0f  0  0   |  %.0f\n", x, a2, c2);
				printf("   |  %.0f  %.0f  %.0f  |  %.0f\n\n", a2, (a2 * x) + 0,
						(((a2 * x) + 0) * x) + 0, (((((((a2 * x) + 0) * x) + 0)
								* x) + b2) + c2));

				if ((a2 * x) + b2 < 0) {
					if (x >= 0) {
						printf("Resultado: (%.0fx%.0f%.0fx+%.0f)*(x-%.0f)\n",
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, x);
					} else {

						printf("Resultado: (%.0fx%.0f%.0fx+%.0f)*(x+%.0f)\n",
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, -x);
					}
				} else {

					if (x >= 0) {
						printf("Resultado: (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, x);
					} else {

						printf("Resultado: (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, -x);
					}
				}

				printf("\n");

			}

			if (grau2 == 4 && grau2seg == 1) {

				if (b2 < 0)
					printf("Completando: %.0fx%.0f+0x3+0x2%.0fx%.0f+%.0f\n\n",
							a2, grau2, b2, grau2seg, c2);
				else
					printf("Completando: %.0fx%.0f+0x3+0x2+%.0fx%.0f+%.0f\n\n",
							a2, grau2, b2, grau2seg, c2);
				printf("%.0f  |  %.0f  0   0  %.0f   |  %.0f\n", x, a2, b2, c2);
				printf("    |  %.0f  %.0f  %.0f  %.0f  |  %.0f\n\n", a2, (a2
						* x) + 0, (((a2 * x) + 0) * x) + 0, (((((a2 * x) + 0)
						* x) + 0) * x) + b2, (((((((a2 * x) + 0) * x) + 0) * x)
						+ b2) * x) + c2);
				if ((a2 * x) + b2 < 0) {
					if (x >= 0) {
						printf(
								"Resultado: (%.0fx%.0f%.0fx2%.0fx+%.0f)*(x-%.0f)\n",
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, (((((a2 * x) + 0) * x) + 0)
										* x) + b2, x);
					} else {

						printf(
								"Resultado: (%.0fx%.0f%.0fx2%.0fx+%.0f)*(x+%.0f)\n",
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, (((((a2 * x) + 0) * x) + 0)
										* x) + b2, -x);
					}
				} else {

					if (x >= 0) {
						printf(
								"Resultado: (%.0fx%.0f+%.0fx2%.0fx+%.0f)*(x-%.0f)\n",
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, (((((a2 * x) + 0) * x) + 0)
										* x) + b2, x);
					} else {

						printf(
								"Resultado: (%.0fx%.0f+%.0fx2%.0fx+%.0f)*(x+%.0f)\n",
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, (((((a2 * x) + 0) * x) + 0)
										* x) + b2, -x);
					}
				}

				printf("\n");

			}

			if (grau == 3 && grauseg == 2 && grau2 == 4 && grau2seg == 1) {

				printf("** Nova Divisao **\n\n");

				if ((a * x) + b < 0) {
					if (x >= 0) {
						printf("      (%.0fx%.0f%.0fx+%.0f)*(x-%.0f)\n", a,
								grau - 1, (a * x) + b, (((a * x) + b) * x) + 0,
								x);
					} else {

						printf("      (%.0fx%.0f%.0fx+%.0f)*(x+%.0f)\n", a,
								grau - 1, (a * x) + b, (((a * x) + b) * x) + 0,
								-x);
					}
				} else {

					if (x >= 0) {
						printf("      (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n", a,
								grau - 1, (a * x) + b, (((a * x) + b) * x) + 0,
								x);
					} else {

						printf("      (%.0fx%.0f+%.0fx+%.0f)*(x+%.0f)\n", a,
								grau - 1, (a * x) + b, (((a * x) + b) * x) + 0,
								-x);
					}
				}

				printf("lim = ----------------------\n");

				if ((a2 * x) + b2 < 0) {
					if (x >= 0) {
						printf("x->%.0f (%.0fx%.0f%.0fx2%.0fx+%.0f)*(x-%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0) * x)
										+ 0, (((((a2 * x) + 0) * x) + 0) * x)
										+ b2, x);
					} else {

						printf("x->%.0f (%.0fx%.0f%.0fx2%.0fx+%.0f)*(x+%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0) * x)
										+ 0, (((((a2 * x) + 0) * x) + 0) * x)
										+ b2, -x);
					}
				} else {

					if (x >= 0) {
						printf("x->%.0f (%.0fx%.0f+%.0fx2%.0fx+%.0f)*(x-%.0f)\n",x,
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, (((((a2 * x) + 0) * x) + 0)
										* x) + b2, x);
					} else {

						printf("x->%.0f (%.0fx%.0f+%.0fx2%.0fx+%.0f)*(x+%.0f)\n",x,
								a2, grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0)
										* x) + 0, (((((a2 * x) + 0) * x) + 0)
										* x) + b2, -x);
					}
				}

				printf("\n");

				if ((a * x) + b < 0) {
					printf("      (%.0f(%.0f)%.0f%.0f(%.0f)+%.0f)\n", a, x,
							grau - 1, (a * x) + b, x, (((a * x) + b) * x) + 0);
				} else {
					printf("      (%.0f(%.0f)%.0f+%.0f(%.0f)+%.0f)\n", a, x,
							grau - 1, (a * x) + b, x, (((a * x) + b) * x) + 0);
				}

				printf("  = ----------------------\n");

				if (((((a2 * x) + 0) * x) + 0) < 0) {
					if ((a2 * x) + b2 < 0) {

						printf(
								"    (%.0f(%.0f)%.0f%.0f(%.0f)2%.0f(%.0f)+%.0f)\n",
								a2, x, grau2 - 1, (a2 * x) + 0, x, (((a2 * x)
										+ 0) * x) + 0, x,
								(((((a2 * x) + 0) * x) + 0) * x) + b2);

					} else {

						printf(
								"    (%.0f(%.0f)%.0f+%.0f(%.0f)2%.0f(%.0f)+%.0f)\n",
								a2, x, grau2 - 1, (a2 * x) + 0, x, (((a2 * x)
										+ 0) * x) + 0, x,
								(((((a2 * x) + 0) * x) + 0) * x) + b2);

					}
				} else {
					if ((a2 * x) + b2 < 0) {

						printf(
								"    (%.0f(%.0f)%.0f%.0f(%.0f)2+%.0f(%.0f)+%.0f)\n",
								a2, x, grau2 - 1, (a2 * x) + 0, x, (((a2 * x)
										+ 0) * x) + 0, x,
								(((((a2 * x) + 0) * x) + 0) * x) + b2);

					} else {

						printf(
								"    (%.0f(%.0f)%.0f+%.0f(%.0f)2+%.0f(%.0f)+%.0f)\n",
								a2, x, grau2 - 1, (a2 * x) + 0, x, (((a2 * x)
										+ 0) * x) + 0, x,
								(((((a2 * x) + 0) * x) + 0) * x) + b2);

					}
				}

				printf("\n");

				num = a * pow(x, grau - 1) + ((a * x) + b)
						* pow(x, grauseg - 1) + ((((a * x) + b) * x) + 0);

				den = (a2 * pow(x, grau2 - 1)) + (((a2 * x) + 0) * pow(x, grau2
						- 2)) + (((((a2 * x) + 0) * x) + 0) * pow(x, grau2seg))
						+ ((((((a2 * x) + 0) * x) + 0) * x) + b2);

				num2 = num;
				den2 = den;

			}
			if (grau == 2 && grauseg == 1 && grau2 == 3 && b2 == 0) {

				printf("** Nova Divisao **\n\n");

				if ((a * x) + b < 0) {
					if (x >= 0) {
						printf("	(x%.0f)*(x-%.0f)\n", ((a * x) + b), x);
					} else {

						printf("	(x%.0f)*(x-%.0f)\n", ((a * x) + b), -x);
					}
				} else {

					if (x >= 0) {
						printf("	(x+%.0f)*(x-%.0f)\n", ((a * x) + b), x);
					} else {

						printf("	(x+%.0f)*(x-%.0f)\n", ((a * x) + b), -x);
					}
				}

				printf("lim = ----------------------\n");

				if ((a2 * x) + b2 < 0) {
					if (x >= 0) {
						printf("x->%.0f (%.0fx%.0f%.0fx+%.0f)*(x-%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0) * x)
										+ 0, x);
					} else {

						printf("x->%.0f (%.0fx%.0f%.0fx+%.0f)*(x+%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0) * x)
										+ 0, -x);
					}
				} else {

					if (x >= 0) {
						printf("x->%.0f (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0) * x)
										+ 0, x);
					} else {

						printf("x->%.0f (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + 0, (((a2 * x) + 0) * x)
										+ 0, -x);
					}
				}

				printf("\n");

				if ((a * x) + b < 0) {
					printf("	(x%.0f)\n", ((a * x) + b));
				} else {
					printf("	(x+%.0f)\n", ((a * x) + b));
				}

				printf("lim = ----------------------\n");

				if ((a2 * x) + b2 < 0) {

					printf("x->%.0f (%.0fx%.0f+%.0fx+%.0f)\n",x, a2, grau2 - 1, (a2
							* x) + 0, (((a2 * x) + 0) * x) + 0);

				} else {

					printf("x->%.0f (%.0fx%.0f+%.0fx+%.0f)\n",x, a2, grau2 - 1, (a2
							* x) + 0, (((a2 * x) + 0) * x) + 0);

				}

				printf("\n");

				num = a * pow(x, grau - 1) + ((a * x) + b);
				den = a2 * pow(x, grau2 - 1) + (((a2 * x) + 0) * x)
						+ (((a2 * x) + 0) * x) + 0;

				num2 = num;
				den2 = den;
			}
			if (num2 % 2 == 0 && den2 % 2 == 0) {

				printf("Resultado Final: \n\n");

				printf("  %.0f\n", num / 2);
				printf("= --\n");
				printf("  %.0f\n", den / 2);

			} else if (num2 % 3 == 0 && den2 % 3 == 0) {

				printf("Resultado Final: \n\n");

				printf("  %.0f\n", num / 3);
				printf("= --\n");
				printf("  %.0f\n", den / 3);

			} else {
				printf("Resultado Final: \n\n");

				printf("  %.0f\n", num);
				printf("= --\n");
				printf("  %.0f\n", den);

			}

		}

		//Opcoes anteriores invertidas (Denominador x Numerador)

		if ((grau2 == 2 && grau2seg == 1) || (grau2 == 3 && grau2seg == 2)
				|| (grau == 4 && grauseg == 1) || (grau == 3 && b == 0)) {

			//Briot Ruffini no Numerador

			if (b < 0 && c >= 0)
				printf("Numerador: %.0fx%.0f%.0fx%.0f+%.0f\n\n", a, grau, b,
						grauseg, c);

			else if (b < 0 && c < 0)
				printf("Numerador: %.0fx%.0f%.0fx%.0f%.0f\n\n", a, grau, b,
						grauseg, c);

			else if (b >= 0 && c < 0)
				printf("Numerador: %.0fx%.0f+%.0fx%.0f%.0f\n\n", a, grau, b,
						grauseg, c);
			else if (b >= 0 && c >= 0)
				printf("Numerador: %.0fx%.0f+%.0fx%.0f+%.0f\n\n", a, grau, b,
						grauseg, c);

			printf("**(x-a)**\n\n");

			if (x >= 0) {
				printf("O Numerador sera dividido por: (x-%.0f)\n\n", x);
			} else
				printf("O Numerador sera dividido por: (x+%.0f)\n\n", -x);

			if (grau == 3 && b == 0) {

				if (c < 0)
					printf("Completando: %.0fx%.0f+0x2+0x1%.0f\n\n", a, grau, c);
				else
					printf("Completando: %.0fx%.0f+0x2+0x1+%.0f\n\n", a, grau,
							c);

				printf("%.0f  |  %.0f  0  0   |  %.0f\n", x, a, c);
				printf("   |  %.0f  %.0f  %.0f  |  %.0f\n\n", a, (a * x) + 0,
						(((a * x) + 0) * x) + 0, (((((((a * x) + 0) * x) + 0)
								* x) + b) + c));

				if ((a * x) + b < 0) {
					if (x >= 0) {
						printf("Resultado: (%.0fx%.0f%.0fx+%.0f)*(x-%.0f)\n",
								a, grau - 1, (a * x) + 0, (((a * x) + 0) * x)
										+ 0, x);
					} else {

						printf("Resultado: (%.0fx%.0f%.0fx+%.0f)*(x+%.0f)\n",
								a, grau - 1, (a * x) + 0, (((a * x) + 0) * x)
										+ 0, -x);
					}
				} else {

					if (x >= 0) {
						printf("Resultado: (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",
								a, grau - 1, (a * x) + 0, (((a * x) + 0) * x)
										+ 0, x);
					} else {

						printf("Resultado: (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",
								a, grau - 1, (a * x) + 0, (((a * x) + 0) * x)
										+ 0, -x);
					}
				}

				printf("\n");

			}

			if (grau == 4 && grauseg == 1) {

				if (b < 0)
					printf("Completando: %.0fx%.0f+0x3+0x2%.0fx%.0f+%.0f\n\n",
							a, grau, b, grauseg, c);
				else
					printf("Completando: %.0fx%.0f+0x3+0x2+%.0fx%.0f+%.0f\n\n",
							a, grau, b, grauseg, c);
				printf("%.0f  |  %.0f  0   0  %.0f   |  %.0f\n", x, a, b, c);
				printf("    |  %.0f  %.0f  %.0f  %.0f  |  %.0f\n\n", a, (a * x)
						+ 0, (((a * x) + 0) * x) + 0,
						(((((a * x) + 0) * x) + 0) * x) + b, (((((((a * x) + 0)
								* x) + 0) * x) + b) * x) + c);
				if ((a * x) + b < 0) {
					if (x >= 0) {
						printf(
								"Resultado: (%.0fx%.0f%.0fx2%.0fx+%.0f)*(x-%.0f)\n",
								a, grau - 1, (a * x) + 0, (((a * x) + 0) * x)
										+ 0, (((((a * x) + 0) * x) + 0) * x)
										+ b, x);
					} else {

						printf(
								"Resultado: (%.0fx%.0f%.0fx2%.0fx+%.0f)*(x+%.0f)\n",
								a, grau - 1, (a * x) + 0, (((a * x) + 0) * x)
										+ 0, (((((a * x) + 0) * x) + 0) * x)
										+ b, -x);
					}
				} else {

					if (x >= 0) {
						printf(
								"Resultado: (%.0fx%.0f+%.0fx2%.0fx+%.0f)*(x-%.0f)\n",
								a, grau - 1, (a * x) + 0, (((a * x) + 0) * x)
										+ 0, (((((a * x) + 0) * x) + 0) * x)
										+ b, x);
					} else {

						printf(
								"Resultado: (%.0fx%.0f+%.0fx2%.0fx+%.0f)*(x+%.0f)\n",
								a, grau - 1, (a * x) + 0, (((a * x) + 0) * x)
										+ 0, (((((a * x) + 0) * x) + 0) * x)
										+ b, -x);
					}
				}

				printf("\n");

			}

			if (b2 < 0)
				printf("Denominador: %.0fx%.0f%.0fx%.0f+%.0f\n\n", a2, grau2,
						b2, grau2seg, c2);
			else
				printf("Denominador: %.0fx%.0f+%.0fx%.0f+%.0f\n\n", a2, grau2,
						b2, grau2seg, c2);

			printf("**(x-a)**\n\n");

			if (x >= 0) {
				printf("O Denominador sera dividido por: (x-%.0f)\n\n", x);

			} else
				printf("O Denominador sera dividido por: (x+%.0f)\n\n", -x);

			if (grau2 == 2 && grau2seg == 1) {

				printf("%.0f |  %.0f  %.0f   | %.0f\n", x, a2, b2, c2);
				printf("  |  %.0f  %.0f  | %.0f\n\n", a2, (a2 * x) + b2, ((((a2
						* x) + b2) * x) + c2));
				if ((a2 * x) + b2 < 0) {
					if (x >= 0) {
						printf("Resultado: (x%.0f)*(x-%.0f)\n",
								((a2 * x) + b2), x);
					} else {

						printf("Resultado: (x%.0f)*(x-%.0f)\n",
								((a2 * x) + b2), -x);
					}
				} else {

					if (x >= 0) {
						printf("Resultado: (x+%.0f)*(x-%.0f)\n",
								((a2 * x) + b2), x);
					} else {

						printf("Resultado: (x+%.0f)*(x-%.0f)\n",
								((a2 * x) + b2), -x);
					}
				}

				printf("\n");

			}
			if (grau2 == 3 && grau2seg == 2) {

				if (b2 < 0)
					printf("Completando: %.0fx%.0f%.0fx%.0f+0x1+%.0f\n\n", a2,
							grau2, b2, grau2seg, c2);
				else
					printf("Completando: %.0fx%.0f+%.0fx%.0f+0x1+%.0f\n\n", a2,
							grau2, b2, grau2seg, c2);
				printf("%.0f |  %.0f  %.0f  0  | %.0f\n", x, a2, b2, c2);
				printf("   |  %.0f  %.0f  %.0f | %.0f\n\n", a2, (a2 * x) + b2,
						(((a2 * x) + b2) * x) + 0, (((((a2 * x) + b2) * x) + 0)
								* x) + c2);
				if ((a2 * x) + b2 < 0) {
					if (x >= 0) {
						printf("Resultado: (%.0fx%.0f%.0fx+%.0f)*(x-%.0f)\n",
								a2, grau2 - 1, (a2 * x) + b2, (((a2 * x) + b2)
										* x) + 0, x);
					} else {

						printf("Resultado: (%.0fx%.0f%.0fx+%.0f)*(x+%.0f)\n",
								a2, grau2 - 1, (a2 * x) + b2, (((a2 * x) + b2)
										* x) + 0, -x);
					}
				} else {

					if (x >= 0) {
						printf("Resultado: (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",
								a2, grau2 - 1, (a2 * x) + b2, (((a2 * x) + b2)
										* x) + 0, x);
					} else {

						printf("Resultado: (%.0fx%.0f+%.0fx+%.0f)*(x+%.0f)\n",
								a2, grau2 - 1, (a2 * x) + b2, (((a2 * x) + b2)
										* x) + 0, -x);
					}
				}

				printf("\n");
			}

			if (grau2 == 3 && grau2seg == 2 && grau == 4 && grauseg == 1) {

				printf("** Nova Divisao **\n\n");

				if ((a * x) + b < 0) {
					if (x >= 0) {
						printf("     (%.0fx%.0f%.0fx2%.0fx+%.0f)*(x-%.0f)\n", a,
								grau - 1, (a * x) + 0, (((a * x) + 0) * x) + 0,
								(((((a * x) + 0) * x) + 0) * x) + b, x);
					} else {

						printf("     (%.0fx%.0f%.0fx2%.0fx+%.0f)*(x+%.0f)\n", a,
								grau - 1, (a * x) + 0, (((a * x) + 0) * x) + 0,
								(((((a * x) + 0) * x) + 0) * x) + b, -x);
					}
				} else {

					if (x >= 0) {
						printf("     (%.0fx%.0f+%.0fx2%.0fx+%.0f)*(x-%.0f)\n", a,
								grau - 1, (a * x) + 0, (((a * x) + 0) * x) + 0,
								(((((a * x) + 0) * x) + 0) * x) + b, x);
					} else {

						printf("     (%.0fx%.0f+%.0fx2%.0fx+%.0f)*(x+%.0f)\n", a,
								grau - 1, (a * x) + 0, (((a * x) + 0) * x) + 0,
								(((((a * x) + 0) * x) + 0) * x) + b, -x);
					}
				}

				printf("lim = ----------------------\n");

				if ((a2 * x) + b2 < 0) {
					if (x >= 0) {
						printf("x->%.0f (%.0fx%.0f%.0fx+%.0f)*(x-%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + b2, (((a2 * x) + b2) * x)
										+ 0, x);
					} else {

						printf("x->%.0f (%.0fx%.0f%.0fx+%.0f)*(x+%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + b2, (((a2 * x) + b2) * x)
										+ 0, -x);
					}
				} else {

					if (x >= 0) {
						printf("x->%.0f (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + b2, (((a2 * x) + b2) * x)
										+ 0, x);
					} else {

						printf("x->%.0f (%.0fx%.0f+%.0fx+%.0f)*(x+%.0f)\n",x, a2,
								grau2 - 1, (a2 * x) + b2, (((a2 * x) + b2) * x)
										+ 0, -x);
					}
				}

				printf("\n");

				if (((((a * x) + 0) * x) + 0) < 0) {
					if ((a * x) + b < 0) {

						printf(
								"   (%.0f(%.0f)%.0f%.0f(%.0f)2%.0f(%.0f)+%.0f)\n",
								a, x, grau - 1, (a * x) + 0, x, (((a * x) + 0)
										* x) + 0, x, (((((a * x) + 0) * x) + 0)
										* x) + b);

					} else {

						printf(
								"   (%.0f(%.0f)%.0f+%.0f(%.0f)2%.0f(%.0f)+%.0f)\n",
								a, x, grau - 1, (a * x) + 0, x, (((a * x) + 0)
										* x) + 0, x, (((((a * x) + 0) * x) + 0)
										* x) + b);

					}
				} else {
					if ((a * x) + b < 0) {

						printf(
								"   (%.0f(%.0f)%.0f%.0f(%.0f)2+%.0f(%.0f)+%.0f)\n",
								a, x, grau - 1, (a * x) + 0, x, (((a * x) + 0)
										* x) + 0, x, (((((a * x) + 0) * x) + 0)
										* x) + b);

					} else {

						printf(
								"   (%.0f(%.0f)%.0f+%.0f(%.0f)2+%.0f(%.0f)+%.0f)\n",
								a, x, grau - 1, (a * x) + 0, x, (((a * x) + 0)
										* x) + 0, x, (((((a * x) + 0) * x) + 0)
										* x) + b);

					}
				}

				printf("   = ----------------------\n");

				if ((a2 * x) + b2 < 0) {
					printf("      (%.0f(%.0f)%.0f%.0f(%.0f)+%.0f)\n", a2, x,
							grau2 - 1, (a2 * x) + b2, x, (((a2 * x) + b2) * x)
									+ 0);
				} else {
					printf("      (%.0f(%.0f)%.0f+%.0f(%.0f)+%.0f)\n", a2, x,
							grau2 - 1, (a2 * x) + b2, x, (((a2 * x) + b2) * x)
									+ 0);
				}

				printf("\n");

				num = a2 * pow(x, grau2 - 1) + ((a2 * x) + b2) * pow(x,
						grau2seg - 1) + ((((a2 * x) + b2) * x) + 0);

				den = (a * pow(x, grau - 1)) + (((a * x) + 0)
						* pow(x, grau - 2)) + (((((a * x) + 0) * x) + 0) * pow(
						x, grauseg)) + ((((((a * x) + 0) * x) + 0) * x) + b);

				num2 = num;
				den2 = den;

			}

			if (grau2 == 2 && grau2seg == 1 && grau == 3 && b == 0) {

				printf("** Nova Divisao **\n\n");

				if ((a * x) + b < 0) {
					if (x >= 0) {
						printf("      (%.0fx%.0f%.0fx+%.0f)*(x-%.0f)\n", a,
								grau - 1, (a * x) + 0, (((a * x) + 0) * x) + 0,
								x);
					} else {

						printf("      (%.0fx%.0f%.0fx+%.0f)*(x+%.0f)\n", a,
								grau - 1, (a * x) + 0, (((a * x) + 0) * x) + 0,
								-x);
					}
				} else {

					if (x >= 0) {
						printf("      (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n", a,
								grau - 1, (a * x) + 0, (((a * x) + 0) * x) + 0,
								x);
					} else {

						printf("      (%.0fx%.0f+%.0fx+%.0f)*(x-%.0f)\n", a,
								grau - 1, (a * x) + 0, (((a * x) + 0) * x) + 0,
								-x);
					}
				}

				printf("lim = ----------------------\n");

				if ((a2 * x) + b2 < 0) {
					if (x >= 0) {
						printf("x->%.0f	(x%.0f)*(x-%.0f)\n",x, ((a2 * x) + b2), x);
					} else {

						printf("x->%.0f	(x%.0f)*(x-%.0f)\n",x, ((a2 * x) + b2), -x);
					}
				} else {

					if (x >= 0) {
						printf("x->%.0f	(x+%.0f)*(x-%.0f)\n",x, ((a2 * x) + b2), x);
					} else {

						printf("x->%.0f	(x+%.0f)*(x-%.0f)\n",x, ((a2 * x) + b2), -x);
					}
				}

				printf("\n");

				if ((a * x) + b < 0) {

					printf("      (%.0fx%.0f+%.0fx+%.0f)\n", a, grau - 1, (a
							* x) + 0, (((a * x) + 0) * x) + 0);

				} else {

					printf("      (%.0fx%.0f+%.0fx+%.0f)\n", a, grau - 1, (a
							* x) + 0, (((a * x) + 0) * x) + 0);

				}

				printf("lim = ----------------------\n");

				if ((a2 * x) + b2 < 0) {
					printf("x->%.0f	(x%.0f)\n",x, ((a2 * x) + b2));
				} else {
					printf("x->%.0f	(x+%.0f)\n",x, ((a2 * x) + b2));
				}

				printf("\n");

				num = a2 * pow(x, grau2 - 1) + ((a2 * x) + b2);
				den = a * pow(x, grau - 1) + (((a * x) + 0) * x) + (((a * x)
						+ 0) * x) + 0;

				num2 = num;
				den2 = den;
			}

			if (num2 % 2 == 0 && den2 % 2 == 0) {

				printf("Resultado Final: \n\n");

				printf("  %.0f\n", den / 2);
				printf("= --\n");
				printf("  %.0f\n", num / 2);

			} else if (num2 % 3 == 0 && den2 % 3 == 0) {

				printf("Resultado Final: \n\n");

				printf("  %.0f\n", den / 3);
				printf("= --\n");
				printf("  %.0f\n", num / 3);

			} else {
				printf("Resultado Final: \n\n");

				printf("  %.0f\n", den);
				printf("= --\n");
				printf("  %.0f\n", num);

			}
		}

		if (num == 0 && den == 0) {
			printf("Indeterminacao Matematica Novamente!\n\n");
			cont++;
			if (cont == 2) {
				printf("\n");
				printf("** Erro ao calcular o limite! **\n\n");
				briot = 0;
			}
		} else
			briot = 0;
	}

	printf("\n");
}

void limiterac() {

	//Limites racionais

	printf("\n");
	printf("** Numerador **\n\n");

	printf("Digite o maior grau de x do numerador: ");
	fflush(stdin);
	scanf("%f", &grau);

	printf("Digite o menor grau de x do numerador: ");
	fflush(stdin);
	scanf("%f", &grauseg);

	if (grau == 1) {
		printf("\n");
		printf("** y=ax+b **\n\n");
	} else {
		printf("\n");
		printf("** y=ax%.0f+bx%.0f+c **\n\n", grau, grauseg);
	}

	printf("Digite o valor de a do numerador: ");
	fflush(stdin);
	scanf("%f", &a);

	printf("Digite o valor de b do numerador: ");
	fflush(stdin);
	scanf("%f", &b);

	printf("Digite o valor de c do numerador: ");
	fflush(stdin);
	scanf("%f", &c);

	printf("\n");
	if (b < 0)
		printf("Numerador: %.0fx%.0f%.0fx%.0f+%.0f\n\n", a, grau, b, grauseg, c);
	else
		printf("Numerador: %.0fx%.0f+%.0fx%.0f+%.0f\n\n", a, grau, b, grauseg,
				c);

	printf("** Denominador **\n\n");

	printf("Digite o maior grau de x do denominador: ");
	fflush(stdin);
	scanf("%f", &grau2);

	printf("Digite o menor grau de x do denominador: ");
	fflush(stdin);
	scanf("%f", &grau2seg);

	if (grau2 == 1) {
		printf("\n");
		printf("** y=ax+b **\n\n");
	} else {
		printf("\n");
		printf("** y=ax%.0f+bx+c **\n\n", grau2);
	}

	printf("Digite o valor de a do denominador: ");
	fflush(stdin);
	scanf("%f", &a2);

	printf("Digite o valor de b do denominador: ");
	fflush(stdin);
	scanf("%f", &b2);

	printf("Digite o valor de c do denominador: ");
	fflush(stdin);
	scanf("%f", &c2);

	printf("\n");

	if (b2 < 0)
		printf("Denominador: %.0fx%.0f%.0fx%.0f+%.0f\n\n", a2, grau2, b2,
				grau2seg, c2);
	else
		printf("Denominador: %.0fx%.0f+%.0fx%.0f+%.0f\n\n", a2, grau2, b2,
				grau2seg, c2);

	printf("Digite o valor a qual x ira tender: ");
	fflush(stdin);
	scanf("%f", &x);

	printf("\n");

	if (b < 0)
		printf("       %.0fx%.0f%.0fx%.0f+%.0f\n", a, grau, b, grauseg, c);
	else
		printf("       %.0fx%.0f+%.0fx%.0f+%.0f\n", a, grau, b, grauseg, c);
	printf("lim  = -----------\n");
	if (b2 < 0)
		printf("x->%.0f  %.0fx%.0f%.0fx%.0f+%.0f\n\n",x, a2, grau2, b2, grau2seg, c2);
	else
		printf("x->%.0f  %.0fx%.0f+%.0fx%.0f+%.0f\n\n",x, a2, grau2, b2, grau2seg, c2);;

	num = a * pow(x, grau) + b * pow(x, grauseg) + c;
	den = a2 * pow(x, grau2) + b2 * pow(x, grau2seg) + c2;

	if (den != 0) {

		if (num2 % 2 == 0 && den2 % 2 == 0) {

			printf("Resultado Final: \n\n");

			printf("%.0f\n", num / 2);
			printf("--\n");
			printf("%.0f\n", den / 2);

			printf("\n");

		} else if (num2 % 3 == 0 && den2 % 3 == 0) {

			printf("Resultado Final: \n\n");

			printf("%.0f\n", num / 3);
			printf("--\n");
			printf("%.0f\n", den / 3);

			printf("\n");

		} else {
			printf("Resultado Final: \n\n");

			printf("%.0f\n", num);
			printf("--\n");
			printf("%.0f\n", den);

			printf("\n");
		}

	} else if (num2 == 0 && den2 == 0) {
		printf(
				"O valor do limite quando x tender a %.0f na funcao e: %.0f/%.0f\n\n",
				x, num, den);
		printf("Indeterminacao Matematica!\n\n");
		printf(
				"Executando calculo do limite atraves da teoria de Briot-Ruffini...\n");
		br();

	} else
		printf("O valor do limite quando x tender a %.0f na funcao e: 0\n\n", x);

}

void limiteirac() {

	//Limite para funcoes irracionais

	printf("\n");
	printf("         ___\n");
	printf("** y = _/x+b **\n\n");
	printf("** Condicao de Existencia **\n");
	printf("** x+b != 0 **\n\n");

	x = 0;
	b = 0;

	while (x + b == 0) {
		printf("Digite o valor de b: ");
		fflush(stdin);
		scanf("%f", &b);

		printf("Digite o valor à qual x ira tender: ");
		fflush(stdin);
		scanf("%f", &x);

		if (x + b == 0) {
			printf("\n");
			printf("Fora da condicao de existencia!\n\n");
		}
	}

	if (b >= 0) {
		printf("         ___\n");
		printf("** y = _/%.0f+%.0f **\n\n", x, b);
	} else {
		printf("         ___\n");
		printf("** y = _/%.0f%.0f **\n\n", x, b);
	}

	printf("          __\n");
	printf("**  y = _/%.0f  **\n\n", x + b);

	printf("O valor do limite quando x tender a %.0f na função e: %.0f\n\n", x,
			sqrt(x + b));

}
void limiteexp() {

	//Limite para funcoes exponenciais

	printf("\n");
	printf("          x+b\n");
	printf("**   y = a    **\n\n");
	printf("** Condicao de Existencia **\n\n");
	printf("** 0< a != 1 **\n\n");

	a = 0;

	while (a == 0 || a == 1) {

		printf("Digite o valor de a: ");
		fflush(stdin);
		scanf("%f", &a);

		if (a == 0 || a == 1) {
			printf("\n");
			printf("Fora da condicao de existencia!\n\n");
		}
	}

	printf("Digite o valor de b: ");
	fflush(stdin);
	scanf("%f", &b);

	printf("Digite o valor à qual x ira tender: ");
	fflush(stdin);
	scanf("%f", &x);

	printf("\n");
	printf("    	  %.0f+%.0f\n", x, b);
	printf("**   y = %.0f    **\n\n", a);
	printf("    	                                             %.0f\n", x + b);
	printf(
			"O valor do limite quando x tender a %.0f na função y = %.0f    e: %.0f\n\n",
			x, a, pow(a, x + b));

}

void limitelog() {

	//Limite para funcoes logaritmicas

	printf("\n");
	printf("** y = log (x+b) **\n");
	printf("          a\n\n");
	printf("** Condicao de Existencia **\n\n");
	printf("** 0 < a != 1 **\n");
	printf("** x+b > 0 **\n");
	printf("** y e |R **\n\n");

	a = 0;

	while (a == 0 || a == 1) {

		printf("Digite no valor de a: ");
		fflush(stdin);
		scanf("%f", &a);

		if (a == 0 || a == 1) {
			printf("\n");
			printf("Fora da condicao de existencia!\n\n");
		}
	}

	b = 0;
	x = 0;

	while (x + b <= 0) {

		printf("Digite o valor de b: ");
		fflush(stdin);
		scanf("%f", &b);

		printf("Digite o valor à qual x ira tender: ");
		fflush(stdin);
		scanf("%f", &x);

		if (x + b <= 0) {
			printf("\n");
			printf("Fora da condicao de existencia!\n\n");
		}
	}

	if (b >= 0) {
		printf("\n");
		printf("** y = log(%.0f+%.0f) **\n", x, b);
		printf("      %.0f\n\n", a);
	} else {
		printf("\n");
		printf("** y = log(%.0f%.0f) **\n", x, b);
		printf("      %.0f\n\n", a);
	}

	printf("** y = log %.0f **\n", x + b);
	printf("      %.0f\n\n", a);

	printf("    y\n");
	printf("** %.0f = %.0f **\n\n", a, x + b);

	int z = x + b, cont = 0, cont2 = 0, z2 = a, cont3 = 0, cont4 = 0, r;

	r = (z / 2);

	if (r % 2 == 0) {

		while (z % 2 == 0) {

			z = z / 2;
			cont++;
		}
	}
	r = (z / 3);
	if (r % 3 == 0) {
		while (z % 3 == 0) {

			z = z / 3;
			cont2++;
		}
	}
	r = (z2 / 2);

	if (r % 2 == 0) {
		while (z2 % 2 == 0) {

			z2 = z2 / 2;
			cont3++;
		}
	}

	r = (z2 / 3);

	if (r % 3 == 0) {
		while (z2 % 3 == 0) {

			z2 = z2 / 3;
			cont4++;
		}
	}

	if (cont > 0) {
		printf("    y   %d\n", cont);
		printf("** %.0f = %d **\n\n", a, z * 2);
		if (a == z * 2)
			printf("** y = %d **\n\n", cont);
	} else if (cont > 0 && cont2 > 0) {
		printf("    y   %d\n", cont2);
		printf("** %.0f = %d **\n\n", a, z * 3);
		if (a == z * 3)
			printf("** y = %d **\n\n", cont2);
	}

	if (cont > 0 && cont3 > 0) {
		printf("    %dy   %d\n", cont3, cont);
		printf("** %d = %d **\n\n", z2 * 2, z * 2);
		if (z2 * 2 == z * 2) {
			printf("** %dy = %d **\n\n", cont3, cont);
			printf("** y = %d/%d **\n", cont, cont3);
		}

	} else if (cont2 > 0 && cont4 > 0) {
		printf("    %dy   %d\n", cont4, cont);
		printf("** %d = %d **\n\n", z2 * 2, z * 2);
		if (z2 * 2 == z * 2) {
			printf("** %dy = %d **\n\n", cont4, cont);
			printf("** y = %d/%d **\n", cont, cont4);
		}
	} else if (cont > 0 && cont4 > 0) {
		printf("    %dy   %d\n", cont4, cont);
		printf("** %d = %d **\n\n", z2 * 2, z * 2);
		if (z2 * 2 == z * 2) {
			printf("** %dy = %d **\n\n", cont4, cont);
			printf("** y = %d/%d **\n", cont, cont4);
		}
	}
}
char sair() {

	char resp;

	printf("Deseja calcular outro limite? s ou n: ");
	fflush(stdin);
	scanf("%c", &resp);

	printf("\n");

	return (resp);
}

int main() {
	setbuf(stdout, NULL);

	int tip;

	printf("** Calculadora de Limites **\n\n");

	do {

		printf("Digite o Tipo de funcao envolvida: ");
		printf("\n\n");
		printf(
				" 1 - Primeiro Grau\n 2 - Quadratica ou Superior\n 3 - Racional\n 4 - Irracional\n 5 - Exponencial\n 6 - Logaritmica\n\n");
		tip = 0;

		while (tip != 1 && tip != 2 && tip != 3 && tip != 4 && tip != 5 && tip
				!= 6) {

			printf("Opcao: ");
			fflush(stdin);
			scanf("%d", &tip);

			if (tip != 1 && tip != 2 && tip != 3 && tip != 4 && tip != 5 && tip
					!= 6)
				printf("Tipo incorreto, digite de novo.\n\n");
		}
		if (tip == 1) {
			limite1();
		} else if (tip == 2) {
			limiteinf();
		} else if (tip == 3) {
			limiterac();
		} else if (tip == 4) {
			limiteirac();
		} else if (tip == 5) {
			limiteexp();
		} else if (tip == 6) {
			limitelog();
		}

	} while (sair() == 's');

	printf("\n");
	printf("Voce saiu do programa.");

	return 0;
}
