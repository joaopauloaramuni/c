# Projeto Prj_VerificarArrayOrdenado (C) 📈

> **Array ordenado? (recursivo)**. Tema: **Recursão**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Verifica, com recursão, se um array está em **ordem crescente**. O exemplo `{1, 2, 3, 5, 4}` não está, por causa do `5` antes do `4`.

## 🎯 Conceitos trabalhados

- Recursão com retorno booleano (1 ou 0)
- Comparação de elementos vizinhos
- Parada antecipada ao achar um par fora de ordem

## 🧠 Como funciona

```c
// Função recursiva para verificar se um array está ordenado de forma crescente
int estaOrdenado(int array[], int tamanho) {
    if (tamanho <= 1)
        return 1;
    if (array[tamanho - 1] < array[tamanho - 2])
        return 0;
    return estaOrdenado(array, tamanho - 1);
}
```

Compara os dois últimos elementos (`array[tamanho - 1]` e `array[tamanho - 2]`). Se estiverem fora de ordem, devolve `0` na hora; se não, verifica o restante. Um array com 0 ou 1 elemento está sempre ordenado (caso base). Troque o array por `{1, 2, 3, 4, 5}` para ver a outra mensagem.

## 💻 Exemplo de execução

```text
O array não está ordenado de forma crescente.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_VerificarArrayOrdenado` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_VerificarArrayOrdenado`:

```bash
gcc src/Prj_VerificarArrayOrdenado.c -o Prj_VerificarArrayOrdenado
./Prj_VerificarArrayOrdenado
```

No Windows, rode `Prj_VerificarArrayOrdenado.exe` (ou `.\Prj_VerificarArrayOrdenado.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_VerificarArrayOrdenado
│
├── 📁 src
│   └── Prj_VerificarArrayOrdenado.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_VerificarParesArray](../Prj_VerificarParesArray): Todos pares? (recursivo)
- [Prj_VerificarElementoPresenteArray](../Prj_VerificarElementoPresenteArray): Elemento presente? (recursivo)

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
