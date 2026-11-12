# Projeto exerstruct2 (C, 2010–2011) 🗂️

> **Exercício: cadastro com alocação dinâmica**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Structs**.

## 📖 Descrição

Cadastro de clientes em que o tamanho do vetor é perguntado ao usuário e alocado com `malloc(tam * sizeof(TCli))`. A função `dinamica()` lê nome, telefone e rua e mostra o cadastro; `sair()` pergunta se há outro.

## 🎯 Conceitos trabalhados

- Vetor de structs alocado em tempo de execução
- Variável global de ponteiro
- Laço `do-while` controlado por função

## 📚 Entendendo o conceito

Este projeto trabalha **Structs e typedef**, **Memória: pilha (stack), heap e alocação dinâmica** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Structs e typedef

Uma **struct** agrupa dados de tipos diferentes que pertencem à mesma coisa: um aluno tem nome (`char[]`), matrícula (`int`) e nota (`float`). Os campos são acessados com `.` (`aluno.nota`) ou, a partir de um ponteiro, com `->` (`p->nota`, que é o mesmo que `(*p).nota`).

Structs podem ser copiadas inteiras com `=`, passadas para funções e devolvidas por elas, e podem conter outras structs (um cliente tem um endereço). O `typedef` dá um nome curto ao tipo (`typedef struct aluno Aluno;`), dispensando escrever `struct` toda vez. Uma struct que contém um ponteiro para o próprio tipo (`struct no *prox;`) é a base de listas e árvores.

#### 🌍 Onde é usado na prática

- Registros de sistemas: cliente, produto, pedido. É o equivalente em C a uma classe só com atributos, ou a uma linha de tabela de banco de dados.
- APIs do sistema operacional usam structs para tudo: `struct tm` (data e hora), `struct stat` (informações de arquivo), `struct sockaddr` (endereços de rede).
- Formatos binários (cabeçalhos de imagens BMP, pacotes de rede) são lidos direto em structs.

#### 💼 Em processos seletivos

Structs aparecem como a forma de modelar o problema: ao implementar uma lista, uma fila ou um cadastro, a primeira coisa avaliada é a modelagem dos dados. Em vagas de C, perguntam sobre `.` × `->`, cópia de struct e **alinhamento** (por que `sizeof` de uma struct às vezes é maior que a soma dos campos).

Perguntas que costumam aparecer:

- Qual a diferença entre `.` e `->`?
- Passar uma struct por valor ou por ponteiro? Quando cada um?
- Por que `sizeof(struct)` pode ser maior que a soma dos campos?

#### 🐞 Erros comuns

- Usar `.` com ponteiro ou `->` com variável.
- Esquecer que copiar uma struct com um ponteiro dentro copia o endereço, não os dados apontados (cópia rasa).
- Escrever o nome do tipo errado no `typedef` (erro de compilação "unknown type name").

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
void dinamica() {
    char no[20];
    printf("Digite o nome: ");
    fflush(stdin);
    gets(no);
    strcpy(cli1->nome, no);

    char tele[20];
    printf("Digite o telefone: ");
    fflush(stdin);
    gets(tele);
    strcpy(cli1->tel, tele);

    char ende[20];
    printf("Digite a rua: ");
    fflush(stdin);
    gets(ende);
    strcpy(cli1->end.rua, ende);

    printf("%s\n", cli1->nome);
    printf("%s\n", cli1->tel);
    printf("%s\n", cli1->end.rua);
}
```

O ganho em relação a `TCli clientes[3]` é que o tamanho não precisa ser conhecido na compilação. O telefone é guardado como texto (`char tel[20]`), uma boa escolha: telefones não são números para fazer conta e podem começar com zero.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
** Cadastro **
Digite o tamanho: 1
Digite o nome: Joao
Digite o telefone: 3133331111
Digite a rua: Rua Cobre
Joao
3133331111
Rua Cobre
Deseja outro cadastro? s ou n n


Voce saiu do programa.
```

## ⚠️ Pontos de atenção

- `dinamica()` sempre grava em `cli1` (a posição 0): cada novo cadastro sobrescreve o anterior. Faltou um índice: `cli1[i].nome`.
- Os textos são lidos em vetores de 20 posições e copiados para campos maiores; nomes com mais de 19 letras estouram o vetor.
- A memória nunca é liberada.
- Usa `gets`, removida do C11 por não limitar o tamanho da leitura: digitar mais caracteres do que o vetor comporta escreve fora dele. Troque por `fgets(str, sizeof str, stdin)` e remova o `\n` final. Veja a seção sobre portabilidade.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/exerstruct2.c -o exerstruct2
./exerstruct2
```

> Compiladores atuais avisam (ou recusam) o uso de `gets`. Se o GCC reclamar, compile com `-std=gnu89` ou troque `gets` por `fgets`.

> O `fflush(stdin)` só limpa a entrada no Windows. No Linux e no macOS, algumas leituras podem "pular"; rode no Windows ou adapte como explicado na seção sobre portabilidade.

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1048: Aumento de Salário (modele um funcionário como struct)](https://judge.beecrowd.com/pt/problems/view/1048)
- [LeetCode 707: Design Linked List (alocar e liberar nós)](https://leetcode.com/problems/design-linked-list/)

## 📂 Estrutura do projeto

```text
📁 exerstruct2
│
├── 📁 src
│   └── exerstruct2.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [exerstruct](../exerstruct): Exercício: structs ligadas por ponteiro
- [Struct](../Struct): Struct cliente com endereço

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Struct_Pessoa_Arg](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Struct_Pessoa_Arg)
- [Prj_Heap](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Heap)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: struct](https://en.cppreference.com/w/c/language/struct)
- [cppreference: typedef](https://en.cppreference.com/w/c/language/typedef)
- [cppreference: operador -> (acesso a membro)](https://en.cppreference.com/w/c/language/operator_member_access)
- [cppreference: malloc](https://en.cppreference.com/w/c/memory/malloc)
- [cppreference: calloc](https://en.cppreference.com/w/c/memory/calloc)
- [cppreference: free](https://en.cppreference.com/w/c/memory/free)
- [Paulo Feofiloff (IME-USP): alocação dinâmica](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)
- [Valgrind: guia rápido](https://valgrind.org/docs/manual/quick-start.html)
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
