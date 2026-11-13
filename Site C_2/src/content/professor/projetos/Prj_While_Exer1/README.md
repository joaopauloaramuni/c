# Projeto Prj_While_Exer1 (C) ⚖️

> **while: contar pares e ímpares**. Tema: **Repetição**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Lê números até o usuário digitar `0` e, no final, mostra quantos foram **pares** e quantos foram **ímpares**.

## 🎯 Conceitos trabalhados

- Laço `while` com valor sentinela (`0`)
- Operador de resto `%` para testar paridade
- Dois contadores independentes

## 🧠 Como funciona

```c
int main(void) {
    int contpar = 0, contimpar = 0, num = 400;

    while (num != 0) {
        printf("Entre com um número; para encerrar, digite 0: ");
        scanf("%d", &num);

        if (num != 0) {
            if (num % 2 == 0) { //operador de módulo - verifica o resto
                contpar = contpar + 1;
            } else {
                contimpar = contimpar + 1;
            }
        }
    }

    printf("A quantidade de números pares é: %d\n", contpar);
    printf("A quantidade de números ímpares é: %d\n", contimpar);

    return 0;
}
```

`num % 2 == 0` é verdadeiro quando o resto da divisão por 2 é zero, ou seja, quando o número é par. A variável `num` começa com `400` só para a condição `num != 0` ser verdadeira na primeira volta; o [Prj_DoWhile_Exer1](../Prj_DoWhile_Exer1) resolve o mesmo problema sem esse truque, com `do-while`.

## 💻 Exemplo de execução

```text
Entre com um número; para encerrar, digite 0: 4
Entre com um número; para encerrar, digite 0: 7
Entre com um número; para encerrar, digite 0: 10
Entre com um número; para encerrar, digite 0: 3
Entre com um número; para encerrar, digite 0: 0
A quantidade de números pares é: 2
A quantidade de números ímpares é: 2
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_While_Exer1` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_While_Exer1`:

```bash
gcc src/Prj_While_Exer1.c -o Prj_While_Exer1
./Prj_While_Exer1
```

No Windows, rode `Prj_While_Exer1.exe` (ou `.\Prj_While_Exer1.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_While_Exer1
│
├── 📁 src
│   └── Prj_While_Exer1.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_DoWhile_Exer1](../Prj_DoWhile_Exer1): do-while: contar pares e ímpares
- [Prj_While_Exer2](../Prj_While_Exer2): while: contar números digitados

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
