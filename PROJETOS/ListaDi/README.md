# Projeto ListaDi (C, 2010–2011) 🔗

> **Lista dinâmica (simplesmente encadeada)**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Estruturas de dados**.

## 📖 Descrição

A primeira lista encadeada completa: inserir no início, imprimir (recursivo), verificar se está vazia, procurar uma letra (recursivo, com a versão iterativa comentada), remover o primeiro, remover qualquer nó e liberar. O `main` monta a lista com as letras de F, U, M, E, C e remove a letra digitada.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag8.html) (seção **Listas**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Nó com `dado` e `prox`
- Inserção no início em O(1)
- Busca e impressão recursivas
- Remoção de um nó do meio

## 📚 Entendendo o conceito

Este projeto trabalha **Listas encadeadas**, **Memória: pilha (stack), heap e alocação dinâmica**, **Recursividade** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Listas encadeadas

Uma **lista encadeada** é uma sequência de **nós** espalhados pela memória, em que cada nó guarda um dado e um ponteiro para o próximo (`prox`). O último aponta para `NULL`. Ao contrário do vetor, a lista não precisa de memória contígua nem de tamanho fixo: cresce um nó por vez com `malloc`.

| Variação | Ponteiros em cada nó | Vantagem |
| --- | --- | --- |
| Simplesmente encadeada | `prox` | Simples e econômica |
| Duplamente encadeada | `prox` e `ant` | Anda nos dois sentidos; remove um nó conhecido em O(1) |
| Circular | O último aponta de volta para o primeiro | Percorrer em ciclo (rodízio, Josephus) |
| Dupla e circular | `prox`, `ant` e fechamento | Acesso direto ao primeiro e ao último |

Inserir ou remover no início custa O(1). Em compensação, não há acesso por índice: chegar ao i-ésimo elemento exige percorrer a lista, O(n).

#### 🌍 Onde é usado na prática

- Histórico de navegação (voltar e avançar) e desfazer/refazer em editores usam listas duplamente encadeadas.
- Caches LRU (como os de navegadores e bancos de dados) combinam uma lista dupla com uma tabela *hash*.
- O núcleo do Linux usa listas duplamente encadeadas circulares (`list_head`) em centenas de lugares.
- Pilhas, filas e tabelas *hash* com encadeamento são construídas sobre listas.

#### 💼 Em processos seletivos

Listas encadeadas estão entre os temas **mais clássicos** de entrevistas técnicas, especialmente em empresas grandes, porque testam ponteiros, casos de borda (lista vazia, um nó só, remover o primeiro) e raciocínio passo a passo. A pergunta mais famosa é **inverter uma lista**; outras são detectar ciclo (algoritmo da lebre e da tartaruga, de Floyd), achar o meio, juntar duas listas ordenadas e implementar um *cache* LRU.

Perguntas que costumam aparecer:

- Inverta uma lista encadeada (iterativo e recursivo).
- Detecte se uma lista tem ciclo.
- Encontre o nó do meio em uma passada.
- Junte duas listas ordenadas.
- Quando usar lista encadeada em vez de vetor?

#### ⏱️ Complexidade

Inserir/remover no início: O(1). Buscar, acessar o i-ésimo ou inserir no fim sem ponteiro para o último: O(n).

#### 🐞 Erros comuns

- Perder a referência para o resto da lista ao reapontar ponteiros fora de ordem.
- Liberar um nó e depois ler `no->prox` (*use-after-free*): guarde o próximo antes do `free`.
- Esquecer o caso da lista vazia ou de um único nó.
- Em lista circular, percorrer com `while (p != NULL)`: o laço nunca termina. A parada é voltar ao nó inicial.
- Em lista dupla, atualizar `prox` e esquecer `ant` (ou o contrário).

### Memória: pilha (stack), heap e alocação dinâmica

Um programa em C usa três regiões principais de memória:

| Região | O que guarda | Quem libera |
| --- | --- | --- |
| Estática | Variáveis globais e `static` | O sistema, quando o programa termina |
| Pilha (*stack*) | Variáveis locais e parâmetros de cada chamada de função | Automaticamente, no `return` |
| *Heap* | Blocos pedidos com `malloc`, `calloc` e `realloc` | O programador, com `free` |

A alocação dinâmica serve quando o tamanho só é conhecido durante a execução ("quantos alunos?") ou quando os dados precisam sobreviver ao fim da função que os criou. Cada `malloc` deve ter exatamente um `free`; memória que nunca é liberada é um **vazamento** (*memory leak*).

#### 🌍 Onde é usado na prática

- Estruturas que crescem: listas, árvores, vetores dinâmicos (como o `ArrayList` do Java e o `vector` do C++, que são implementados com realocação).
- Servidores que rodam por meses: um vazamento pequeno por requisição acaba derrubando a máquina.
- Ferramentas como Valgrind e AddressSanitizer (`gcc -fsanitize=address`) acham vazamentos e acessos a memória liberada.

#### 💼 Em processos seletivos

Perguntas sobre *stack* × *heap* são frequentes em vagas de C/C++, sistemas e jogos, e aparecem em entrevistas de Java/C#/Python para explicar *garbage collection*. *Stack overflow* (recursão profunda demais) e vazamento de memória são temas recorrentes.

Perguntas que costumam aparecer:

- Qual a diferença entre *stack* e *heap*?
- O que é um vazamento de memória e como detectar?
- Qual a diferença entre `malloc` e `calloc`?
- O que acontece ao usar um ponteiro depois do `free` (*use-after-free*)?

#### 🐞 Erros comuns

- Não verificar se `malloc` devolveu `NULL`.
- Esquecer o `free`, ou chamar `free` duas vezes no mesmo bloco.
- Ler um campo do nó depois de liberá-lo: `free(p); p = p->prox;` lê memória liberada. O certo é guardar `p->prox` antes do `free`.
- Calcular o tamanho errado: `malloc(n)` em vez de `malloc(n * sizeof(int))`.

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
TLista* insere(char letra, TLista *lista) {
    TLista *aux;

    aux = (TLista*) malloc(sizeof(TLista));
    aux -> dado = letra;
    aux -> prox = lista;

    return aux;
}
```

```c
TLista* procura(char letra, TLista *lista) {
    //Recursivo
    if ((lista == NULL) || (lista->dado == letra))
        return lista;
    else
        return procura(letra, lista->prox);

    /*
     Iterativo
     TLista *aux;
     for (aux = lista; aux != NULL; aux = aux -> prox) {
     if (aux->dado == letra) {
     return aux;
     }
     }
     return aux;
     */
}
```

```c
TLista* removequalquer(TLista *lista, char letra) {
    TLista* aux;
    if (lista) {
        if (lista->dado == letra) {
            return removeinicio(lista);
        } else if (lista->prox) {
            if (lista->prox->dado == letra) {
                aux = lista->prox;
                lista->prox = lista->prox->prox;
                free(aux);
            } else
                removequalquer(lista->prox, letra);
        }
    }
    return lista;
}
```

Como cada `insere` coloca o novo nó **na frente**, a lista fica C → E → M → U → F. A `imprimerec` chama a si mesma **antes** de imprimir, então imprime do último para o primeiro: F, U, M, E, C. O código comentado no `main` mostra a mesma lista montada "à mão", com `no1`, `no2` e `no3`. Página [Listas](https://sitec-aramuni.vercel.app/pag8.html) do Site C.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
F
U
M
E
C

A lista não está vazia

Digite a letra a ser procurada: U
Achou

F
M
E
C

A lista está vazia
```

## ⚠️ Pontos de atenção

- `removeinicio` faz `free(lista)` e **depois** lê `lista->prox`: é um *use-after-free*. Pode ter funcionado no Windows de 2011 por sorte, porque a memória recém-liberada costuma ainda guardar o valor antigo; hoje pode travar. O certo é guardar `TLista *prox = lista->prox;` antes do `free`.
- Em `liberarec`, o `return` vem **antes** do `free`, então nenhum nó é liberado (vazamento). A mensagem final "A lista está vazia" aparece porque a função devolve `NULL` ao chegar ao fim da recursão, mas os nós continuam na memória. A versão iterativa comentada (`libera`) também está errada: anda para o próximo antes de liberar o atual.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/ListaDi.c -o ListaDi
./ListaDi
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

- [LeetCode 206: Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [LeetCode 21: Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [LeetCode 141: Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
- [LeetCode 876: Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)
- [LeetCode 203: Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
- [LeetCode 146: LRU Cache](https://leetcode.com/problems/lru-cache/)
- [LeetCode 707: Design Linked List (alocar e liberar nós)](https://leetcode.com/problems/design-linked-list/)

## 📂 Estrutura do projeto

```text
📁 ListaDi
│
├── 📁 src
│   └── ListaDi.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [ListaCi](../ListaCi): Lista circular
- [ListaDupEnc](../ListaDupEnc): Lista duplamente encadeada
- [Pilha](../Pilha): Pilha (com lista encadeada)
- [FilaDinamica](../FilaDinamica): Fila dinâmica

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): listas encadeadas](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html)
- [VisuAlgo: listas, pilhas e filas animadas](https://visualgo.net/en/list)
- [Wikipedia: Linked list](https://en.wikipedia.org/wiki/Linked_list)
- [Wikipedia: Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)
- [cppreference: malloc](https://en.cppreference.com/w/c/memory/malloc)
- [cppreference: calloc](https://en.cppreference.com/w/c/memory/calloc)
- [cppreference: free](https://en.cppreference.com/w/c/memory/free)
- [Paulo Feofiloff (IME-USP): alocação dinâmica](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)
- [Valgrind: guia rápido](https://valgrind.org/docs/manual/quick-start.html)
- [Paulo Feofiloff (IME-USP): recursão e algoritmos recursivos](https://www.ime.usp.br/~pf/algoritmos/aulas/recu.html)
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
