# Projeto Prj_Soma_Recursiva_Array (C) ➕

> **Soma recursiva de um array**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Soma os elementos de um array com recursão: a soma de `n` elementos é o último elemento mais a soma dos `n - 1` primeiros.

## 🎯 Conceitos trabalhados

- Recursão sobre arrays
- Tamanho do array com `sizeof(arr) / sizeof(arr[0])`
- Caso base `n <= 0`

## 🧠 Como funciona

```c
// Função recursiva para somar os elementos de um array
int somaArray(int arr[], int n) {
    // Caso base: se o tamanho do array é 0, retorna 0
    if (n <= 0)
        return 0;
    // Caso recursivo: soma o último elemento ao resultado da soma dos elementos restantes
    return arr[n-1] + somaArray(arr, n-1);
}
```

`sizeof(arr)` devolve o tamanho do array **em bytes** (20 para 5 `int`). Dividir pelo tamanho de um elemento (`sizeof(arr[0])`, 4 bytes) dá a quantidade de elementos. Essa conta só funciona no lugar onde o array foi declarado; dentro da função, `arr` já é um ponteiro.

## 💻 Exemplo de execução

```text
A soma dos elementos do array é 15
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Soma_Recursiva_Array` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Soma_Recursiva_Array`:

```bash
gcc src/Prj_Soma_Recursiva_Array.c -o Prj_Soma_Recursiva_Array
./Prj_Soma_Recursiva_Array
```

No Windows, rode `Prj_Soma_Recursiva_Array.exe` (ou `.\Prj_Soma_Recursiva_Array.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Soma_Recursiva_Array
│
├── 📁 src
│   └── Prj_Soma_Recursiva_Array.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Prova_AV2](../Prj_Prova_AV2): Prova AV2: arrays e recursão
- [Prj_ContarElementoArray](../Prj_ContarElementoArray): Contar ocorrências recursivamente
- [Prj_ReverterArray_Recursivo](../Prj_ReverterArray_Recursivo): Reverter array recursivamente

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
