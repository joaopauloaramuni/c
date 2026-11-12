# Projeto getch (C, 2010–2011) ⌨️

> **getch: tecla sem Enter**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Primeiros passos**.

## 📖 Descrição

Lê **uma tecla**, sem esperar o *Enter* e sem mostrar a tecla na tela, com `getch()` da biblioteca `conio.h`, e responde `Voce pressionou a tecla ...`.

## 🎯 Conceitos trabalhados

- `getch()` de `conio.h`
- Entrada sem *buffer* de linha
- Bibliotecas específicas de plataforma

## 📚 Entendendo o conceito

Este projeto trabalha **Entrada e saída (printf, scanf e o buffer do teclado)** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Entrada e saída (printf, scanf e o buffer do teclado)

`printf` escreve texto formatado na saída padrão e `scanf` lê da entrada padrão. Os dois usam **especificadores de formato**: `%d` (int), `%f` (float no `printf` e no `scanf`), `%lf` (double no `scanf`), `%c` (char), `%s` (string), `%p` (endereço).

O teclado não entrega os caracteres direto para o programa: eles ficam num **buffer** até o *Enter*. O `scanf("%d", ...)` lê o número e **deixa o `\n` no buffer**, e a próxima leitura de caractere ou de linha (`%c`, `getchar`, `fgets`) pega esse `\n` sobrando. Esse é o bug mais comum de quem começa em C.

#### 🌍 Onde é usado na prática

- Programas de linha de comando, ferramentas de terminal e scripts leem e escrevem pela entrada e saída padrão (`stdin`, `stdout`).
- Plataformas de programação competitiva (Beecrowd, Codeforces, HackerRank) avaliam o programa só pela saída: um espaço a mais reprova a solução.
- `fprintf(stderr, ...)` separa mensagens de erro da saída normal.

#### 💼 Em processos seletivos

Em testes online (HackerRank, Codility, Beecrowd) a leitura correta da entrada é metade do problema. Saber ler até o fim do arquivo (`while (scanf(...) == 2)`) e lidar com o `\n` sobrando economiza muito tempo.

Perguntas que costumam aparecer:

- Por que o programa "pula" a leitura de um caractere depois de um `scanf("%d")`?
- Por que `scanf("%d", &x)` precisa do `&`, e `scanf("%s", nome)` não?
- Qual a diferença entre `%f` no `printf` e `%lf` no `scanf`?

#### 🐞 Erros comuns

- Esquecer o `&` no `scanf` (o programa trava ou escreve em lugar errado).
- Usar `fflush(stdin)` para limpar o buffer: só funciona no Windows; o padrão C não define esse uso. O portável é `while (getchar() != '\n');` ou `scanf(" %c", &c)` com espaço antes do `%c`.
- Usar `gets`: foi removida do C11 porque não limita o tamanho da leitura. Use `fgets`.

### C portável e seguro: do MinGW de 2011 ao C moderno

Os códigos de 2010–2011 foram escritos no Eclipse com MinGW, no Windows do laboratório, e usam recursos que funcionavam ali mas não são padrão C:

| Recurso de 2011 | Problema | Alternativa portável |
| --- | --- | --- |
| `gets(s)` | Removida no C11: não limita o tamanho e permite estouro de *buffer* | `fgets(s, sizeof s, stdin)` |
| `fflush(stdin)` | Comportamento indefinido no padrão; só limpa a entrada no Windows | `while (getchar() != '\n');` ou `scanf(" %c", &c)` |
| `conio.h` / `getch()` | Só existe no Windows/DOS | `getchar()`, ou `termios`/ncurses no Linux |
| `windows.h` / `MessageBox` | API do Windows | `printf` ou uma biblioteca gráfica multiplataforma |
| `setbuf(stdout, NULL)` | Funciona em todo lugar | Era usado para o console do Eclipse mostrar a saída na hora |

O `setbuf(stdout, NULL)` no início dos programas desliga o *buffer* da saída. Sem ele, o console do Eclipse no Windows só mostrava as mensagens depois do `scanf`, e o usuário digitava sem ver a pergunta.

#### 🌍 Onde é usado na prática

- Código que roda em servidores Linux, contêineres Docker e serviços de integração contínua precisa ser portável.
- `gets` e outras funções sem limite de tamanho aparecem em listas de falhas de segurança (CWE-242, uso de função perigosa).

#### 💼 Em processos seletivos

Em vagas de C/C++ e de segurança, é comum perguntarem por que `gets` é perigosa, o que é um estouro de *buffer* e como ler uma linha com segurança.

Perguntas que costumam aparecer:

- Por que `gets` foi removida do C11?
- O que é estouro de *buffer*?
- Por que `fflush(stdin)` não é portável?

## 🧠 Como funciona o código

```c
int main ()
{
    setbuf(stdout,NULL);
    char Ch;
    Ch=getch();
    printf ("Voce pressionou a tecla %c",Ch);
    return(0);
}
```

O `getchar()` padrão só recebe os caracteres depois do *Enter*. O `getch()` lê a tecla na hora, o que é útil em menus e jogos. Mas `conio.h` vem do DOS e só existe nos compiladores para Windows.

## 💻 Exemplo de execução

> No Windows, a tecla não aparece na tela. A captura abaixo foi feita no Linux trocando `getch` por `getchar`, por isso a tecla aparece e foi preciso apertar *Enter*.

```text
x
Voce pressionou a tecla x
```

## ⚠️ Pontos de atenção

- `conio.h` não existe no Linux nem no macOS. Para ler uma tecla sem *Enter* nesses sistemas, use `termios` ou a biblioteca ncurses.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/getch.c -o getch
./getch
```

> Este programa usa uma biblioteca exclusiva do Windows (`conio.h` ou `windows.h`): compile no Windows com MinGW, ou adapte o código como explicado em **Pontos de atenção**.

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

- [Beecrowd 1003: Soma Simples](https://judge.beecrowd.com/pt/problems/view/1003)
- [Beecrowd 1004: Produto Simples](https://judge.beecrowd.com/pt/problems/view/1004)
- [Beecrowd 1005: Média 1](https://judge.beecrowd.com/pt/problems/view/1005)

## 📂 Estrutura do projeto

```text
📁 getch
│
├── 📁 src
│   └── getch.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [getchar](../getchar): getchar com do-while
- [do_while](../do_while): Laço do-while

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: scanf](https://en.cppreference.com/w/c/io/fscanf)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)
- [cppreference: getchar](https://en.cppreference.com/w/c/io/getchar)
- [cppreference: gets (removida no C11)](https://en.cppreference.com/w/c/io/gets)
- [cppreference: fflush](https://en.cppreference.com/w/c/io/fflush)
- [cppreference: setbuf](https://en.cppreference.com/w/c/io/setbuf)
- [MinGW-w64 (GCC no Windows)](https://www.mingw-w64.org/)

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
