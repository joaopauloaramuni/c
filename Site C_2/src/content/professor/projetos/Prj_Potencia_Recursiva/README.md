# Projeto Prj_Potencia_Recursiva (C) 🚀

> **Potência recursiva**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calcula `base^expoente` de forma recursiva. O `main` mostra `2^3 = 8`.

## 🎯 Conceitos trabalhados

- Caso base `expoente == 0`
- Redução do problema a cada chamada
- Multiplicação acumulada na volta da recursão

## 🧠 Como funciona

```c
// Função recursiva para calcular base^expoente
int potencia(int base, int expoente) {
    if (expoente == 0)
        return 1;
    else
        return base * potencia(base, expoente - 1);
}
```

`potencia(2, 3) = 2 * potencia(2, 2) = 2 * 2 * potencia(2, 1) = 2 * 2 * 2 * potencia(2, 0) = 2 * 2 * 2 * 1 = 8`.

## 💻 Exemplo de execução

```text
2^3 = 8
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Potencia_Recursiva` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Potencia_Recursiva`:

```bash
gcc src/Prj_Potencia_Recursiva.c -o Prj_Potencia_Recursiva
./Prj_Potencia_Recursiva
```

No Windows, rode `Prj_Potencia_Recursiva.exe` (ou `.\Prj_Potencia_Recursiva.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Potencia_Recursiva
│
├── 📁 src
│   └── Prj_Potencia_Recursiva.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Fatorial_Recursivo](../Prj_Fatorial_Recursivo): Fatorial recursivo
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
