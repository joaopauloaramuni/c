# Projeto Prj_Matriz (C) ▦

> **Leitura e exibição de matriz**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê uma matriz 3×3 elemento por elemento e a mostra organizada em linhas e colunas.

## 🎯 Conceitos trabalhados

- Matriz com tamanho definido por `#define`
- Leitura com `scanf` em laços aninhados
- Tabulação `\t` para alinhar colunas

## 🧠 Como funciona

```c
int main(void) {
    // Declaração da matriz bidimensional
    int matriz[LINHAS][COLUNAS];

    // Preenchimento da matriz
    printf("Digite os elementos da matriz (%d x %d):\n", LINHAS, COLUNAS);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibição da matriz
    printf("\nMatriz digitada:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

Usar `LINHAS` e `COLUNAS` com `#define` facilita mudar o tamanho da matriz: basta trocar os dois números no topo do arquivo.

## 💻 Exemplo de execução

```text
Digite os elementos da matriz (3 x 3):
Elemento [0][0]: 1
Elemento [0][1]: 2
Elemento [0][2]: 3
Elemento [1][0]: 4
Elemento [1][1]: 5
Elemento [1][2]: 6
Elemento [2][0]: 7
Elemento [2][1]: 8
Elemento [2][2]: 9

Matriz digitada:
1	2	3	
4	5	6	
7	8	9
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Matriz` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Matriz`:

```bash
gcc src/Prj_Matriz.c -o Prj_Matriz
./Prj_Matriz
```

No Windows, rode `Prj_Matriz.exe` (ou `.\Prj_Matriz.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Matriz
│
├── 📁 src
│   └── Prj_Matriz.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Array_Exer2](../Prj_Array_Exer2): Exercício: soma de uma matriz 3x3
- [Prj_Tarefa_4](../Prj_Tarefa_4): Tarefa 4: vetores e matrizes
- [Prj_MultiplicaMatrizes_Recursivo](../Prj_MultiplicaMatrizes_Recursivo): Multiplicação de matrizes recursiva

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
