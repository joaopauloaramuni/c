# Projeto Prj_Array_Exer1 (C) ➗

> **Exercício: soma e média de um array**. Tema: **Arrays e matrizes**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê 5 inteiros em um array, calcula a **soma** durante a leitura e mostra a **média** com duas casas decimais.

## 🎯 Conceitos trabalhados

- Leitura de array com `for`
- Acumulador
- Conversão `(double)` para evitar divisão inteira

## 🧠 Como funciona

```c
int main(void) {
    int numeros[5];
    int soma = 0;

    printf("Digite 5 números inteiros:\n");

    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        soma = soma + numeros[i];
    }

    double media = (double) soma / 5;

    printf("Soma: %d\n", soma);
    printf("Média: %.2lf\n", media);

    return 0;
}
```

`(double) soma / 5` converte a soma antes de dividir. Sem a conversão, `151 / 5` daria `30` (divisão inteira) em vez de `30.20`.

## 💻 Exemplo de execução

```text
Digite 5 números inteiros:
Número 1: 10
Número 2: 20
Número 3: 30
Número 4: 40
Número 5: 50
Soma: 150
Média: 30.00
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Array_Exer1` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Array_Exer1`:

```bash
gcc src/Prj_Array_Exer1.c -o Prj_Array_Exer1
./Prj_Array_Exer1
```

No Windows, rode `Prj_Array_Exer1.exe` (ou `.\Prj_Array_Exer1.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Array_Exer1
│
├── 📁 src
│   └── Prj_Array_Exer1.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Prova_AV2](../Prj_Prova_AV2): Prova AV2: arrays e recursão
- [Prj_Tarefa_4](../Prj_Tarefa_4): Tarefa 4: vetores e matrizes

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
