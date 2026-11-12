# Projeto fatorial (C, 2010–2011) ❗

> **Fatorial recursivo**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Recursão**.

## 📖 Descrição

Calcula o fatorial de `n` com recursão. Um comentário no código rastreia, chamada por chamada, como `fat(5)` desce até `fat(0)` e volta multiplicando.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag3.html) (seção **Fatorial**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Caso base (`fat(0) = 1`)
- Passo recursivo
- Pilha de chamadas

## 📚 Entendendo o conceito

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

## 🧠 Como funciona o código

```c
int fat(int n) {
    if (n)
        return n * fat(n - 1);
    else
        return 1; //Caso conhecido n = 0 - Fatorial de 0 eh 1

    /*
     Ex: Fatorial de 5
     fat(5)= 5 * fat (4)
     fat(4)= 4 * fat (3)
     fat(3)= 3 * fat (2)
     fat(2)= 2 * fat (1)
     fat(1)= 1 * fat (0)
     fat(0) = return 1 (pois fatorial de 0 eh 1 e 0 e falso no teste)
     Entao volta..

     fat(1)= 1 * fat (0)
     fat(1)= 1 * 1 = 1
     fat(2)= 2 * fat (1)
     fat(2)= 2 * 1 = 2
     fat(3)= 3 * fat(2)
     fat(3)= 3 * 2 = 6
     fat(4)= 4 * fat(3)
     fat(4)= 4 * 6 = 24
     fat(5)= 5 * fat(4)
     fat(5)= 5 * 24 = 120

     */
}
```

A condição `if (n)` aproveita que 0 é falso em C: enquanto `n` for diferente de zero, chama `fat(n - 1)`; quando chega a 0, devolve 1. Página [Fatorial](https://sitec-aramuni.vercel.app/pag3.html) do Site C.

## 💻 Exemplo de execução

```text
** Fatorial **

Digite um valor para n: 5

O fatorial de 5 e 120
```

## ⚠️ Pontos de atenção

- Com `n` negativo, a recursão nunca chega a 0 e o programa quebra por *stack overflow*.
- Com `int`, o maior fatorial correto é `12!`; `13!` já estoura.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/fatorial.c -o fatorial
./fatorial
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

- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [LeetCode 70: Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [LeetCode 50: Pow(x, n)](https://leetcode.com/problems/powx-n/)
- [LeetCode 206: Reverse Linked List (versão recursiva)](https://leetcode.com/problems/reverse-linked-list/)
- [Beecrowd 1029: Fibonacci, Quantas Chamadas?](https://judge.beecrowd.com/pt/problems/view/1029)
- [Beecrowd 1153: Fatorial Simples](https://judge.beecrowd.com/pt/problems/view/1153)

## 📂 Estrutura do projeto

```text
📁 fatorial
│
├── 📁 src
│   └── fatorial.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [Fatorial_Normal](../Fatorial_Normal): Fatorial iterativo
- [Recursividade](../Recursividade): Recursividade: fatorial e Fibonacci
- [Pow_Recursivo](../Pow_Recursivo): Potência recursiva

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Fatorial_Recursivo](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Fatorial_Recursivo)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): recursão e algoritmos recursivos](https://www.ime.usp.br/~pf/algoritmos/aulas/recu.html)
- [VisuAlgo: visualização de recursão](https://visualgo.net/en/recursion)
- [Wikipedia: recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))
- [Python Tutor: veja a pilha de chamadas em C](https://pythontutor.com/c.html)

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
