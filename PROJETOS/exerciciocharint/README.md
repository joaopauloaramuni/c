# Projeto exerciciocharint (C, 2010–2011) 🔢

> **Vetor de int e vetor de char**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Strings**.

## 📖 Descrição

Percorre um vetor de inteiros e uma string usando o mesmo truque: **parar no zero**. O vetor `{10, 15, 30, 45}` tem 100 posições, e as que não foram inicializadas valem 0; a string `"teste"` termina no `'\0'`, que também vale 0.

## 🎯 Conceitos trabalhados

- Inicialização parcial de vetor (o resto vira 0)
- Valor sentinela
- Strings são vetores de `char`

## 📚 Entendendo o conceito

Este projeto trabalha **Vetores (arrays)** e **Strings em C**.

### Vetores (arrays)

Um **vetor** guarda vários valores do mesmo tipo em posições **contíguas** de memória, acessadas por um índice que começa em **0**. Em `int v[5];` os índices válidos vão de `v[0]` a `v[4]`.

Acessar `v[i]` custa O(1) porque o endereço é calculado direto: início do vetor + `i` × tamanho do elemento. Em compensação, o tamanho é fixo, e C **não verifica os limites**: ler `v[5]` não dá erro de compilação, apenas lê o que estiver na memória ao lado. Quando um vetor é passado para uma função, ele vira um ponteiro para o primeiro elemento, e o tamanho precisa ir junto como parâmetro.

#### 🌍 Onde é usado na prática

- Qualquer lista de tamanho conhecido: notas de uma turma, leituras de um sensor, *pixels* de uma linha de imagem.
- A memória contígua aproveita o *cache* do processador; por isso percorrer um vetor é muito mais rápido que percorrer uma lista encadeada.
- É a base de estruturas mais sofisticadas: pilhas e filas em vetor, *heaps*, tabelas *hash*.

#### 💼 Em processos seletivos

Vetores são o tema mais frequente em entrevistas técnicas. Os padrões que mais caem são **dois ponteiros**, **janela deslizante**, **soma de prefixos** e o uso de *hash* para contar elementos.

Perguntas que costumam aparecer:

- Some, calcule a média e encontre o maior elemento.
- Inverta um vetor no próprio lugar.
- Dado um vetor e um alvo, encontre dois números que somam o alvo (Two Sum).
- Por que o índice começa em 0?

#### ⏱️ Complexidade

Acesso por índice O(1); busca de um valor O(n); inserir no meio O(n), porque é preciso deslocar os elementos.

#### 🐞 Erros comuns

- Ler ou escrever fora dos limites (`i <= n`).
- Usar `sizeof(v) / sizeof(v[0])` dentro de uma função que recebeu o vetor por parâmetro (ali `v` é ponteiro, e a conta dá errado).
- Esquecer de inicializar o vetor antes de somar os elementos.

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
int main() {
    char str[100]="teste";
    int i,vet[100]={10,15,30,45};
    i=0;
    while(vet[i]){
        printf("A posicao do numero %d tem o conteudo %d\n",i,vet[i]);
        i++;
    }
    printf("\n");

    for (i=0;str[i];i++) {
        printf("A posicao da palavra %d tem conteudo %c\n",i,str[i]);
    }

    return 0;
}
```

`while(vet[i])` para no primeiro 0, por isso imprime só as 4 primeiras posições. A ideia funciona para a string, que sempre termina em `'\0'`, mas é frágil para números: se um dos valores fosse 0, o laço pararia antes da hora.

## 💻 Exemplo de execução

```text
A posicao do numero 0 tem o conteudo 10
A posicao do numero 1 tem o conteudo 15
A posicao do numero 2 tem o conteudo 30
A posicao do numero 3 tem o conteudo 45

A posicao da palavra 0 tem conteudo t
A posicao da palavra 1 tem conteudo e
A posicao da palavra 2 tem conteudo s
A posicao da palavra 3 tem conteudo t
A posicao da palavra 4 tem conteudo e
```

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/exerciciocharint.c -o exerciciocharint
./exerciciocharint
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

- [LeetCode 1: Two Sum](https://leetcode.com/problems/two-sum/)
- [LeetCode 1480: Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)
- [Beecrowd 1172: Substituição em Vetor I](https://judge.beecrowd.com/pt/problems/view/1172)
- [Beecrowd 1173: Preenchimento de Vetor I](https://judge.beecrowd.com/pt/problems/view/1173)
- [LeetCode 344: Reverse String](https://leetcode.com/problems/reverse-string/)
- [LeetCode 242: Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [LeetCode 58: Length of Last Word](https://leetcode.com/problems/length-of-last-word/)

## 📂 Estrutura do projeto

```text
📁 exerciciocharint
│
├── 📁 src
│   └── exerciciocharint.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [Char](../Char): Caractere e tabela ASCII
- [frases](../frases): Contar letras em uma frase

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Array_Ex1](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Array_Ex1)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: arrays](https://en.cppreference.com/w/c/language/array)
- [cppreference: inicialização de arrays](https://en.cppreference.com/w/c/language/array_initialization)
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
