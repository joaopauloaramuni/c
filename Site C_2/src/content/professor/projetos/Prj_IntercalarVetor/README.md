# Projeto Prj_IntercalarVetor (C) 🧵

> **Intercalar vetores com malloc**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Junta dois vetores alternando os elementos (`1 3 5` + `2 4 6` → `1 2 3 4 5 6`) em um terceiro vetor criado com `malloc`. Se um vetor for maior, as sobras são copiadas no final.

## 🎯 Conceitos trabalhados

- Alocação dinâmica com `malloc` e `sizeof`
- Função que devolve ponteiro (`int*`)
- Aritmética de ponteiros `*(vetor + i)`
- Liberação com `free`

## 🧠 Como funciona

```c
int* intercalar(int* vetor1, int* vetor2, int tam1, int tam2) {
    int tamTotal = tam1 + tam2;
    int* vetor3 = (int*) malloc(tamTotal * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Intercala os dois vetores
    while (i < tam1 && j < tam2) {
        vetor3[k++] = vetor1[i++];
        vetor3[k++] = vetor2[j++];
    }

    // Copia os elementos restantes de vetor1 (se houver)
    while (i < tam1) {
        vetor3[k++] = vetor1[i++];
    }

    // Copia os elementos restantes de vetor2 (se houver)
    while (j < tam2) {
        vetor3[k++] = vetor2[j++];
    }

    return vetor3;
}
```

O vetor `vetor3` não pode ser um vetor local da função `intercalar`: ele deixaria de existir quando a função terminasse. Por isso é alocado no *heap* com `malloc`, sobrevive ao `return`, e o `main` o libera com `free` depois de usar. `*(vetor + i)` e `vetor[i]` são a mesma coisa.

## 💻 Exemplo de execução

```text
Vetor 1: 1 3 5 
Vetor 2: 2 4 6 
Vetor Intercalado: 1 2 3 4 5 6
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_IntercalarVetor` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_IntercalarVetor`:

```bash
gcc src/Prj_IntercalarVetor.c -o Prj_IntercalarVetor
./Prj_IntercalarVetor
```

No Windows, rode `Prj_IntercalarVetor.exe` (ou `.\Prj_IntercalarVetor.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_IntercalarVetor
│
├── 📁 src
│   └── Prj_IntercalarVetor.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Heap](../Prj_Heap): Alocação dinâmica (heap)
- [Prj_MultiplicaMatrizes_Recursivo](../Prj_MultiplicaMatrizes_Recursivo): Multiplicação de matrizes recursiva

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
