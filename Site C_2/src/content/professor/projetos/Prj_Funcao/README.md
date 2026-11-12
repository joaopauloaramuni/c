# Projeto Prj_Funcao (C) 🧩

> **Funções: protótipo e definição**. Tema: **Funções**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Cria a função `calcularQuadrado`, que recebe um número e devolve o quadrado dele. O protótipo fica **antes** do `main` e a definição **depois**, com comentários no estilo de documentação (`@param`, `@return`).

## 🎯 Conceitos trabalhados

- Protótipo (assinatura) de função
- Parâmetros e valor de retorno
- Documentação de funções com comentários

## 🧠 Como funciona

```c
/**
 * Definição da função calcularQuadrado
 *
 * Esta função recebe um número como argumento e retorna o quadrado desse número.
 *
 * @param numero (int) - O número para o qual queremos calcular o quadrado.
 * @return int - O quadrado do número de entrada.
 */
int calcularQuadrado(int numero) {
    // Calculando o quadrado do número
    int quadrado = numero * numero;

    // Retornando o resultado
    return quadrado;
}
```

O compilador lê o arquivo de cima para baixo. Sem o protótipo `int calcularQuadrado(int numero);` antes do `main`, ele ainda não conheceria a função no momento da chamada. O protótipo diz o nome, o tipo do retorno e os parâmetros; o corpo pode vir depois.

## 💻 Exemplo de execução

```text
O quadrado de 5 é: 25
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Funcao` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Funcao`:

```bash
gcc src/Prj_Funcao.c -o Prj_Funcao
./Prj_Funcao
```

No Windows, rode `Prj_Funcao.exe` (ou `.\Prj_Funcao.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Funcao
│
├── 📁 src
│   └── Prj_Funcao.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Soma](../Prj_Soma): Função soma
- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência
- [Prj_Struct_Livro_Arg](../Prj_Struct_Livro_Arg): Struct Livro como argumento

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
