# Projeto Prj_Memoria (C) 🧠

> **Endereço de memória**. Tema: **Ponteiros e memória**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Imprime o **endereço de memória** onde a variável `minhaVariavel` foi guardada. É a ponte entre variáveis e ponteiros: toda variável mora em algum endereço da memória RAM.

## 🎯 Conceitos trabalhados

- Operador `&` (endereço de)
- Especificador `%p` para endereços
- Memória de pilha (*stack*)

## 🧠 Como funciona

```c
int main(void) {
    int minhaVariavel = 13;
    printf("O endereço de memória de 'minhaVariavel' é: %p\n", &minhaVariavel);
    return 0;
}
```

O `&minhaVariavel` devolve o endereço da variável e o `%p` o formata em hexadecimal. O valor muda a cada execução porque o sistema operacional sorteia a posição da pilha (ASLR, *Address Space Layout Randomization*), uma proteção de segurança.

## 💻 Exemplo de execução

```text
O endereço de memória de 'minhaVariavel' é: 0x7ffc2dbeb3d4
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Memoria` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Memoria`:

```bash
gcc src/Prj_Memoria.c -o Prj_Memoria
./Prj_Memoria
```

No Windows, rode `Prj_Memoria.exe` (ou `.\Prj_Memoria.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Memoria
│
├── 📁 src
│   └── Prj_Memoria.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Heap](../Prj_Heap): Alocação dinâmica (heap)
- [Prj_ByVal_ByRef](../Prj_ByVal_ByRef): Passagem por valor e por referência
- [Prj_Funcoes_Ponteiros](../Prj_Funcoes_Ponteiros): Funções com ponteiros: troca e zera

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
