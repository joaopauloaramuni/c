# Projeto Prj_StrCpy (C) 📝

> **Copiar strings com strcpy**. Tema: **Strings**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra as duas formas de colocar texto em um array de `char`: na **declaração** (`char string1[] = "Hello"`) e depois, com `strcpy`.

## 🎯 Conceitos trabalhados

- Strings como arrays de `char` terminados em `\0`
- `strcpy` de `<string.h>`
- Tamanho do array de destino

## 🧠 Como funciona

```c
int main(void) {
    char string1[] = "Hello"; // Atribuição para um array de char (string)

    char string2[10];         // Declaração de outro array de char (string)
    strcpy(string2, "World"); // Atribuição usando strcpy

    printf("String1: %s\n", string1);
    printf("String2: %s\n", string2);

    return 0;
}
```

Depois da declaração, não dá para escrever `string2 = "World";`: arrays não aceitam atribuição em C. Por isso existe o `strcpy`. O destino precisa caber o texto mais o `\0`: `"World"` ocupa 6 posições, e `string2` tem 10.

## 💻 Exemplo de execução

```text
String1: Hello
String2: World
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_StrCpy` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_StrCpy`:

```bash
gcc src/Prj_StrCpy.c -o Prj_StrCpy
./Prj_StrCpy
```

No Windows, rode `Prj_StrCpy.exe` (ou `.\Prj_StrCpy.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_StrCpy
│
├── 📁 src
│   └── Prj_StrCpy.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_StrLen](../Prj_StrLen): Tamanho de string com strlen
- [Prj_Struct_Livro](../Prj_Struct_Livro): Struct Livro
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
