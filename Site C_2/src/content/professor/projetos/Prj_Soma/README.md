# Projeto Prj_Soma (C) ➕

> **Função soma**. Tema: **Funções**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Função simples `soma(a, b)` que devolve a soma de dois inteiros, chamada pelo `main` com `x = 2` e `y = 3`.

## 🎯 Conceitos trabalhados

- Definição de função antes do `main`
- Passagem de argumentos por valor
- `return`

## 🧠 Como funciona

```c
int soma(int a, int b){
    int c = a + b;
    return c;
}
```

Aqui a função é definida **antes** do `main`, então não precisa de protótipo (compare com o [Prj_Funcao](../Prj_Funcao)). Os valores de `x` e `y` são **copiados** para `a` e `b`.

## 💻 Exemplo de execução

```text
Soma = 5
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Soma` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Soma`:

```bash
gcc src/Prj_Soma.c -o Prj_Soma
./Prj_Soma
```

No Windows, rode `Prj_Soma.exe` (ou `.\Prj_Soma.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Soma
│
├── 📁 src
│   └── Prj_Soma.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Funcao](../Prj_Funcao): Funções: protótipo e definição
- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
