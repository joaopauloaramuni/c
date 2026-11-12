# Projeto Prj_Palindromo (C) 🔄

> **Palíndromo (iterativo)**. Tema: **Strings**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Verifica se uma palavra é um **palíndromo** (lida igual de trás para frente, como ARARA, OVO e OTTO) comparando as letras das pontas para o meio com dois índices.

## 🎯 Conceitos trabalhados

- Dois índices em um mesmo `for` (`i++, j--`)
- `break` para sair do laço
- Variável *flag* (`palindromo`)

## 🧠 Como funciona

```c
int main(void) { // Palíndromo - ARARA - OVO - OTTO - SOCORRAMMESUBINOONIBUSEMMARROCOS
    char palavra[100];
    int i, j, tamanho;
    int palindromo = 1;

    printf("Digite uma palavra: ");
    fflush(stdout);
    scanf("%s", palavra);

    tamanho = strlen(palavra);

    //A comparação acontece de fora pra dentro
    //  A R A R A
    //i=A R
    //j=      R A
    // Verificar se é um palíndromo
    for(i = 0, j = tamanho - 1; i < j; i++, j--) {
        printf("i: %c\n", palavra[i]);
        printf("j: %c\n", palavra[j]);
        if(palavra[i] != palavra[j]) {
            palindromo = 0;
            break;
        }
    }
    if(palindromo) {
        printf("\nA palavra é um palíndromo.\n");
    } else {
        printf("\nA palavra não é um palíndromo.\n");
    }

    return 0;
}
```

`i` começa na primeira letra e `j` na última. A cada volta os dois andam um passo para o meio, e o laço para quando se cruzam (`i < j`). Os `printf` de `i` e `j` dentro do laço estão lá para acompanhar as comparações. A frase do comentário, SOCORRAMMESUBINOONIBUSEMMARROCOS, também é um palíndromo.

## 💻 Exemplo de execução

```text
Digite uma palavra: ARARA
i: A
j: A
i: R
j: R

A palavra é um palíndromo.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Palindromo` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Palindromo`:

```bash
gcc src/Prj_Palindromo.c -o Prj_Palindromo
./Prj_Palindromo
```

No Windows, rode `Prj_Palindromo.exe` (ou `.\Prj_Palindromo.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Palindromo
│
├── 📁 src
│   └── Prj_Palindromo.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Palindromo_Recursivo](../Prj_Palindromo_Recursivo): Palíndromo recursivo
- [Prj_Pali+File](../Prj_Pali+File): Palíndromos gravados em arquivo

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
