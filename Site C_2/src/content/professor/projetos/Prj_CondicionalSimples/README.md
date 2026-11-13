# Projeto Prj_CondicionalSimples (C) 🔀

> **Condicional simples (if)**. Tema: **Condicionais**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Soma dois números e só mostra o resultado **se** a soma for maior que 60. Quando a condição é falsa, o programa termina sem imprimir nada.

## 🎯 Conceitos trabalhados

- Estrutura condicional simples `if`
- Operadores relacionais (`>`)
- Bloco de código entre chaves

## 🧠 Como funciona

```c
int main(void) {
    int ValA, ValB, ValC;

    printf("Entre com os números para serem somados: ");
    scanf("%d", &ValA);
    scanf("%d", &ValB);

    ValC = ValA + ValB;

    if (ValC > 60) {
        printf("O valor da soma é: %d\n", ValC);
    }

    return 0;
}
```

Com `40` e `35` a soma é `75`, a condição `ValC > 60` é verdadeira e a mensagem aparece. Com `10` e `20` (soma `30`) o `printf` é pulado.

## 💻 Exemplo de execução

```text
Entre com os números para serem somados: 40
35
O valor da soma é: 75
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_CondicionalSimples` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_CondicionalSimples`:

```bash
gcc src/Prj_CondicionalSimples.c -o Prj_CondicionalSimples
./Prj_CondicionalSimples
```

No Windows, rode `Prj_CondicionalSimples.exe` (ou `.\Prj_CondicionalSimples.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_CondicionalSimples
│
├── 📁 src
│   └── Prj_CondicionalSimples.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Sequencial](../Prj_Sequencial): Estrutura sequencial
- [Prj_CondicionalComposta](../Prj_CondicionalComposta): Condicional composta (if/else)
- [Prj_CondicionalMultipla](../Prj_CondicionalMultipla): Condicional múltipla (else if e switch)

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
