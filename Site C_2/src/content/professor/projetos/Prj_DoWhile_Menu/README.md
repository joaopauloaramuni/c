# Projeto Prj_DoWhile_Menu (C) 📋

> **Menu com do-while e switch**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Monta um **menu de opções** que se repete até o usuário escolher **Sair**. É o padrão de menu usado em vários trabalhos da disciplina: `do-while` para repetir e `switch` para tratar a escolha.

## 🎯 Conceitos trabalhados

- Menu interativo
- `do-while` controlado por uma *flag* (`escolha`)
- `switch` com `default` para opção inválida

## 🧠 Como funciona

```c
int main(void) {
    int escolha;

    do {
        printf("Menu:\n");
        printf("1. Opção 1\n");
        printf("2. Opção 2\n");
        printf("3. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {//flag
        case 1:
            printf("Você escolheu a Opção 1.\n");
            break;
        case 2:
            printf("Você escolheu a Opção 2.\n");
            break;
        case 3:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 3);

    return 0;
}
```

O laço só termina quando `escolha` vale `3`. Qualquer outro número cai no `default` e o menu aparece de novo. O mesmo padrão aparece, maior, no [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo) e na [Tarefa 3](../Prj_Tarefa_3_1).

## 💻 Exemplo de execução

```text
Menu:
1. Opção 1
2. Opção 2
3. Sair
Escolha uma opção: 1
Você escolheu a Opção 1.
(menu)
Escolha uma opção: 2
Você escolheu a Opção 2.
(menu)
Escolha uma opção: 3
Saindo do programa.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_DoWhile_Menu` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_DoWhile_Menu`:

```bash
gcc src/Prj_DoWhile.c -o Prj_DoWhile_Menu
./Prj_DoWhile_Menu
```

No Windows, rode `Prj_DoWhile_Menu.exe` (ou `.\Prj_DoWhile_Menu.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_DoWhile_Menu
│
├── 📁 src
│   └── Prj_DoWhile.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_CondicionalMultipla](../Prj_CondicionalMultipla): Condicional múltipla (else if e switch)
- [Prj_Tarefa_3_1](../Prj_Tarefa_3_1): Tarefa 3.1: eleição de 2º turno
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
