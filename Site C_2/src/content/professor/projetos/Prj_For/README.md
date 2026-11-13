# Projeto Prj_For (C) 🔄

> **Laço for**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê e soma dois números três vezes com o laço `for`, que junta inicialização, condição e incremento na mesma linha.

## 🎯 Conceitos trabalhados

- Laço `for (início; condição; incremento)`
- Contador
- Equivalência com `while`

## 🧠 Como funciona

```c
int main(void) {
    int x, y, result, cont;

    for (cont = 1; cont <= 3; cont++) {
        //cont = 1, cont = 2, cont = 3, (cont = 4)
        printf("Entre com os dois números para serem somados: ");
        scanf("%d %d", &x, &y);

        result = x + y;

        printf("O resultado da soma é: %d\n", result);
    }

    return 0;
}
```

O comentário `//cont = 1, cont = 2, cont = 3, (cont = 4)` mostra os valores que o contador assume: no `4` a condição `cont <= 3` falha e o laço acaba. Use `for` quando o número de repetições é conhecido antes de começar.

## 💻 Exemplo de execução

```text
Entre com os dois números para serem somados: 1 2
O resultado da soma é: 3
Entre com os dois números para serem somados: 3 4
O resultado da soma é: 7
Entre com os dois números para serem somados: 5 6
O resultado da soma é: 11
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_For` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_For`:

```bash
gcc src/Prj_For.c -o Prj_For
./Prj_For
```

No Windows, rode `Prj_For.exe` (ou `.\Prj_For.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_For
│
├── 📁 src
│   └── Prj_For.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_While](../Prj_While): Laço while
- [Prj_DoWhile](../Prj_DoWhile): Laço do-while
- [Prj_Maior_Menor](../Prj_Maior_Menor): Maior e menor de 10 números

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
