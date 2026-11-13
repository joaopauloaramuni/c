# Projeto Prj_While_Exer2 (C) 🧮

> **while: contar números digitados**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Conta quantos números o usuário digitou até informar `-1`, o valor de saída (sentinela), que não entra na contagem.

## 🎯 Conceitos trabalhados

- Laço `while` com sentinela
- Contador (`contnum++`)
- Inicialização da variável de controle

## 🧠 Como funciona

```c
int main(void) {
    int Num = 999, contnum = 0;

    while (Num != -1) {
        printf("Entre com um número; para encerrar, digite -1: ");
        scanf("%d", &Num);

        if (Num != -1) {
            contnum = contnum + 1; // ou contnum++
        }
    }

    printf("A quantidade de números digitados é: %d\n", contnum);

    return 0;
}
```

`Num` começa com `999` para garantir a primeira entrada no laço. O `if (Num != -1)` impede que o próprio `-1` seja contado.

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
2. Em **Select root directory**, escolha a pasta `Prj_While_Exer2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_While_Exer2`:

```bash
gcc src/Prj_While_Exer2.c -o Prj_While_Exer2
./Prj_While_Exer2
```

No Windows, rode `Prj_While_Exer2.exe` (ou `.\Prj_While_Exer2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_While_Exer2
│
├── 📁 src
│   └── Prj_While_Exer2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_DoWhile_Exer2](../Prj_DoWhile_Exer2): do-while: contar números digitados
- [Prj_While_Exer1](../Prj_While_Exer1): while: contar pares e ímpares

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
