# Projeto Prj_Array_Ex1 (C) 📚

> **Arrays: declaração e percurso**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Declara e inicializa um **array de inteiros** e um **array de strings** (os três Atléticos) e percorre os dois com `for` para imprimir os elementos.

## 🎯 Conceitos trabalhados

- Declaração e inicialização com `{ }`
- Índices começando em 0
- Array de strings como matriz de `char`

## 🧠 Como funciona

```c
int main(void) {
    // Exemplo de declaração e inicialização de um array de inteiros
    int numeros[5] = { 1, 2, 3, 4, 5 };
    // Exemplo de declaração e inicialização de um array de strings
    char clubes[][30] = { "Atlético Mineiro", "Atlético Paranaense",
            "Atlético de Madrid" };

    // Loop for para percorrer o array e imprimir seus elementos
    printf("Elementos do array de inteiros: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    // Loop for para percorrer o array de strings e imprimir os nomes dos clubes
    printf("\nNomes dos clubes: ");
    for (int i = 0; i < 3; i++) {
        printf("%s ", clubes[i]);
    }

    return 0;
}
```

`char clubes[][30]` é uma matriz de caracteres: o compilador conta as linhas (3) pela inicialização, e cada linha guarda até 29 letras mais o `\0` que fecha a string.

## 💻 Exemplo de execução

```text
Elementos do array de inteiros: 1 2 3 4 5 
Nomes dos clubes: Atlético Mineiro Atlético Paranaense Atlético de Madrid
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Array_Ex1` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Array_Ex1`:

```bash
gcc src/Prj_Array_Ex1.c -o Prj_Array_Ex1
./Prj_Array_Ex1
```

No Windows, rode `Prj_Array_Ex1.exe` (ou `.\Prj_Array_Ex1.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Array_Ex1
│
├── 📁 src
│   └── Prj_Array_Ex1.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Array_Ex2](../Prj_Array_Ex2): Arrays de strings
- [Prj_Array_Exer1](../Prj_Array_Exer1): Exercício: soma e média de um array

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
