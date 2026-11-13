# Projeto Prj_Maior_Menor (C) 📏

> **Maior e menor de 10 números**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê 10 números e mostra o **maior** e o **menor** deles, sem guardar todos em um vetor.

## 🎯 Conceitos trabalhados

- Laço `for`
- Inicialização com o primeiro valor lido
- Comparações para atualizar máximo e mínimo

## 🧠 Como funciona

```c
int main(void) {
    int i, number;
    int maior, menor;

    // Solicita ao usuário que insira 10 números
    printf("Digite 10 números:\n");

    // Lê o primeiro número
    scanf("%d", &number);

    // Inicializa o maior e o menor com o primeiro número
    maior = number;
    menor = number;

    // Loop para ler os próximos 9 números
    for (i = 1; i < 10; i++) { // i = 1, 2, .... , 9, 10 falso
        scanf("%d", &number);

        // Verifica se o número atual é maior que o maior atual
        if (number > maior) {
            maior = number;
        }

        // Verifica se o número atual é menor que o menor atual
        if (number < menor) {
            menor = number;
        }
    }

    // Exibe o maior e o menor número
    printf("O maior número é: %d\n", maior);
    printf("O menor número é: %d\n", menor);

    return 0;
}
```

O truque é usar o **primeiro número lido** como maior e menor iniciais. Começar com `0` daria errado se todos os números fossem negativos (o maior seria `0`, que nem foi digitado). Os outros 9 números são comparados um a um.

## 💻 Exemplo de execução

```text
Digite 10 números:
5 12 -3 8 21 0 7 14 -9 3
O maior número é: 21
O menor número é: -9
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Maior_Menor` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Maior_Menor`:

```bash
gcc src/Prj_Maior_Menor.c -o Prj_Maior_Menor
./Prj_Maior_Menor
```

No Windows, rode `Prj_Maior_Menor.exe` (ou `.\Prj_Maior_Menor.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Maior_Menor
│
├── 📁 src
│   └── Prj_Maior_Menor.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Prova_AV2](../Prj_Prova_AV2): Prova AV2: arrays e recursão
- [Prj_Tarefa_4](../Prj_Tarefa_4): Tarefa 4: vetores e matrizes
- [Prj_For](../Prj_For): Laço for

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
