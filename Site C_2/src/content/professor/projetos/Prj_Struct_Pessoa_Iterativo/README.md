# Projeto Prj_Struct_Pessoa_Iterativo (C) 🧓

> **Pessoa mais velha (iterativo)**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Encontra a pessoa mais velha em um array de `Pessoa` (nome e idade) usando um laço `for`. Compare com a versão recursiva no [Prj_Struct_Pessoa_Recursivo](../Prj_Struct_Pessoa_Recursivo).

## 🎯 Conceitos trabalhados

- Array de structs inicializado com `{ }`
- Busca do máximo com laço
- Função que devolve struct

## 🧠 Como funciona

```c
// Função iterativa para encontrar a pessoa mais velha
Pessoa encontraMaisVelho(Pessoa Pessoas[], int n) {
    Pessoa maisVelho = Pessoas[0];

    for (int i = 1; i < n; i++) {
        if (Pessoas[i].idade > maisVelho.idade) {
            maisVelho = Pessoas[i];
        }
    }

    return maisVelho;
}
```

Começa supondo que a primeira pessoa é a mais velha e compara com as outras. Quando acha alguém mais velho, guarda a struct inteira em `maisVelho`.

## 💻 Exemplo de execução

```text
Pessoa mais velha: Maria, 35 anos
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Pessoa_Iterativo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Pessoa_Iterativo`:

```bash
gcc src/Prj_Struct_Pessoa_Iterativo.c -o Prj_Struct_Pessoa_Iterativo
./Prj_Struct_Pessoa_Iterativo
```

No Windows, rode `Prj_Struct_Pessoa_Iterativo.exe` (ou `.\Prj_Struct_Pessoa_Iterativo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Pessoa_Iterativo
│
├── 📁 src
│   └── Prj_Struct_Pessoa_Iterativo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Pessoa_Recursivo](../Prj_Struct_Pessoa_Recursivo): Pessoa mais velha (recursivo)
- [Prj_Maior_Menor](../Prj_Maior_Menor): Maior e menor de 10 números

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
