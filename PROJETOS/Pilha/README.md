# Projeto Pilha (C, 2010–2011) 📚

> **Pilha (com lista encadeada)**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Estruturas de dados**.

## 📖 Descrição

Uma **pilha** construída sobre a lista encadeada, separada em `pilha.h` (estrutura e operações) e `Pilha.c` (o `main`). Empilha F, U, M, E, C, imprime, desempilha três vezes e imprime de novo.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag11.html) (seção **Pilhas**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Pilha LIFO
- `push` = inserir no início; `pop` = remover do início
- Separar interface (`.h`) e uso (`.c`)
- Struct com o ponteiro `topo`

## 📚 Entendendo o conceito

Este projeto trabalha **Pilha (stack)**, **Listas encadeadas** e **Memória: pilha (stack), heap e alocação dinâmica**.

### Pilha (stack)

Uma **pilha** é uma coleção em que o último elemento a entrar é o primeiro a sair (**LIFO**, *Last In, First Out*), como uma pilha de pratos. As operações são `push` (empilhar no topo), `pop` (desempilhar do topo), `top`/`peek` (ver o topo) e `vazia`.

Ela pode ser implementada com um vetor (o topo é um índice) ou com uma lista encadeada (o topo é o primeiro nó, e `push`/`pop` são inserção e remoção no início). Nas duas formas, todas as operações custam O(1).

#### 🌍 Onde é usado na prática

- A própria **pilha de chamadas** do programa: cada chamada de função empilha um registro, cada `return` desempilha. Por isso recursão e pilha andam juntas.
- Desfazer (Ctrl+Z), o botão Voltar do navegador e a navegação entre telas em aplicativos móveis.
- Verificar parênteses e tags balanceados, avaliar expressões (notação polonesa reversa) e percorrer grafos em profundidade (DFS).

#### 💼 Em processos seletivos

Pilha é tema certo em entrevistas. O problema mais famoso é **validar parênteses** (`([]{})`). Outros clássicos: pilha que devolve o mínimo em O(1), fila feita com duas pilhas, próximo elemento maior (*monotonic stack*) e avaliar expressões.

Perguntas que costumam aparecer:

- Verifique se uma sequência de parênteses, colchetes e chaves está balanceada.
- Implemente uma pilha com mínimo em O(1).
- Implemente uma fila usando duas pilhas.
- O que acontece ao dar `pop` em uma pilha vazia?

#### ⏱️ Complexidade

`push`, `pop` e `top`: O(1).

#### 🐞 Erros comuns

- Fazer `pop` em pilha vazia (*underflow*).
- No `pop` com lista encadeada, liberar o nó do topo antes de guardar o ponteiro para o próximo.
- Esquecer de devolver o valor desempilhado.

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

## 🧠 Como funciona o código

`pilha.h`

```c
void push(TPilha *pilha,char ch){
    pilha->topo = insere(ch,pilha->topo);
}
```

`pilha.h`

```c
void pop(TPilha* pilha){
    pilha->topo = removeinicio(pilha->topo);
}
```

A pilha é só uma struct com um ponteiro `topo`, e as operações reaproveitam a lista: `push` chama `insere` (no início) e `pop` chama `removeinicio`. Depois de três `pop`, saem C, E e M, e sobra F, U. Página [Pilhas](https://sitec-aramuni.vercel.app/pag11.html) do Site C.

## 💻 Exemplo de execução

> Saída depois de corrigir o `removeinicio` como mostrado em **Pontos de atenção**. O código original termina com *segmentation fault* no Linux.

```text
FUMEC
FU
```

## ⚠️ Pontos de atenção

- **No Linux de hoje, o programa trava com *segmentation fault*.** O `removeinicio` faz `free(lista)` e depois lê `lista->prox` (*use-after-free*). Pode ter funcionado no Windows de 2011 por sorte, porque a memória recém-liberada costuma ainda guardar o valor antigo. A correção é guardar o próximo antes do `free`:

  ```c
  TLista* removeinicio(TLista *lista) {
      TLista *prox = lista->prox;
      free(lista);
      return prox;
  }
  ```
- O `pop` não devolve o valor desempilhado nem verifica se a pilha está vazia.
- Funções definidas dentro do `.h` funcionam neste projeto, mas causam erro de definição duplicada se o `.h` for incluído em dois `.c`. O habitual é deixar só os protótipos no `.h` e o código num `pilha.c`.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/Pilha.c -o Pilha
./Pilha
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

- [LeetCode 20: Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
- [LeetCode 155: Min Stack](https://leetcode.com/problems/min-stack/)
- [LeetCode 232: Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
- [Beecrowd 1068: Balanço de Parênteses I](https://judge.beecrowd.com/pt/problems/view/1068)
- [Beecrowd 1069: Diamantes e Areia](https://judge.beecrowd.com/pt/problems/view/1069)
- [LeetCode 206: Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [LeetCode 21: Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

## 📂 Estrutura do projeto

```text
📁 Pilha
│
├── 📁 src
│   ├── pilha.h                       └── Cabeçalho com a estrutura e as operações
│   └── Pilha.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [FilaDinamica](../FilaDinamica): Fila dinâmica
- [ListaDi](../ListaDi): Lista dinâmica (simplesmente encadeada)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): pilhas](https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html)
- [VisuAlgo: pilha](https://visualgo.net/en/list)
- [Wikipedia: Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Paulo Feofiloff (IME-USP): listas encadeadas](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html)
- [Wikipedia: Linked list](https://en.wikipedia.org/wiki/Linked_list)
- [Wikipedia: Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)
- [cppreference: malloc](https://en.cppreference.com/w/c/memory/malloc)
- [cppreference: calloc](https://en.cppreference.com/w/c/memory/calloc)
- [cppreference: free](https://en.cppreference.com/w/c/memory/free)
- [Paulo Feofiloff (IME-USP): alocação dinâmica](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)
- [Valgrind: guia rápido](https://valgrind.org/docs/manual/quick-start.html)

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
