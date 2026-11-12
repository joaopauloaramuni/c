# Projeto Prj_VerificarParesArray (C) ✌️

> **Todos pares? (recursivo)**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Verifica, com recursão, se **todos** os elementos de um array são pares. Para no primeiro ímpar que encontrar.

## 🎯 Conceitos trabalhados

- Recursão avançando um índice (`index + 1`)
- Caso base: chegar ao fim sem achar ímpar

## 🧠 Como funciona

```c
int saoPares(int array[], int tamanho, int index) {
    if (index == tamanho)
        return 1;
    if (array[index] % 2 != 0)
        return 0;
    return saoPares(array, tamanho, index + 1);
}
```

Ao contrário dos projetos que diminuem o `tamanho`, aqui o índice cresce de `0` até `tamanho`. Chegar ao fim (`index == tamanho`) quer dizer que nenhum ímpar apareceu, então a resposta é `1`.

## 💻 Exemplo de execução

```text
Todos os elementos do array são pares.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_VerificarParesArray` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_VerificarParesArray`:

```bash
gcc src/Prj_VerificarParesArray.c -o Prj_VerificarParesArray
./Prj_VerificarParesArray
```

No Windows, rode `Prj_VerificarParesArray.exe` (ou `.\Prj_VerificarParesArray.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_VerificarParesArray
│
├── 📁 src
│   └── Prj_VerificarParesArray.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_VerificarArrayOrdenado](../Prj_VerificarArrayOrdenado): Array ordenado? (recursivo)
- [Prj_ContarElementoArray](../Prj_ContarElementoArray): Contar ocorrências recursivamente

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
