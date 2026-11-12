# Projeto Prj_Tarefa_4 (C) 📊

> **Tarefa 4: vetores e matrizes**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução da **Tarefa 4**, uma função por exercício:

1. Vetor com 10 idades e a média delas.
2. Vetor com 10 alturas e a maior e a menor altura.
3. Matriz 3×3 multiplicada por um escalar.
4. Soma de duas matrizes 2×2.

📄 Enunciado: [Tarefa 4 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%204.pdf)

## 🎯 Conceitos trabalhados

- Vetores e matrizes como parâmetros de função
- Matriz como parâmetro (`int matriz[][3]`)
- Máximo e mínimo
- Operações com matrizes

## 🧠 Como funciona

```c
// Função para encontrar a maior e menor altura
void encontrarMaiorMenorAltura(float alturas[]) {
    float maior;
    float menor;

    printf("Digite a altura do aluno 1: ");
    scanf("%f", &alturas[0]);

    maior = alturas[0];
    menor = alturas[0];

    for (int i = 1; i < 10; i++) {
        printf("Digite a altura do aluno %d: ", i + 1);
        scanf("%f", &alturas[i]);

        if (alturas[i] > maior) {
            maior = alturas[i];
        }
        if (alturas[i] < menor) {
            menor = alturas[i];
        }
    }

    printf("Maior altura: %.2f\n", maior);
    printf("Menor altura: %.2f\n", menor);
}
```

```c
// Função para multiplicar uma matriz por um valor escalar
void multiplicarMatrizPorEscalar(int matriz[][3], int escalar) {
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &matriz[i][j]);

    printf("Digite o valor escalar: ");
    scanf("%d", &escalar);

    printf("Matriz resultante após multiplicação:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j] * escalar);
        }
        printf("\n");
    }
}
```

Ao passar uma matriz para uma função, a primeira dimensão pode ficar vazia, mas as outras são obrigatórias (`int matriz[][3]`): o compilador precisa saber o tamanho de cada linha para calcular onde está `matriz[i][j]`.

## 💻 Exemplo de execução

```text
### Função 1 ###
Digite a idade do aluno 1: 18
Digite a idade do aluno 2: 19
Digite a idade do aluno 3: 20
Digite a idade do aluno 4: 21
Digite a idade do aluno 5: 22
Digite a idade do aluno 6: 18
Digite a idade do aluno 7: 19
Digite a idade do aluno 8: 20
Digite a idade do aluno 9: 21
Digite a idade do aluno 10: 22
Média das idades: 20.00

### Função 2 ###
Digite a altura do aluno 1: 1.60
Digite a altura do aluno 2: 1.75
Digite a altura do aluno 3: 1.82
Digite a altura do aluno 4: 1.68
Digite a altura do aluno 5: 1.90
Digite a altura do aluno 6: 1.55
Digite a altura do aluno 7: 1.70
Digite a altura do aluno 8: 1.80
Digite a altura do aluno 9: 1.65
Digite a altura do aluno 10: 1.72
Maior altura: 1.90
Menor altura: 1.55

### Função 3 ###
Digite os elementos da matriz 3x3:
1 2 3
4 5 6
7 8 9
Digite o valor escalar: 2
Matriz resultante após multiplicação:
2 4 6 
8 10 12 
14 16 18 

### Função 4 ###
Digite os elementos da primeira matriz 2x2:
1 2
3 4
Digite os elementos da segunda matriz 2x2:
5 6
7 8
Matriz resultante após soma:
6 8 
10 12
```

## ⚠️ Pontos de atenção

- Em `main`, a variável `escalar` é passada para `multiplicarMatrizPorEscalar` sem valor, mas como a função lê o escalar com `scanf` antes de usá-lo, o resultado sai certo. Uma versão mais clara não teria esse parâmetro e declararia `escalar` dentro da função.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_4` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_4`:

```bash
gcc src/Prj_Tarefa_4.c -o Prj_Tarefa_4
./Prj_Tarefa_4
```

No Windows, rode `Prj_Tarefa_4.exe` (ou `.\Prj_Tarefa_4.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_4
│
├── 📁 src
│   └── Prj_Tarefa_4.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Matriz](../Prj_Matriz): Leitura e exibição de matriz
- [Prj_Maior_Menor](../Prj_Maior_Menor): Maior e menor de 10 números
- [Prj_Array_Exer1](../Prj_Array_Exer1): Exercício: soma e média de um array

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
