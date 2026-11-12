# Projeto Prj_Sequencial (C) ➡️

> **Estrutura sequencial**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê dois inteiros, soma e mostra o resultado. Cada instrução roda uma vez, de cima para baixo, sem desvios nem repetições: é a **estrutura sequencial**, ponto de partida para as estruturas de controle.

## 🎯 Conceitos trabalhados

- Estrutura sequencial
- Leitura com `scanf` e escrita com `printf`
- Atribuição e operador aritmético `+`

## 🧠 Como funciona

```c
int main(void) {
    int ValA, ValB, ValC;

    printf("Entre com os números para serem somados: ");
    scanf("%d", &ValA);
    scanf("%d", &ValB);

    ValC = ValA + ValB;

    printf("O valor da soma é: %d\n", ValC);

    return 0;
}
```

O programa é um passo a passo direto: declara `ValA`, `ValB` e `ValC`, lê os dois primeiros, calcula `ValC = ValA + ValB` e imprime. Compare com o [Prj_CondicionalSimples](../Prj_CondicionalSimples), que é o mesmo programa com um `if` antes do `printf`.

## 💻 Exemplo de execução

```text
Entre com os números para serem somados: 40
35
O valor da soma é: 75
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Sequencial` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Sequencial`:

```bash
gcc src/Prj_Sequencial.c -o Prj_Sequencial
./Prj_Sequencial
```

No Windows, rode `Prj_Sequencial.exe` (ou `.\Prj_Sequencial.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Sequencial
│
├── 📁 src
│   └── Prj_Sequencial.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_CondicionalSimples](../Prj_CondicionalSimples): Condicional simples (if)
- [Prj_Soma](../Prj_Soma): Função soma

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
