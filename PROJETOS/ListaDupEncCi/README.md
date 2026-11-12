# Projeto ListaDupEncCi (C, 2010–2011) 🔄

> **Lista duplamente encadeada circular**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Estruturas de dados**.

## 📖 Descrição

Junta as duas ideias anteriores: cada nó tem `prox` e `ant`, e a lista é circular nos dois sentidos. O `main` insere F, U, M, E, C, imprime a lista, busca a letra F e deixa a remoção comentada.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag8.html) (seção **Listas**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Lista dupla e circular
- Percorrer até voltar ao início com `do-while`

## 📚 Entendendo o conceito

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

## 🧠 Como funciona o código

```c
void imprimir(TLista *lista, TLista *cont) {
    do {
        printf("%c", cont->dado);
        cont = cont->prox;
    } while (cont != lista);
}
```

```c
void imprime(TLista *lista) {
    while(lista){
        printf("\n%c", lista->dado);
        lista = lista->prox;
    }
}
```

`imprimir` usa o padrão certo para listas circulares: `do { ... } while (cont != lista);`, que para ao voltar ao nó de partida. Numa lista dupla circular, o último nó é sempre `lista->ant`, então dá para inserir no fim em O(1).

## 💻 Exemplo de execução

> Execução real no Linux, interrompida com Ctrl + C: depois da primeira linha, a função `imprime` repete as letras indefinidamente.

```text
C
C
F
U
M
E
C
F
U
M
E
C
F
U
...
```

## ⚠️ Pontos de atenção

- **O programa entra em laço infinito.** O `main` chama também a função `imprime`, que percorre com `while(lista)`. Numa lista circular, nenhum ponteiro é `NULL`, e o laço imprime C, F, U, M, E sem parar (veja a saída). Remova a chamada `imprime(lista);` ou troque a condição.
- O `main` chama `imprimir(lista->prox, lista)`, com os argumentos na ordem trocada: o laço para logo depois do primeiro nó e a primeira linha mostra só `C`. Para imprimir a lista inteira, chame `imprimir(lista, lista)`.
- A `insere` percorre a lista com dois contadores em vez de usar `lista->ant`, e a `removedado` atualiza só `prox`.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/ListaDupEncCi.c -o ListaDupEncCi
./ListaDupEncCi
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

- [LeetCode 206: Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [LeetCode 21: Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [LeetCode 141: Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
- [LeetCode 876: Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)
- [LeetCode 203: Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
- [LeetCode 146: LRU Cache](https://leetcode.com/problems/lru-cache/)

## 📂 Estrutura do projeto

```text
📁 ListaDupEncCi
│
├── 📁 src
│   └── ListaDupEncCi.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [ListaCi](../ListaCi): Lista circular
- [ListaDupEnc](../ListaDupEnc): Lista duplamente encadeada

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): listas encadeadas](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html)
- [VisuAlgo: listas, pilhas e filas animadas](https://visualgo.net/en/list)
- [Wikipedia: Linked list](https://en.wikipedia.org/wiki/Linked_list)
- [Wikipedia: Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)

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
