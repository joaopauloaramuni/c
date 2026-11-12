# Projeto Prj_HelloWorld (C) 👋

> **Hello World**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

O primeiro programa da disciplina: imprime `!!!Hello World!!!` no console. É o modelo que o **Eclipse IDE for C/C++ Developers** gera ao criar um projeto C novo (*Hello World ANSI C Project*), e serve para conferir se o compilador (GCC/MinGW) e a IDE estão instalados corretamente.

## 🎯 Conceitos trabalhados

- Estrutura mínima de um programa C (`#include`, `main`, `return`)
- Saída de texto com `puts`
- Constante `EXIT_SUCCESS` de `<stdlib.h>`
- Comentários de bloco `/* ... */`

## 🧠 Como funciona

```c
int main(void) {
    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
    return EXIT_SUCCESS;
}
```

`puts` escreve a string e já acrescenta a quebra de linha no final, diferente do `printf`, que só quebra a linha quando encontra `\n`. O `return EXIT_SUCCESS` (que vale `0`) avisa ao sistema operacional que o programa terminou sem erros.

## 💻 Exemplo de execução

```text
!!!Hello World!!!
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_HelloWorld` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_HelloWorld`:

```bash
gcc src/Prj_HelloWorld.c -o Prj_HelloWorld
./Prj_HelloWorld
```

No Windows, rode `Prj_HelloWorld.exe` (ou `.\Prj_HelloWorld.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_HelloWorld
│
├── 📁 src
│   └── Prj_HelloWorld.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Variaveis](../Prj_Variaveis): Variáveis e constantes
- [Prj_LeituraDados](../Prj_LeituraDados): Leitura de dados com scanf

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
