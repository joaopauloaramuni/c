# Projeto Prj_Smith (C) 🔬

> **Números de Smith**. Tema: **Jogos e desafios**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Verifica se um número é um **número de Smith**: um número composto em que a soma dos dígitos é igual à soma dos dígitos dos seus fatores primos. Exemplos: 4, 22, 27, 58, 85 e 94.

## 🎯 Conceitos trabalhados

- Soma de dígitos
- Teste de primalidade até a raiz quadrada (`i * i <= num`)
- Fatoração em primos
- Composição de funções pequenas

## 🧠 Como funciona

```c
// Função para verificar se um número é primo
int eh_primo(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}
```

```c
// Função para calcular a soma dos dígitos dos fatores primos de um número
int soma_digitos_fatores_primos(int num) {
    int soma = 0;
    int fator = 2;
    while (num > 1) {
        while (num % fator == 0) {
            soma += soma_digitos(fator);
            num /= fator;
        }
        fator++;
        while (!eh_primo(fator)) {
            fator++;
        }
    }
    return soma;
}
```

Para `22`: os dígitos somam `2 + 2 = 4`; os fatores primos são `2 × 11`, e os dígitos deles somam `2 + 1 + 1 = 4`. Como `4 = 4`, 22 é um número de Smith. Números primos ficam de fora pela definição (seriam todos de Smith, trivialmente).

## 💻 Exemplo de execução

```text
Digite um número: 22
22 é um número de Smith.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Smith` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Smith`:

```bash
gcc src/Prj_Smith.c -o Prj_Smith
./Prj_Smith
```

No Windows, rode `Prj_Smith.exe` (ou `.\Prj_Smith.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Smith
│
├── 📁 src
│   └── Prj_Smith.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Soma_Recursiva](../Prj_Soma_Recursiva): Soma recursiva dos dígitos
- [Prj_ContarDigitos_Ponteiros](../Prj_ContarDigitos_Ponteiros): Contar dígitos com ponteiros

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
