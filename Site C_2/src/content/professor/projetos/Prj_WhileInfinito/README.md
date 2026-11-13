# Projeto Prj_WhileInfinito (C) ♾️

> **Laço infinito**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Um `while (1)` que imprime a mesma frase para sempre. Serve para mostrar o que acontece quando a condição de parada nunca fica falsa e como interromper o programa.

## 🎯 Conceitos trabalhados

- Laço infinito com `while (1)`
- Condição de parada
- Interromper um processo pelo terminal ou pela IDE

## 🧠 Como funciona

```c
int main(void) {

    while (1) {
        printf("Exemplo de loop infinito.\n");
    }

    return 0;
}
```

Em C, qualquer valor diferente de zero é verdadeiro, então `while (1)` nunca termina sozinho. Para parar, use **Ctrl + C** no terminal ou o botão vermelho **Terminate** do console do Eclipse. Laços infinitos são úteis de propósito em servidores, jogos e no [Prj_ASCII_Clock](../Prj_ASCII_Clock), que redesenha o relógio a cada segundo.

## 💻 Exemplo de execução

```text
Exemplo de loop infinito.
Exemplo de loop infinito.
Exemplo de loop infinito.
Exemplo de loop infinito.
... (repete até você pressionar Ctrl + C)
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_WhileInfinito` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_WhileInfinito`:

```bash
gcc src/Prj_WhileInfinito.c -o Prj_WhileInfinito
./Prj_WhileInfinito
```

No Windows, rode `Prj_WhileInfinito.exe` (ou `.\Prj_WhileInfinito.exe` no PowerShell).

> O programa não termina sozinho. Pressione **Ctrl + C** para encerrar.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_WhileInfinito
│
├── 📁 src
│   └── Prj_WhileInfinito.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_While](../Prj_While): Laço while
- [Prj_ASCII_Clock](../Prj_ASCII_Clock): Relógio em ASCII

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
