# Projeto Prj_Struct_Livro_Ponteiro (C) 📙

> **Struct Livro por ponteiro**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Terceira versão do exemplo do livro: `printLivro` recebe um **ponteiro** para a struct e acessa os campos com `->`.

## 🎯 Conceitos trabalhados

- Ponteiro para struct
- Operador seta `->`
- Passagem do endereço com `&Livro1`

## 🧠 Como funciona

```c
void printLivro(struct Livro *livro) {
    printf("Livro titulo : %s\n", livro->titulo);
    printf("Livro autor : %s\n", livro->autor);
    printf("Livro assunto : %s\n", livro->assunto);
    printf("Livro id_livro : %d\n", livro->id_livro);
}
```

`livro->titulo` é um atalho para `(*livro).titulo`. A função recebe só um endereço (8 bytes em sistemas de 64 bits) em vez de copiar a struct inteira.

## 💻 Exemplo de execução

```text
Livro titulo : Título genérico
Livro autor : Autor
Livro assunto : Um livro genérico
Livro id_livro : 123
Livro titulo : Outro título genérico
Livro autor : Autor 2
Livro assunto : Outro livro genérico
Livro id_livro : 456
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Livro_Ponteiro` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Livro_Ponteiro`:

```bash
gcc src/Prj_Struct_Livro_Ponteiro.c -o Prj_Struct_Livro_Ponteiro
./Prj_Struct_Livro_Ponteiro
```

No Windows, rode `Prj_Struct_Livro_Ponteiro.exe` (ou `.\Prj_Struct_Livro_Ponteiro.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Livro_Ponteiro
│
├── 📁 src
│   └── Prj_Struct_Livro_Ponteiro.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Livro_Arg](../Prj_Struct_Livro_Arg): Struct Livro como argumento
- [Prj_Struct_Pessoa_Ponteiro](../Prj_Struct_Pessoa_Ponteiro): Struct Pessoa por ponteiro

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
