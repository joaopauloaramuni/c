# Projeto Prj_Variaveis (C) 📦

> **Variáveis e constantes**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra as três formas de guardar um valor que aparecem logo no início da disciplina: uma **variável comum** (`int idade`), uma **variável constante** (`const int MAX_NUM`) e uma **constante de pré-processador** (`#define PI`).

## 🎯 Conceitos trabalhados

- Declaração e inicialização de variáveis
- Modificador `const`
- Macro `#define`
- Especificadores `%d` e `%f` do `printf`

## 🧠 Como funciona

```c
int main(void) {

    int idade = 26;
    const int MAX_NUM = 100;

    printf("Minha variável int comum = %d\n", idade);
    printf("Minha variável int constante = %d\n", MAX_NUM);
    printf("Minha constante = %f\n", PI);

    // MAX_NUM = 99;

    return EXIT_SUCCESS;
}
```

O `#define PI 3.14159` não ocupa memória: o pré-processador troca cada `PI` pelo texto `3.14159` **antes** da compilação. Já o `const int MAX_NUM = 100` é uma variável de verdade, só que o compilador recusa qualquer atribuição a ela. Para ver isso, descomente a linha `// MAX_NUM = 99;` e compile: o GCC acusa `assignment of read-only variable`.

## 💻 Exemplo de execução

```text
Minha variável int comum = 26
Minha variável int constante = 100
Minha constante = 3.141590
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Variaveis` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Variaveis`:

```bash
gcc src/Prj_Variaveis.c -o Prj_Variaveis
./Prj_Variaveis
```

No Windows, rode `Prj_Variaveis.exe` (ou `.\Prj_Variaveis.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Variaveis
│
├── 📁 src
│   └── Prj_Variaveis.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_HelloWorld](../Prj_HelloWorld): Hello World
- [Prj_Typedef](../Prj_Typedef): typedef
- [Prj_Memoria](../Prj_Memoria): Endereço de memória

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
