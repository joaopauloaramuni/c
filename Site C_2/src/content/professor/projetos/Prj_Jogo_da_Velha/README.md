# Projeto Prj_Jogo_da_Velha (C) ⭕

> **Jogo da velha**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Jogo da velha completo no console, com dois modos: **Multiplayer** (dois jogadores) e **Single Player** contra o computador, em três níveis:

| Nível | Estratégia do computador |
| --- | --- |
| EASY | Joga em uma casa vazia sorteada |
| MEDIUM | Completa ou bloqueia linhas, colunas e diagonais com duas peças iguais; se não houver, sorteia |
| HARD | Começa pelos cantos (jogada estratégica) e depois segue a lógica do MEDIUM |

É uma reedição do jogo da velha que fiz como aluno de ED1 na FUMEC, em 2011.

## 🎯 Conceitos trabalhados

- Matriz `char tabuleiro[3][3]` como estado do jogo
- Variáveis globais
- Funções para cada etapa (limpar, imprimir, jogar, verificar)
- Decisões do computador com `if/else if` e `rand`

## 🧠 Como funciona

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

O `main` repete o ciclo **jogada do jogador 1 → verifica vencedor → verifica empate → jogada do jogador 2 (ou do computador)** até alguém vencer ou o tabuleiro encher. As jogadas são digitadas como `linha coluna` (de `0 0` a `2 2`), conforme o quadro de POSICOES que aparece antes de cada jogada.

## 💻 Exemplo de execução

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

Simbolo x ou o: Simbolo incorreto, digite de novo...

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
...
```

## ⚠️ Pontos de atenção

- O código usa `fflush(stdin)` antes dos `scanf`, o que funciona no Windows (MinGW) mas não é garantido no Linux e no macOS. Se o "Simbolo x ou o" for pedido duas vezes, troque `scanf("%c", &jogador1)` por `scanf(" %c", &jogador1)` (com espaço antes do `%c`).
- No modo MEDIUM/HARD, várias mensagens `Jogada: %d %d` mostram coordenadas que não batem com a casa realmente jogada (por exemplo, `printf("Jogada: %d %d", 2, a)` nas diagonais). O tabuleiro impresso logo depois está certo.
- Uma das condições da diagonal confere `tabuleiro[2][2] == ' '` em vez de `tabuleiro[0][0] == ' '`, então o computador não completa essa diagonal no canto `0 0`.
- A jogada não valida se `lin` e `col` estão entre 0 e 2: digitar `5 5` escreve fora da matriz.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Jogo_da_Velha` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Jogo_da_Velha`:

```bash
gcc src/Teste.c -o Prj_Jogo_da_Velha
./Prj_Jogo_da_Velha
```

No Windows, rode `Prj_Jogo_da_Velha.exe` (ou `.\Prj_Jogo_da_Velha.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**. O OnlineGDB roda em Linux: veja os **Pontos de atenção**.

## 📂 Estrutura do projeto

```text
📁 Prj_Jogo_da_Velha
│
├── 📁 src
│   └── Teste.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Forca](../Prj_Forca): Jogo da forca
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
