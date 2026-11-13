# Projeto Prj_Heap (C) 🗄️

> **Alocação dinâmica (heap)**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Exemplo curto de **alocação dinâmica**: reserva dois blocos de memória no *heap* com `malloc` e libera um deles com `free`. O programa não imprime nada; a ideia é acompanhar a memória no depurador do Eclipse ou desenhar no quadro onde cada variável fica.

## 🎯 Conceitos trabalhados

- Diferença entre *stack* (pilha) e *heap*
- `malloc` e `free` de `<stdlib.h>`
- Ponteiro para `int`
- Vazamento de memória (*memory leak*)

## 🧠 Como funciona

```c
int main(void) {

    int x = 2;
    int *y = malloc(100);
    int *z = malloc(400);
    free(z);

    return 0;
}
```

| Variável | Onde fica | Tamanho |
| --- | --- | --- |
| `x` | Pilha (*stack*) | `sizeof(int)`, normalmente 4 bytes |
| `y` | O ponteiro fica na pilha; os 100 bytes ficam no *heap* | 100 bytes |
| `z` | O ponteiro fica na pilha; os 400 bytes ficam no *heap* | 400 bytes (liberados com `free`) |

O bloco apontado por `y` **nunca é liberado**: é um vazamento de memória proposital, para discutir em aula. Para conferir, rode com o Valgrind: `valgrind --leak-check=full ./Prj_Heap` mostra `definitely lost: 100 bytes in 1 blocks`.

## 💻 Exemplo de execução

```text
(o programa não imprime nada)
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Heap` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Heap`:

```bash
gcc src/Prj_Heap.c -o Prj_Heap
./Prj_Heap
```

No Windows, rode `Prj_Heap.exe` (ou `.\Prj_Heap.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Heap
│
├── 📁 src
│   └── Prj_Heap.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Memoria](../Prj_Memoria): Endereço de memória
- [Prj_IntercalarVetor](../Prj_IntercalarVetor): Intercalar vetores com malloc
- [Prj_MultiplicaMatrizes_Recursivo](../Prj_MultiplicaMatrizes_Recursivo): Multiplicação de matrizes recursiva

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
