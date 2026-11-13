# Projeto Prj_Tarefa_2 (C) 🛒

> **Tarefa 2: laços, funções e menu de pagamento**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução da **Tarefa 2**, com uma função por exercício, chamadas em sequência pelo `main`:

1. Números pares múltiplos de 3 até 1000.
2. Soma e média de 10 inteiros.
3. Área de 4 cômodos de uma casa (e a área total).
4. Perímetro e área de um círculo com π = 3,14.
5. Formas de pagamento de uma loja (à vista com 10% de desconto, 2x sem juros ou de 3x a 10x com 3% de juros ao mês para compras acima de R$ 300,00), em loop até o valor `-999`.

📄 Enunciado: [Tarefa 2 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%202.pdf)

## 🎯 Conceitos trabalhados

- `for` com passo 2
- `#define` para a constante π
- `while (1)` com `break` e `continue`
- `switch` dentro de laço
- `fflush(stdout)` antes do `scanf`

## 🧠 Como funciona

```c
// Função para mostrar os números pares múltiplos de 3 até 1000
void mostrarNumerosParesMultiplosDeTres() {
    int cont = 0;
    printf("Números pares múltiplos de 3 até 1000:\n");
    for (int i = 2; i <= 1000; i += 2) {
        if (i % 3 == 0) {
            printf("%d ", i);
            cont++;
        }
    }
    printf("\nTotal de números pares múltiplos de 3: %d\n\n", cont);
}
```

```c
// Função para calcular o valor total das prestações ou à vista
void calcularPagamento(double totalGasto) {
    int opcaoPagamento;
    double valorFinal;

    while (1) {
        // Mostrar opções de pagamento
        printf("\nOpções de pagamento:\n");
        printf("1 - À Vista (com 10%% de desconto)\n");
        printf("2 - Parcelado 2x (preço da etiqueta)\n");
        printf("3 - Parcelado de 3x até 10x (3%% de juros ao mês, compras acima de R$300.00)\n");
        printf("Digite a opção desejada (ou -999 para encerrar): ");
        fflush(stdout);
        scanf("%d", &opcaoPagamento);

        if (opcaoPagamento == -999) {
            printf("Programa encerrado.\n");
            break;
        }

        // Calcular o valor final com base na opção de pagamento
        switch (opcaoPagamento) {
            case 1:
                valorFinal = totalGasto * 0.9; // À vista com 10% de desconto
                printf("Valor à vista com desconto: R$%.2lf\n", valorFinal);
                break;
            case 2:
                valorFinal = totalGasto; // Parcelado 2x (preço da etiqueta)
                printf("Valor parcelado em 2x: 2x R$%.2lf\n", valorFinal / 2);
                break;
            case 3:
                // Parcelado de 3x até 10x com 3% de juros ao mês (para compras acima de R$300.00)
                if (totalGasto > 300.00) {
                    int numParcelas;
                    printf("Digite o número de parcelas (3 a 10): ");
                    fflush(stdout);
                    scanf("%d", &numParcelas);

                    if (numParcelas >= 3 && numParcelas <= 10) {
                        valorFinal = totalGasto * (1 + 0.03 * numParcelas);
                        printf("Valor parcelado em %dx: %dx R$%.2lf\n", numParcelas, numParcelas, valorFinal / numParcelas);
                        break;
                    } else {
                        printf("Escolha nova forma de pagamento. ");
                        continue;
                    }
                } else {
                    printf("Escolha nova forma de pagamento. ");
                    continue;
                }
            default:
                printf("Opção inválida. ");
        }
    }
}
```

No exercício 1, o `for` já anda de 2 em 2 (`i += 2`), então só testa os pares e basta verificar `i % 3 == 0`. São 166 números. No exercício 5, o `continue` volta direto para o começo do `while (1)` e mostra as opções de novo, que é o que o enunciado pede em "Escolha nova forma de pagamento".

## 💻 Exemplo de execução

```text
Números pares múltiplos de 3 até 1000:
6 12 18 24 30 36 42 48 54 60 ... 984 990 996 
Total de números pares múltiplos de 3: 166

Digite 10 números inteiros:
1 2 3 4 5 6 7 8 9 10
Soma: 55
Média: 5.00
Digite a largura do cômodo 1: 3
Digite o comprimento do cômodo 1: 4
Área do cômodo 1: 12.00 metros quadrados
Digite a largura do cômodo 2: 2
Digite o comprimento do cômodo 2: 5
Área do cômodo 2: 10.00 metros quadrados
Digite a largura do cômodo 3: 3
Digite o comprimento do cômodo 3: 3
Área do cômodo 3: 9.00 metros quadrados
Digite a largura do cômodo 4: 4
Digite o comprimento do cômodo 4: 2
Área do cômodo 4: 8.00 metros quadrados
A área total é: 39.00Digite o valor do raio do círculo: 2
Perímetro do círculo: 12.56
Área do círculo: 12.56
Digite o total gasto (ou -999 para encerrar): 500

Opções de pagamento:
1 - À Vista (com 10% de desconto)
2 - Parcelado 2x (preço da etiqueta)
3 - Parcelado de 3x até 10x (3% de juros ao mês, compras acima de R$300.00)
Digite a opção desejada (ou -999 para encerrar): 1
Valor à vista com desconto: R$450.00

(opções de pagamento)
Digite a opção desejada (ou -999 para encerrar): 3
Digite o número de parcelas (3 a 10): 5
Valor parcelado em 5x: 5x R$115.00

(opções de pagamento)
Digite a opção desejada (ou -999 para encerrar): -999
Programa encerrado.
Digite o total gasto (ou -999 para encerrar): -999
Programa encerrado.
```

## ⚠️ Pontos de atenção

- Em `calcularSomaEMedia`, `soma / 10` é uma divisão **inteira** (os dois lados são `int`): para os números de 1 a 10 a média mostrada é `5.00`, e não `5.50`. Troque por `soma / 10.0`.
- Em `calcularAreaDosComodos`, `areatotal` não é inicializada. Em C, variável local sem valor inicial guarda "lixo" de memória; declare `double areatotal = 0;`.
- Os juros do parcelamento são simples (`1 + 0.03 * numParcelas`). Se a ideia for juros compostos, use `pow(1.03, numParcelas)` de `<math.h>`.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_2`:

```bash
gcc src/Prj_Tarefa_2.c -o Prj_Tarefa_2
./Prj_Tarefa_2
```

No Windows, rode `Prj_Tarefa_2.exe` (ou `.\Prj_Tarefa_2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_2
│
├── 📁 src
│   └── Prj_Tarefa_2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Tarefa_1](../Prj_Tarefa_1): Tarefa 1: funções com cálculos
- [Prj_Tarefa_3_1](../Prj_Tarefa_3_1): Tarefa 3.1: eleição de 2º turno
- [Prj_DoWhile_Menu](../Prj_DoWhile_Menu): Menu com do-while e switch

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
