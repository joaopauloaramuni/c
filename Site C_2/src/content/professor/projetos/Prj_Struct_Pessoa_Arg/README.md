# Projeto Prj_Struct_Pessoa_Arg (C) 🧍

> **Struct Pessoa com typedef**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Cria o tipo `Pessoa` com `typedef struct`, monta um vetor de 10 pessoas (`Povo`) e mostra que uma struct inteira pode ser **copiada com uma única atribuição** (`P2 = Povo[4];`).

## 🎯 Conceitos trabalhados

- `typedef struct`
- Vetor de structs
- Atribuição de struct inteira
- Struct como parâmetro

## 🧠 Como funciona

```c
int main(void) {
    Pessoa Joao, P2;
    Pessoa Povo[10];

    Joao.Idade = 15;
    Joao.Peso = 60.5;
    Joao.Altura = 1.75;

    Povo[4].Idade = 23;
    Povo[4].Peso = 75.3;
    Povo[4].Altura = 1.89;

    /*Outra vantagem de utilizar struct é a possibilidade de atribuir os dados de uma
    struct para outra, com apenas um comando de atribuição, como neste exemplo: */
    P2 = Povo[4];
    P2.Idade++;

    // chama a função que recebe a struct como parâmetro
    ImprimePessoa(Joao);
    ImprimePessoa(Povo[4]);
    ImprimePessoa(P2);
    return 0;
}
```

Depois de `P2 = Povo[4];`, `P2` é uma cópia independente: o `P2.Idade++` muda só a cópia, e `Povo[4]` continua com 23 anos. Isso aparece nas duas últimas linhas da saída (23 e 24).

## 💻 Exemplo de execução

```text
Idade: 15  Peso: 60.50 Altura: 1.75
Idade: 23  Peso: 75.30 Altura: 1.89
Idade: 24  Peso: 75.30 Altura: 1.89
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Struct_Pessoa_Arg` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Struct_Pessoa_Arg`:

```bash
gcc src/Prj_Struct_Pessoa_Arg.c -o Prj_Struct_Pessoa_Arg
./Prj_Struct_Pessoa_Arg
```

No Windows, rode `Prj_Struct_Pessoa_Arg.exe` (ou `.\Prj_Struct_Pessoa_Arg.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Struct_Pessoa_Arg
│
├── 📁 src
│   └── Prj_Struct_Pessoa_Arg.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Struct_Pessoa_Ponteiro](../Prj_Struct_Pessoa_Ponteiro): Struct Pessoa por ponteiro
- [Prj_Struct_Pessoa_Return](../Prj_Struct_Pessoa_Return): Struct Pessoa como retorno
- [Prj_Typedef](../Prj_Typedef): typedef

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
