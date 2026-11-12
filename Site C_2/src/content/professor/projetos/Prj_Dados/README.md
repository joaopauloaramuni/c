# Projeto Prj_Dados (C) 🎲

> **Jogo de dados**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Dois jogadores rolam dois dados cada (pressionando *Enter*) e vence quem tiver a maior soma.

## 🎯 Conceitos trabalhados

- Função que sorteia de 1 a 6 (`rand() % 6 + 1`)
- `getchar` para esperar o *Enter*
- Vetores de 2 posições para os dados de cada jogador

## 🧠 Como funciona

```c
// Função para lançar um dado
int rolarDado() {
    return rand() % 6 + 1; // Gera um número aleatório entre 1 e 6
}
```

`rand() % 6` dá de 0 a 5; somando 1, fica de 1 a 6, como um dado de verdade. Os resultados mudam a cada execução por causa do `srand(time(NULL))`.

## 💻 Exemplo de execução

```text
Jogador 1, pressione ENTER para rolar os dados.

Jogador 1: 2 + 5
Soma do Jogador 1: 7

Jogador 2, pressione ENTER para rolar os dados.

Jogador 2: 3 + 5
Soma do Jogador 2: 8

Jogador 2 vence!
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Dados` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Dados`:

```bash
gcc src/Prj_Dados.c -o Prj_Dados
./Prj_Dados
```

No Windows, rode `Prj_Dados.exe` (ou `.\Prj_Dados.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Dados
│
├── 📁 src
│   └── Prj_Dados.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Rand](../Prj_Rand): Números aleatórios
- [Prj_Loteria](../Prj_Loteria): Loteria
- [Prj_MontyHall](../Prj_MontyHall): Problema de Monty Hall

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
