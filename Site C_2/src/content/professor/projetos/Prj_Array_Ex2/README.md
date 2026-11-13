# Projeto Prj_Array_Ex2 (C) 🔤

> **Arrays de strings**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê três nomes, mostra os nomes na **ordem inversa** e depois cada nome com o seu comprimento, calculado por `strlen`.

## 🎯 Conceitos trabalhados

- Array de strings (`char nomes[3][30]`)
- Laço `for` decrescente
- `strlen` e o especificador `%zu` para `size_t`

## 🧠 Como funciona

```c
int main(void) {

    // Declaração de um array de strings para armazenar três nomes
    char nomes[3][30];  // Supondo nomes com até 30 caracteres

    // Solicitar ao usuário para inserir três nomes
    for (int i = 0; i < 3; i++) {
        printf("Digite o %do nome: ", i + 1);
        scanf("%s", nomes[i]);
    }

    // Imprimir os nomes na ordem inversa
    printf("\nNomes na ordem inversa:\n");
    for (int i = 2; i >= 0; i--) {
        printf("%s\n", nomes[i]);
    }

    // Imprimir os nomes e seus comprimentos
    printf("\nNomes e comprimentos:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s - Comprimento: %zu\n", nomes[i], strlen(nomes[i]));
        //%zu é um especificador de formato usado em linguagem C para imprimir valores do tipo size_t.
        //Ele é particularmente útil quando você está trabalhando com funções que retornam valores do tipo size_t,
        //como strlen, que retorna o comprimento de uma string.
    }

    return 0;
}
```

No `scanf("%s", nomes[i])` não vai `&`: o nome de um array já é o endereço do primeiro elemento. O `%s` para no primeiro espaço, então nomes compostos ("Ana Clara") são lidos só até "Ana".

## 💻 Exemplo de execução

```text
Digite o 1o nome: Ana
Digite o 2o nome: Bruno
Digite o 3o nome: Carla

Nomes na ordem inversa:
Carla
Bruno
Ana

Nomes e comprimentos:
Ana - Comprimento: 3
Bruno - Comprimento: 5
Carla - Comprimento: 5
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Array_Ex2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Array_Ex2`:

```bash
gcc src/Prj_Array_Ex2.c -o Prj_Array_Ex2
./Prj_Array_Ex2
```

No Windows, rode `Prj_Array_Ex2.exe` (ou `.\Prj_Array_Ex2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Array_Ex2
│
├── 📁 src
│   └── Prj_Array_Ex2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Array_Ex1](../Prj_Array_Ex1): Arrays: declaração e percurso
- [Prj_StrLen](../Prj_StrLen): Tamanho de string com strlen

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
