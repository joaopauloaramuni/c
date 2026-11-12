# Projeto Prj_Fatorial_Recursivo (C) ❗

> **Fatorial recursivo**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calcula o fatorial de 5 (`5! = 120`) de **três** formas: recursiva tradicional, recursiva em uma linha com operador ternário e iterativa com `for`. O `main` usa a versão recursiva.

## 🎯 Conceitos trabalhados

- Caso base e passo recursivo
- Pilha de chamadas
- Recursão com operador ternário
- Comparação entre recursão e laço

## 🧠 Como funciona

```c
// Função recursiva padrão
int fatorialRecursivo(int n) {
    // Quarta chamada recursiva: 1 == 0 || 1 == 1 true
    // Terceira chamada recursiva: 2 == 0 || 2 == 1 falso
    // Segunda chamada recursiva: 3 == 0 || 3 == 1 falso
    // Primeira chamada recursiva: 4 == 0 || 4 == 1 falso
    // Chamada do main: 5 == 0 || 5 == 1 falso
    if (n == 0 || n == 1) {
        // Caso base
        return 1;
    } else {
        // Quarta chamada recursiva: 2 * fr(1) = 2 * 1 = 2
        // Terceira chamada recursiva: 3 * fr(2) = 3 * 2 = 6
        // Segunda chamada recursiva: 4 * fr(3) = 4 * 6 = 24
        // Primeira chamada recursiva: 5 * fr(4) = 5 * 24 = 120

        // 5 * (4 * 3 * 2 * 1) = 120
        // 5 * (4 * 3 * 2 * fr(1)) = ?
        // 5 * (4 * 3 * fr(2)) = ?
        // 5 * (4 * fr(3)) = ?
        // 5 * fr(4) = ?
        // fr(5) = ?
        // Leia de baixo pra cima

        return n * fatorialRecursivo(n - 1);
        // Chamada recursiva
    }
}
```

```c
// Função recursiva em uma linha utilizando o operador ternário
int fatorialRecursivoUmaLinha(int c) {
    return (c == 0 || c == 1) ? 1 : (c * fatorialRecursivoUmaLinha(c - 1));
}
```

As chamadas vão sendo empilhadas até o caso base e depois resolvidas de volta:

```text
fr(5) = 5 * fr(4)
        fr(4) = 4 * fr(3)
                fr(3) = 3 * fr(2)
                        fr(2) = 2 * fr(1)
                                fr(1) = 1   ← caso base
                        fr(2) = 2
                fr(3) = 6
        fr(4) = 24
fr(5) = 120
```

Os comentários no código fazem esse mesmo rastreamento, chamada por chamada ("Leia de baixo pra cima"). Com `int`, o maior fatorial que cabe é `12!`; a partir de `13!` o valor estoura.

## 💻 Exemplo de execução

```text
O fatorial de 5 é: 120
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Fatorial_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Fatorial_Recursivo`:

```bash
gcc src/Prj_Fatorial_Recursivo.c -o Prj_Fatorial_Recursivo
./Prj_Fatorial_Recursivo
```

No Windows, rode `Prj_Fatorial_Recursivo.exe` (ou `.\Prj_Fatorial_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Fatorial_Recursivo
│
├── 📁 src
│   └── Prj_Fatorial_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Fibonacci_Recursivo](../Prj_Fibonacci_Recursivo): Fibonacci recursivo
- [Prj_Potencia_Recursiva](../Prj_Potencia_Recursiva): Potência recursiva
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
