# Projeto Prj_MultiplicaMatrizes_Recursivo (C) ✖️

> **Multiplicação de matrizes recursiva**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Multiplica duas matrizes de qualquer tamanho alocadas dinamicamente, trocando os três `for` aninhados da multiplicação por **uma função recursiva** que controla os índices `i`, `j` e `k`. Verifica antes se a multiplicação é possível (colunas de A = linhas de B).

## 🎯 Conceitos trabalhados

- Matrizes dinâmicas com `int **`, `malloc` e `calloc`
- Recursão substituindo laços aninhados
- Regra de compatibilidade das dimensões
- Liberação de memória linha por linha

## 🧠 Como funciona

```c
// Função auxiliar recursiva para multiplicar matrizes
void multiplicarRec(int **A, int **B, int **C,
                   int i, int j, int k,
                   int linhasA, int colunasA, int linhasB, int colunasB) {
    if (i >= linhasA) return;
    if (j >= colunasB) {
        multiplicarRec(A, B, C, i + 1, 0, 0, linhasA, colunasA, linhasB, colunasB);
        return;
    }
    if (k < linhasB) {
        C[i][j] += A[i][k] * B[k][j];
        multiplicarRec(A, B, C, i, j, k + 1, linhasA, colunasA, linhasB, colunasB);
        return;
    }
    multiplicarRec(A, B, C, i, j + 1, 0, linhasA, colunasA, linhasB, colunasB);
}
```

A função imita três laços:

| Laço | Índice | O que a recursão faz |
| --- | --- | --- |
| Mais interno | `k` | Soma `A[i][k] * B[k][j]` em `C[i][j]` e chama com `k + 1` |
| Do meio | `j` | Quando `k` termina, chama com `j + 1` e `k = 0` |
| Mais externo | `i` | Quando `j` termina, chama com `i + 1` e `j = k = 0` |

A matriz C é criada com `calloc`, que já zera os valores; isso é essencial, porque a função faz `C[i][j] +=`.

As dimensões são lidas primeiro (linhas e colunas de A, depois de B), seguidas dos elementos de A e de B, linha por linha.

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

## ⚠️ Pontos de atenção

- Cada elemento de C gera uma chamada recursiva a mais na pilha. Para matrizes grandes (centenas de linhas), a profundidade da recursão pode estourar a pilha (*stack overflow*); é um bom ponto para comparar com a versão com laços.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_MultiplicaMatrizes_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_MultiplicaMatrizes_Recursivo`:

```bash
gcc src/Prj_MultiplicaMatrizes_Recursivo.c -o Prj_MultiplicaMatrizes_Recursivo
./Prj_MultiplicaMatrizes_Recursivo
```

No Windows, rode `Prj_MultiplicaMatrizes_Recursivo.exe` (ou `.\Prj_MultiplicaMatrizes_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_MultiplicaMatrizes_Recursivo
│
├── 📁 src
│   └── Prj_MultiplicaMatrizes_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_MultiplicaMatrizes_Recursivo_v2](../Prj_MultiplicaMatrizes_Recursivo_v2): Multiplicação de matrizes recursiva (v2)
- [Prj_IntercalarVetor](../Prj_IntercalarVetor): Intercalar vetores com malloc
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
