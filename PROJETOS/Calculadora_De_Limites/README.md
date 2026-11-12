# Projeto Calculadora_De_Limites (C, 2010–2011) ∞

> **Calculadora de limites**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Calculadoras e matemática**.

## 📖 Descrição

O maior projeto da pasta (cerca de 1.400 linhas), feito em grupo por **João Paulo Aramuni, Rafael Lott e Klelvin Carvalho**. Calcula limites de seis tipos de função:

| Opção | Função |
| --- | --- |
| 1 | Primeiro grau (`y = ax + b`) |
| 2 | Quadrática ou de grau superior |
| 3 | Racional (com Briot-Ruffini quando dá 0/0) |
| 4 | Irracional (raiz quadrada) |
| 5 | Exponencial |
| 6 | Logarítmica |

As opções 4, 5 e 6 verificam a **condição de existência** antes de calcular (por exemplo, base `0 < a ≠ 1` na exponencial e no logaritmo).

📜 Este projeto tem uma página no [Site C](https://sitec-aramuni.vercel.app/pag15.html) (seção **Limites**), o site que criei em 2011 para organizar estes códigos.

## 🎯 Conceitos trabalhados

- Programa grande dividido em funções
- Menu com validação
- Variáveis globais
- Dispositivo de Briot-Ruffini
- `pow`, `sqrt`, `log`

## 📚 Entendendo o conceito

Este projeto trabalha **Limites de funções e o dispositivo de Briot-Ruffini**, **Funções e procedimentos** e **C portável e seguro: do MinGW de 2011 ao C moderno**.

### Limites de funções e o dispositivo de Briot-Ruffini

O **limite** de uma função quando `x` tende a `a` é o valor de que `f(x)` se aproxima quando `x` chega perto de `a`. Para funções **contínuas** (polinômios, exponenciais, logaritmos dentro do domínio), o limite é simplesmente `f(a)`: basta substituir.

A dificuldade aparece nas funções racionais, quando a substituição dá **0/0** (indeterminação). Nesse caso, `a` é raiz do numerador e do denominador, então os dois são divisíveis por `(x − a)`. O **dispositivo de Briot-Ruffini** faz essa divisão de polinômio por `(x − a)` só com os coeficientes; depois de cancelar o fator comum, a substituição volta a funcionar.

#### 🌍 Onde é usado na prática

- Cálculo numérico e simulação: derivadas aproximadas são limites calculados com passos pequenos.
- Sistemas de álgebra computacional (Wolfram Alpha, SymPy) resolvem limites simbolicamente.
- O algoritmo de Horner, a mesma ideia do Briot-Ruffini, é o jeito eficiente de avaliar polinômios em programas.

#### 💼 Em processos seletivos

Limites em si não caem em entrevistas de desenvolvimento, mas avaliar polinômios (Horner), trabalhar com ponto flutuante e organizar um programa grande com menus e funções são habilidades cobradas.

Perguntas que costumam aparecer:

- Avalie um polinômio com o método de Horner.
- Por que comparar `float` com `==` é perigoso em cálculos numéricos?

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

### C portável e seguro: do MinGW de 2011 ao C moderno

Os códigos de 2010–2011 foram escritos no Eclipse com MinGW, no Windows do laboratório, e usam recursos que funcionavam ali mas não são padrão C:

| Recurso de 2011 | Problema | Alternativa portável |
| --- | --- | --- |
| `gets(s)` | Removida no C11: não limita o tamanho e permite estouro de *buffer* | `fgets(s, sizeof s, stdin)` |
| `fflush(stdin)` | Comportamento indefinido no padrão; só limpa a entrada no Windows | `while (getchar() != '\n');` ou `scanf(" %c", &c)` |
| `conio.h` / `getch()` | Só existe no Windows/DOS | `getchar()`, ou `termios`/ncurses no Linux |
| `windows.h` / `MessageBox` | API do Windows | `printf` ou uma biblioteca gráfica multiplataforma |
| `setbuf(stdout, NULL)` | Funciona em todo lugar | Era usado para o console do Eclipse mostrar a saída na hora |

O `setbuf(stdout, NULL)` no início dos programas desliga o *buffer* da saída. Sem ele, o console do Eclipse no Windows só mostrava as mensagens depois do `scanf`, e o usuário digitava sem ver a pergunta.

#### 🌍 Onde é usado na prática

- Código que roda em servidores Linux, contêineres Docker e serviços de integração contínua precisa ser portável.
- `gets` e outras funções sem limite de tamanho aparecem em listas de falhas de segurança (CWE-242, uso de função perigosa).

#### 💼 Em processos seletivos

Em vagas de C/C++ e de segurança, é comum perguntarem por que `gets` é perigosa, o que é um estouro de *buffer* e como ler uma linha com segurança.

Perguntas que costumam aparecer:

- Por que `gets` foi removida do C11?
- O que é estouro de *buffer*?
- Por que `fflush(stdin)` não é portável?

## 🧠 Como funciona o código

```c
void limite1() {
    printf("\n");

    printf("** y=ax+b **\n\n");

    printf("Digite o valor de a: ");
    fflush(stdin);
    scanf("%f", &a);

    printf("Digite o valor de b: ");
    fflush(stdin);
    scanf("%f", &b);

    printf("\n");
    printf("Função: y=%.0fx+%.0f\n\n", a, b);

    printf("Digite o valor à qual x ira tender: ");
    fflush(stdin);
    scanf("%f", &x);

    printf("\n");
    printf(
            "O valor do limite quando x tender a %.0f na função y=%.0fx+%.0f e: %.0f\n\n",
            x, a, b, a * x + b);
}
```

Para funções contínuas, o limite é o valor da função no ponto, e é isso que as opções 1 e 2 calculam. A opção 3 é a mais trabalhosa: quando numerador e denominador se anulam, a função `br()` aplica Briot-Ruffini para dividir os polinômios por `(x − a)` e mostra o dispositivo na tela. Página [Limites](https://sitec-aramuni.vercel.app/pag15.html) do Site C.

## 💻 Exemplo de execução

> Execução real, compilada com GCC e com `fflush(stdin)` e `gets` se comportando como no MinGW do Windows de 2011.

```text
** Calculadora de Limites **

Digite o Tipo de funcao envolvida: 

 1 - Primeiro Grau
 2 - Quadratica ou Superior
 3 - Racional
 4 - Irracional
 5 - Exponencial
 6 - Logaritmica

Opcao: 1

** y=ax+b **

Digite o valor de a: 2
Digite o valor de b: 3

Função: y=2x+3

Digite o valor à qual x ira tender: 4

O valor do limite quando x tender a 4 na função y=2x+3 e: 11

Deseja calcular outro limite? s ou n: s

Digite o Tipo de funcao envolvida: 

(menu)

Opcao: 2

Digite o maior grau de x: 3
Digite o menor grau de x: 1

** y=ax3+bx1+c **

Digite o valor de a: 1
Digite o valor de b: 2
Digite o valor de c: 3

Funcao: y=1x3+2x1+3

Digite o valor a qual x ira tender: 2

O valor do limite quando x tender a 2 na função y=1x3+2x+3 e: 15

Deseja calcular outro limite? s ou n: n


Voce saiu do programa.
```

## ⚠️ Pontos de atenção

- Todos os resultados saem com `%.0f`, então limites não inteiros aparecem arredondados.
- As variáveis são globais e reaproveitadas entre as funções: uma conta pode herdar valores da anterior. Passar parâmetros deixaria cada cálculo independente.
- No Linux, compile com `-lm`.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/Calculadora_De_Limites.c -o Calculadora_De_Limites -lm
./Calculadora_De_Limites
```

O `-lm` liga a biblioteca matemática (`sqrt`, `pow`), obrigatório no Linux.

> O `fflush(stdin)` só limpa a entrada no Windows. No Linux e no macOS, algumas leituras podem "pular"; rode no Windows ou adapte como explicado na seção sobre portabilidade.

### No Eclipse IDE for C/C++ Developers

O repositório guarda só a pasta `src` (e a `Debug` gerada em 2011); os arquivos de projeto do Eclipse (`.project` e `.cproject`) não foram versionados. Para abrir:

1. **File → New → C/C++ Project → C Managed Build → Empty Project**, com o *toolchain* **MinGW GCC** (Windows) ou **Linux GCC**.
2. Copie a pasta `src` deste projeto para dentro do projeto novo e atualize (F5).
3. **Project → Build Project** (Ctrl + B) e **Run → Run As → Local C/C++ Application** (Ctrl + F11).

No Linux, adicione a biblioteca `m` em **Project → Properties → C/C++ Build → Settings → GCC C Linker → Libraries**.

### Acentos quebrados?

Os arquivos foram salvos em **ISO-8859-1 (Latin-1)**, o padrão do Eclipse no Windows em 2011. Se os acentos aparecerem como `�`, reabra o arquivo nessa codificação (no VS Code: **Reopen with Encoding → Western (ISO 8859-1)**; no Eclipse: **Edit → Set Encoding**).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C** (o OnlineGDB roda em Linux).

## 🏋️ Para praticar

Exercícios com correção automática sobre o mesmo assunto. O [Beecrowd](https://judge.beecrowd.com/) (antigo URI Online Judge) tem enunciados em português; o [LeetCode](https://leetcode.com/) é a plataforma mais usada para treinar para entrevistas.

- [Beecrowd 1009: Salário com Bônus](https://judge.beecrowd.com/pt/problems/view/1009)
- [Beecrowd 1048: Aumento de Salário](https://judge.beecrowd.com/pt/problems/view/1048)

## 📂 Estrutura do projeto

```text
📁 Calculadora_De_Limites
│
├── 📁 src
│   └── Calculadora_De_Limites.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [ExerRevi4](../ExerRevi4): Exercício de revisão 4: sete operações

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [Wikipedia: Limit of a function](https://en.wikipedia.org/wiki/Limit_of_a_function)
- [Wikipedia: Ruffini's rule](https://en.wikipedia.org/wiki/Ruffini%27s_rule)
- [Wikipedia: Horner's method](https://en.wikipedia.org/wiki/Horner%27s_method)
- [cppreference: declaração de funções](https://en.cppreference.com/w/c/language/function_declaration)
- [cppreference: definição de funções](https://en.cppreference.com/w/c/language/function_definition)
- [cppreference: return](https://en.cppreference.com/w/c/language/return)
- [cppreference: gets (removida no C11)](https://en.cppreference.com/w/c/io/gets)
- [cppreference: fgets](https://en.cppreference.com/w/c/io/fgets)
- [cppreference: fflush](https://en.cppreference.com/w/c/io/fflush)
- [cppreference: setbuf](https://en.cppreference.com/w/c/io/setbuf)
- [MinGW-w64 (GCC no Windows)](https://www.mingw-w64.org/)

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
