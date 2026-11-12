# Projeto Torre (C, 2010–2011) 🗼

> **Torre de Hanói**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Recursão**.

## 📖 Descrição

Resolve a Torre de Hanói para até 10 discos, imprimindo cada movimento e o total de movimentos (2ⁿ − 1). Ao fim, pergunta se o usuário quer sair ou resolver outra torre.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag1.html) (seção **Torre de Hanói**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Recursão com duas chamadas
- Validação com `do-while` (limite de 10 discos)
- `pow` para 2ⁿ − 1

## 📚 Entendendo o conceito

Este projeto trabalha **Torre de Hanói**, **Recursividade** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Torre de Hanói

A Torre de Hanói tem três pinos e `n` discos de tamanhos diferentes empilhados no primeiro pino, do maior (embaixo) ao menor. O objetivo é levar todos para outro pino movendo **um disco por vez** e **nunca colocando um disco maior sobre um menor**.

A solução recursiva é curta: para mover `n` discos de A para B usando C como auxiliar, (1) mova `n-1` discos de A para C, (2) mova o maior disco de A para B, (3) mova os `n-1` discos de C para B. O número mínimo de movimentos é **2ⁿ − 1**: 7 para 3 discos, 1.023 para 10, e mais de 18 quintilhões para 64 (a lenda diz que o mundo acaba quando os monges terminarem a torre de 64 discos).

#### 🌍 Onde é usado na prática

- É o exemplo clássico para ensinar recursão e para mostrar o que é crescimento **exponencial**.
- A mesma estratégia (resolver para n-1, depois juntar) aparece em algoritmos de divisão e conquista.
- Variações são usadas em testes de psicologia cognitiva para avaliar planejamento.

#### 💼 Em processos seletivos

Aparece em entrevistas e provas como exercício de recursão pura: escrever a função, contar os movimentos e justificar por que são 2ⁿ − 1 (a recorrência é T(n) = 2·T(n-1) + 1).

Perguntas que costumam aparecer:

- Escreva a função recursiva que imprime os movimentos.
- Quantos movimentos são necessários para n discos? Prove.
- Qual a complexidade de tempo?

#### ⏱️ Complexidade

O(2ⁿ) movimentos; a pilha de chamadas tem profundidade n.

### Recursividade

Uma função **recursiva** resolve um problema chamando a si mesma para uma versão **menor** do mesmo problema. Toda recursão correta tem duas partes:

1. **Caso base**: a versão tão pequena que a resposta é direta (o fatorial de 0 é 1; uma lista vazia tem soma 0).
2. **Passo recursivo**: reduz o problema e combina o resultado da chamada menor (`n! = n × (n-1)!`).

Cada chamada ganha um espaço próprio na **pilha de chamadas** (*call stack*), com as suas variáveis locais. As chamadas vão sendo empilhadas até o caso base e depois são resolvidas na ordem inversa, "de baixo para cima". Se o caso base nunca é alcançado, a pilha enche e o programa quebra com *stack overflow*.

Todo algoritmo recursivo pode ser reescrito com laços (e uma pilha explícita, se preciso). A recursão vale a pena quando o problema **já é recursivo por natureza**: árvores, divisão e conquista, combinações, *backtracking*.

#### 🌍 Onde é usado na prática

- Percorrer estruturas recursivas: pastas dentro de pastas no sistema de arquivos, o DOM de uma página HTML, um JSON aninhado, árvores de decisão.
- Algoritmos de divisão e conquista: *Merge Sort*, *Quicksort* (veja o artigo de Hoare, de 1961), busca binária.
- *Backtracking*: Sudoku, labirintos, problema das 8 rainhas, gerar permutações.
- Compiladores e interpretadores analisam expressões com funções recursivas (*recursive descent parser*).

#### 💼 Em processos seletivos

Recursão é um dos temas **mais cobrados** em etapas técnicas, de estágio a vagas sênior. Ela aparece sozinha (fatorial, Fibonacci, potência, inverter uma string) e, principalmente, como ferramenta para problemas de árvores, grafos, *backtracking* e programação dinâmica. Os avaliadores costumam pedir para você **explicar a pilha de chamadas**, identificar o caso base e dizer a complexidade de tempo e de memória. Um passo seguinte comum é otimizar o Fibonacci recursivo com **memoização** (guardar resultados já calculados).

Perguntas que costumam aparecer:

- Qual o caso base e o passo recursivo desta função?
- Qual a complexidade do Fibonacci recursivo ingênuo? Como melhorar? (O(2ⁿ) → O(n) com memoização ou laço.)
- O que é *stack overflow* e quando acontece em recursão?
- Converta esta recursão em um laço.
- O que é recursão de cauda (*tail recursion*)?

#### ⏱️ Complexidade

Depende de quantas chamadas são feitas e do trabalho em cada uma. Fatorial e soma de um vetor fazem n chamadas: O(n) de tempo e O(n) de pilha. Fibonacci ingênuo faz duas chamadas por nível: O(2ⁿ). A memória usada pela pilha cresce com a **profundidade** da recursão.

#### 🐞 Erros comuns

- Esquecer o caso base, ou ter um caso base que nunca é atingido (por exemplo, fatorial de número negativo).
- Não reduzir o problema a cada chamada.
- Recalcular os mesmos subproblemas várias vezes (Fibonacci).
- Usar recursão profunda (milhares de níveis) onde um laço simples resolve.

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
void hanoi(int disco, char orig, char dest, char aux) {
    if (disco == 1)
        printf("Move disco %d de %c para %c\n", disco, orig, dest);
    else {
        hanoi(disco - 1, orig, aux, dest);
        printf("Move disco %d de %c para %c\n", disco, orig, dest);
        hanoi(disco - 1, aux, dest, orig);
    }
}
```

Para mover `n` discos de A para B: move `n-1` de A para C, move o maior de A para B e move os `n-1` de C para B. Com 3 discos são 7 movimentos. O limite de 10 discos (1.023 movimentos) evita encher a tela. É o conteúdo da página [Torre de Hanói](https://sitec-aramuni.vercel.app/pag1.html), a primeira do Site C.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
** Torre de Hanoi **

Digite o numero de discos: 3

Move disco 1 de A para B
Move disco 2 de A para C
Move disco 1 de B para C
Move disco 3 de A para B
Move disco 1 de C para A
Move disco 2 de C para B
Move disco 1 de A para B

Numero de movimentos otimos: 7

Deseja sair? (s/n): s

Voce saiu do programa.
```

## ⚠️ Pontos de atenção

- No Linux, compile com `-lm`.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/Torre.c -o Torre -lm
./Torre
```

O `-lm` liga a biblioteca matemática (`sqrt`, `pow`), obrigatório no Linux.

> O `fflush(stdin)` só limpa a entrada no Windows. No Linux e no macOS, algumas leituras podem "pular"; rode no Windows ou adapte como explicado na seção sobre portabilidade.

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

No Linux, adicione a biblioteca `m` em **Project → Properties → C/C++ Build → Settings → GCC C Linker → Libraries**.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [LeetCode 70: Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [LeetCode 50: Pow(x, n)](https://leetcode.com/problems/powx-n/)
- [LeetCode 206: Reverse Linked List (versão recursiva)](https://leetcode.com/problems/reverse-linked-list/)
- [Beecrowd 1029: Fibonacci, Quantas Chamadas?](https://judge.beecrowd.com/pt/problems/view/1029)
- [Beecrowd 1153: Fatorial Simples](https://judge.beecrowd.com/pt/problems/view/1153)

## 📂 Estrutura do projeto

```text
📁 Torre
│
├── 📁 src
│   └── Torre.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [hanoi](../hanoi): Torre de Hanói em uma linha
- [FunRecUmReturn](../FunRecUmReturn): Funções recursivas com um único return

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Aramuni_Recursivo](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Aramuni_Recursivo)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi)
- [Paulo Feofiloff (IME-USP): recursão](https://www.ime.usp.br/~pf/algoritmos/aulas/recu.html)
- [VisuAlgo: visualização de recursão](https://visualgo.net/en/recursion)
- [Wikipedia: recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))
- [Python Tutor: veja a pilha de chamadas em C](https://pythontutor.com/c.html)
- [cppreference: gets (removida no C11)](https://en.cppreference.com/w/c/io/gets)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)
- [cppreference: fflush](https://en.cppreference.com/w/c/io/fflush)
- [cppreference: setbuf](https://en.cppreference.com/w/c/io/setbuf)
- [MinGW-w64 (GCC no Windows)](https://www.mingw-w64.org/)

**Ferramentas e referências gerais**

- [Site C (2011): o site original com estes códigos](https://sitec-aramuni.vercel.app/)
- [Repositório de 2011](https://github.com/joaopauloaramuni/c)
- [Aulas do Prof. Rafael Nunes (PDF)](https://github.com/joaopauloaramuni/c/tree/main/Site%20C/pdf)
- [cppreference: referência completa da linguagem C](https://en.cppreference.com/w/c)
- [Projeto de Algoritmos em C, Paulo Feofiloff (IME-USP)](https://www.ime.usp.br/~pf/algoritmos/)
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
