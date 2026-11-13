# Projeto Prj_While (C) 🔁

> **Laço while**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Repete três vezes a leitura e a soma de dois números usando `while` e uma variável contadora.

## 🎯 Conceitos trabalhados

- Laço `while` (enquanto)
- Variável contadora
- Condição de parada

## 🧠 Como funciona

```c
int main(void) {
    int x, y, result, cont;
    cont = 1;

    while (cont <= 3) { //enquanto //for - para
        printf("Entre com os dois números para serem somados: ");
        scanf("%d %d", &x, &y);

        result = x + y;

        printf("O resultado da soma é: %d\n", result);

        cont = cont + 1;
    }

    return 0;
}
```

O `cont` começa em `1` e cresce a cada volta (`cont = cont + 1`). Quando chega a `4`, a condição `cont <= 3` fica falsa e o laço termina. O mesmo programa aparece com `do-while` no [Prj_DoWhile](../Prj_DoWhile) e com `for` no [Prj_For](../Prj_For).

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
2. Em **Select root directory**, escolha a pasta `Prj_While` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_While`:

```bash
gcc src/Prj_While.c -o Prj_While
./Prj_While
```

No Windows, rode `Prj_While.exe` (ou `.\Prj_While.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_While
│
├── 📁 src
│   └── Prj_While.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_DoWhile](../Prj_DoWhile): Laço do-while
- [Prj_For](../Prj_For): Laço for
- [Prj_WhileInfinito](../Prj_WhileInfinito): Laço infinito

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
