# Projeto Prj_StrLen (C) 📐

> **Tamanho de string com strlen**. Tema: **Strings**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calcula o comprimento da string `"Exemplo"` com `strlen` e imprime o resultado com `%zu`.

## 🎯 Conceitos trabalhados

- `strlen` de `<string.h>`
- Tipo `size_t`
- Especificador `%zu`

## 🧠 Como funciona

```c
int main(void) {
    char minhaString[] = "Exemplo";

    // Calcula o comprimento da string
    size_t comprimento = strlen(minhaString);

    // Imprime a string e seu comprimento
    printf("String: %s\n", minhaString);
    printf("Comprimento: %zu\n", comprimento);

    return 0;
}
```

`strlen` conta os caracteres até o `\0`, sem incluí-lo: `"Exemplo"` tem 7 letras, mas ocupa 8 posições na memória. Uma versão recursiva da função está no [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo) (`strLen`).

## 💻 Exemplo de execução

```text
String: Exemplo
Comprimento: 7
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_StrLen` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_StrLen`:

```bash
gcc src/Prj_StrLen.c -o Prj_StrLen
./Prj_StrLen
```

No Windows, rode `Prj_StrLen.exe` (ou `.\Prj_StrLen.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_StrLen
│
├── 📁 src
│   └── Prj_StrLen.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_StrCpy](../Prj_StrCpy): Copiar strings com strcpy
- [Prj_Array_Ex2](../Prj_Array_Ex2): Arrays de strings
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
