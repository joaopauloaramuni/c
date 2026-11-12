# Projeto ed1_velha (C, 2010–2011) ⭕

> **Jogo da velha**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Jogos**.

## 📖 Descrição

O jogo da velha do trabalho de ED1, com modo **Multiplayer** e modo **Single Player** contra o computador em três níveis:

| Nível | Estratégia |
| --- | --- |
| EASY | Joga em uma casa vazia sorteada |
| MEDIUM | Completa ou bloqueia linhas, colunas e diagonais com duas peças iguais; se não houver, sorteia |
| HARD | Começa pelos cantos e depois segue a lógica do MEDIUM |

Este mesmo código voltou para a sala de aula em 2024, como [Prj_Jogo_da_Velha](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Jogo_da_Velha).

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag14.html) (seção **Jogo da Velha**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Matriz `char tabuleiro[3][3]` como estado do jogo
- Funções para cada etapa
- Regras de decisão do computador
- Números aleatórios

## 📚 Entendendo o conceito

Este projeto trabalha **Jogos de tabuleiro em console: estado, regras e IA simples**, **Matrizes (vetores bidimensionais)** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Jogos de tabuleiro em console: estado, regras e IA simples

Um jogo como o jogo da velha ou a forca é um bom exercício de **modelagem**: o **estado** do jogo (o tabuleiro, as letras descobertas, as tentativas) fica em variáveis e matrizes, e o programa repete um ciclo **ler jogada → validar → atualizar o estado → verificar fim de jogo → trocar o turno**.

Uma "inteligência artificial" simples para o computador pode seguir regras em ordem de prioridade: ganhar se puder, bloquear se o adversário for ganhar, ocupar uma casa estratégica (centro, cantos) e, por fim, jogar ao acaso. A versão ótima do jogo da velha usa o algoritmo **minimax**, que explora recursivamente todas as jogadas possíveis; com ele o computador nunca perde.

#### 🌍 Onde é usado na prática

- A mesma estrutura de ciclo de jogo e de máquina de estados está em jogos comerciais, em simuladores e em sistemas com fluxo de telas.
- O minimax, com podas alfa-beta, foi a base dos programas de xadrez por décadas.

#### 💼 Em processos seletivos

Projetar um jogo da velha (ou um jogo de cartas) é uma pergunta comum de **design orientado a objetos** e de *live coding*, e verificar o vencedor em uma matriz é um exercício frequente. O minimax aparece em vagas de jogos e em maratonas.

Perguntas que costumam aparecer:

- Verifique se há vencedor em um tabuleiro de jogo da velha.
- Como verificar o vencedor em O(1) a cada jogada?
- Como o computador escolheria a jogada ótima? (minimax)

#### 🐞 Erros comuns

- Não validar se a posição está dentro do tabuleiro e livre.
- Verificar só linhas e colunas e esquecer as diagonais.

### Matrizes (vetores bidimensionais)

Uma **matriz** `int m[3][4];` é um vetor de linhas: 3 linhas, cada uma com 4 colunas. Na memória, as linhas ficam uma depois da outra (ordem por linhas, *row-major*), então `m[i][j]` está na posição `i * 4 + j` a partir do início.

Percorrer uma matriz pede dois laços aninhados: o de fora nas linhas, o de dentro nas colunas. Ao passar uma matriz para uma função, a primeira dimensão pode ficar vazia, mas as outras são obrigatórias (`int m[][4]`), porque o compilador precisa delas para calcular o endereço de `m[i][j]`.

#### 🌍 Onde é usado na prática

- Imagens (cada *pixel* em `[linha][coluna]`), planilhas, tabuleiros de jogos, mapas de jogos 2D.
- Álgebra linear: transformações em computação gráfica, redes neurais (multiplicação de matrizes é a operação central do aprendizado de máquina).
- Grafos representados por matriz de adjacência.

#### 💼 Em processos seletivos

Problemas de matriz aparecem bastante: girar uma imagem 90°, percorrer em espiral, zerar linhas e colunas, buscar em matriz ordenada e problemas de grade (ilhas, caminhos) que usam busca em largura ou em profundidade.

Perguntas que costumam aparecer:

- Transponha uma matriz.
- Gire uma matriz quadrada 90° no próprio lugar.
- Some a diagonal principal e a secundária.
- Percorra a matriz em espiral.

#### ⏱️ Complexidade

Percorrer uma matriz n × m custa O(n·m).

#### 🐞 Erros comuns

- Trocar a ordem dos índices (`m[j][i]`).
- Percorrer por colunas no laço de fora: o resultado é o mesmo, mas fica mais lento por causa do *cache*.

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
//Verifica se deu empate
int verificaempate() {
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][1] != ' ' && tabuleiro[0][2]
            != ' ' && tabuleiro[1][0] != ' ' && tabuleiro[1][1] != ' '
            && tabuleiro[1][2] != ' ' && tabuleiro[2][0] != ' '
            && tabuleiro[2][1] != ' ' && tabuleiro[2][2] != ' ') {
        printf("Deu Velha! Empate...");
        return 0;
    }

    return 1;
}
```

```c
//-------------------------------------------------------------------------
//Preenche o tabuleiro do jogo com espacos (tabuleiro[lin][col] = ' ')
void limpa(void) {
    int lin, col;
    for (lin = 0; lin < 3; lin++) {
        for (col = 0; col < 3; col++) {
            tabuleiro[lin][col] = ' ';
        }
    }
}
```

O `main` repete o ciclo: jogada do jogador 1, verifica vencedor, verifica empate, jogada do jogador 2 ou do computador. As posições são digitadas como `linha coluna` (de `0 0` a `2 2`), conforme o quadro de posições mostrado a cada jogada. Página [Jogo da Velha](https://sitec-aramuni.vercel.app/pag14.html) do Site C.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
**** JOGO DA VELHA ****

MENU
 1 - Single Player
 2 - Multiplayer

Opcao: 2

---------------
    GAME     
---------------
   |   |   
--- --- ---
   |   |   
--- --- ---
   |   |   

Simbolo x ou o: x

---------------
    POSICOES     
---------------
0 0 | 0 1 | 0 2
  --- --- ---
1 0 | 1 1 | 1 2
  --- --- ---
2 0 | 2 1 | 2 2
---------------
Jogada: 0 0

---------------
    GAME     
---------------
 x |   |   
--- --- ---
   |   |   
--- --- ---
   |   |   

(quadro de posições)
Jogada: 1 1

---------------
    GAME     
---------------
 x |   |   
--- --- ---
   | o |   
--- --- ---
   |   |   

(quadro de posições)
Jogada: 0 1

---------------
    GAME     
---------------
 x | x |   
--- --- ---
   | o |   
...
```

## ⚠️ Pontos de atenção

- As jogadas não são validadas quanto aos limites: digitar `5 5` escreve fora da matriz.
- No MEDIUM e no HARD, algumas mensagens `Jogada: %d %d` mostram coordenadas diferentes da casa realmente jogada (o tabuleiro impresso está certo).
- Uma das condições da diagonal confere `tabuleiro[2][2] == ' '` em vez de `tabuleiro[0][0]`, então o computador não completa essa diagonal no canto `0 0`.
- Usa `fflush(stdin)`, que só limpa a entrada no Windows.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/ed1_velha_JoaoPaulo.c -o ed1_velha
./ed1_velha
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

- [LeetCode 1275: Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/)
- [LeetCode 794: Valid Tic-Tac-Toe State](https://leetcode.com/problems/valid-tic-tac-toe-state/)
- [LeetCode 867: Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)
- [LeetCode 1572: Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)
- [LeetCode 48: Rotate Image](https://leetcode.com/problems/rotate-image/)
- [LeetCode 54: Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
- [Beecrowd 1181: Linha na Matriz](https://judge.beecrowd.com/pt/problems/view/1181)

## 📂 Estrutura do projeto

```text
📁 ed1_velha
│
├── 📁 src
│   └── ed1_velha_JoaoPaulo.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [switch](../switch): switch: dias da semana

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Jogo_da_Velha](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Jogo_da_Velha)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Tic-tac-toe](https://en.wikipedia.org/wiki/Tic-tac-toe)
- [Wikipedia: Minimax](https://en.wikipedia.org/wiki/Minimax)
- [cppreference: arrays multidimensionais](https://en.cppreference.com/w/c/language/array)
- [Wikipedia: ordem por linhas e por colunas](https://en.wikipedia.org/wiki/Row-_and_column-major_order)
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
