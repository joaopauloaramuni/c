# Projeto Prj_Array_Exer2 (C) 🔲

> **Exercício: soma de uma matriz 3x3**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Soma todos os elementos de uma matriz 3×3 já inicializada (`1` a `9`), percorrendo linhas e colunas com dois `for` aninhados.

## 🎯 Conceitos trabalhados

- Matriz bidimensional
- Laços `for` aninhados
- Acumulador

## 🧠 Como funciona

```c
int main(void) {
    int matriz[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int soma = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma = soma + matriz[i][j];
        }
    }

    printf("Soma dos elementos da matriz: %d\n", soma);

    return 0;
}
```

O `i` percorre as linhas e o `j` as colunas. Para cada linha, o laço de dentro passa pelas três colunas: são 9 somas no total, e o resultado é `45`.

## 💻 Exemplo de execução

```text
Soma dos elementos da matriz: 45
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Array_Exer2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Array_Exer2`:

```bash
gcc src/Prj_Array_Exer2.c -o Prj_Array_Exer2
./Prj_Array_Exer2
```

No Windows, rode `Prj_Array_Exer2.exe` (ou `.\Prj_Array_Exer2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Array_Exer2
│
├── 📁 src
│   └── Prj_Array_Exer2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz
- [Prj_Array_Exer3](../Prj_Array_Exer3): Exercício: média de uma matriz 3D

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
