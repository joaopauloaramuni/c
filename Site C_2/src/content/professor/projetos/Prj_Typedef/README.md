# Projeto Prj_Typedef (C) 🏷️

> **typedef**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Cria um **apelido** (`MeuInteiro`) para o tipo `int` com `typedef` e o usa para declarar uma variável.

## 🎯 Conceitos trabalhados

- Palavra-chave `typedef`
- Apelidos de tipo
- Escopo global

## 🧠 Como funciona

```c
int main(void) {
    // Usando o novo tipo criado com typedef
    MeuInteiro numero = 13;

    printf("Número: %d\n", numero);

    return 0;
}
```

`typedef int MeuInteiro;` não cria um tipo novo, só dá outro nome a um tipo que já existe. O uso mais comum aparece nos projetos de struct, como em `typedef struct { ... } Pessoa;`, que dispensa escrever `struct` toda vez.

## 💻 Exemplo de execução

```text
Número: 13
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Typedef` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Typedef`:

```bash
gcc src/Prj_Typedef.c -o Prj_Typedef
./Prj_Typedef
```

No Windows, rode `Prj_Typedef.exe` (ou `.\Prj_Typedef.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Typedef
│
├── 📁 src
│   └── Prj_Typedef.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Pessoa_Arg](../Prj_Struct_Pessoa_Arg): Struct Pessoa com typedef
- [Prj_Enum](../Prj_Enum): Enum: dias da semana

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
