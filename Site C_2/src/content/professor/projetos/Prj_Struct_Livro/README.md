# Projeto Prj_Struct_Livro (C) 📘

> **Struct Livro**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Define uma `struct Livro` com título, autor, assunto e id, preenche dois livros e imprime os campos de cada um.

## 🎯 Conceitos trabalhados

- Declaração de `struct`
- Acesso aos campos com `.`
- `strcpy` para preencher campos `char[]`

## 🧠 Como funciona

```c
int main(void) {

    struct Livro Livro1; // Declaramos Livro1 do tipo Livro
    struct Livro Livro2; // Declaramos Livro2 do tipo Livro

    // especificações do livro 1
    strcpy(Livro1.titulo, "Título genérico");
    strcpy(Livro1.autor, "Autor");
    strcpy(Livro1.assunto, "Um livro genérico");
    Livro1.id_livro = 123;

    // especificações do livro 2
    strcpy(Livro2.titulo, "Outro título genérico");
    strcpy(Livro2.autor, "Autor 2");
    strcpy(Livro2.assunto, "Outro livro genérico");
    Livro2.id_livro = 456;

    // mostrando as informações do livro 1
    printf("Livro 1 titulo : %s\n", Livro1.titulo);
    printf("Livro 1 autor : %s\n", Livro1.autor);
    printf("Livro 1 assunto : %s\n", Livro1.assunto);
    printf("Livro 1 id_livro : %d\n", Livro1.id_livro);

    // mostrando as informações do livro 2
    printf("Livro 2 titulo : %s\n", Livro2.titulo);
    printf("Livro 2 autor : %s\n", Livro2.autor);
    printf("Livro 2 assunto : %s\n", Livro2.assunto);
    printf("Livro 2 id_livro : %d\n", Livro2.id_livro);

    return 0;
}
```

Cada variável `struct Livro` tem a sua própria cópia de todos os campos. O código de impressão se repete para os dois livros; o [Prj_Struct_Livro_Arg](../Prj_Struct_Livro_Arg) resolve isso com uma função.

## 💻 Exemplo de execução

```text
Livro 1 titulo : Título genérico
Livro 1 autor : Autor
Livro 1 assunto : Um livro genérico
Livro 1 id_livro : 123
Livro 2 titulo : Outro título genérico
Livro 2 autor : Autor 2
Livro 2 assunto : Outro livro genérico
Livro 2 id_livro : 456
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Livro` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Livro`:

```bash
gcc src/Prj_Struct_Livro.c -o Prj_Struct_Livro
./Prj_Struct_Livro
```

No Windows, rode `Prj_Struct_Livro.exe` (ou `.\Prj_Struct_Livro.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Livro
│
├── 📁 src
│   └── Prj_Struct_Livro.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Livro_Arg](../Prj_Struct_Livro_Arg): Struct Livro como argumento
- [Prj_Struct_Livro_Ponteiro](../Prj_Struct_Livro_Ponteiro): Struct Livro por ponteiro
- [Prj_StrCpy](../Prj_StrCpy): Copiar strings com strcpy

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
