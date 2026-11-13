# Projeto Prj_Forca (C) 🪢

> **Jogo da forca**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Jogo da forca no console: o programa sorteia uma de 10 palavras, mostra os espaços com `_` e o jogador tem **6 tentativas** de errar.

## 🎯 Conceitos trabalhados

- Matriz de strings com as palavras
- Sorteio com `rand() % MAX_PALAVRAS`
- Revelar letras em uma cópia da palavra
- `strcmp` para detectar a vitória

## 🧠 Como funciona

```c
int main(void) {
    srand(time(NULL));

    char palavra[TAM_PALAVRA];
    char palavraOculta[TAM_PALAVRA];
    int tamanho;
    int tentativas = 6;
    int indicePalavra = rand() % MAX_PALAVRAS;

    strcpy(palavra, palavras[indicePalavra]);
    tamanho = strlen(palavra);

    // Inicializa a palavra oculta
    for (int i = 0; i < tamanho; i++) {
        palavraOculta[i] = '_';
    }
    palavraOculta[tamanho] = '\0';

    printf("Bem-vindo ao jogo da forca!\n");

    while (tentativas > 0) {
        printf("Palavra: %s\n", palavraOculta);
        printf("Tentativas restantes: %d\n", tentativas);

        char letra;
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        int acertos = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra) {
                palavraOculta[i] = letra;
                acertos++;
            }
        }

        if (acertos == 0) {
            tentativas--;
            printf("Letra incorreta!\n");
        } else {
            printf("Letra correta!\n");
        }

        if (strcmp(palavra, palavraOculta) == 0) {
            printf("Parabéns, você ganhou! A palavra era: %s\n", palavra);
            break;
        }
    }

    if (tentativas == 0) {
        printf("Você perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
```

`palavraOculta` começa só com `_` e recebe cada letra certa na posição correspondente. Quando ela fica igual à palavra sorteada (`strcmp(...) == 0`), o jogador vence. O espaço em `scanf(" %c", &letra)` descarta o *Enter* da jogada anterior.

## 💻 Exemplo de execução

```text
Bem-vindo ao jogo da forca!
Palavra: __________
Tentativas restantes: 6
Digite uma letra: a
Letra incorreta!
Palavra: __________
Tentativas restantes: 5
Digite uma letra: e
Letra correta!
Palavra: e_e_______
Tentativas restantes: 5
Digite uma letra: i
Letra correta!
Palavra: e_e____i__
Tentativas restantes: 5
Digite uma letra: o
Letra correta!
Palavra: e_e__o_i_o
Tentativas restantes: 5
Digite uma letra: u
Letra incorreta!
Palavra: e_e__o_i_o
Tentativas restantes: 4
Digite uma letra: r
...
```

## ⚠️ Pontos de atenção

- Repetir uma letra já acertada conta como acerto e não gasta tentativa, e letras maiúsculas contam como erro, já que as palavras estão em minúsculas. Dois bons exercícios: guardar as letras já tentadas e usar `tolower` de `<ctype.h>`.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Forca` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Forca`:

```bash
gcc src/Prj_Forca.c -o Prj_Forca
./Prj_Forca
```

No Windows, rode `Prj_Forca.exe` (ou `.\Prj_Forca.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Forca
│
├── 📁 src
│   └── Prj_Forca.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Jogo_da_Velha](../Prj_Jogo_da_Velha): Jogo da velha
- [Prj_Rand](../Prj_Rand): Números aleatórios

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
