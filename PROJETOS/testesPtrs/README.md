# Projeto testesPtrs (C, 2010–2011) 🧪

> **Testes com ponteiros**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Ponteiros**.

## 📖 Descrição

Aprofunda o [Ponteiros](../Ponteiros): além do endereço de `x` e do valor por `*ptr`, mostra o **endereço do próprio ponteiro** (`&ptr`) e uma função que recebe uma string, um ponteiro para `int`, um vetor de `char` e um `int`.

## 🎯 Conceitos trabalhados

- `&ptr`: o ponteiro também mora na memória
- Vetor como parâmetro vira ponteiro
- `char *` e `char str[100]` como parâmetros

## 📚 Entendendo o conceito

Este projeto trabalha **Ponteiros e passagem por referência** e **Strings em C**.

### Ponteiros e passagem por referência

Um **ponteiro** é uma variável que guarda um **endereço de memória**. O operador `&` pega o endereço de uma variável (`&x`) e o operador `*` acessa o valor que está naquele endereço (`*p`, a **desreferência**). Em `int *p = &x;`, `p` aponta para `x`, e `*p = 10;` muda o próprio `x`.

Como C só tem passagem por valor, ponteiros são a forma de uma função **alterar variáveis de quem a chamou** (passagem por referência) e de **devolver mais de um resultado** (parâmetros de saída). Vetores também são acessados por ponteiros: `v[i]` é exatamente `*(v + i)`.

#### 🌍 Onde é usado na prática

- Funções da biblioteca padrão que preenchem variáveis: `scanf("%d", &x)`, `strtol(texto, &fim, 10)`.
- Estruturas de dados encadeadas (listas, pilhas, filas, árvores, grafos) são feitas de nós ligados por ponteiros.
- Passar estruturas grandes por ponteiro evita copiá-las a cada chamada.
- Linguagens como Java, Python e C# usam referências, que são ponteiros com proteções; entender ponteiros explica por que `a = b` em objetos não copia o objeto.

#### 💼 Em processos seletivos

Ponteiros são tema certo em vagas de C, C++, sistemas embarcados e jogos, e aparecem indiretamente em qualquer vaga quando o assunto é lista encadeada ou passagem por referência. A pergunta clássica é escrever a função `troca` (*swap*) e explicar por que a versão sem ponteiros não funciona.

Perguntas que costumam aparecer:

- Escreva `void troca(int *a, int *b)`.
- Qual a diferença entre `int *p`, `*p` e `&p`?
- O que é um ponteiro nulo? E um ponteiro pendente (*dangling pointer*)?
- Por que `*p++` e `(*p)++` fazem coisas diferentes?

#### 🐞 Erros comuns

- Desreferenciar ponteiro não inicializado ou `NULL` (*segmentation fault*).
- Imprimir endereço com `%d` em vez de `%p`.
- Usar o ponteiro depois de liberar a memória para onde ele apontava.

### Strings em C

C não tem um tipo `string`: uma string é um **vetor de `char` terminado pelo caractere nulo `'\0'`**. A palavra `"FUMEC"` ocupa 6 bytes, 5 letras mais o `'\0'`. Todas as funções de `<string.h>` dependem desse terminador para saber onde o texto acaba.

| Função | O que faz |
| --- | --- |
| `strlen(s)` | Conta os caracteres até o `'\0'` (sem contá-lo) |
| `strcpy(dest, orig)` | Copia `orig` para `dest`, incluindo o `'\0'` |
| `strcat(dest, orig)` | Acrescenta `orig` no fim de `dest` |
| `strcmp(a, b)` | Compara: 0 se iguais, negativo ou positivo conforme a ordem |

Nenhuma delas confere o tamanho do destino. Por isso estouros de *buffer* em strings estão entre as falhas de segurança mais antigas e mais exploradas.

#### 🌍 Onde é usado na prática

- Processamento de texto: validar CPF ou e-mail, contar palavras, montar mensagens.
- Protocolos de rede baseados em texto (HTTP, SMTP) e formatos como CSV e JSON.
- Falhas históricas de segurança (como o *worm* de Morris, de 1988, que explorou a função `gets`) vieram de strings sem limite de tamanho.

#### 💼 Em processos seletivos

Manipulação de strings é um dos temas mais cobrados: palíndromos, anagramas, inverter palavras, contar caracteres, compressão simples, encontrar uma substring. Em C, também é comum pedirem para **reimplementar** `strlen`, `strcpy` ou `strcmp` sem a biblioteca.

Perguntas que costumam aparecer:

- Implemente `strlen` e `strcpy` com ponteiros.
- Verifique se duas palavras são anagramas.
- Inverta as palavras de uma frase.
- Por que `gets` foi removida da linguagem?

#### ⏱️ Complexidade

`strlen` é O(n), porque precisa percorrer a string até achar o `'\0'`; chamar `strlen` na condição de um `for` deixa o laço O(n²).

#### 🐞 Erros comuns

- Esquecer espaço para o `'\0'`.
- Comparar strings com `==` (compara endereços, não o texto). Use `strcmp`.
- Atribuir com `=` depois da declaração (`nome = "Ana";` não compila). Use `strcpy`.
- Ler com `gets` ou com `scanf("%s")` sem limite. Use `fgets(s, sizeof s, stdin)` ou `scanf("%99s", s)`.

## 🧠 Como funciona o código

```c
void pointer(char *ptr, int *ptr2, char str[100], int x) {
    printf("%s - %d - %s - %d\n", ptr, *ptr2, str, x);
}
```

Na função `pointer`, `char *ptr` e `char str[100]` são, para o compilador, a mesma coisa: um ponteiro para `char`. O `[100]` no parâmetro é ignorado. Na execução abaixo, `&ptr` ficou 8 bytes depois de `&x`: as duas variáveis locais estão lado a lado na pilha (a posição exata depende do compilador).

## 💻 Exemplo de execução

> Os endereços mudam a cada execução.

```text
Endereco de x 0x7ffe03071600
Conteudo de ptr 0x7ffe03071600
Conteudo de x 10
Dado guardado em x atraves de ptr 10
Endereco de ptr 0x7ffe03071608
xubaca - 10 - xeruca - 20
```

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/testesPtrs.c -o testesPtrs
./testesPtrs
```

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [LeetCode 344: Reverse String (dois ponteiros)](https://leetcode.com/problems/reverse-string/)
- [LeetCode 283: Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [LeetCode 242: Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [LeetCode 58: Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
- [Beecrowd 1238: Combinador](https://judge.beecrowd.com/pt/problems/view/1238)

## 📂 Estrutura do projeto

```text
📁 testesPtrs
│
├── 📁 src
│   └── testesPtrs.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [Ponteiros](../Ponteiros): Ponteiros: o primeiro contato
- [ExerPonteiros](../ExerPonteiros): Exercício: string e ponteiro

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Funcoes_Ponteiros](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Funcoes_Ponteiros)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: ponteiros](https://en.cppreference.com/w/c/language/pointer)
- [Paulo Feofiloff (IME-USP): endereços e ponteiros](https://www.ime.usp.br/~pf/algoritmos/aulas/pont.html)
- [Python Tutor: visualizar ponteiros em C passo a passo](https://pythontutor.com/c.html)
- [cppreference: biblioteca de strings (<string.h>)](https://en.cppreference.com/w/c/string/byte)
- [cppreference: strlen](https://en.cppreference.com/w/c/string/byte/strlen)
- [cppreference: strcpy](https://en.cppreference.com/w/c/string/byte/strcpy)
- [cppreference: strcmp](https://en.cppreference.com/w/c/string/byte/strcmp)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)

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
