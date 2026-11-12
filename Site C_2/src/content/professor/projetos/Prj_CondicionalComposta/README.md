# Projeto Prj_CondicionalComposta (C) ✅

> **Condicional composta (if/else)**. Tema: **Condicionais**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê três notas, soma e informa se o aluno foi **Aprovado** (soma maior ou igual a 60) ou **Reprovado**. Mostra o `if/else`, em que sempre um dos dois caminhos é executado.

## 🎯 Conceitos trabalhados

- Estrutura condicional composta `if / else`
- Leitura de vários valores em um `scanf`
- Operador `>=`

## 🧠 Como funciona

```c
int main(void) {
    float Nota1, Nota2, Nota3, NotaF;

    printf("Entre com as notas do aluno: ");
    scanf("%f %f %f", &Nota1, &Nota2, &Nota3);

    NotaF = Nota1 + Nota2 + Nota3;

    if (NotaF >= 60) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;
}
```

As três notas podem ser digitadas na mesma linha, separadas por espaço, porque o formato `"%f %f %f"` lê os três valores de uma vez. A regra de aprovação (60 pontos no total) é a mesma usada nas disciplinas da PUC Minas.

## 💻 Exemplo de execução

```text
Entre com as notas do aluno: 20 25 30
Aprovado
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_CondicionalComposta` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_CondicionalComposta`:

```bash
gcc src/Prj_CondicionalComposta.c -o Prj_CondicionalComposta
./Prj_CondicionalComposta
```

No Windows, rode `Prj_CondicionalComposta.exe` (ou `.\Prj_CondicionalComposta.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_CondicionalComposta
│
├── 📁 src
│   └── Prj_CondicionalComposta.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_CondicionalSimples](../Prj_CondicionalSimples): Condicional simples (if)
- [Prj_CondicionalMultipla](../Prj_CondicionalMultipla): Condicional múltipla (else if e switch)
- [Prj_Ternario](../Prj_Ternario): Operador ternário

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
