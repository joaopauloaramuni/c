# Projeto Prj_Aramuni_Recursivo (C) 🧙

> **Aramuni Recursivo: 12 funções em uma linha**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Um menu com **12 funções recursivas escritas em uma única linha cada**, usando operador ternário e operador vírgula: palíndromo, tamanho, cópia, concatenação, inversão e limpeza de string, contagem de letra, fatorial, Fibonacci, MDC, potência e Torre de Hanói.

É a versão atualizada do [`Aramuni.c`](https://github.com/joaopauloaramuni/c/blob/main/PROJETOS/Aramuni.c), escrito em 2011 quando eu era aluno de Estruturas de Dados na FUMEC, com `fgets` no lugar do antigo `gets` (removido do padrão C11).

## 🎯 Conceitos trabalhados

- Recursão em uma linha com `?:`
- Operador vírgula para várias ações em uma expressão
- Macros `#define` como atalho (`A`, `B`, `C` da Torre de Hanói)
- Aritmética de ponteiros em strings
- Menu com `do-while` + `switch`

## 🧠 Como funciona

```c
int palindrome(char str[100], int tam) {
    return (tam <= 1) || (*str == str[tam - 1] && palindrome(str + 1, tam - 2));
}
```

```c
int strLen(char *orig, int cont) {
    return (*orig++) ? cont++, strLen(orig, cont) : cont;
}
```

```c
int mdc(int a, int b) {
    return (a == 0) ? b : ((b == 0) ? a : mdc(b, a % b));
}
```

```c
void hanoi(int disc, char orig, char dest, char aux) {
    (disc != 1) ? A, C, B : C;
}
```

| Opção | Função | Ideia recursiva |
| --- | --- | --- |
| 1 | `palindrome` | Pontas iguais e o miolo também é palíndromo |
| 2 | `strLen` | Conta 1 e anda o ponteiro até o `\0` |
| 3 | `strCpy` | Copia um caractere e chama para o próximo |
| 4 | `strCat` | Escreve a segunda string a partir da posição `p` |
| 5 | `strInverte` | Vai até o fim da string e copia voltando |
| 6 | `strLimpa` | Troca cada caractere por espaço |
| 7 | `contLetra` | Soma 1 a cada ocorrência da letra |
| 8 | `fatorial` | `n * fatorial(n - 1)` |
| 9 | `fibonacci` | `fib(n - 1) + fib(n - 2)` |
| 10 | `mdc` | Algoritmo de Euclides: `mdc(b, a % b)` |
| 11 | `powExpo` | `base * powExpo(base, expo - 1)` |
| 12 | `hanoi` | Move `n - 1` discos, o maior, e de novo `n - 1` |

Na Torre de Hanói, as macros deixam a função quase ilegível de propósito: `(disc != 1) ? A, C, B : C;` vira "move `n - 1` para o auxiliar, move o disco, move `n - 1` para o destino". O número de movimentos é `2^n - 1`.

## 💻 Exemplo de execução

```text
Menu
1-Palíndrome
2-Tamanho da Palavra
3-Copiar Palavra
4-Concatenar Palavras
5-Inverter Palavra
6-Limpar Palavra
7-Ocorrência de Letra no Texto
8-Fatorial
9-Fibonacci
10-MDC
11-Exponencial
12-Hanoi
0-Sair

Digite a opção: 8

Digite um número: 5
Fatorial de 5 = 120

(menu)

Digite a opção: 10

Digite um número: 12
Digite outro número: 18
MDC de 12 e 18 = 6

(menu)

Digite a opção: 12

Digite o número de discos: 3

Move disco 1 de A para B
Move disco 2 de A para C
Move disco 1 de B para C
Move disco 3 de A para B
Move disco 1 de C para A
Move disco 2 de C para B
Move disco 1 de A para B

Número de movimentos ótimos: 7

(menu)

Digite a opção: 0

Fim da Aplicação.
```

## ⚠️ Pontos de atenção

- O código usa `fflush(stdin)` para descartar o *Enter* que sobra depois do `scanf`. Isso funciona no Windows (MinGW, usado no laboratório), mas o padrão C não define `fflush` para entrada: no Linux e no macOS o `fgets` lê esse *Enter* sobrando e as opções de texto (1 a 7) recebem uma palavra vazia. Para rodar em qualquer sistema, troque cada `fflush(stdin);` depois de um `scanf` por `while (getchar() != '\n');`. As opções numéricas (8 a 12) funcionam em todos os sistemas.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Aramuni_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Aramuni_Recursivo`:

```bash
gcc src/Prj_Aramuni_Recursivo.c -o Prj_Aramuni_Recursivo
./Prj_Aramuni_Recursivo
```

No Windows, rode `Prj_Aramuni_Recursivo.exe` (ou `.\Prj_Aramuni_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**. O OnlineGDB roda em Linux: veja os **Pontos de atenção**.

## 📂 Estrutura do projeto

```text
📁 Prj_Aramuni_Recursivo
│
├── 📁 src
│   └── Prj_Aramuni_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Fatorial_Recursivo](../Prj_Fatorial_Recursivo): Fatorial recursivo
- [Prj_Palindromo_Recursivo](../Prj_Palindromo_Recursivo): Palíndromo recursivo
- [Prj_Ternario](../Prj_Ternario): Operador ternário

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
