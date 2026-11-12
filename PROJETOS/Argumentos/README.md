# Projeto Argumentos (C, 2010–2011) 📨

> **Argumentos de função**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Primeiros passos**.

## 📖 Descrição

Mostra como passar **argumentos** para uma função: `mult` recebe três `float` e imprime o produto. Os dois primeiros vêm de variáveis (`x = 23.5`, `y = 12.9`) e o terceiro é um valor literal (`3.87`).

## 🎯 Conceitos trabalhados

- Parâmetros e argumentos
- Função `void`
- Valores literais como argumento

## 📚 Entendendo o conceito

### Funções e procedimentos

Uma **função** é um bloco de código com nome, que recebe **parâmetros** e pode devolver um valor com `return`. Quando não devolve nada (`void`), costuma ser chamada de **procedimento**. O **protótipo** (`int soma(int a, int b);`) declara a função antes do uso, para o compilador conhecer a assinatura.

Em C, os argumentos são **passados por valor**: a função recebe uma cópia, e alterar o parâmetro não muda a variável de quem chamou. Para alterar uma variável de fora, passa-se o endereço dela (um ponteiro). As variáveis declaradas dentro da função são **locais**: nascem na chamada e somem no `return`.

#### 🌍 Onde é usado na prática

- Evitar repetição: o mesmo cálculo usado em vários lugares vira uma função (o princípio DRY, *Don't Repeat Yourself*).
- Testes automatizados testam funções isoladas; código todo dentro do `main` é difícil de testar.
- Bibliotecas (como a `<string.h>` e a `<math.h>`) são conjuntos de funções.

#### 💼 Em processos seletivos

Em entrevistas práticas (*live coding*), dividir a solução em funções pequenas e bem nomeadas é um dos sinais de maturidade mais observados. Também é comum perguntarem a diferença entre passagem por valor e por referência.

Perguntas que costumam aparecer:

- Qual a diferença entre passar por valor e por referência?
- Para que serve o protótipo de uma função?
- Uma função pode devolver mais de um valor em C? Como?

#### 🐞 Erros comuns

- Chamar a função antes de declarar e sem protótipo.
- Esperar que alterar o parâmetro mude a variável original.
- Devolver o endereço de uma variável local (ela deixa de existir no `return`).

## 🧠 Como funciona o código

```c
void mult (float a, float b, float c)
{
    printf("%f",a*b*c);
}
```

Os argumentos são copiados para os parâmetros na ordem em que aparecem: `x` vai para `a`, `y` para `b` e `3.87` para `c`. O resultado `23,5 × 12,9 × 3,87 = 1173,19` sai com seis casas decimais, o padrão do `%f`; o último dígito (`1173.190430`) mostra a imprecisão do `float`.

## 💻 Exemplo de execução

```text
1173.190430
```

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/Argumentos.c -o Argumentos
./Argumentos
```

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

### Acentos quebrados?

Os arquivos foram salvos em **ISO-8859-1 (Latin-1)**, o padrão do Eclipse no Windows em 2011. Se os acentos aparecerem como `�`, reabra o arquivo nessa codificação (no VS Code: **Reopen with Encoding → Western (ISO 8859-1)**; no Eclipse: **Edit → Set Encoding**).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1009: Salário com Bônus](https://judge.beecrowd.com/pt/problems/view/1009)
- [Beecrowd 1048: Aumento de Salário](https://judge.beecrowd.com/pt/problems/view/1048)

## 📂 Estrutura do projeto

```text
📁 Argumentos
│
├── 📁 src
│   └── Argumentos.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [prod](../prod): Produto com retorno
- [PrimeiraFuncao](../PrimeiraFuncao): Primeira função

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Soma](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Soma)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: declaração de funções](https://en.cppreference.com/w/c/language/function_declaration)
- [cppreference: definição de funções](https://en.cppreference.com/w/c/language/function_definition)
- [cppreference: return](https://en.cppreference.com/w/c/language/return)

**Ferramentas e referências gerais**

- [Site C (2011): o site original com estes códigos](https://sitec-aramuni.vercel.app/)
- [Repositório de 2011](https://github.com/joaopauloaramuni/c)
- [Aulas do Prof. Rafael Nunes (PDF)](https://github.com/joaopauloaramuni/c/tree/main/Site%20C/pdf)
- [cppreference: referência completa da linguagem C](https://en.cppreference.com/w/c)
- [Projeto de Algoritmos em C, Paulo Feofiloff (IME-USP)](https://www.ime.usp.br/~pf/algoritmos/)
- [Python Tutor: execute C passo a passo e veja a memória](https://pythontutor.com/c.html)
- [VisuAlgo: estruturas de dados e algoritmos animados](https://visualgo.net/)
- [OnlineGDB: compile e rode C no navegador](https://www.onlinegdb.com/)
- [Eclipse CDT (IDE usada na disciplina)](https://eclipse.dev/cdt/)
- [GCC: documentação oficial](https://gcc.gnu.org/onlinedocs/)

**Livros**

- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação – padrão ANSI*. Campus/Elsevier. O livro clássico, escrito por Kernighan com Dennis Ritchie, o criador da linguagem.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Elsevier.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Campus/Elsevier.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. Elsevier.

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Veja o arquivo [LICENSE](../../LICENSE) na raiz do repositório.

-----

João Paulo Aramuni, aluno de Ciência da Computação na FUMEC (2010–2011) · [Repositório](https://github.com/joaopauloaramuni/c)
