# Projeto Prj_Fibonacci_Recursivo (C) 🐚

> **Fibonacci recursivo**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calcula o n-ésimo termo da **sequência de Fibonacci** (0, 1, 1, 2, 3, 5, 8, 13...) de três formas: recursiva, recursiva em uma linha e com laço. Para trocar o termo calculado, altere `int termo = 2;` no `main`.

## 🎯 Conceitos trabalhados

- Recursão com duas chamadas (recursão em árvore)
- Dois casos base (`0` e `1`)
- Versão iterativa com duas variáveis auxiliares

## 🧠 Como funciona

```c
// Função recursiva padrão
int fiboRecursivo(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else
        return fiboRecursivo(n - 1) + fiboRecursivo(n - 2);
    // fib(5) = [[fib(3) + fib(2)] + [fib(2) + fib(1)]]
    // fib(5) = [[[fib(2) + fib(1)] + [fib(1) + fib(0)]] + [[fib(1) + fib(0)] + fib(1)]]
    // fib(5) = [[[[fib(1) + fib(0)] + fib(1)] + [fib(1) + fib(0)]] + [[fib(1) + fib(0)] + fib(1)]]
    // fib(5) = [[[1 + 0] + 1] + [1 + 0]] + [1 + 0] + 1
    // fib(5) = [[1 + 1] + 1] + 1 + 1
    // fib(5) = [2 + 1] + 1
    // fib(5) = 3 + 2
    // fib(5) = 5
    // 0 1 1 2 3 5 8 13...
}
```

```c
//Utiliza um loop para calcular os termos da sequência de Fibonacci
int fiboComLoop(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        int a = 0, b = 1, resultado;

        for (int i = 2; i <= n; ++i) {
            resultado = a + b;
            a = b;
            b = resultado;
        }
        return resultado;
    }
}
```

`fib(n) = fib(n-1) + fib(n-2)`. Cada chamada abre duas outras, então a versão recursiva recalcula os mesmos termos várias vezes: `fib(5)` chama `fib(2)` três vezes. O comentário dentro de `fiboRecursivo` expande `fib(5)` até chegar em `5`. A versão com laço guarda só os dois últimos termos e é muito mais rápida para valores grandes (experimente `termo = 40` nas duas).

## 💻 Exemplo de execução

```text
O 2º termo da sequência de Fibonacci é: 1
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Fibonacci_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Fibonacci_Recursivo`:

```bash
gcc src/Prj_Fibonacci_Recursivo.c -o Prj_Fibonacci_Recursivo
./Prj_Fibonacci_Recursivo
```

No Windows, rode `Prj_Fibonacci_Recursivo.exe` (ou `.\Prj_Fibonacci_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Fibonacci_Recursivo
│
├── 📁 src
│   └── Prj_Fibonacci_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Fatorial_Recursivo](../Prj_Fatorial_Recursivo): Fatorial recursivo
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
