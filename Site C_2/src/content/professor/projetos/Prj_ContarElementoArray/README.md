# Projeto Prj_ContarElementoArray (C) 🔍

> **Contar ocorrências recursivamente**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Conta quantas vezes um elemento aparece em um array usando recursão. No exemplo, o `4` aparece 3 vezes em `{1, 2, 4, 4, 4}`.

## 🎯 Conceitos trabalhados

- Recursão que acumula um contador na volta
- Caso base com array vazio (`tamanho == 0`)

## 🧠 Como funciona

```c
int contarElemento(int array[], int elemento, int tamanho){
    if(tamanho == 0){
        return 0;
    }
    int ocorrencias = contarElemento(array, elemento, tamanho - 1);
    if(array[tamanho-1] == elemento){
        ocorrencias++;
    }
    return ocorrencias;
}
```

A função primeiro resolve o problema para os `tamanho - 1` primeiros elementos e só depois olha o último (`array[tamanho-1]`), somando 1 se ele for o procurado.

## 💻 Exemplo de execução

```text
Quantidade de aparições do elemento: 3
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ContarElementoArray` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ContarElementoArray`:

```bash
gcc src/Prj_ContarElementoArray.c -o Prj_ContarElementoArray
./Prj_ContarElementoArray
```

No Windows, rode `Prj_ContarElementoArray.exe` (ou `.\Prj_ContarElementoArray.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_ContarElementoArray
│
├── 📁 src
│   └── Prj_ContarElementoArray.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_VerificarElementoPresenteArray](../Prj_VerificarElementoPresenteArray): Elemento presente? (recursivo)
- [Prj_VerificarParesArray](../Prj_VerificarParesArray): Todos pares? (recursivo)
- [Prj_Soma_Recursiva_Array](../Prj_Soma_Recursiva_Array): Soma recursiva de um array

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
