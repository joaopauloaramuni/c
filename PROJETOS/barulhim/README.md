# Projeto barulhim (C, 2010–2011) 🔔

> **Barulhinho (bip)**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Primeiros passos**.

## 📖 Descrição

Toca dois bipes com o caractere de controle `\a` (*alert*) e, entre eles, faz uma pausa contando até 100 milhões em um laço vazio.

## 🎯 Conceitos trabalhados

- Caractere de controle `\a`
- Laço vazio como espera (*busy waiting*)
- `long int`

## 📚 Entendendo o conceito

### Terminal: caracteres especiais, códigos ANSI e espera

O terminal entende alguns caracteres de controle: `\n` (nova linha), `\t` (tabulação) e `\a` (*alert*, o bipe). Terminais modernos também interpretam **sequências de escape ANSI**, que começam com `\033[`: `\033[2J` limpa a tela, `\033[H` volta o cursor ao topo e `\033[1;32m` liga o verde.

Para esperar um tempo, o correto é pedir ao sistema operacional para suspender o programa (`sleep` no Linux, `Sleep` no Windows). Um laço vazio que conta até um número grande (**espera ocupada**, *busy waiting*) gasta 100% de um núcleo do processador, depende da velocidade da máquina e pode ser removido inteiro pelo otimizador do compilador.

#### 🌍 Onde é usado na prática

- Ferramentas de linha de comando coloridas (Git, compiladores, *test runners*) e barras de progresso.
- Interfaces de texto completas (`htop`, `vim`) usam as mesmas sequências, normalmente por meio da biblioteca ncurses.

#### 💼 Em processos seletivos

Pouco cobrado diretamente; *busy waiting* aparece em perguntas de sistemas operacionais e concorrência.

Perguntas que costumam aparecer:

- Qual a diferença entre `sleep` e um laço de espera?
- O que é espera ocupada e quando ela é aceitável?

## 🧠 Como funciona o código

```c
int main()
{
  long int i;
  printf("\a");
  for (i=0; i<100000000;i++);
  printf("\a");
  return 0;
}
```

O `for (i=0; i<100000000; i++);` não faz nada além de contar: a pausa depende da velocidade do processador. Em 2011 isso dava cerca de meio segundo; numa máquina atual é bem menos.

## 💻 Exemplo de execução

```text
(dois bipes, separados por uma pausa curta)
```

## ⚠️ Pontos de atenção

- Compilando com otimização (`gcc -O2`), o compilador percebe que o laço não tem efeito e o remove: os dois bipes saem juntos. Para esperar de verdade, use `sleep` (`unistd.h`) ou `Sleep` (`windows.h`).
- Muitos terminais modernos não tocam o bipe; alguns piscam a tela.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/barulhim.c -o barulhim
./barulhim
```

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

### Acentos quebrados?

Os arquivos foram salvos em **ISO-8859-1 (Latin-1)**, o padrão do Eclipse no Windows em 2011. Se os acentos aparecerem como `�`, reabra o arquivo nessa codificação (no VS Code: **Reopen with Encoding → Western (ISO 8859-1)**; no Eclipse: **Edit → Set Encoding**).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 📂 Estrutura do projeto

```text
📁 barulhim
│
├── 📁 src
│   └── barulhim.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [for](../for): Laço for

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_ASCII_Clock](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_ASCII_Clock)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code)
- [Wikipedia: Busy waiting](https://en.wikipedia.org/wiki/Busy_waiting)
- [cppreference: sequências de escape](https://en.cppreference.com/w/c/language/escape)

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
- [GCC: documentação oficial](https://gcc.gnu.org/onlinedocs/)

**Livros**

- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação – padrão ANSI*. Campus/Elsevier. O livro clássico, escrito por Kernighan com Dennis Ritchie, o criador da linguagem.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Elsevier.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Campus/Elsevier.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. Elsevier.

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Veja o arquivo [LICENSE](../../LICENSE) na raiz do repositório.

-----

João Paulo Aramuni, aluno de Ciência da Computação na FUMEC (2010–2011) · [Repositório](https://github.com/joaopauloaramuni/c)
