# Projeto Prj_Tarefa_3_1 (C) 🗳️

> **Tarefa 3.1: eleição de 2º turno**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução do exercício 1 da **Tarefa 3**: um menu registra votos para o Candidato A ou B, apura o resultado (vencedor ou empate) e sai na opção 4.

📄 Enunciado: [Tarefa 3 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%203.pdf)

## 🎯 Conceitos trabalhados

- Menu com `do-while` + `switch`
- Contadores de votos
- Função que lê e devolve a opção (`obterVoto`)

## 🧠 Como funciona

```c
// Função para obter o voto do eleitor
int obterVoto() {
    int voto;
    printf("Escolha uma opção:\n");
    printf("1 – Voto Candidato A\n");
    printf("2 – Voto Candidato B\n");
    printf("3 – Apurar Resultado\n");
    printf("4 - Sair\n");
    scanf("%d", &voto);

    return voto;
}
```

A leitura do menu fica isolada em `obterVoto()`, e o `main` só decide o que fazer com a opção. A apuração pode ser feita várias vezes no meio da votação, porque os contadores continuam valendo.

## 💻 Exemplo de execução

```text
Escolha uma opção:
1 – Voto Candidato A
2 – Voto Candidato B
3 – Apurar Resultado
4 - Sair
1
Voto para Candidato A registrado!
(menu)
1
Voto para Candidato A registrado!
(menu)
2
Voto para Candidato B registrado!
(menu)
3
Resultado:
Candidato A: 2 votos
Candidato B: 1 votos
Candidato A venceu!
(menu)
4
Saindo do programa...
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_3_1` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_3_1`:

```bash
gcc src/Prj_Tarefa_3_1.c -o Prj_Tarefa_3_1
./Prj_Tarefa_3_1
```

No Windows, rode `Prj_Tarefa_3_1.exe` (ou `.\Prj_Tarefa_3_1.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_3_1
│
├── 📁 src
│   └── Prj_Tarefa_3_1.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Tarefa_3_2](../Prj_Tarefa_3_2): Tarefa 3.2: gasto de um fumante
- [Prj_Tarefa_3_3](../Prj_Tarefa_3_3): Tarefa 3.3: seleção de basquete
- [Prj_DoWhile_Menu](../Prj_DoWhile_Menu): Menu com do-while e switch

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
