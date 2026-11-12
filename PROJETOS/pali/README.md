# Projeto pali (C, 2010–2011) 🔄

> **Palíndromo com cópia invertida**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Strings**.

## 📖 Descrição

Verifica se uma frase é palíndromo copiando-a de trás para frente em `string2` e comparando as duas, caractere por caractere.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag13.html) (seção **Palíndromo**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Inverter uma string em outro vetor
- Comparar strings caractere a caractere
- Função que devolve 1 ou 0

## 📚 Entendendo o conceito

Este projeto trabalha **Palíndromos e a técnica de dois ponteiros**, **Strings em C** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Palíndromos e a técnica de dois ponteiros

Um **palíndromo** é uma palavra ou frase que se lê igual nos dois sentidos: ARARA, OVO, RADAR. A forma eficiente de verificar é a técnica de **dois ponteiros**: um índice começa no início, outro no fim, e os dois andam em direção ao meio comparando os caracteres. Se algum par for diferente, não é palíndromo; se os índices se cruzarem, é.

A mesma verificação tem uma forma recursiva natural: a palavra é palíndromo se as pontas são iguais **e** o miolo também é palíndromo.

#### 🌍 Onde é usado na prática

- A técnica de dois ponteiros resolve muitos problemas em vetores ordenados (achar pares com soma alvo, remover duplicados) sem memória extra.
- Bioinformática: sequências palindrômicas de DNA marcam pontos de corte de enzimas de restrição.

#### 💼 Em processos seletivos

"Verifique se uma string é palíndromo" é uma das perguntas de aquecimento mais comuns. As variações ignoram maiúsculas, espaços e pontuação, permitem remover um caractere ou pedem o maior palíndromo dentro de uma string. Dois ponteiros é um dos padrões que mais caem em entrevistas.

Perguntas que costumam aparecer:

- Verifique um palíndromo sem criar uma cópia invertida.
- Ignore espaços e maiúsculas ("Socorram-me, subi no ônibus em Marrocos").
- Verifique se um número inteiro é palíndromo sem convertê-lo em texto.

#### ⏱️ Complexidade

O(n) de tempo; O(1) de memória com dois ponteiros (O(n) se criar uma cópia invertida).

#### 🐞 Erros comuns

- Comparar além do `'\0'`.
- Esquecer que maiúsculas e minúsculas são caracteres diferentes.

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
int palindrome() {
    char string[100], string2[100];
    int tam, i, j;
    printf("Digite uma frase: ");
    fflush(stdin);
    gets(string);
    tam = strlen(string);
    for (i = tam - 1, j = 0; i >= 0; i--, j++)
    string2[j] = string[i];
    string2[j] = '\0';
    for (i = 0; string[i] == string2[i]; i++);
    i--;
    if (i == tam) {
    return 1;
    }else return 0;
}
```

O primeiro `for` copia a string ao contrário e fecha `string2` com `'\0'`. O segundo avança enquanto os caracteres forem iguais; se chegou ao fim, é palíndromo. A versão recursiva com dois ponteiros, sem a cópia, está no [String_Recursivo](../String_Recursivo).

## 💻 Exemplo de execução

> Execução real com GCC no Linux: o bug descrito em **Pontos de atenção** faz o programa errar.

```text
Digite uma frase: ARARA
Não é palindrome!
```

## ⚠️ Pontos de atenção

- **Há um bug.** Quando as duas strings são iguais, o segundo `for` não para no `'\0'`: compara `'\0'` com `'\0'`, avança e continua comparando posições **não inicializadas** dos dois vetores. O resultado depende do lixo de memória: pode acertar em uma máquina e errar em outra. No Linux de hoje, ARARA é classificada como **não** palíndromo (veja a saída abaixo). A correção é parar no fim: `for (i = 0; i < tam && string[i] == string2[i]; i++);` e testar `i == tam`, sem o `i--`.
- Usa `gets`, removida do C11 por não limitar o tamanho da leitura: digitar mais caracteres do que o vetor comporta escreve fora dele. Troque por `fgets(str, sizeof str, stdin)` e remova o `\n` final. Veja a seção sobre portabilidade.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/pali.c -o pali
./pali
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

- [LeetCode 125: Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
- [LeetCode 9: Palindrome Number](https://leetcode.com/problems/palindrome-number/)
- [LeetCode 680: Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/)
- [LeetCode 344: Reverse String](https://leetcode.com/problems/reverse-string/)
- [LeetCode 242: Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [LeetCode 58: Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
- [Beecrowd 1238: Combinador](https://judge.beecrowd.com/pt/problems/view/1238)

## 📂 Estrutura do projeto

```text
📁 pali
│
├── 📁 src
│   └── pali.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [String_Recursivo](../String_Recursivo): Palíndromo recursivo
- [Inverte String Rec](../Inverte%20String%20Rec): Inverter string (recursivo)

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Palindromo](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Palindromo)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Palindrome](https://en.wikipedia.org/wiki/Palindrome)
- [cppreference: biblioteca de strings (<string.h>)](https://en.cppreference.com/w/c/string/byte)
- [cppreference: strlen](https://en.cppreference.com/w/c/string/byte/strlen)
- [cppreference: strcpy](https://en.cppreference.com/w/c/string/byte/strcpy)
- [cppreference: strcmp](https://en.cppreference.com/w/c/string/byte/strcmp)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)
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
