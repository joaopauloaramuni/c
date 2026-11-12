# Projeto Esfera (C, 2010–2011) 🔵

> **Área e volume da esfera**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Calculadoras e matemática**.

## 📖 Descrição

Lê o raio e calcula a área da superfície (`4πr²`) e o volume (`4/3 πr³`) de uma esfera, cada um em um procedimento que devolve o resultado por ponteiro.

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag18.html) (seção **Esfera**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- `#define pi 3.14`
- `pow`
- Dois parâmetros de saída

## 📚 Entendendo o conceito

Este projeto trabalha **Geometria no plano e fórmulas com <math.h>**, **Ponteiros e passagem por referência** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Geometria no plano e fórmulas com <math.h>

Muitos programas traduzem fórmulas da matemática para código. A **distância entre dois pontos** vem do teorema de Pitágoras: `d = sqrt((x1 - x0)² + (y1 - y0)²)`. Um ponto está **dentro de um retângulo** de lados paralelos aos eixos quando `x` está entre os `x` dos cantos **e** `y` está entre os `y` dos cantos. A **esfera** tem área `4πr²` e volume `(4/3)πr³`.

A biblioteca `<math.h>` traz `sqrt`, `pow`, `sin`, `cos` e outras; no Linux, é preciso ligá-la na compilação com `-lm`.

#### 🌍 Onde é usado na prática

- Jogos: colisão entre objetos (distância entre centros, retângulos de colisão, as *bounding boxes*).
- Mapas e geolocalização: "lojas a menos de 5 km" (com a fórmula de Haversine na superfície da Terra).
- Interfaces gráficas: saber se o clique do mouse caiu dentro de um botão é exatamente o teste do retângulo.

#### 💼 Em processos seletivos

Problemas geométricos simples aparecem em testes online (pontos mais próximos, retângulos que se sobrepõem, ponto dentro de um polígono), e em entrevistas de jogos e computação gráfica. Comparar a distância ao quadrado, sem `sqrt`, é uma otimização que costuma impressionar.

Perguntas que costumam aparecer:

- Dois retângulos se sobrepõem?
- Encontre os k pontos mais próximos da origem.
- Por que comparar distâncias ao quadrado em vez de calcular a raiz?

#### 🐞 Erros comuns

- Guardar a distância em `int` e perder as casas decimais.
- Esquecer o `-lm` no Linux (erro de ligação `undefined reference to 'sqrt'`).
- Usar `pow(x, 2)` em vez de `x * x` em laços críticos (é mais lento).

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
void area(float *r, float *A) {
    *A = (4 * pi) * (pow(*r, 2));
}
```

```c
void volume(float *r, float *B) {
    *B = ((4 * pi) * pow(*r, 3)) / 3;
}
```

Com raio 2: área = 4 × 3,14 × 4 = 50,24 e volume = 4 × 3,14 × 8 / 3 = 33,49. A página [Esfera](https://sitec-aramuni.vercel.app/pag18.html) do Site C traz o enunciado, que exigia a função `void calc_esfera` com ponteiros.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
** ESFERA **

Digite o valor do raio da circunferencia: 2

Area: 50.240002
Volume: 33.493332
```

## ⚠️ Pontos de atenção

- `pi` com duas casas (3,14) dá um erro de cerca de 0,05%. A `<math.h>` de muitos compiladores tem `M_PI`, e dá para escrever `#define PI 3.14159265358979`.
- No Linux, compile com `-lm`.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/Esfera.c -o Esfera -lm
./Esfera
```

O `-lm` liga a biblioteca matemática (`sqrt`, `pow`), obrigatório no Linux.

> O `fflush(stdin)` só limpa a entrada no Windows. No Linux e no macOS, algumas leituras podem "pular"; rode no Windows ou adapte como explicado na seção sobre portabilidade.

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

No Linux, adicione a biblioteca `m` em **Project → Properties → C/C++ Build → Settings → GCC C Linker → Libraries**.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1015: Distância Entre Dois Pontos](https://judge.beecrowd.com/pt/problems/view/1015)
- [Beecrowd 1011: Esfera](https://judge.beecrowd.com/pt/problems/view/1011)
- [LeetCode 836: Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/)
- [LeetCode 973: K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)
- [LeetCode 344: Reverse String (dois ponteiros)](https://leetcode.com/problems/reverse-string/)
- [LeetCode 283: Move Zeroes](https://leetcode.com/problems/move-zeroes/)

## 📂 Estrutura do projeto

```text
📁 Esfera
│
├── 📁 src
│   └── Esfera.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [Distancia](../Distancia): Distância entre dois pontos
- [Retangulo](../Retangulo): Ponto dentro do retângulo

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: sqrt](https://en.cppreference.com/w/c/numeric/math/sqrt)
- [cppreference: pow](https://en.cppreference.com/w/c/numeric/math/pow)
- [Wikipedia: Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance)
- [cppreference: ponteiros](https://en.cppreference.com/w/c/language/pointer)
- [Paulo Feofiloff (IME-USP): endereços e ponteiros](https://www.ime.usp.br/~pf/algoritmos/aulas/pont.html)
- [Python Tutor: visualizar ponteiros em C passo a passo](https://pythontutor.com/c.html)
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
