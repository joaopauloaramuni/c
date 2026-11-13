# Projeto Prj_Ternario (C) ❓

> **Operador ternário**. Tema: **Condicionais**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Escolhe entre dois valores com o **operador ternário** `condição ? valor_se_verdadeiro : valor_se_falso`, a forma compacta do `if/else`.

## 🎯 Conceitos trabalhados

- Operador condicional `?:`
- Expressões que devolvem valor
- Equivalência com `if/else`

## 🧠 Como funciona

```c
int main(void) {
    int numero = 10;
    // Estrutura de "se senão" usando operador ternário
    int resultado = (numero > 5) ? 2 : 3;

    printf("Resultado: %d\n", resultado);

    return 0;
}
```

`int resultado = (numero > 5) ? 2 : 3;` é o mesmo que:

```c
int resultado;
if (numero > 5) {
    resultado = 2;
} else {
    resultado = 3;
}
```

O ternário aparece bastante nas funções recursivas de uma linha, como no [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo).

## 💻 Exemplo de execução

```text
Resultado: 2
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Ternario` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Ternario`:

```bash
gcc src/Prj_Ternario.c -o Prj_Ternario
./Prj_Ternario
```

No Windows, rode `Prj_Ternario.exe` (ou `.\Prj_Ternario.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Ternario
│
├── 📁 src
│   └── Prj_Ternario.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_CondicionalComposta](../Prj_CondicionalComposta): Condicional composta (if/else)
- [Prj_Fatorial_Recursivo](../Prj_Fatorial_Recursivo): Fatorial recursivo
- [Prj_Aramuni_Recursivo](../Prj_Aramuni_Recursivo): Aramuni Recursivo: 12 funções em uma linha

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
