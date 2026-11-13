# Projeto Prj_Tarefa_1 (C) 🧾

> **Tarefa 1: funções com cálculos**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução da **Tarefa 1**. Cada exercício virou uma função, e o `main` testa todas com valores fixos:

1. Soma de quatro inteiros.
2. Média aritmética de três notas.
3. Novo salário com aumento de 25%.
4. Valor do aumento e novo salário a partir de um percentual informado.
5. Salário a receber com gratificação de 5% e imposto de 7% sobre o salário base.

📄 Enunciado: [Tarefa 1 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%201.pdf)

## 🎯 Conceitos trabalhados

- Funções com parâmetros e retorno `int` e `float`
- Cálculo de percentuais
- Organização de exercícios em funções

## 🧠 Como funciona

```c
// Função para calcular o valor do aumento e o novo salário com percentual informado
float calcularAumentoSalario(float salario, float percentual_aumento) {
    float aumento = salario * (percentual_aumento / 100);
    return salario + aumento;
}
```

```c
// Função para calcular o salário a receber com gratificação e desconto de imposto
float calcularSalarioReceber(float salario_base) {
    float gratificacao = salario_base * 0.05;
    float imposto = salario_base * 0.07;
    return salario_base + gratificacao - imposto;
}
```

Um aumento de 25% é o mesmo que multiplicar por `1.25`. No exercício 5, a gratificação e o imposto são calculados sobre o **salário base**: `1200 + 60 − 84 = 1176`.

## 💻 Exemplo de execução

```text
1) A soma dos números é: 17
2) A média aritmética é: 8.33
3) O novo salário é: 1250.00
4) O valor do aumento é: 150.00
   O novo salário com aumento é: 1150.00
5) O salário a receber é: 1176.00
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_1` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_1`:

```bash
gcc src/Prj_Tarefa_1.c -o Prj_Tarefa_1
./Prj_Tarefa_1
```

No Windows, rode `Prj_Tarefa_1.exe` (ou `.\Prj_Tarefa_1.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_1
│
├── 📁 src
│   └── Prj_Tarefa_1.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Tarefa_2](../Prj_Tarefa_2): Tarefa 2: laços, funções e menu de pagamento
- [Prj_Funcao](../Prj_Funcao): Funções: protótipo e definição

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
