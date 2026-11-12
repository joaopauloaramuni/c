# Projeto ExerRevi3 (C, 2010–2011) #️⃣

> **Exercício de revisão 3: função hash**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Calculadoras e matemática**.

## 📖 Descrição

Uma função `gerahash(arg1, arg2)` que devolve `arg1 % arg2`. Com `arg2 = 13`, **qualquer** número digitado vira um valor de 0 a 12. É a ideia por trás das tabelas *hash*.

## 🎯 Conceitos trabalhados

- Operador de resto `%`
- Função *hash* pelo método da divisão
- Tabela de 13 posições

## 📚 Entendendo o conceito

Este projeto trabalha **Funções hash**, **Operadores aritméticos, divisão inteira e resto** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Funções hash

Uma **função hash** transforma uma chave (um número, um texto) em um índice de uma tabela. A mais simples é o **método da divisão**: `h(chave) = chave % m`, que sempre devolve um valor de 0 a m − 1. Com m = 13, qualquer chave cai em uma das 13 posições.

Uma **tabela hash** usa esse índice para guardar e buscar dados em tempo médio O(1). Duas chaves diferentes podem cair na mesma posição (**colisão**), e a tabela precisa tratar isso, por exemplo com uma lista encadeada em cada posição. Escolher m primo ajuda a espalhar melhor as chaves.

#### 🌍 Onde é usado na prática

- Os dicionários do Python, o `HashMap` do Java e os objetos do JavaScript são tabelas *hash*.
- Índices de bancos de dados, *caches* e deduplicação de arquivos.
- Funções *hash* criptográficas (SHA-256), que são outra família, protegem senhas e garantem a integridade de arquivos e *commits* do Git.

#### 💼 Em processos seletivos

Tabelas *hash* são, possivelmente, a ferramenta **mais usada** em soluções de entrevistas: contar frequências, achar duplicados, Two Sum, agrupar anagramas. Também se pergunta como elas funcionam por dentro: colisões, fator de carga e por que o pior caso é O(n).

Perguntas que costumam aparecer:

- Como uma tabela *hash* trata colisões?
- Por que a busca é O(1) em média e O(n) no pior caso?
- O que acontece com `chave % m` quando a chave é negativa em C?

#### ⏱️ Complexidade

Inserir, buscar e remover: O(1) em média; O(n) no pior caso.

#### 🐞 Erros comuns

- Usar `%` com chave negativa (em C o resto fica negativo e vira índice inválido).
- Escolher um m que se relaciona com o padrão das chaves (por exemplo, potência de 10 para chaves terminadas em 0).

### Operadores aritméticos, divisão inteira e resto

Os operadores `+ - * /` funcionam como na matemática, com uma diferença importante: **se os dois lados são inteiros, a divisão é inteira** (`7 / 2` dá `3`). Basta um dos lados ser `float`/`double` para a conta ser feita com casas decimais (`7 / 2.0` dá `3.5`), o que se força com uma conversão (*cast*): `(double) soma / n`.

O operador `%` devolve o **resto** da divisão inteira (`7 % 2` dá `1`). Ele é a ferramenta para testar paridade (`n % 2 == 0`), pegar o último dígito (`n % 10`), andar em círculo (`(i + 1) % n`) e espalhar valores em uma tabela *hash* (`chave % tamanho`).

#### 🌍 Onde é usado na prática

- Relógios, calendários e *buffers* circulares usam resto (`hora % 24`, `indice % capacidade`).
- Tabelas *hash* usam `%` para mapear uma chave em uma posição do vetor.
- Algoritmos com dígitos (somar dígitos, inverter número, validar CPF) combinam `% 10` e `/ 10`.

#### 💼 Em processos seletivos

Problemas com `%` e `/ 10` estão entre os mais comuns em etapas técnicas iniciais: inverter um inteiro, verificar se um número é palíndromo sem convertê-lo em texto, somar dígitos, FizzBuzz.

Perguntas que costumam aparecer:

- Implemente FizzBuzz.
- Inverta os dígitos de um inteiro sem usar strings.
- Quanto vale `-7 % 3` em C? (Desde o C99, o resto tem o sinal do dividendo: `-1`.)

#### 🐞 Erros comuns

- Esperar casas decimais em `int / int`.
- Dividir por zero: com inteiros, o programa é encerrado; com `float`, o resultado vira `inf` ou `nan`.
- Imprimir um `float` com `%.0f` e achar que a conta está errada: o valor só foi arredondado na exibição.

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
int gerahash(int arg1, int arg2){
    int chave;
    chave = arg1 % arg2;
    return (chave);
}
```

Com 100, o resultado é `100 % 13 = 9`: a chave 100 iria para a posição 9 de uma tabela de 13 posições. O 13 é primo, o que ajuda a espalhar melhor as chaves.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
Entre com o valor inteiro: 100
Nao importa o valor que vc digitar, o resultado sera sempre um valor entre 0 e 12, veja: 9
```

## ⚠️ Pontos de atenção

- Para números negativos, o resto em C é negativo (`-5 % 13` dá `-5`), e a promessa da mensagem ("sempre entre 0 e 12") falha. A correção é `((x % m) + m) % m`.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/ExerRevi3.c -o ExerRevi3
./ExerRevi3
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

- [LeetCode 1: Two Sum](https://leetcode.com/problems/two-sum/)
- [LeetCode 705: Design HashSet](https://leetcode.com/problems/design-hashset/)
- [LeetCode 706: Design HashMap](https://leetcode.com/problems/design-hashmap/)
- [Beecrowd 1257: Array Hash](https://judge.beecrowd.com/pt/problems/view/1257)
- [LeetCode 412: Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
- [LeetCode 7: Reverse Integer](https://leetcode.com/problems/reverse-integer/)
- [Beecrowd 1074: Par ou Ímpar](https://judge.beecrowd.com/pt/problems/view/1074)

## 📂 Estrutura do projeto

```text
📁 ExerRevi3
│
├── 📁 src
│   └── ExerRevi3.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [parouimpar](../parouimpar): Par ou ímpar
- [ExerRevi4](../ExerRevi4): Exercício de revisão 4: sete operações

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [VisuAlgo: tabela hash](https://visualgo.net/en/hashtable)
- [Wikipedia: Hash function](https://en.wikipedia.org/wiki/Hash_function)
- [cppreference: operadores aritméticos](https://en.cppreference.com/w/c/language/operator_arithmetic)
- [cppreference: conversões implícitas](https://en.cppreference.com/w/c/language/conversion)
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
