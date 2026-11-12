# Projeto aloMundo (C, 2010–2011) 👋

> **Alô Mundo**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Primeiros passos**.

## 📖 Descrição

O primeiro programa: imprime `!!! Hello World !!!`. É o modelo que o Eclipse gerava ao criar um projeto *Hello World ANSI C Project*, e serviu para testar a instalação do Eclipse com o MinGW no início do curso.

## 🎯 Conceitos trabalhados

- Estrutura mínima de um programa C
- `puts`
- `EXIT_SUCCESS`

## 📚 Entendendo o conceito

### Estrutura de um programa em C e compilação

Todo programa em C começa pela função `main`. Antes dela vêm as diretivas do **pré-processador** (`#include`, `#define`), que são resolvidas antes da compilação: o `#include <stdio.h>` cola no arquivo as declarações de `printf`, `puts`, `scanf` e companhia.

C é uma linguagem **compilada**: o código-fonte (`.c`) passa por pré-processamento, compilação (gera código objeto `.o`) e ligação (*linking*, junta o seu código com a biblioteca padrão) até virar um executável. O valor devolvido por `main` (`return 0` ou `EXIT_SUCCESS`) é o código de saída que o sistema operacional recebe: zero quer dizer "terminou bem".

#### 🌍 Onde é usado na prática

- C continua no núcleo de sistemas operacionais (Linux, partes do Windows e do macOS), bancos de dados (SQLite, PostgreSQL), interpretadores (CPython, Lua) e firmware de dispositivos embarcados.
- O código de saída de `main` é o que scripts, *pipelines* de CI e o próprio terminal usam para saber se um programa falhou.
- Entender as etapas de compilação ajuda a ler mensagens de erro: `undefined reference` é erro de **ligação**, não de sintaxe.

#### 💼 Em processos seletivos

Raramente alguém pergunta o "Hello World" em si, mas perguntas conceituais sobre a cadeia de compilação aparecem em vagas de sistemas embarcados, C/C++ e infraestrutura.

Perguntas que costumam aparecer:

- Quais são as etapas entre o arquivo `.c` e o executável?
- Qual a diferença entre erro de compilação e erro de ligação?
- O que o valor de retorno de `main` significa?

#### 🐞 Erros comuns

- Esquecer o `#include` de uma função: compiladores modernos tratam a declaração implícita como erro.
- Confundir `puts` (sempre quebra a linha) com `printf` (só quebra com `\n`).

## 🧠 Como funciona o código

```c
int main(void) {
    puts("!!! Hello World !!!"); /* prints !!! Hello World !!! */
    return EXIT_SUCCESS;
}
```

`puts` imprime o texto e já pula a linha. `return EXIT_SUCCESS;` (que vale 0) avisa o sistema que tudo correu bem.

## 💻 Exemplo de execução

```text
!!! Hello World !!!
```

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/aloMundo.c -o aloMundo
./aloMundo
```

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

### Acentos quebrados?

Os arquivos foram salvos em **ISO-8859-1 (Latin-1)**, o padrão do Eclipse no Windows em 2011. Se os acentos aparecerem como `�`, reabra o arquivo nessa codificação (no VS Code: **Reopen with Encoding → Western (ISO 8859-1)**; no Eclipse: **Edit → Set Encoding**).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1000: Hello World!](https://judge.beecrowd.com/pt/problems/view/1000)
- [Beecrowd 1001: Extremamente Básico](https://judge.beecrowd.com/pt/problems/view/1001)

## 📂 Estrutura do projeto

```text
📁 aloMundo
│
├── 📁 src
│   └── aloMundo.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [aloMundo2](../aloMundo2): Alô Mundo 2
- [PrimeiraFuncao](../PrimeiraFuncao): Primeira função

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_HelloWorld](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_HelloWorld)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: a função main](https://en.cppreference.com/w/c/language/main_function)
- [cppreference: pré-processador](https://en.cppreference.com/w/c/preprocessor)
- [GCC: documentação oficial](https://gcc.gnu.org/onlinedocs/)

**Ferramentas e referências gerais**

- [Site C (2011): o site original com estes códigos](https://sitec-aramuni.vercel.app/)
- [Repositório de 2011](https://github.com/joaopauloaramuni/c)
- [Aulas do Prof. Rafael Nunes (PDF)](https://github.com/joaopauloaramuni/c/tree/main/Site%20C/pdf)
- [cppreference: referência completa da linguagem C](https://en.cppreference.com/w/c)
- [Projeto de Algoritmos em C, Paulo Feofiloff (IME-USP)](https://www.ime.usp.br/~pf/algoritmos/)
- [Python Tutor: execute C passo a passo e veja a memória](https://pythontutor.com/c.html)
- [VisuAlgo: estruturas de dados e algoritmos animados](https://visualgo.net/)
- [OnlineGDB: compile e rode C no navegador](https://www.onlinegdb.com/)
- [Eclipse CDT (IDE usada na disciplina)](https://eclipse.dev/cdt/)

**Livros**

- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação – padrão ANSI*. Campus/Elsevier. O livro clássico, escrito por Kernighan com Dennis Ritchie, o criador da linguagem.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Elsevier.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Campus/Elsevier.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. Elsevier.

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Veja o arquivo [LICENSE](../../LICENSE) na raiz do repositório.

-----

João Paulo Aramuni, aluno de Ciência da Computação na FUMEC (2010–2011) · [Repositório](https://github.com/joaopauloaramuni/c)
