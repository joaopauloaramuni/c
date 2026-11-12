# Projeto Prj_Enum (C) 📅

> **Enum: dias da semana**. Tema: **Structs, enums e unions**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Cria o tipo enumerado `enum DiaSemana` (DOMINGO a SABADO) e usa um `switch` para escrever o dia por extenso.

## 🎯 Conceitos trabalhados

- `enum` e constantes nomeadas
- Valores implícitos (DOMINGO = 0, SEGUNDA = 1...)
- `enum` em `switch`

## 🧠 Como funciona

```c
int main(void) {
    // Declaração de uma variável do tipo enum DiaSemana
    enum DiaSemana hoje = TERCA;

    // Uso do enum em uma estrutura de controle (switch)
    switch (hoje) {
    case DOMINGO:
        printf("Hoje é domingo.\n");
        break;
    case SEGUNDA:
        printf("Hoje é segunda-feira.\n");
        break;
    case TERCA:
        printf("Hoje é terça-feira.\n");
        break;
    case QUARTA:
        printf("Hoje é quarta-feira.\n");
        break;
    case QUINTA:
        printf("Hoje é quinta-feira.\n");
        break;
    case SEXTA:
        printf("Hoje é sexta-feira.\n");
        break;
    case SABADO:
        printf("Hoje é sábado.\n");
        break;
    default:
        printf("Dia desconhecido.\n");
        break;
    }

    return 0;
}
```

Por baixo, cada constante do `enum` é um inteiro: DOMINGO vale 0, SEGUNDA 1 e assim por diante. A vantagem é ler `case TERCA:` em vez de `case 2:`.

## 💻 Exemplo de execução

```text
Hoje é terça-feira.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Enum` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Enum`:

```bash
gcc src/Prj_Enum.c -o Prj_Enum
./Prj_Enum
```

No Windows, rode `Prj_Enum.exe` (ou `.\Prj_Enum.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Enum
│
├── 📁 src
│   └── Prj_Enum.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Enum_Struct](../Prj_Enum_Struct): Enum dentro de struct
- [Prj_CondicionalMultipla](../Prj_CondicionalMultipla): Condicional múltipla (else if e switch)

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
