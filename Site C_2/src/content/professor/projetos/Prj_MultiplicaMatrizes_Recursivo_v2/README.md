# Projeto Prj_MultiplicaMatrizes_Recursivo_v2 (C) ✖️

> **Multiplicação de matrizes recursiva (v2)**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Segunda versão do [Prj_MultiplicaMatrizes_Recursivo](../Prj_MultiplicaMatrizes_Recursivo): em vez de três índices, a função recursiva recebe **uma única posição** (`pos`) e calcula `i`, `j` e `k` a partir dela com divisão e resto.

## 🎯 Conceitos trabalhados

- Linearização de índices (`pos` → `i`, `j`, `k`)
- Recursão de cauda simples (`pos + 1`)
- Matrizes dinâmicas

## 🧠 Como funciona

```c
// Função recursiva única para multiplicar matrizes
void multiplicarUnicaRec(int **A, int **B, int **C,
                         int pos, int linhasA, int colunasA, int colunasB) {
    int total = linhasA * colunasB * colunasA;
    if (pos >= total) return;

    int i = pos / (colunasB * colunasA);
    int j = (pos / colunasA) % colunasB;
    int k = pos % colunasA;

    C[i][j] += A[i][k] * B[k][j];

    multiplicarUnicaRec(A, B, C, pos + 1, linhasA, colunasA, colunasB);
}
```

São `linhasA × colunasB × colunasA` multiplicações no total, numeradas de `0` até `total - 1`. Para cada `pos`:

```text
i = pos / (colunasB * colunasA)
j = (pos / colunasA) % colunasB
k = pos % colunasA
```

É a mesma ideia de converter um número em "dígitos" de bases diferentes. A recursão fica mais simples, mas faz uma chamada por multiplicação, então a pilha cresce ainda mais que na primeira versão.

## 💻 Exemplo de execução

```text
Digite a quantidade de linhas e colunas da matriz A:
2 3
Digite a quantidade de linhas e colunas da matriz B:
3 2
1 2 3
4 5 6
7 8
9 10
11 12

Matriz A:
   1    2    3 
   4    5    6 

Matriz B:
   7    8 
   9   10 
  11   12 

Matriz C = A x B:
  58   64 
 139  154
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_MultiplicaMatrizes_Recursivo_v2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_MultiplicaMatrizes_Recursivo_v2`:

```bash
gcc src/Prj_MultiplicaMatrizes_Recursivo_v2.c -o Prj_MultiplicaMatrizes_Recursivo_v2
./Prj_MultiplicaMatrizes_Recursivo_v2
```

No Windows, rode `Prj_MultiplicaMatrizes_Recursivo_v2.exe` (ou `.\Prj_MultiplicaMatrizes_Recursivo_v2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_MultiplicaMatrizes_Recursivo_v2
│
├── 📁 src
│   └── Prj_MultiplicaMatrizes_Recursivo_v2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_MultiplicaMatrizes_Recursivo](../Prj_MultiplicaMatrizes_Recursivo): Multiplicação de matrizes recursiva
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
