# Projeto Prj_ASCII_Clock (C) ⏰

> **Relógio em ASCII**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Um relógio digital no terminal: mostra a hora atual (HHMMSS) com dígitos desenhados em ASCII, em verde, e atualiza a cada segundo.

## 🎯 Conceitos trabalhados

- Matriz de strings com o desenho de cada dígito
- `time` e `localtime` de `<time.h>`
- `snprintf` e `strcat`
- Códigos de escape ANSI para cor e limpar a tela
- `sleep` de `<unistd.h>`

## 🧠 Como funciona

```c
// Função para imprimir a hora atual em ASCII
void print_time_ascii() {
    time_t agora = time(NULL);
    struct tm *hora_local = localtime(&agora);

    // Obtém hora, minutos e segundos
    int hora = hora_local->tm_hour;
    int minutos = hora_local->tm_min;
    int segundos = hora_local->tm_sec;

    // Converte os números para string para fácil manipulação
    char time_string[7];
    snprintf(time_string, sizeof(time_string), "%02d%02d%02d", hora, minutos, segundos);

    // Monta as 3 linhas da saída ASCII
    char linhas[3][100] = {"", "", ""};
    for (int i = 0; time_string[i] != '\0'; i++) {
        int digito = time_string[i] - '0'; // Converte char para índice numérico
        for (int j = 0; j < 3; j++) {
            strcat(linhas[j], ascii_digits[digito][j]);
            strcat(linhas[j], "  "); // Espaço entre os números
        }
    }

    // Exibe as linhas
    for (int i = 0; i < 3; i++) {
        printf("\033[1;32m%s\033[0m\n", linhas[i]); // Cor verde no texto
    }
}
```

Cada dígito é desenhado em 3 linhas (`ascii_digits[d][0..2]`). A função transforma a hora em uma string de 6 caracteres, por exemplo `"143507"`, e monta as 3 linhas da tela juntando os pedaços de cada dígito. `\033[H\033[J` volta o cursor ao topo e limpa a tela; `\033[1;32m` liga o verde e `\033[0m` volta à cor normal.

## 💻 Exemplo de execução

```text
           _    _    _    _
  |  |_|   _|  |_   | |    |
  |    |   _|   _|  |_|    |

(14:35:07, em verde, redesenhado a cada segundo)
```

## ⚠️ Pontos de atenção

- `<unistd.h>` e `sleep` são do padrão POSIX (Linux e macOS). No Windows com MinGW, troque por `#include <windows.h>` e `Sleep(1000)` (com S maiúsculo, em milissegundos). Os códigos de cor funcionam no Terminal do Windows 10 ou mais novo, mas podem aparecer como texto no console do Eclipse.
- O programa não termina sozinho: use **Ctrl + C**.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ASCII_Clock` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ASCII_Clock`:

```bash
gcc src/Prj_ASCII_Clock.c -o Prj_ASCII_Clock
./Prj_ASCII_Clock
```

No Windows, rode `Prj_ASCII_Clock.exe` (ou `.\Prj_ASCII_Clock.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_ASCII_Clock
│
├── 📁 src
│   └── Prj_ASCII_Clock.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_WhileInfinito](../Prj_WhileInfinito): Laço infinito
- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
