# Projeto Char (C, 2010–2011) 🔤

> **Caractere e tabela ASCII**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Primeiros passos**.

## 📖 Descrição

Lê um caractere e mostra o seu código na **tabela ASCII**: `A` é 65, `a` é 97, `0` é 48. A função `xulambs` recebe um `char` e devolve o mesmo valor como `int`.

## 🎯 Conceitos trabalhados

- `char` é um número pequeno
- Tabela ASCII
- Conversão implícita de `char` para `int`

## 📚 Entendendo o conceito

Este projeto trabalha **Variáveis, tipos e constantes** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Variáveis, tipos e constantes

Uma **variável** é um nome para uma região da memória, e o **tipo** diz quantos bytes ela ocupa e como interpretar esses bytes: `int` (inteiro, normalmente 4 bytes), `float` e `double` (ponto flutuante), `char` (1 byte, um caractere ou um número pequeno).

Valores que não devem mudar podem ser declarados de duas formas: com `const` (uma variável de verdade, que o compilador protege contra escrita) ou com `#define` (uma **macro**, que o pré-processador troca pelo texto antes da compilação, sem ocupar memória e sem tipo).

#### 🌍 Onde é usado na prática

- Escolher o tipo certo evita bugs de precisão: dinheiro em `float` acumula erro de arredondamento; sistemas financeiros usam inteiros (centavos) ou tipos decimais.
- Constantes nomeadas (`MAX_ALUNOS`, `PI`) deixam o código legível e mudam em um lugar só.
- `typedef` cria apelidos de tipo, muito usados em APIs (`size_t`, `FILE`, `uint32_t`).

#### 💼 Em processos seletivos

Perguntas sobre tipos aparecem como "pegadinhas" em testes técnicos: estouro de inteiro (*overflow*), divisão inteira e comparação de `float` com `==`.

Perguntas que costumam aparecer:

- Qual a diferença entre `const` e `#define`?
- Quanto vale `7 / 2` em C? E `7 / 2.0`?
- Por que não comparar dois `float` com `==`?
- O que acontece quando um `int` passa do maior valor possível?

#### 🐞 Erros comuns

- Usar uma variável local sem inicializar: ela guarda "lixo" de memória.
- Dividir dois inteiros esperando resultado com casas decimais.
- Esquecer que `#define` é substituição de texto: `#define DOBRO(x) x*2` faz `DOBRO(1+1)` virar `1+1*2 = 3`.

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
int xulambs(char letra) //Recebe char devolve int
{
return letra;
}
```

Em C, um `char` guarda um número de 1 byte; a letra é só a forma de mostrá-lo. `printf("%c", 65)` imprime `A` e `printf("%d", 'A')` imprime `65`. Por isso dá para fazer contas com letras: `'a' - 'A'` é 32, a distância entre minúsculas e maiúsculas.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
Entre com o caracter: A

O carater digitado: A na tabela ASCII é 65
```

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/CHAR1.c -o Char
./Char
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

- [Beecrowd 1002: Área do Círculo](https://judge.beecrowd.com/pt/problems/view/1002)
- [Beecrowd 1008: Salário](https://judge.beecrowd.com/pt/problems/view/1008)

## 📂 Estrutura do projeto

```text
📁 Char
│
├── 📁 src
│   └── CHAR1.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [exerciciocharint](../exerciciocharint): Vetor de int e vetor de char
- [frases](../frases): Contar letras em uma frase

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: tipos aritméticos](https://en.cppreference.com/w/c/language/arithmetic_types)
- [cppreference: const](https://en.cppreference.com/w/c/language/const)
- [cppreference: typedef](https://en.cppreference.com/w/c/language/typedef)
- [cppreference: #define](https://en.cppreference.com/w/c/preprocessor/replace)
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
