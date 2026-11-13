# Projeto Prj_CondicionalMultipla (C) 🔢

> **Condicional múltipla (else if e switch)**. Tema: **Condicionais**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê um número de 1 a 5 e responde qual foi escolhido. O mesmo problema é resolvido **duas vezes**: primeiro com uma cadeia de `if / else if` e depois com `switch`, a alternativa mais enxuta. Por isso a resposta aparece repetida na saída.

## 🎯 Conceitos trabalhados

- `if / else if / else` encadeado
- `switch`, `case`, `break` e `default`
- Comparação de valores inteiros

## 🧠 Como funciona

```c
int main(void) {
    int escolha;

    printf("Digite um número de 1 a 5: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        printf("Você escolheu o número 1.\n");
    } else if (escolha == 2) {
        printf("Você escolheu o número 2.\n");
    } else if (escolha == 3) {
        printf("Você escolheu o número 3.\n");
    } else if (escolha == 4) {
        printf("Você escolheu o número 4.\n");
    } else if (escolha == 5) {
        printf("Você escolheu o número 5.\n");
    } else {
        printf("Opção inválida.\n");
    }

    // Alternativa mais enxuta
    switch (escolha) {
    case 1:
        printf("Você escolheu o número 1.\n");
        break;
    case 2:
        printf("Você escolheu o número 2.\n");
        break;
    case 3:
        printf("Você escolheu o número 3.\n");
        break;
    case 4:
        printf("Você escolheu o número 4.\n");
        break;
    case 5:
        printf("Você escolheu o número 5.\n");
        break;
    default:
        printf("Opção inválida.\n");
    }

    return 0;
}
```

O `switch` compara a variável com cada `case` e pula direto para o que bate. O `break` encerra o `switch`; sem ele, a execução "cai" para o `case` seguinte (*fall-through*). O `default` funciona como o `else` final.

## 💻 Exemplo de execução

```text
Digite um número de 1 a 5: 3
Você escolheu o número 3.
Você escolheu o número 3.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_CondicionalMultipla` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_CondicionalMultipla`:

```bash
gcc src/Prj_CondicionalMultipla.c -o Prj_CondicionalMultipla
./Prj_CondicionalMultipla
```

No Windows, rode `Prj_CondicionalMultipla.exe` (ou `.\Prj_CondicionalMultipla.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_CondicionalMultipla
│
├── 📁 src
│   └── Prj_CondicionalMultipla.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_CondicionalComposta](../Prj_CondicionalComposta): Condicional composta (if/else)
- [Prj_DoWhile_Menu](../Prj_DoWhile_Menu): Menu com do-while e switch
- [Prj_Enum](../Prj_Enum): Enum: dias da semana

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
