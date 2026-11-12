# Projeto Prj_Soma_Recursiva (C) 🔢

> **Soma recursiva dos dígitos**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Soma os dígitos de um número recursivamente: `1 + 2 + 3 + 4 + 5 = 15` para `12345`.

## 🎯 Conceitos trabalhados

- `n % 10` pega o último dígito
- `n / 10` remove o último dígito
- Caso base `n == 0`

## 🧠 Como funciona

```c
// Função recursiva para calcular a soma dos dígitos de um número
int somaDosDigitos(int n) {
    //Caso base
    if (n == 0)
        return 0;
    //Passo recursivo
    else
        // n % 10 = último dígito
        // n / 10 = número menos o último dígito
        return (n % 10) + somaDosDigitos(n / 10);
        // Quinta chamada recursiva: 1 + somaDosDigitos(0) = 1 + 0 = 1
        // Quarta chamada recursiva: 2 + somaDosDigitos(1) = 2 + 1 = 3
        // Terceira chamada recursiva: 3 + somaDosDigitos(12) = 3 + 3 = 6
        // Segunda chamada recursiva: 4 + somaDosDigitos(123) = 4 + 6 = 10
        // Primeira chamada recursiva: 5 + somaDosDigitos(1234)= 5 + 10 = 15
}
```

Os comentários na função mostram as cinco chamadas: `5 + somaDosDigitos(1234)`, `4 + somaDosDigitos(123)`... até `somaDosDigitos(0) = 0`, e as somas voltando: `1, 3, 6, 10, 15`.

## 💻 Exemplo de execução

```text
A soma dos dígitos de 12345 é 15
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Soma_Recursiva` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Soma_Recursiva`:

```bash
gcc src/Prj_Soma_Recursiva.c -o Prj_Soma_Recursiva
./Prj_Soma_Recursiva
```

No Windows, rode `Prj_Soma_Recursiva.exe` (ou `.\Prj_Soma_Recursiva.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Soma_Recursiva
│
├── 📁 src
│   └── Prj_Soma_Recursiva.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_ContarDigitos_Ponteiros](../Prj_ContarDigitos_Ponteiros): Contar dígitos com ponteiros
- [Prj_Soma_Recursiva_Array](../Prj_Soma_Recursiva_Array): Soma recursiva de um array
- [Prj_Smith](../Prj_Smith): Números de Smith

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
