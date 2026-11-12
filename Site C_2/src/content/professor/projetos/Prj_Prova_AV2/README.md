# Projeto Prj_Prova_AV2 (C) 📝

> **Prova AV2: arrays e recursão**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução das questões da **prova AV2**. Cada questão é um arquivo `.c` com o seu próprio `main`:

| Arquivo | Questão |
| --- | --- |
| `Q1.c` | Média dos elementos de um array (com função) |
| `Q2.c` | Maior elemento de um array |
| `Q3.c` | Soma dos elementos de um array |
| `Q4_Solucao_1.c` | Soma recursiva, avançando um índice do início para o fim |
| `Q4_Solucao_2.c` | Soma recursiva, diminuindo o tamanho do fim para o início |

## 🎯 Conceitos trabalhados

- Percurso de arrays
- Máximo de um array
- Recursão com caso base e passo recursivo
- Duas formas de dividir o mesmo problema recursivo

## 🧠 Como funciona

`Q4_Solucao_1.c`

```c
// Função recursiva para somar os elementos de um array
int somaRecursiva(int A[], int n, int indice) {
    // Caso base: se o índice é igual ao tamanho do array, retorna 0
    if (indice == n)
        return 0;
    // Caso recursivo: soma o elemento atual e chama a função para o próximo índice
    return A[indice] + somaRecursiva(A, n, indice + 1);
}
```

`Q4_Solucao_2.c`

```c
// Função recursiva para somar os elementos de um array
int somaRecursiva(int A[], int tamanho) {
    // Caso base: se o índice é igual ao tamanho do array, retorna 0
    if (tamanho == 0)
        return 0;
    // Caso recursivo: soma o elemento atual e chama a função para o próximo índice
    return A[tamanho - 1] + somaRecursiva(A, tamanho - 1);
}
```

As duas soluções da Q4 chegam ao mesmo resultado por caminhos opostos: a Solução 1 soma `A[indice]` e avança para `indice + 1` até chegar em `n`; a Solução 2 soma `A[tamanho - 1]` e chama com `tamanho - 1` até chegar em `0`. No `Q4_Solucao_2.c`, os comentários mostram a pilha de chamadas sendo empilhada (lida de cima para baixo) e desempilhada (de baixo para cima).

## 💻 Exemplo de execução

`Q1.c`

```text
A média dos elementos do array é: 30.00
```

`Q2.c`

```text
O maior elemento do array é 8
```

`Q3.c`

```text
A soma dos elementos do array é 30
```

`Q4_Solucao_1.c`

```text
A soma dos elementos do array é 15
```

`Q4_Solucao_2.c`

```text
A soma dos elementos do array é 30
```

## ⚠️ Pontos de atenção

- Como os cinco arquivos têm `main`, o projeto **não compila inteiro** no Eclipse (erro `multiple definition of 'main'`). Compile e rode uma questão por vez pelo terminal, ou exclua os outros arquivos do build (**botão direito no arquivo → Resource Configurations → Exclude from Build**).

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Prova_AV2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

> ⚠️ Este projeto tem um `main` em cada arquivo. No Eclipse, deixe só um arquivo no build de cada vez (veja **Pontos de atenção**) ou use o terminal.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Prova_AV2`:

```bash
gcc src/Q1.c -o Q1 && ./Q1
gcc src/Q2.c -o Q2 && ./Q2
gcc src/Q3.c -o Q3 && ./Q3
gcc src/Q4_Solucao_1.c -o Q4_Solucao_1 && ./Q4_Solucao_1
gcc src/Q4_Solucao_2.c -o Q4_Solucao_2 && ./Q4_Solucao_2
```

No Windows, rode cada executável com `.exe` no final.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Prova_AV2
│
├── 📁 src
│   ├── Q1.c
│   ├── Q2.c
│   ├── Q3.c
│   ├── Q4_Solucao_1.c
│   └── Q4_Solucao_2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Soma_Recursiva_Array](../Prj_Soma_Recursiva_Array): Soma recursiva de um array
- [Prj_Maior_Menor](../Prj_Maior_Menor): Maior e menor de 10 números
- [Prj_Array_Exer1](../Prj_Array_Exer1): Exercício: soma e média de um array

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
