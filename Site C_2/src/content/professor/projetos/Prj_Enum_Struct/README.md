# Projeto Prj_Enum_Struct (C) 🗓️

> **Enum dentro de struct**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Uma `struct Compromisso` com descrição, dia (do tipo `enum DiaSemana`) e hora. Três compromissos são criados e impressos.

## 🎯 Conceitos trabalhados

- Campo do tipo `enum` em uma struct
- Inicialização de struct com `{ }`

## 🧠 Como funciona

```c
int main(void) {
    // Criando uma instância da struct Compromisso com um valor do enum
    struct Compromisso compromisso1 = { "Reunião de equipe", SEGUNDA, 14 };
    struct Compromisso compromisso2 = { "Almoço com cliente", QUARTA, 12 };
    struct Compromisso compromisso3 = { "Treino na academia", SEXTA, 18 };

    // Exibindo informações dos compromissos
    printf("Compromisso 1: %s, Dia: %d, Hora: %d\n", compromisso1.descricao,
            compromisso1.dia, compromisso1.hora);
    printf("Compromisso 2: %s, Dia: %d, Hora: %d\n", compromisso2.descricao,
            compromisso2.dia, compromisso2.hora);
    printf("Compromisso 3: %s, Dia: %d, Hora: %d\n", compromisso3.descricao,
            compromisso3.dia, compromisso3.hora);

    return 0;
}
```

Na saída, os dias aparecem como números (`Dia: 1`, `Dia: 3`, `Dia: 5`) porque o `printf` com `%d` mostra o valor inteiro do `enum`. Para escrever o nome, dá para usar um vetor de strings: `const char *nomes[] = {"Domingo", "Segunda", ...};` e imprimir `nomes[compromisso1.dia]`.

## 💻 Exemplo de execução

```text
Compromisso 1: Reunião de equipe, Dia: 1, Hora: 14
Compromisso 2: Almoço com cliente, Dia: 3, Hora: 12
Compromisso 3: Treino na academia, Dia: 5, Hora: 18
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Enum_Struct` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Enum_Struct`:

```bash
gcc src/Prj_Enum_Struct.c -o Prj_Enum_Struct
./Prj_Enum_Struct
```

No Windows, rode `Prj_Enum_Struct.exe` (ou `.\Prj_Enum_Struct.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Enum_Struct
│
├── 📁 src
│   └── Prj_Enum_Struct.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Enum](../Prj_Enum): Enum: dias da semana
- [Prj_Union_Struct](../Prj_Union_Struct): Union dentro de struct

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
