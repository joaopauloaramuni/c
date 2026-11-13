# Projeto Prj_Rand (C) 🎲

> **Números aleatórios**. Tema: **Fundamentos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Gera e mostra um número aleatório entre 0 e 100 usando `rand()`, com a semente iniciada pelo relógio (`srand(time(NULL))`).

## 🎯 Conceitos trabalhados

- `rand` e `srand` de `<stdlib.h>`
- `time(NULL)` de `<time.h>` como semente
- Operador de resto `%` para limitar o intervalo

## 🧠 Como funciona

```c
int main(void) {
    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    // Gera e imprime um número aleatório no intervalo de 0 a 100
    int numeroAleatorio = rand() % 101;
    printf("Número Aleatório: %d\n", numeroAleatorio);

    return 0;
}
```

`rand()` devolve um número entre `0` e `RAND_MAX`. O `% 101` pega o resto da divisão por 101, que fica sempre entre `0` e `100`. Sem o `srand(time(NULL))`, a sequência começaria sempre da mesma semente e o programa mostraria o mesmo número a cada execução.

## 💻 Exemplo de execução

```text
Número Aleatório: 21
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Rand` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Rand`:

```bash
gcc src/Prj_Rand.c -o Prj_Rand
./Prj_Rand
```

No Windows, rode `Prj_Rand.exe` (ou `.\Prj_Rand.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Rand
│
├── 📁 src
│   └── Prj_Rand.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Loteria](../Prj_Loteria): Loteria
- [Prj_Dados](../Prj_Dados): Jogo de dados
- [Prj_MontyHall](../Prj_MontyHall): Problema de Monty Hall

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
