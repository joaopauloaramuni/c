# Projeto arvorebinaria (C, 2010–2011) 🌳

> **Árvore binária de busca**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Estruturas de dados**.

## 📖 Descrição

Uma **árvore binária de busca** de caracteres, em `arvore.h` e `arvorebinaria.c`: criar árvore vazia, testar se está vazia, criar nó, inserir respeitando a ordem e imprimir em **pré-ordem** com parênteses. O `main` insere h, p, f, g, k, c, s.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag9.html) (seção **Árvores**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Nó com `esq` e `dir`
- Inserção recursiva em BST
- Percurso pré-ordem
- Notação com parênteses

## 📚 Entendendo o conceito

Este projeto trabalha **Árvore binária de busca** e **Recursividade**.

### Árvore binária de busca

Uma **árvore binária** é formada por nós em que cada nó tem no máximo dois filhos: esquerdo e direito. O nó do topo é a **raiz** e os nós sem filhos são **folhas**. Na **árvore binária de busca** (*BST*), vale uma regra em todos os nós: tudo à esquerda é menor e tudo à direita é maior (ou igual).

Essa regra permite buscar como num jogo de "maior ou menor": a cada nó, descarta-se metade da árvore. Numa árvore equilibrada, buscar, inserir e remover custam O(log n). Se os dados chegam já ordenados, porém, a árvore vira uma "lista torta" e tudo volta a custar O(n); por isso existem as árvores balanceadas (AVL, rubro-negra).

Árvores são percorridas recursivamente: **pré-ordem** (raiz, esquerda, direita), **em ordem** (esquerda, raiz, direita; numa BST, sai ordenado) e **pós-ordem** (esquerda, direita, raiz).

#### 🌍 Onde é usado na prática

- Índices de bancos de dados usam árvores B e B+, parentes da árvore de busca adaptados ao disco.
- O `map` e o `set` do C++ e o `TreeMap` do Java são árvores rubro-negras.
- Sistemas de arquivos, o DOM do navegador, árvores sintáticas de compiladores e árvores de decisão em aprendizado de máquina.

#### 💼 Em processos seletivos

Árvores binárias estão entre os temas **mais frequentes** em entrevistas técnicas de empresas de tecnologia. Os clássicos são calcular a altura, validar se é uma BST, os três percursos (recursivos e iterativos), percurso por nível (com fila), menor ancestral comum e inverter a árvore. Quase todos são resolvidos com recursão.

Perguntas que costumam aparecer:

- Calcule a altura (profundidade máxima) da árvore.
- Verifique se uma árvore binária é uma BST válida.
- Escreva os percursos pré-ordem, em ordem e pós-ordem.
- Por que a BST pode degenerar para O(n)? Como evitar?

#### ⏱️ Complexidade

Busca, inserção e remoção: O(h), em que h é a altura. Árvore equilibrada: O(log n); degenerada: O(n).

#### 🐞 Erros comuns

- Esquecer de devolver a nova raiz na inserção recursiva (`raiz->esq = inserir(raiz->esq, x)`).
- Testar só o filho imediato ao validar uma BST (a regra vale para a subárvore inteira).
- Não liberar a árvore (é preciso um percurso pós-ordem com `free`).

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

`arvore.h`

```c
TArv* inserir(TArv* raiz, char ch) {
    if (!raiz) {
        raiz = arv_cria(ch,arv_criavazia(),arv_criavazia());
    } else {
        if (ch < raiz->dado)
            raiz->esq = inserir(raiz->esq,ch);
        else
            raiz->dir = inserir(raiz->dir,ch);
    }
    return raiz;
}
```

`arvore.h`

```c
void imprime(TArv* arv){
    if(!arv_vazia(arv)){
        printf("(%c",arv->dado);
        imprime(arv->esq);
        imprime(arv->dir);
        printf(")");
    }
}
```

Letras menores que a raiz vão para a esquerda e maiores para a direita (comparando os códigos ASCII). Com h, p, f, g, k, c, s a árvore fica:

```text
        h
      /   \
     f     p
    / \   / \
   c   g k   s
```

A impressão em pré-ordem gera `(h(f(c)(g))(p(k)(s)))`: cada parêntese é uma subárvore. O comentário no `main` monta a mesma árvore "à mão" com `arv_cria`. Página [Árvores](https://sitec-aramuni.vercel.app/pag9.html) do Site C.

## 💻 Exemplo de execução

```text
(h(f(c)(g))(p(k)(s)))
vazia --> 0
```

## ⚠️ Pontos de atenção

- Faltam busca, remoção e liberação da árvore (um percurso pós-ordem com `free`). A remoção, com os três casos (folha, um filho, dois filhos), é o exercício clássico seguinte.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/arvorebinaria.c -o arvorebinaria
./arvorebinaria
```

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 104: Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [LeetCode 94: Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
- [LeetCode 700: Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)
- [LeetCode 701: Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)
- [LeetCode 98: Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
- [Beecrowd 1195: Árvore Binária de Busca](https://judge.beecrowd.com/pt/problems/view/1195)
- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)

## 📂 Estrutura do projeto

```text
📁 arvorebinaria
│
├── 📁 src
│   ├── arvore.h                      └── Cabeçalho com a estrutura e as operações
│   └── arvorebinaria.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [ListaDi](../ListaDi): Lista dinâmica (simplesmente encadeada)
- [Recursividade](../Recursividade): Recursividade: fatorial e Fibonacci

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): árvores binárias](https://www.ime.usp.br/~pf/algoritmos/aulas/bint.html)
- [Paulo Feofiloff (IME-USP): árvores binárias de busca](https://www.ime.usp.br/~pf/algoritmos/aulas/binst.html)
- [VisuAlgo: BST animada](https://visualgo.net/en/bst)
- [Wikipedia: Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree)
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
