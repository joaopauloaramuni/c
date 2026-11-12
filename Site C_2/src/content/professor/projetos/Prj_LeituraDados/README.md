# Projeto Prj_LeituraDados (C) ⌨️

> **Leitura de dados com scanf**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê um número inteiro digitado pelo usuário e o mostra de volta. É o primeiro contato com a **entrada de dados** em C.

## 🎯 Conceitos trabalhados

- Função `scanf` com o especificador `%d`
- Operador de endereço `&`
- Fluxo entrada → processamento → saída

## 🧠 Como funciona

```c
int main(void) {
    // Declaração da variável para armazenar o valor lido
    int numero;

    // Utilização da scanf para ler um inteiro
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Exibição do valor lido
    printf("Você digitou: %d\n", numero);

    return 0;
}
```

O `scanf("%d", &numero)` precisa saber **onde** guardar o valor lido, por isso recebe o endereço da variável (`&numero`) e não o valor dela. Esse mesmo `&` volta mais tarde na matéria de ponteiros.

## 💻 Exemplo de execução

```text
Digite um número inteiro: 42
Você digitou: 42
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_LeituraDados` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_LeituraDados`:

```bash
gcc src/Prj_LeituraDados.c -o Prj_LeituraDados
./Prj_LeituraDados
```

No Windows, rode `Prj_LeituraDados.exe` (ou `.\Prj_LeituraDados.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_LeituraDados
│
├── 📁 src
│   └── Prj_LeituraDados.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Sequencial](../Prj_Sequencial): Estrutura sequencial
- [Prj_Memoria](../Prj_Memoria): Endereço de memória
- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
