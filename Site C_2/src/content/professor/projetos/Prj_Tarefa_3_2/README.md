# Projeto Prj_Tarefa_3_2 (C) 🚭

> **Tarefa 3.2: gasto de um fumante**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução do exercício 2 da **Tarefa 3**: calcula quantos cigarros uma pessoa fumou ao longo da vida e quanto gastou, considerando 20 cigarros por maço. Como extra, estima o tempo de vida perdido (11 minutos por cigarro).

📄 Enunciado: [Tarefa 3 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%203.pdf)

## 🎯 Conceitos trabalhados

- Funções de cálculo
- Mistura de `int` e `float` (`/ 20.0`)
- Conversão de unidades (minutos para horas)

## 🧠 Como funciona

```c
// Função para calcular o total gasto
float calcularTotalGasto(int cigarrosAoLongoDaVida, float precoMaco) {
    return (cigarrosAoLongoDaVida / 20.0) * precoMaco;
}
```

```c
// Função para calcular o tempo de vida perdido
float calcularTempoVidaPerdido(int cigarrosAoLongoDaVida) {
    // Estimativa de que cada cigarro reduz 11 minutos de vida
    return cigarrosAoLongoDaVida * 11 / 60.0;
}
```

Dividir por `20.0` (e não `20`) força a conta em ponto flutuante, para não perder os maços incompletos. Com 10 anos, 20 cigarros por dia e maço a R$ 12,50: `10 × 365 × 20 = 73.000` cigarros, `3.650` maços e R$ 45.625,00.

## 💻 Exemplo de execução

```text
Digite o número de anos que você fuma: 10
Digite o número de cigarros fumados por dia: 20
Digite o preço médio de um maço de cigarros: 12.50

Número de cigarros fumados ao longo da vida: 73000
Total gasto: R$45625.00
Tempo de vida perdido devido com o hábito de fumar: 13383.33 horas
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_3_2` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_3_2`:

```bash
gcc src/Prj_Tarefa_3_2.c -o Prj_Tarefa_3_2
./Prj_Tarefa_3_2
```

No Windows, rode `Prj_Tarefa_3_2.exe` (ou `.\Prj_Tarefa_3_2.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_3_2
│
├── 📁 src
│   └── Prj_Tarefa_3_2.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Tarefa_3_1](../Prj_Tarefa_3_1): Tarefa 3.1: eleição de 2º turno
- [Prj_Tarefa_3_3](../Prj_Tarefa_3_3): Tarefa 3.3: seleção de basquete

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
