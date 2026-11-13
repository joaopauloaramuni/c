# Projeto Prj_Union_Struct (C) 🧬

> **Union dentro de struct**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Uma `struct Pessoa` com nome, idade e uma `union DadosAdicionais` que guarda **ou** um inteiro, **ou** um float, **ou** um texto, conforme a pessoa.

## 🎯 Conceitos trabalhados

- Union como campo de struct
- Inicializadores designados (`.valorInteiro = 123`)

## 🧠 Como funciona

```c
int main(void) {
    // Criando uma instância da struct Pessoa
    struct Pessoa pessoa1 = { "João", 25, { .valorInteiro = 123} };
    struct Pessoa pessoa2 = { "Maria", 30, { .valorFlutuante = 42.0f } };
    struct Pessoa pessoa3 = { "Carlos", 22, { .texto = "Texto Extra" } };

    // Exibindo informações das pessoas
    printf("Nome: %s, Idade: %d, Dados Extras: %d\n", pessoa1.nome,
            pessoa1.idade, pessoa1.dadosExtras.valorInteiro);
    printf("Nome: %s, Idade: %d, Dados Extras: %.2f\n", pessoa2.nome,
            pessoa2.idade, pessoa2.dadosExtras.valorFlutuante);
    printf("Nome: %s, Idade: %d, Dados Extras: %s\n", pessoa3.nome,
            pessoa3.idade, pessoa3.dadosExtras.texto);

    return 0;
}
```

O `{ .valorFlutuante = 42.0f }` escolhe qual campo da union inicializar. O programa precisa "saber" qual campo foi usado em cada pessoa: em projetos reais, isso costuma ficar em um `enum` ao lado da union (*tagged union*).

## 💻 Exemplo de execução

```text
Nome: João, Idade: 25, Dados Extras: 123
Nome: Maria, Idade: 30, Dados Extras: 42.00
Nome: Carlos, Idade: 22, Dados Extras: Texto Extra
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Union_Struct` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Union_Struct`:

```bash
gcc src/Prj_Union_Struct.c -o Prj_Union_Struct
./Prj_Union_Struct
```

No Windows, rode `Prj_Union_Struct.exe` (ou `.\Prj_Union_Struct.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Union_Struct
│
├── 📁 src
│   └── Prj_Union_Struct.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Union](../Prj_Union): Union
- [Prj_Enum_Struct](../Prj_Enum_Struct): Enum dentro de struct

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
