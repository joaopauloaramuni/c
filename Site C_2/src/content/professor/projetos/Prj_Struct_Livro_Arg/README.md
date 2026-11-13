# Projeto Prj_Struct_Livro_Arg (C) 📗

> **Struct Livro como argumento**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mesmo exemplo do [Prj_Struct_Livro](../Prj_Struct_Livro), agora com a função `printLivro`, que recebe um livro **por valor** e imprime os campos.

## 🎯 Conceitos trabalhados

- Struct como parâmetro de função (por valor)
- Protótipo de função com struct
- Reaproveitamento de código

## 🧠 Como funciona

```c
void printLivro(struct Livro livro) {
    printf("Livro titulo : %s\n", livro.titulo);
    printf("Livro autor : %s\n", livro.autor);
    printf("Livro assunto : %s\n", livro.assunto);
    printf("Livro id_livro : %d\n", livro.id_livro);
}
```

Passar a struct por valor copia **todos** os campos para a função: são 204 bytes por chamada (`50 + 50 + 100 + 4`). Para structs grandes, o [Prj_Struct_Livro_Ponteiro](../Prj_Struct_Livro_Ponteiro) passa só o endereço.

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
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Livro_Arg` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Livro_Arg`:

```bash
gcc src/Prj_Struct_Livro_Arg.c -o Prj_Struct_Livro_Arg
./Prj_Struct_Livro_Arg
```

No Windows, rode `Prj_Struct_Livro_Arg.exe` (ou `.\Prj_Struct_Livro_Arg.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Livro_Arg
│
├── 📁 src
│   └── Prj_Struct_Livro_Arg.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Livro](../Prj_Struct_Livro): Struct Livro
- [Prj_Struct_Livro_Ponteiro](../Prj_Struct_Livro_Ponteiro): Struct Livro por ponteiro

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
