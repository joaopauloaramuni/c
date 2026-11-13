# Projeto Prj_Funcoes_Ponteiros (C) 🔁

> **Funções com ponteiros: troca e zera**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Duas funções clássicas com ponteiros: `troca`, que inverte os valores de duas variáveis do `main`, e `modifica`, que zera uma variável que começa valendo `1`.

## 🎯 Conceitos trabalhados

- Ponteiros como parâmetros
- Função *swap* com variável temporária
- Diferença entre `x` e `&x` no `printf`

## 🧠 Como funciona

```c
//Função que receba um ponteiro e modifique o valor da variável
//para zero (0)
//Na função main a variável deve ser inicializada com 1
//No final da função main o valor 0 deve ser impresso na tela
void modifica(int *x){
    *x = 0;
}
```

```c
// Função que realiza a troca de valores usando ponteiros
void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
```

A `troca` precisa de uma variável auxiliar (`temp`): sem ela, `*x = *y` apagaria o valor de `x` antes de copiá-lo para `y`. A linha comentada `//printf("%d", &x);` mostra um erro comum: imprimir o endereço com `%d` em vez do valor.

## 💻 Exemplo de execução

```text
Digite o primeiro número: 7
Digite o segundo número: 42
Antes da troca: a = 7, b = 42
Depois da troca: a = 42, b = 7
0
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Funcoes_Ponteiros` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Funcoes_Ponteiros`:

```bash
gcc src/Prj_Funcoes_Ponteiros.c -o Prj_Funcoes_Ponteiros
./Prj_Funcoes_Ponteiros
```

No Windows, rode `Prj_Funcoes_Ponteiros.exe` (ou `.\Prj_Funcoes_Ponteiros.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Funcoes_Ponteiros
│
├── 📁 src
│   └── Prj_Funcoes_Ponteiros.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência
- [Prj_Calculadora_Ponteiros](../Prj_Calculadora_Ponteiros): Calculadora com ponteiros
- [Prj_ContarDigitos_Ponteiros](../Prj_ContarDigitos_Ponteiros): Contar dígitos com ponteiros

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
