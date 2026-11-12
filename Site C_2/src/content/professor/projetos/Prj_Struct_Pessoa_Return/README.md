# Projeto Prj_Struct_Pessoa_Return (C) ↩️

> **Struct Pessoa como retorno**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Faz o mesmo que o [Prj_Struct_Pessoa_Ponteiro](../Prj_Struct_Pessoa_Ponteiro), mas a função `SetPessoa` **devolve** uma struct preenchida em vez de receber um ponteiro.

## 🎯 Conceitos trabalhados

- Função que retorna struct
- Atribuição do retorno a uma variável struct

## 🧠 Como funciona

```c
Pessoa SetPessoa(int idade, float peso, float altura) {
    Pessoa P;
    P.Idade = idade;
    P.Peso = peso;
    P.Altura = altura;
    return P; // retorna a struct contendo os dados passados por parâmetro
}
```

Comparando os dois projetos: com ponteiro, a função altera uma struct que já existe; com retorno, ela cria uma struct local, preenche e devolve uma cópia. As duas formas são válidas.

## 💻 Exemplo de execução

```text
Idade: 15  Peso: 60.50 Altura: 1.75
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Pessoa_Return` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Pessoa_Return`:

```bash
gcc src/Prj_Struct_Pessoa_Return.c -o Prj_Struct_Pessoa_Return
./Prj_Struct_Pessoa_Return
```

No Windows, rode `Prj_Struct_Pessoa_Return.exe` (ou `.\Prj_Struct_Pessoa_Return.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Pessoa_Return
│
├── 📁 src
│   └── Prj_Struct_Pessoa_Return.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Pessoa_Ponteiro](../Prj_Struct_Pessoa_Ponteiro): Struct Pessoa por ponteiro
- [Prj_Struct_Pessoa_Arg](../Prj_Struct_Pessoa_Arg): Struct Pessoa com typedef

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
