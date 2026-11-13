# Projeto Prj_DoWhile (C) 🔂

> **Laço do-while**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê e soma dois números três vezes usando `do-while`, que executa o bloco **pelo menos uma vez** antes de testar a condição.

## 🎯 Conceitos trabalhados

- Laço `do { ... } while (condição);`
- Teste da condição no final
- Contador

## 🧠 Como funciona

```c
int main(void) {
    int x, y, result, cont;

    cont = 1;
    do {
        printf("Entre com os dois números para serem somados\n");
        scanf("%d %d", &x, &y);

        result = x + y;
        printf("O valor da soma é %d \n", result);
        cont++;

    } while (cont <= 3);

}
```

No `while` a condição é testada antes de entrar; no `do-while`, depois. Repare no ponto e vírgula depois do `while (cont <= 3);`: ele é obrigatório.

## 💻 Exemplo de execução

```text
Entre com os dois números para serem somados
1 2
O valor da soma é 3 
Entre com os dois números para serem somados
3 4
O valor da soma é 7 
Entre com os dois números para serem somados
5 6
O valor da soma é 11
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_DoWhile` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_DoWhile`:

```bash
gcc src/Prj_DoWhile.c -o Prj_DoWhile
./Prj_DoWhile
```

No Windows, rode `Prj_DoWhile.exe` (ou `.\Prj_DoWhile.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_DoWhile
│
├── 📁 src
│   └── Prj_DoWhile.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_While](../Prj_While): Laço while
- [Prj_For](../Prj_For): Laço for
- [Prj_DoWhile_Menu](../Prj_DoWhile_Menu): Menu com do-while e switch

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
