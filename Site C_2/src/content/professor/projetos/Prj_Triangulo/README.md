# Projeto Prj_Triangulo (C) 🎄

> **Exercício de revisão: árvore de Natal**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução do **Exercício de Revisão – Árvore de Natal**: desenha padrões de asteriscos no console a partir do número de linhas informado. São três desenhos: o triângulo, o triângulo com as bordas trocadas por `#` e, como desafio extra, o losango.

📄 Enunciado: [Exercício de Revisão (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Exerc%C3%ADcio%20de%20Revis%C3%A3o.pdf)

## 🎯 Conceitos trabalhados

- Laços `for` aninhados
- Relação entre linha e quantidade de caracteres (`2 * i - 1`)
- Funções `void` com parâmetro

## 🧠 Como funciona

```c
void exercicio1(int linhas) {
    // Exibe o padrão de asteriscos em forma de triângulo
    printf("Padrão de asteriscos:\n");
    for (int i = 1; i <= linhas; i++) {
        //linhas = 5
        // Loop para exibir os espaços em branco antes dos asteriscos
        for (int j = 1; j <= linhas - i; j++) {
            printf(" ");
        }
        // Loop para exibir os asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}
```

```c
void exercicio2(int linhas) {
    // Exibe o padrão de asteriscos em forma de triângulo
    printf("Padrão de asteriscos:\n");
    for (int i = 1; i <= linhas; i++) {
        // Loop para exibir os espaços em branco antes dos asteriscos
        for (int j = 1; j <= linhas - i; j++) {
            printf(" ");
        }
        // Loop para exibir os caracteres nas extremidades e os asteriscos internos
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("#");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}
```

Para a linha `i` de um triângulo com `linhas` linhas:

| O que imprimir | Quantidade |
| --- | --- |
| Espaços antes | `linhas - i` |
| Asteriscos | `2 * i - 1` |

No `exercicio2`, o primeiro (`k == 1`) e o último (`k == 2 * i - 1`) caractere de cada linha viram `#`. O `exercicio3` desenha a metade de cima e repete a mesma lógica de baixo para cima para formar o losango.

## 💻 Exemplo de execução

```text
Digite o número de linhas (maior que 0): 5
Padrão de asteriscos:
    *
   ***
  *****
 *******
*********
Padrão de asteriscos:
    #
   #*#
  #***#
 #*****#
#*******#
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Triangulo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Triangulo`:

```bash
gcc src/Prj_Triangulo.c -o Prj_Triangulo
./Prj_Triangulo
```

No Windows, rode `Prj_Triangulo.exe` (ou `.\Prj_Triangulo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Triangulo
│
├── 📁 src
│   └── Prj_Triangulo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_For](../Prj_For): Laço for
- [Prj_Tarefa_2](../Prj_Tarefa_2): Tarefa 2: laços, funções e menu de pagamento

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
