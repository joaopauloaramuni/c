# Projeto polinomio (C, 2010–2011) 📈

> **Polinômio com lista circular**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Estruturas de dados**.

## 📖 Descrição

Representa um **polinômio** como uma lista circular em que cada nó é um termo (coeficiente e expoente). Pelo menu, insere termos e imprime o polinômio na ordem de inserção ou "ordenado".

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag2.html) (seção **Polinômio**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Lista encadeada de structs com dois campos
- Impressão recursiva formatada
- Sinal do coeficiente na impressão

## 📚 Entendendo o conceito

Este projeto trabalha **Listas encadeadas** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

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
void imprime(TLista *lista, TLista *aux) {
    char ch = '+';
    if (aux->coef < 0) {
        ch = ' ';
    }
    if (aux->prox == lista) {
        if (aux->expo != 0)
            printf("%c%dx^%d ", ch, aux->coef, aux->expo);
        else
            printf("%c%d", ch, aux->coef);
    } else {
        imprime(lista, aux->prox);
        if (aux->expo != 0)
            printf("%c%dx^%d ", ch, aux->coef, aux->expo);
        else
            printf("%c%d", ch, aux->coef);
    }
}
```

Listas são a forma natural de guardar polinômios esparsos, como 3x¹⁰⁰ + 1, que num vetor desperdiçaria 99 posições. A impressão coloca `+` antes dos coeficientes positivos e deixa o sinal de menos dos negativos aparecer sozinho. Página [Polinômio](https://sitec-aramuni.vercel.app/pag2.html) do Site C.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
Polinômio

Menu
1-Inserir Dado
2-Imprimir Polinômio
3-Imprimir Polinômio Ordenado
0-Sair

Opção: 1

Digite o coeficiente: 3
Digite o expoente: 2

Dado inserido com sucesso.

(menu)

Opção: 1

Digite o coeficiente: 5
Digite o expoente: 0

Dado inserido com sucesso.

(menu)

Opção: 1

Digite o coeficiente: -2
Digite o expoente: 1

Dado inserido com sucesso.

(menu)

Opção: 2

Polinômio: +3x^2 +5 -2x^1 

(menu)

Opção: 3

Polinômio:  -2x^1 +3x^2 +5

(menu)

Opção: 0
```

## ⚠️ Pontos de atenção

- A opção 3 não ordena de verdade: `ordena` faz uma única passada trocando vizinhos, e na execução abaixo o resultado é `-2x^1 +3x^2 +5`. Uma ordenação completa (por exemplo, inserção já na posição certa) resolveria.
- Termos com o mesmo expoente não são somados (3x² + 2x² fica como dois termos).
- O expoente 1 aparece como `x^1`.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/polinomio.c -o polinomio
./polinomio
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

## 📂 Estrutura do projeto

```text
📁 polinomio
│
├── 📁 src
│   └── polinomio.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [ListaCi](../ListaCi): Lista circular
- [josephus](../josephus): Problema de Josephus

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Paulo Feofiloff (IME-USP): listas encadeadas](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html)
- [VisuAlgo: listas, pilhas e filas animadas](https://visualgo.net/en/list)
- [Wikipedia: Linked list](https://en.wikipedia.org/wiki/Linked_list)
- [Wikipedia: Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)
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
