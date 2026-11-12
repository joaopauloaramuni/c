# Projeto Prj_Calculadora_Ponteiros (C) 🧮

> **Calculadora com ponteiros**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calculadora de quatro operações em que cada operação é um **procedimento** (`void`) que devolve o resultado por um ponteiro (`int *resultado`), em vez de usar `return`. A divisão trata o caso de divisão por zero.

## 🎯 Conceitos trabalhados

- Procedimentos com parâmetro de saída
- Ponteiros para `int` e `float`
- Conversão de tipo `(float)` na divisão
- Tratamento de divisão por zero

## 🧠 Como funciona

```c
// Procedimento que calcula a diferença entre dois números usando ponteiros
void diferenca(int *x, int *y, int *resultado) {
    *resultado = *x - *y;
}
```

```c
// Procedimento que calcula o quociente de dois números usando ponteiros
void quociente(int *x, int *y, float *resultado) {
    if (*y != 0) {
        *resultado = (float)*x / *y;
    } else {
        printf("Divisão por zero não é permitida!\n");
        *resultado = 0.0;
    }
}
```

Sem o `(float)` em `(float)*x / *y`, a divisão seria inteira: `7 / 2` daria `3` em vez de `3.50`.

## 💻 Exemplo de execução

> Saída depois de renomear a segunda função `soma` para `somaValor`.

```text
Digite o primeiro número: 7
Digite o segundo número: 2
Soma: 9
Diferença: 5
Produto: 14
Quociente: 3.50
```

## ⚠️ Pontos de atenção

- **O arquivo não compila como está.** Ele tem duas funções chamadas `soma`: `void soma(int *x, int *y, int *resultado)` e `int soma(int x, int y)`. C não tem **sobrecarga de funções** (C++ tem), e o GCC acusa `conflicting types for 'soma'`. Para compilar, apague ou renomeie a segunda (por exemplo, `somaValor`). Vale como exercício: explique por que C++ aceitaria o mesmo código.
- O `#include <stdio.h>` aparece duas vezes. Não causa erro (o cabeçalho tem proteção contra inclusão dupla), mas pode ser removido.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Calculadora_Ponteiros` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Calculadora_Ponteiros`:

```bash
gcc src/Prj_Calculadora_Ponteiros.c -o Prj_Calculadora_Ponteiros
./Prj_Calculadora_Ponteiros
```

No Windows, rode `Prj_Calculadora_Ponteiros.exe` (ou `.\Prj_Calculadora_Ponteiros.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Calculadora_Ponteiros
│
├── 📁 src
│   └── Prj_Calculadora_Ponteiros.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Funcoes_Ponteiros](../Prj_Funcoes_Ponteiros): Funções com ponteiros: troca e zera
- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência
- [Prj_ClasseCarro_Cpp](../Prj_ClasseCarro_Cpp): C++: classe Carro

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
