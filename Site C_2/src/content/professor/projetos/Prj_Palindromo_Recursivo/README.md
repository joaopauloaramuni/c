# Projeto Prj_Palindromo_Recursivo (C) 🔁

> **Palíndromo recursivo**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Verifica se uma palavra é palíndromo com recursão, em duas versões: uma de uma linha só (com ternário e `&&`) e outra passo a passo, com comentários que rastreiam cada chamada para ARARA.

## 🎯 Conceitos trabalhados

- Recursão com dois índices (`left` e `right`)
- Curto-circuito do `&&`
- Rastreamento de chamadas recursivas

## 🧠 Como funciona

```c
int isPalindrome(char str[], int left, int right) {
    return (left >= right) ? 1 : (str[left] == str[right]) && isPalindrome(str, left + 1, right - 1);
}
```

```c
int isPalindrome2(char str[], int left, int right) {
    // Quarta chamada recursiva: 3 >= 2 true
    // Terceira chamada recursiva: 2 >= 3 falso
    // Segunda chamada recursiva: 1 >= 4 falso
    // Primeira chamada recursiva: 0 >= 5 falso
    if (left >= right)
        return 1;

    // Quarta chamada recursiva: retornou 1 acima
    // Terceira chamada recursiva: A != A ? falso
    // Segunda chamada recursiva: R != R ? falso
    // Primeira chamada recursiva: A != A ? falso
    if (str[left] != str[right])
        // Verifica se os caracteres nos extremos são iguais
        return 0;

    // Chama recursivamente para o próximo par de caracteres
    return isPalindrome2(str, left + 1, right - 1);
    // Quarta chamada recursiva: ARARA -> R != A (Não chega a fazer esse teste) [left == 3 e right == 2]
    // Terceira chamada recursiva: ARXRA -> A != A [left == 2 e right == 3]
    // Segunda chamada recursiva: AXAXA -> R != R [left == 1 e right == 4]
    // Primeira chamada recursiva: XRARX -> A != A [left == 0 e right == 5]
    // >> ARARA <<
}
```

Se as letras das pontas são diferentes, não é palíndromo. Se são iguais, a resposta depende do pedaço de dentro, e a função chama a si mesma com `left + 1` e `right - 1`. Na versão de uma linha, o `&&` só faz a chamada recursiva se a comparação das pontas for verdadeira (curto-circuito).

## 💻 Exemplo de execução

```text
Digite uma palavra: ARARA
Tamanho: 5 
A palavra é um palíndromo.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Palindromo_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Palindromo_Recursivo`:

```bash
gcc src/Prj_Palindromo_Recursivo.c -o Prj_Palindromo_Recursivo
./Prj_Palindromo_Recursivo
```

No Windows, rode `Prj_Palindromo_Recursivo.exe` (ou `.\Prj_Palindromo_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Palindromo_Recursivo
│
├── 📁 src
│   └── Prj_Palindromo_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Palindromo](../Prj_Palindromo): Palíndromo (iterativo)
- [Prj_Pali+File](../Prj_Pali+File): Palíndromos gravados em arquivo
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
