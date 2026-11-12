# Projeto Prj_Loteria (C) 🍀

> **Loteria**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

O programa sorteia um número de 0 a 100 e o jogador tenta acertar. Se errar, o número sorteado é revelado.

## 🎯 Conceitos trabalhados

- `srand` e `rand`
- Comparação do palpite com o sorteio

## 🧠 Como funciona

```c
int main(void) {

    // Inicializa a semente para a função rand() usando o tempo atual
    srand(time(NULL));

    // Gera um número aleatório entre 0 e 100
    int numSorteado = rand() % 101;

    printf("Loteria");
    printf("\n\nEscolha um número entre 0 e 100: ");
    int numEscolhido;
    scanf("%d", &numEscolhido);

    if(numEscolhido == numSorteado){
        printf("\nVocê ganhou!");
    }else{
        printf("\nVocê perdeu! O número sorteado foi: %d", numSorteado);
    }

    return EXIT_SUCCESS;
}
```

A chance de acerto é de 1 em 101. Um bom exercício é transformar o jogo em "maior ou menor": dar dicas e deixar o jogador tentar até acertar, contando as tentativas.

## 💻 Exemplo de execução

```text
Loteria

Escolha um número entre 0 e 100: 50

Você perdeu! O número sorteado foi: 93
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Loteria` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Loteria`:

```bash
gcc src/Prj_Loteria.c -o Prj_Loteria
./Prj_Loteria
```

No Windows, rode `Prj_Loteria.exe` (ou `.\Prj_Loteria.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Loteria
│
├── 📁 src
│   └── Prj_Loteria.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Rand](../Prj_Rand): Números aleatórios
- [Prj_MontyHall](../Prj_MontyHall): Problema de Monty Hall
- [Prj_Dados](../Prj_Dados): Jogo de dados

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
