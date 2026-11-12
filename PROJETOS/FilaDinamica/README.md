# Projeto FilaDinamica (C, 2010–2011) 🚶

> **Fila dinâmica**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Estruturas de dados**.

## 📖 Descrição

Uma **fila** com lista encadeada e dois ponteiros, `ini` e `fim`, em `lista.h` (criado pelo Prof. Rafael Nunes em 23/05/2011) e `filaDinamica.c`. Enfileira F, U, M, E, C e imprime FUMEC, na ordem de chegada.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag10.html) (seção **Filas**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Fila FIFO
- Ponteiros para início e fim
- Inserção no fim em O(1)
- Impressão recursiva com ternário

## 📚 Entendendo o conceito

Este projeto trabalha **Fila (queue)**, **Listas encadeadas** e **Recursividade**.

### Fila (queue)

Uma **fila** é uma coleção em que o primeiro elemento a entrar é o primeiro a sair (**FIFO**, *First In, First Out*), como a fila do banco. As operações são `enfileirar` (inserir no fim), `desenfileirar` (remover do início), `frente` e `vazia`.

Com lista encadeada, a fila guarda dois ponteiros, `ini` e `fim`, para que as duas pontas sejam acessadas em O(1). Com vetor, usa-se um **buffer circular**: os índices de início e fim andam com `(i + 1) % capacidade`, reaproveitando as posições liberadas.

#### 🌍 Onde é usado na prática

- Filas de impressão, de atendimento e de processos no escalonador do sistema operacional.
- Sistemas de mensageria (RabbitMQ, Kafka, Amazon SQS) e filas de tarefas em *back-ends*.
- *Buffers* de teclado, de áudio e de rede.
- Busca em largura (BFS) em grafos: menor caminho em labirintos e redes sociais ("amigos de amigos").

#### 💼 Em processos seletivos

Filas aparecem em perguntas de implementação (fila com duas pilhas, fila circular) e, muito mais, como ferramenta da **busca em largura**, um dos padrões mais cobrados em problemas de grafos e de grades.

Perguntas que costumam aparecer:

- Implemente uma fila circular em vetor.
- Implemente uma fila com duas pilhas (e uma pilha com duas filas).
- Por que a fila com lista encadeada precisa do ponteiro `fim`?

#### ⏱️ Complexidade

Enfileirar e desenfileirar: O(1) com os ponteiros de início e fim.

#### 🐞 Erros comuns

- Esquecer de atualizar `fim` ao inserir na fila vazia, ou `fim` ao remover o último elemento.
- Não liberar os nós ao desenfileirar.

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

`lista.h`

```c
void insere(TFila* fila, char ch){
    TLista* aux;
    aux = (TLista*)malloc(sizeof(TLista));
    aux->dado = ch;

    //inverte o sentido do prox
    aux->prox = NULL;

    if(fila->fim != NULL)
        fila->fim->prox = aux;
    else
        fila->ini = aux;

    fila->fim = aux;
}
```

`lista.h`

```c
void imprimerec(TLista *lista){
    /*

    Imprime Iterativo

    TLista *aux;

    aux = fila->ini;

    while(aux != NULL){
        printf("fila --> %c\n", aux->dado);
        aux = aux->prox;
    }

    Imprime Recursivo

    if(lista){
    printf("%c", lista->dado);
    imprimerec(lista->prox);
    }

    */

    //Imprime Recursivo com Ternário
    lista ? printf("%c", lista->dado),imprimerec(lista->prox) : 0;
}
```

Com o ponteiro `fim`, inserir no final não exige percorrer a lista: o novo nó é ligado em `fila->fim->prox` e passa a ser o `fim`. Quando a fila está vazia, o novo nó é ao mesmo tempo `ini` e `fim`. A `imprimerec` tem três versões no comentário: iterativa, recursiva com `if` e recursiva com ternário (a ativa). Página [Filas](https://sitec-aramuni.vercel.app/pag10.html) do Site C.

## 💻 Exemplo de execução

```text
FUMEC
```

## ⚠️ Pontos de atenção

- Falta a operação de **desenfileirar** (remover do início, atualizando `fim` quando a fila esvazia) e a liberação dos nós. É um bom exercício.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/filaDinamica.c -o FilaDinamica
./FilaDinamica
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

- [LeetCode 622: Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)
- [LeetCode 225: Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
- [Beecrowd 1110: Jogando Cartas Fora](https://judge.beecrowd.com/pt/problems/view/1110)
- [LeetCode 206: Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [LeetCode 21: Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [LeetCode 141: Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
- [LeetCode 876: Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

## 📂 Estrutura do projeto

```text
📁 FilaDinamica
│
├── 📁 src
│   ├── lista.h                       └── Cabeçalho com a estrutura e as operações
│   └── filaDinamica.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [Pilha](../Pilha): Pilha (com lista encadeada)
- [ListaDi](../ListaDi): Lista dinâmica (simplesmente encadeada)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): filas](https://www.ime.usp.br/~pf/algoritmos/aulas/fila.html)
- [VisuAlgo: fila](https://visualgo.net/en/list)
- [Wikipedia: Queue (abstract data type)](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))
- [Paulo Feofiloff (IME-USP): listas encadeadas](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html)
- [Wikipedia: Linked list](https://en.wikipedia.org/wiki/Linked_list)
- [Wikipedia: Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)
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
