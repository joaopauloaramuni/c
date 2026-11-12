# Projeto Prj_ContarDigitos_Ponteiros (C) 🔢

> **Contar dígitos com ponteiros**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Conta quantos dígitos tem um número inteiro (`12345` tem 5). O resultado volta para o `main` por um ponteiro.

## 🎯 Conceitos trabalhados

- Divisão inteira por 10 para remover o último dígito
- Parâmetro de saída por ponteiro
- Caso especial do zero

## 🧠 Como funciona

```c
// Função que conta o número de dígitos de um número inteiro
void contarDigitos(int *numero, int *quantidade) {
    int n = *numero;
    *quantidade = 0;

    // Se o número for zero, conta como um dígito
    if (n == 0) {
        *quantidade = 1;
        return;
    }

    // Conta os dígitos
    while (n != 0) {
        n /= 10; // Remove o último dígito
        (*quantidade)++; // Incrementa o contador
    }
}
```

Cada `n /= 10` tira o último dígito: `12345 → 1234 → 123 → 12 → 1 → 0`. São 5 divisões até zerar, então 5 dígitos. O `0` é tratado à parte porque o `while (n != 0)` nem entraria e o resultado seria 0 dígitos. Repare em `(*quantidade)++`: os parênteses fazem o `++` agir sobre o valor, não sobre o ponteiro. A versão recursiva do mesmo raciocínio está no [Prj_Soma_Recursiva](../Prj_Soma_Recursiva).

## 💻 Exemplo de execução

```text
Número: 12345
Quantidade de dígitos: 5
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ContarDigitos_Ponteiros` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ContarDigitos_Ponteiros`:

```bash
gcc src/Prj_ContarDigitos.c -o Prj_ContarDigitos_Ponteiros
./Prj_ContarDigitos_Ponteiros
```

No Windows, rode `Prj_ContarDigitos_Ponteiros.exe` (ou `.\Prj_ContarDigitos_Ponteiros.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_ContarDigitos_Ponteiros
│
├── 📁 src
│   └── Prj_ContarDigitos.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Soma_Recursiva](../Prj_Soma_Recursiva): Soma recursiva dos dígitos
- [Prj_Funcoes_Ponteiros](../Prj_Funcoes_Ponteiros): Funções com ponteiros: troca e zera

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
