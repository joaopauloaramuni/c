# Projeto Prj_Tarefa_3_3 (C) 🏀

> **Tarefa 3.3: seleção de basquete**. Tema: **Tarefas e provas**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Resolução do exercício 3 da **Tarefa 3**: com idade, altura (em cm) e sexo, informa se a pessoa está apta para o time juvenil feminino ou masculino de basquete.

📄 Enunciado: [Tarefa 3 (PDF)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/blob/main/TAREFAS/PDF/Tarefa%203.pdf)

## 🎯 Conceitos trabalhados

- `if` aninhado
- Operador lógico `&&`
- Validação de uma opção codificada (1 ou 2)

## 🧠 Como funciona

```c
// Função para validar a situação da pessoa
void validarSituacao(int idade, int altura, int sexo) {
    if (altura >= 180 && idade > 16) {
        if (sexo == 1) {
            printf("Apta a jogar no time Feminino Juvenil de Basquete.\n");
        } else if (sexo == 2) {
            printf("Apto a jogar no time Masculino Juvenil de Basquete.\n");
        } else {
            printf("Não apto.\n");
        }
    } else {
        printf("Não apto.\n");
    }
}
```

A regra comum (altura ≥ 180 cm **e** idade > 16) fica no `if` de fora. Só depois o sexo decide o time. Qualquer código de sexo diferente de 1 ou 2 também resulta em "Não apto".

## 💻 Exemplo de execução

```text
Digite a idade do candidato: 17
Digite a altura do candidato (em cm): 182
Digite o sexo do candidato (Feminino=1, Masculino=2): 1
Apta a jogar no time Feminino Juvenil de Basquete.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Tarefa_3_3` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Tarefa_3_3`:

```bash
gcc src/Prj_Tarefa_3_3.c -o Prj_Tarefa_3_3
./Prj_Tarefa_3_3
```

No Windows, rode `Prj_Tarefa_3_3.exe` (ou `.\Prj_Tarefa_3_3.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Tarefa_3_3
│
├── 📁 src
│   └── Prj_Tarefa_3_3.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Tarefa_3_1](../Prj_Tarefa_3_1): Tarefa 3.1: eleição de 2º turno
- [Prj_Tarefa_3_2](../Prj_Tarefa_3_2): Tarefa 3.2: gasto de um fumante
- [Prj_IMC](../Prj_IMC): Cálculo do IMC

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
