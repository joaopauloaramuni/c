# Projeto do_while (C, 2010–2011) 🔂

> **Laço do-while**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Primeiros passos**.

## 📖 Descrição

Pede `Digite uma opção:` repetidamente até o usuário digitar `q` ou `Q`. Como o `do-while` testa a condição no final, a pergunta aparece pelo menos uma vez.

## 🎯 Conceitos trabalhados

- Laço `do-while`
- `getchar`
- Condição com `&&`

## 📚 Entendendo o conceito

Este projeto trabalha **Laços de repetição (while, do-while e for)**, **Entrada e saída (printf, scanf e o buffer do teclado)** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Laços de repetição (while, do-while e for)

Laços repetem um bloco enquanto uma condição for verdadeira. Os três de C são equivalentes em poder, e a escolha é de legibilidade:

| Laço | Quando a condição é testada | Uso típico |
| --- | --- | --- |
| `while` | Antes de cada volta | Repetir até um evento (sentinela, fim do arquivo) |
| `do-while` | Depois de cada volta (roda pelo menos 1 vez) | Menus e validação de entrada |
| `for` | Antes de cada volta, com início e passo na mesma linha | Número de repetições conhecido, percorrer vetores |

Um **valor sentinela** (como `0` ou `-1`) é um valor especial que avisa o fim da entrada. `break` sai do laço na hora e `continue` pula para a próxima volta.

#### 🌍 Onde é usado na prática

- Percorrer coleções: linhas de um arquivo, itens de um carrinho, pixels de uma imagem.
- Laços de eventos: servidores, jogos e interfaces gráficas rodam um laço "infinito" que espera e trata eventos.
- Tentativas com limite: reconectar a um servidor até 3 vezes.

#### 💼 Em processos seletivos

Quase toda questão de algoritmo usa laços. Os avaliadores olham os **limites** (`<` ou `<=`? começa em 0 ou 1?), o caso de entrada vazia e a complexidade: dois laços aninhados sobre `n` elementos custam O(n²).

Perguntas que costumam aparecer:

- Some os números de 1 a n (com laço e com fórmula).
- Encontre o maior e o menor valor de uma sequência sem guardar todos.
- Qual a complexidade de dois `for` aninhados que vão até `n`?

#### ⏱️ Complexidade

Um laço que percorre `n` itens custa O(n). Laços aninhados multiplicam: O(n²), O(n³).

#### 🐞 Erros comuns

- Erro de "um a mais ou a menos" (*off-by-one*): `i <= n` em um vetor de `n` posições lê fora do vetor.
- Esquecer de atualizar a variável de controle e criar um laço infinito.
- Colocar `;` logo depois do `for (...)`: o laço fica vazio.

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
int main() {
    setbuf(stdout,NULL);
    char Ch;
    do {
        printf("Digite uma opção: ");
        fflush(stdin);
        Ch=getchar();
    }while (Ch!='q' && Ch!='Q');

    return 0;
}
```

A condição `Ch!='q' && Ch!='Q'` aceita a letra nas duas caixas. O `fflush(stdin)` antes do `getchar` descarta o *Enter* da digitação anterior; sem ele, o *Enter* seria lido como mais uma opção.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
Digite uma opção: a
Digite uma opção: b
Digite uma opção: q
```

## ⚠️ Pontos de atenção

- No Linux e no macOS, `fflush(stdin)` não descarta a entrada, e cada *Enter* conta como uma opção: a pergunta aparece duas vezes a cada letra. Veja a seção sobre portabilidade.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/do_while.c -o do_while
./do_while
```

> O `fflush(stdin)` só limpa a entrada no Windows. No Linux e no macOS, algumas leituras podem "pular"; rode no Windows ou adapte como explicado na seção sobre portabilidade.

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

- [Beecrowd 1059: Números Pares](https://judge.beecrowd.com/pt/problems/view/1059)
- [Beecrowd 1060: Números Positivos](https://judge.beecrowd.com/pt/problems/view/1060)
- [Beecrowd 1078: Tabuada](https://judge.beecrowd.com/pt/problems/view/1078)
- [Beecrowd 1094: Experiências](https://judge.beecrowd.com/pt/problems/view/1094)
- [Beecrowd 1003: Soma Simples](https://judge.beecrowd.com/pt/problems/view/1003)
- [Beecrowd 1004: Produto Simples](https://judge.beecrowd.com/pt/problems/view/1004)
- [Beecrowd 1005: Média 1](https://judge.beecrowd.com/pt/problems/view/1005)

## 📂 Estrutura do projeto

```text
📁 do_while
│
├── 📁 src
│   └── do_while.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [getchar](../getchar): getchar com do-while
- [while](../while): Laço while
- [MenuOpcoes](../MenuOpcoes): Menu de opções (cópia do Letra)

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_DoWhile](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_DoWhile)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: while](https://en.cppreference.com/w/c/language/while)
- [cppreference: do-while](https://en.cppreference.com/w/c/language/do)
- [cppreference: for](https://en.cppreference.com/w/c/language/for)
- [cppreference: break e continue](https://en.cppreference.com/w/c/language/break)
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
