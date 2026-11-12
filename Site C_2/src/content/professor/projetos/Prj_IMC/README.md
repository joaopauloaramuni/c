# Projeto Prj_IMC (C) ⚖️

> **Cálculo do IMC**. Tema: **Condicionais**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Calcula o **Índice de Massa Corporal** (IMC = peso ÷ altura²) e classifica o resultado em abaixo do peso, normal, acima do peso ou obeso, com uma cadeia de `if / else if`.

## 🎯 Conceitos trabalhados

- Variáveis `float` e leitura com `%f`
- Expressões aritméticas
- `if / else if` encadeado
- Operador lógico `&&`

## 🧠 Como funciona

```c
int main(void) {

    //Declarando as variáveis
    float peso, altura, imc;

    //Lendo as variáveis do usuário
    printf("Cálculo do IMC\n");
    printf("Digite o peso em kg: ");
    scanf("%f", &peso);
    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

    //Calculando o IMC (Regra de negócio)
    imc = peso / (altura * altura);

    //Exibindo o resultado
    printf("\nSeu IMC é: %.2f", imc);

    //Testando o IMC calculado
    if(imc < 18.5){
        printf("\nVocê está abaixo do peso.");
    }else if(imc >= 18.5 && imc <= 25.0){ //&& AND (e) ------ || OR (ou)
        printf("\nSeu peso está normal.");
    }else if(imc > 25.0 && imc <= 30.0){
        printf("\nVocê está acima do peso.");
    }else if(imc > 30.0){
        printf("\nVocê está obeso.");
    }

    //Saindo do programa
    return EXIT_SUCCESS;
}
```

| IMC | Mensagem |
| --- | --- |
| menor que 18,5 | Você está abaixo do peso. |
| de 18,5 a 25,0 | Seu peso está normal. |
| de 25,0 a 30,0 | Você está acima do peso. |
| maior que 30,0 | Você está obeso. |

O comentário `//&& AND (e) ------ || OR (ou)` no código resume os dois operadores lógicos usados nas condições. A altura deve ser digitada em metros, com **ponto** decimal (`1.75`).

## 💻 Exemplo de execução

```text
Cálculo do IMC
Digite o peso em kg: 70
Digite a altura em metros: 1.75

Seu IMC é: 22.86
Seu peso está normal.
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_IMC` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_IMC`:

```bash
gcc src/Prj_IMC.c -o Prj_IMC
./Prj_IMC
```

No Windows, rode `Prj_IMC.exe` (ou `.\Prj_IMC.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_IMC
│
├── 📁 src
│   └── Prj_IMC.c
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_CondicionalComposta](../Prj_CondicionalComposta): Condicional composta (if/else)
- [Prj_CondicionalMultipla](../Prj_CondicionalMultipla): Condicional múltipla (else if e switch)
- [Prj_Tarefa_3_3](../Prj_Tarefa_3_3): Tarefa 3.3: seleção de basquete

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
