# Projeto Prj_Struct_Pessoa_Recursivo (C) 👴

> **Pessoa mais velha (recursivo)**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Encontra a pessoa mais velha em um array de `struct Pessoa` usando recursão. É a versão recursiva do [Prj_Struct_Pessoa_Iterativo](../Prj_Struct_Pessoa_Iterativo).

## 🎯 Conceitos trabalhados

- Recursão sobre um array de structs
- Função que devolve uma struct
- Máximo recursivo

## 🧠 Como funciona

```c
// Função recursiva para encontrar a pessoa mais velha
Pessoa encontraMaisVelho(Pessoa Pessoas[], int n) {
    if (n == 1)
        return Pessoas[0];

    Pessoa maisVelhoRestante = encontraMaisVelho(Pessoas, n - 1);

    if (Pessoas[n - 1].idade > maisVelhoRestante.idade)
        return Pessoas[n - 1];
    else
        return maisVelhoRestante;
}
```

A pessoa mais velha entre `n` é a mais velha entre a última (`Pessoas[n - 1]`) e a mais velha das `n - 1` primeiras. Com uma pessoa só, ela é a resposta (caso base).

## 💻 Exemplo de execução

```text
Pessoa mais velha: Maria, 35 anos
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Pessoa_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Pessoa_Recursivo`:

```bash
gcc src/Prj_Struct_Pessoa_Recursivo.c -o Prj_Struct_Pessoa_Recursivo
./Prj_Struct_Pessoa_Recursivo
```

No Windows, rode `Prj_Struct_Pessoa_Recursivo.exe` (ou `.\Prj_Struct_Pessoa_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Pessoa_Recursivo
│
├── 📁 src
│   └── Prj_Struct_Pessoa_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Pessoa_Iterativo](../Prj_Struct_Pessoa_Iterativo): Pessoa mais velha (iterativo)
- [Prj_Struct_Pessoa_Return](../Prj_Struct_Pessoa_Return): Struct Pessoa como retorno

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
