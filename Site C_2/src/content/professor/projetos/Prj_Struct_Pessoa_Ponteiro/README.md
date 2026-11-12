# Projeto Prj_Struct_Pessoa_Ponteiro (C) 👉

> **Struct Pessoa por ponteiro**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

A função `SetPessoa` recebe um **ponteiro** para `Pessoa` e preenche os campos da struct original, mostrando as duas formas de acesso: `(*P).Idade` e `P->Peso`.

## 🎯 Conceitos trabalhados

- Ponteiro para struct como parâmetro de saída
- `(*P).campo` × `P->campo`

## 🧠 Como funciona

```c
// Nesta função o parâmetro P é um ponteiro para uma struct
void SetPessoa(Pessoa *P, int idade, float peso, float altura) {
    (*P).Idade = idade;  // o campo pode ser acessado desta forma
    P->Peso = peso;      // ou desta
    P->Altura = altura;
}
```

Os parênteses em `(*P).Idade` são obrigatórios: o `.` tem precedência maior que o `*`, e `*P.Idade` tentaria acessar o campo `Idade` de um ponteiro. Por isso todo mundo usa o `->`.

## 💻 Exemplo de execução

```text
Idade: 15  Peso: 70.50 Altura: 1.75
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Pessoa_Ponteiro` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Pessoa_Ponteiro`:

```bash
gcc src/Prj_Struct_Pessoa_Ponteiro.c -o Prj_Struct_Pessoa_Ponteiro
./Prj_Struct_Pessoa_Ponteiro
```

No Windows, rode `Prj_Struct_Pessoa_Ponteiro.exe` (ou `.\Prj_Struct_Pessoa_Ponteiro.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Pessoa_Ponteiro
│
├── 📁 src
│   └── Prj_Struct_Pessoa_Ponteiro.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Pessoa_Return](../Prj_Struct_Pessoa_Return): Struct Pessoa como retorno
- [Prj_Struct_Livro_Ponteiro](../Prj_Struct_Livro_Ponteiro): Struct Livro por ponteiro
- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
