# Projeto Prj_ReverterArray_Recursivo (C) ↔️

> **Reverter array recursivamente**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Inverte a ordem dos elementos de um array (`1 2 3 4 5` → `5 4 3 2 1`) trocando as pontas e chamando a função para o pedaço do meio.

## 🎯 Conceitos trabalhados

- Recursão com dois índices (`inicio` e `fim`)
- Troca com variável temporária
- Função `void` que altera o array original

## 🧠 Como funciona

```c
// Função recursiva para reverter os elementos do array
void reverteArray(int A[], int inicio, int fim) {
    if (inicio >= fim)
        return;

    // Troca os elementos nas posições inicio e fim
    int temp = A[inicio];
    A[inicio] = A[fim];
    A[fim] = temp;

    // Chama a função recursivamente para os próximos elementos
    reverteArray(A, inicio + 1, fim - 1);
}
```

A cada chamada, `A[inicio]` e `A[fim]` trocam de lugar e os índices se aproximam. Quando `inicio >= fim`, todos os pares já foram trocados. O array muda de verdade porque, em C, arrays são passados como ponteiros para o primeiro elemento.

## 💻 Exemplo de execução

```text
Array original: 1 2 3 4 5 
Array revertido: 5 4 3 2 1
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ReverterArray_Recursivo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ReverterArray_Recursivo`:

```bash
gcc src/Prj_ReverterArray_Recursivo.c -o Prj_ReverterArray_Recursivo
./Prj_ReverterArray_Recursivo
```

No Windows, rode `Prj_ReverterArray_Recursivo.exe` (ou `.\Prj_ReverterArray_Recursivo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_ReverterArray_Recursivo
│
├── 📁 src
│   └── Prj_ReverterArray_Recursivo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Palindromo_Recursivo](../Prj_Palindromo_Recursivo): Palíndromo recursivo
- [Prj_Funcoes_Ponteiros](../Prj_Funcoes_Ponteiros): Funções com ponteiros: troca e zera

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
