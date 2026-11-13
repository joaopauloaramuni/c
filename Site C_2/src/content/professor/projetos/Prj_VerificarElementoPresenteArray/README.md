# Projeto Prj_VerificarElementoPresenteArray (C) 🎯

> **Elemento presente? (recursivo)**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Busca, com recursão, se um valor está presente no array, olhando do fim para o começo. No exemplo, procura o `3` em `{1, 2, 3, 5, 4}`.

## 🎯 Conceitos trabalhados

- Busca linear recursiva
- Retorno antecipado ao encontrar o elemento
- Limites de índice em arrays

## 🧠 Como funciona

```c
// Função recursiva para verificar se um elemento está presente no array
int elementoPresente(int array[], int elemento, int tamanho) {
    if (tamanho < 0)
        return 0;
    if (array[tamanho] == elemento)
        return 1;
    return elementoPresente(array, elemento, tamanho - 1);
}
```

A cada chamada a função olha uma posição e, se não encontrou, chama a si mesma com a posição anterior. Quando passa da posição `0` (`tamanho < 0`), conclui que o elemento não está no array.

## 💻 Exemplo de execução

```text
O elemento está presente no array.
```

## ⚠️ Pontos de atenção

- O `main` chama `elementoPresente(arr, 3, tamanho)` com `tamanho = 5`, e a primeira comparação lê `array[5]`, **uma posição depois do fim** do array (os índices válidos vão de 0 a 4). O programa funciona no exemplo por sorte, mas ler fora do array é comportamento indefinido em C. A correção é chamar com `tamanho - 1`.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_VerificarElementoPresenteArray` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_VerificarElementoPresenteArray`:

```bash
gcc src/Prj_VerificarElementoPresenteArray.c -o Prj_VerificarElementoPresenteArray
./Prj_VerificarElementoPresenteArray
```

No Windows, rode `Prj_VerificarElementoPresenteArray.exe` (ou `.\Prj_VerificarElementoPresenteArray.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_VerificarElementoPresenteArray
│
├── 📁 src
│   └── Prj_VerificarElementoPresenteArray.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_ContarElementoArray](../Prj_ContarElementoArray): Contar ocorrências recursivamente
- [Prj_VerificarArrayOrdenado](../Prj_VerificarArrayOrdenado): Array ordenado? (recursivo)

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
