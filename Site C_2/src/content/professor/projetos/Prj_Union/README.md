# Projeto Prj_Union (C) 🔀

> **Union**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Uma `union` com um `int`, um `float` e uma string. Os três campos **dividem o mesmo espaço de memória**, então só o último valor gravado é válido.

## 🎯 Conceitos trabalhados

- `union` × `struct`
- Memória compartilhada entre campos
- Tamanho da union = tamanho do maior campo

## 🧠 Como funciona

```c
int main(void) {
    dado.i = 10; /* union sera do tipo inteiro */
    printf("Sou inteiro : %d\n", dado.i);
    dado.f = 34.5; /* union sera do tipo float */
    printf("Sou real : %f\n", dado.f);
    strcpy(dado.str, "Sou String"); /* union sera do tipo String */
    printf("Sou string : %s\n", dado.str);

    return 0;
}
```

Uma `struct` com esses campos ocuparia 28 bytes (4 + 4 + 20). A `union` ocupa só 20, o tamanho do maior campo. Depois do `strcpy`, ler `dado.i` daria um número sem sentido, formado pelos primeiros bytes da string.

## 💻 Exemplo de execução

```text
Sou inteiro : 10
Sou real : 34.500000
Sou string : Sou String
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Union` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Union`:

```bash
gcc src/Prj_Union.c -o Prj_Union
./Prj_Union
```

No Windows, rode `Prj_Union.exe` (ou `.\Prj_Union.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Union
│
├── 📁 src
│   └── Prj_Union.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Union_Struct](../Prj_Union_Struct): Union dentro de struct
- [Prj_Struct_Livro](../Prj_Struct_Livro): Struct Livro

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
