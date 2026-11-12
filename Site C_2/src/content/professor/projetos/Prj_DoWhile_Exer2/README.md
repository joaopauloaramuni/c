# Projeto Prj_DoWhile_Exer2 (C) 🧮

> **do-while: contar números digitados**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Versão com `do-while` do [Prj_While_Exer2](../Prj_While_Exer2): conta os números digitados até o `-1`.

## 🎯 Conceitos trabalhados

- `do-while` com sentinela
- Contador
- Comparação entre `while` e `do-while`

## 🧠 Como funciona

```c
int main(void) {
    int Num, contnum = 0;

    do {
        printf("Entre com um número; para encerrar, digite -1: ");
        scanf("%d", &Num);

        if (Num != -1) {
            contnum = contnum + 1; // ou contnum++
        }
    } while (Num != -1);

    printf("A quantidade de números digitados é: %d\n", contnum);

    return 0;
}
```

O comentário `// ou contnum++` lembra que `contnum = contnum + 1` e `contnum++` fazem a mesma coisa.

## 💻 Exemplo de execução

```text
Entre com um número; para encerrar, digite -1: 5
Entre com um número; para encerrar, digite -1: 8
Entre com um número; para encerrar, digite -1: 13
Entre com um número; para encerrar, digite -1: -1
A quantidade de números digitados é: 3
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_DoWhile_Exer2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_DoWhile_Exer2`:

```bash
gcc src/Prj_DoWhile_Exer2.c -o Prj_DoWhile_Exer2
./Prj_DoWhile_Exer2
```

No Windows, rode `Prj_DoWhile_Exer2.exe` (ou `.\Prj_DoWhile_Exer2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_DoWhile_Exer2
│
├── 📁 src
│   └── Prj_DoWhile_Exer2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_While_Exer2](../Prj_While_Exer2): while: contar números digitados
- [Prj_DoWhile_Exer1](../Prj_DoWhile_Exer1): do-while: contar pares e ímpares

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
