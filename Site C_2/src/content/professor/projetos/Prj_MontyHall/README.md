# Projeto Prj_MontyHall (C) 🚪

> **Problema de Monty Hall**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Simula o famoso **problema de Monty Hall**: o jogador escolhe uma de três portas, o apresentador abre uma porta vazia e pergunta se o jogador quer trocar. Trocar ganha em 2/3 das vezes; manter, em 1/3.

## 🎯 Conceitos trabalhados

- Sorteio da porta premiada
- Laço `do-while` para sortear até achar uma porta válida
- Validação da entrada
- Probabilidade condicional

## 🧠 Como funciona

```c
int main(void) {

    printf("Bem-vindo ao jogo Monty Hall!");
    printf("\n\nEscolha uma porta (1, 2 ou 3): ");
    int portaEscolhida;
    scanf("%d", &portaEscolhida);

    // Validar a entrada do usuário
    if (portaEscolhida < 1 || portaEscolhida > 3) {
        printf("\nEscolha inválida. O número da porta deve ser 1, 2 ou 3.");
    } else {
        // Definir a porta premiada

        // Inicializa a semente para a função rand() usando o tempo atual
        srand(time(NULL));

        // Gera um número aleatório entre 1 e 3
        int portaPremiada = rand() % 3 + 1;
        // printf("\nA porta premiada é: %d", portaPremiada); //comente essa linha para ficar divertido

        // Simulação da abertura de uma das outras portas vazias
        int portaVazia = -1;
        do {
            portaVazia = rand() % 3 + 1;
        } while (portaVazia == portaPremiada || portaVazia == portaEscolhida);
        printf("\nO apresentador abriu a porta %d, que está vazia.", portaVazia);

        // Oferecer a opção de trocar de porta ou não
        printf("\n\nVocê deseja trocar para a outra porta? (s/n): ");
        char opcao;
        scanf(" %c", &opcao);

        // Verifica se a opção é 's' para decidir se deve trocar a porta
        int trocarPorta = (opcao == 's' || opcao == 'S');

        // Determinar a nova porta escolhida (caso o jogador opte por trocar)
        int portaEscolhidaOriginal = portaEscolhida;
        if (trocarPorta) {
            do {
                portaEscolhida = rand() % 3 + 1;
            } while (portaEscolhida == portaVazia
                    || portaEscolhida == portaEscolhidaOriginal);
            printf("\nVocê trocou para a porta %d.", portaEscolhida);
            //portaEscolhida agora é a porta nova que foi trocada
            //portaEscolhidaOriginal é a porta escolhida no início do jogo, antes da troca
        }

        // Determinar o resultado final
        if (portaEscolhida == portaPremiada) {
            printf("\nVocê ganhou! Parabéns!");
        } else {
            printf("\nVocê perdeu. A porta premiada era a %d.", portaPremiada);
        }

        // Resultado final
        printf("\n\nPorta premiada: %d", portaPremiada);
        printf("\nPorta vazia: %d", portaVazia);
        printf("\nPorta escolhida: %d", portaEscolhida);
        printf("\nPorta escolhida Originalmente: %d", portaEscolhidaOriginal);
    }

    return EXIT_SUCCESS;
}
```

O apresentador nunca abre a porta premiada nem a escolhida, por isso o `do-while` sorteia de novo até cair em uma porta vazia diferente da escolhida. A linha comentada `// printf("\nA porta premiada é: %d", portaPremiada);` revela o prêmio antes da hora, para testar.

Por que trocar é melhor? Na primeira escolha, a chance de acertar é 1/3. Os outros 2/3 ficam nas duas portas restantes; quando o apresentador elimina uma delas, os 2/3 ficam todos na porta que sobrou.

## 💻 Exemplo de execução

```text
Bem-vindo ao jogo Monty Hall!

Escolha uma porta (1, 2 ou 3): 2

O apresentador abriu a porta 3, que está vazia.

Você deseja trocar para a outra porta? (s/n): s

Você trocou para a porta 1.
Você perdeu. A porta premiada era a 2.

Porta premiada: 2
Porta vazia: 3
Porta escolhida: 1
Porta escolhida Originalmente: 2
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_MontyHall` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_MontyHall`:

```bash
gcc src/Prj_MontyHall.c -o Prj_MontyHall
./Prj_MontyHall
```

No Windows, rode `Prj_MontyHall.exe` (ou `.\Prj_MontyHall.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_MontyHall
│
├── 📁 src
│   └── Prj_MontyHall.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Loteria](../Prj_Loteria): Loteria
- [Prj_Rand](../Prj_Rand): Números aleatórios

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
