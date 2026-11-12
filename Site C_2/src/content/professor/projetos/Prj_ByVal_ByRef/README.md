# Projeto Prj_ByVal_ByRef (C) 🔗

> **Passagem por valor e por referência**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Compara duas funções que tentam somar 1 a uma variável: uma recebe uma **cópia** do valor (por valor) e não altera o original; a outra recebe o **endereço** (por referência) e altera.

## 🎯 Conceitos trabalhados

- Passagem por valor
- Passagem por referência com ponteiro (`int *x`)
- Desreferência `(*x)++`
- Escopo de variáveis

## 🧠 Como funciona

```c
void incrementarPorValor(int x) {
    x++;
    // O escopo desta variável vale somente dentro da função.
    // Você pode inclusive chamar esta variável de y ou de z.
}
```

```c
void incrementarPorReferencia(int *x) {
    (*x)++;
}
```

Em `incrementarPorValor`, o `x` é uma variável nova que nasce com uma cópia de `numero` e some quando a função termina. Em `incrementarPorReferencia`, o `x` guarda o endereço de `numero`, e `(*x)++` muda o valor que está lá. Os parênteses importam: `*x++` andaria com o ponteiro em vez de somar 1 ao valor.

## 💻 Exemplo de execução

```text
Valor original: 5
Valor modificado: 6
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ByVal_ByRef` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ByVal_ByRef`:

```bash
gcc src/Prj_ByVal_ByRef.c -o Prj_ByVal_ByRef
./Prj_ByVal_ByRef
```

No Windows, rode `Prj_ByVal_ByRef.exe` (ou `.\Prj_ByVal_ByRef.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_ByVal_ByRef
│
├── 📁 src
│   └── Prj_ByVal_ByRef.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Funcoes_Ponteiros](../Prj_Funcoes_Ponteiros): Funções com ponteiros: troca e zera
- [Prj_Memoria](../Prj_Memoria): Endereço de memória
- [Prj_Struct_Pessoa_Ponteiro](../Prj_Struct_Pessoa_Ponteiro): Struct Pessoa por ponteiro

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
