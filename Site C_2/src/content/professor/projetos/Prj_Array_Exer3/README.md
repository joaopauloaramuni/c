# Projeto Prj_Array_Exer3 (C) 🧊

> **Exercício: média de uma matriz 3D**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calcula a média dos 8 elementos de uma **matriz tridimensional** 2×2×2 usando três laços aninhados e um contador.

## 🎯 Conceitos trabalhados

- Matriz com três dimensões
- Três `for` aninhados
- Contador e conversão `(double)`

## 🧠 Como funciona

```c
int main(void) {
    int matriz[2][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
    int soma = 0;
    int contador = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                soma = soma + matriz[i][j][k];
                contador++;
            }
        }
    }

    double media = (double) soma / contador;

    printf("Média dos elementos da matriz tridimensional: %.2lf\n", media);

    return 0;
}
```

Dá para pensar na matriz `[2][2][2]` como duas matrizes 2×2 empilhadas. O contador chega a `8` e a média é `36 / 8 = 4.50`.

## 💻 Exemplo de execução

```text
Média dos elementos da matriz tridimensional: 4.50
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Array_Exer3` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Array_Exer3`:

```bash
gcc src/Prj_Array_Exer3.c -o Prj_Array_Exer3
./Prj_Array_Exer3
```

No Windows, rode `Prj_Array_Exer3.exe` (ou `.\Prj_Array_Exer3.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Array_Exer3
│
├── 📁 src
│   └── Prj_Array_Exer3.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Array_Exer2](../Prj_Array_Exer2): Exercício: soma de uma matriz 3x3
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
