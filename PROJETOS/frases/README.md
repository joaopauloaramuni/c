# Projeto frases (C, 2010–2011) 🔎

> **Contar letras em uma frase**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Strings**.

## 📖 Descrição

Lê uma frase e conta quantas vezes aparece a letra `c` minúscula.

## 🎯 Conceitos trabalhados

- Percorrer uma string até o `'\0'`
- Contador
- Comparação de caracteres

## 📚 Entendendo o conceito

Este projeto trabalha **Strings em C**, **Laços de repetição (while, do-while e for)** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

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

### Laços de repetição (while, do-while e for)

Laços repetem um bloco enquanto uma condição for verdadeira. Os três de C são equivalentes em poder, e a escolha é de legibilidade:

| Laço | Quando a condição é testada | Uso típico |
| --- | --- | --- |
| `while` | Antes de cada volta | Repetir até um evento (sentinela, fim do arquivo) |
| `do-while` | Depois de cada volta (roda pelo menos 1 vez) | Menus e validação de entrada |
| `for` | Antes de cada volta, com início e passo na mesma linha | Número de repetições conhecido, percorrer vetores |

Um **valor sentinela** (como `0` ou `-1`) é um valor especial que avisa o fim da entrada. `break` sai do laço na hora e `continue` pula para a próxima volta.

#### 🌍 Onde é usado na prática

- Percorrer coleções: linhas de um arquivo, itens de um carrinho, pixels de uma imagem.
- Laços de eventos: servidores, jogos e interfaces gráficas rodam um laço "infinito" que espera e trata eventos.
- Tentativas com limite: reconectar a um servidor até 3 vezes.

#### 💼 Em processos seletivos

Quase toda questão de algoritmo usa laços. Os avaliadores olham os **limites** (`<` ou `<=`? começa em 0 ou 1?), o caso de entrada vazia e a complexidade: dois laços aninhados sobre `n` elementos custam O(n²).

Perguntas que costumam aparecer:

- Some os números de 1 a n (com laço e com fórmula).
- Encontre o maior e o menor valor de uma sequência sem guardar todos.
- Qual a complexidade de dois `for` aninhados que vão até `n`?

#### ⏱️ Complexidade

Um laço que percorre `n` itens custa O(n). Laços aninhados multiplicam: O(n²), O(n³).

#### 🐞 Erros comuns

- Erro de "um a mais ou a menos" (*off-by-one*): `i <= n` em um vetor de `n` posições lê fora do vetor.
- Esquecer de atualizar a variável de controle e criar um laço infinito.
- Colocar `;` logo depois do `for (...)`: o laço fica vazio.

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
int main() {
    setbuf(stdout,NULL);
    char string[100]; /*String ate 99 caracteres*/
    int i, cont;
    printf("\n\nDigite uma frase: ");
    fflush(stdin);
    gets(string); /*Le a string*/
    printf("\n\nFrase digitida:\n%s",string);
    cont = 0;
    for (i=0;string[i]!='\0';i++)/*poderia ser tambem apenas string[i];
                                   pois !='\0' é verdadeiro e string[i]
                                   tambem é verdadeiro*/
    {
        if (string[i]=='c')/*Se for a letra 'c'*/
            cont = cont +1; /*Incremeta o contador de caracteres*/
    }
    printf("\nNumero de caracteres c = %d",cont);
    return 0;
}
```

O comentário do `for` explica um detalhe de C: `string[i]!='\0'` e só `string[i]` são a mesma condição, porque `'\0'` vale zero (falso) e qualquer outro caractere é verdadeiro. Em "Ciencia da computacao" há três `c` minúsculos; o `C` maiúsculo não conta.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
Digite uma frase: Ciencia da computacao


Frase digitida:
Ciencia da computacao
Numero de caracteres c = 3
```

## ⚠️ Pontos de atenção

- Para contar sem diferenciar maiúsculas, compare `tolower(string[i]) == 'c'` (da `<ctype.h>`). Usa `gets`, removida do C11 por não limitar o tamanho da leitura: digitar mais caracteres do que o vetor comporta escreve fora dele. Troque por `fgets(str, sizeof str, stdin)` e remova o `\n` final. Veja a seção sobre portabilidade.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/frases.c -o frases
./frases
```

> Compiladores atuais avisam (ou recusam) o uso de `gets`. Se o GCC reclamar, compile com `-std=gnu89` ou troque `gets` por `fgets`.

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

- [LeetCode 344: Reverse String](https://leetcode.com/problems/reverse-string/)
- [LeetCode 242: Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [LeetCode 58: Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
- [Beecrowd 1238: Combinador](https://judge.beecrowd.com/pt/problems/view/1238)
- [Beecrowd 1059: Números Pares](https://judge.beecrowd.com/pt/problems/view/1059)
- [Beecrowd 1060: Números Positivos](https://judge.beecrowd.com/pt/problems/view/1060)
- [Beecrowd 1078: Tabuada](https://judge.beecrowd.com/pt/problems/view/1078)

## 📂 Estrutura do projeto

```text
📁 frases
│
├── 📁 src
│   └── frases.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [Letra](../Letra): Menu de opções com strings
- [exerciciocharint](../exerciciocharint): Vetor de int e vetor de char

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: biblioteca de strings (<string.h>)](https://en.cppreference.com/w/c/string/byte)
- [cppreference: strlen](https://en.cppreference.com/w/c/string/byte/strlen)
- [cppreference: strcpy](https://en.cppreference.com/w/c/string/byte/strcpy)
- [cppreference: strcmp](https://en.cppreference.com/w/c/string/byte/strcmp)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)
- [cppreference: while](https://en.cppreference.com/w/c/language/while)
- [cppreference: do-while](https://en.cppreference.com/w/c/language/do)
- [cppreference: for](https://en.cppreference.com/w/c/language/for)
- [cppreference: break e continue](https://en.cppreference.com/w/c/language/break)
- [cppreference: gets (removida no C11)](https://en.cppreference.com/w/c/io/gets)
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
