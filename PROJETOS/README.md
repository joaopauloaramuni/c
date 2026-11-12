# 📁 PROJETOS (2010–2011)

Códigos em C que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, entre 2010 e 2011, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Os exercícios foram planejados pelo professor, e a publicação foi autorizada por ele.

São **61 projetos** do Eclipse e o arquivo solto [`Aramuni.c`](Aramuni.c). Cada pasta tem um `README.md` que explica o código e o conceito por trás dele (o que é, onde é usado, como aparece em processos seletivos), com uma execução real, os pontos de atenção encontrados ao revisar o código em 2024 e exercícios para praticar.

> 🕰️ Estes códigos têm 15 anos e foram escritos para o Windows com MinGW. Alguns usam recursos que não são padrão (`gets`, `fflush(stdin)`, `conio.h`); os READMEs explicam cada caso e como adaptar.

📜 O [Site C](https://sitec-aramuni.vercel.app/), criado em 2011, apresenta 19 destes programas com os enunciados da época.

🔁 Os projetos que escrevi em 2024, já como professor, estão no repositório [algoritmos-e-estruturas-de-dados-i](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS).

## Primeiros passos

| Projeto | O que faz | Site C |
| --- | --- | --- |
| 👋 [aloMundo](aloMundo) | O primeiro programa: imprime `!!! Hello World !!!`. |  |
| 👋 [aloMundo2](aloMundo2) | A segunda versão do primeiro programa, agora com a própria mensagem: `!!! Alo Mundo 2 !!!`. |  |
| 📨 [Argumentos](Argumentos) | Mostra como passar **argumentos** para uma função: `mult` recebe três `float` e imprime o produto. |  |
| 🔔 [barulhim](barulhim) | Toca dois bipes com o caractere de controle `\a` (*alert*) e, entre eles, faz uma pausa contando até 100 milhões em um laço vazio. |  |
| 🔤 [Char](Char) | Lê um caractere e mostra o seu código na **tabela ASCII**: `A` é 65, `a` é 97, `0` é 48. |  |
| 🔂 [do_while](do_while) | Pede `Digite uma opção:` repetidamente até o usuário digitar `q` ou `Q`. |  |
| 🔁 [ExerRevi](ExerRevi) | Lê um inteiro e imprime `Este é o seu valor: ...` cinco vezes, com cinco `printf` iguais. |  |
| 🔁 [ExerRevi2](ExerRevi2) | O mesmo ExerRevi, agora com as cinco linhas dentro da função `imprime5x(int x)`. |  |
| 🔄 [for](for) | Imprime `Numero:1` até `Numero:5` com um laço `for`. |  |
| ⌨️ [getch](getch) | Lê **uma tecla**, sem esperar o *Enter* e sem mostrar a tecla na tela, com `getch()` da biblioteca `conio.h`, e responde `Voce pressionou a tecla ...`. |  |
| ⌨️ [getchar](getchar) | Variação do do_while: lê caracteres com `getchar()` até `q` ou `Q`, com uma leitura extra antes do laço. |  |
| ⚖️ [parouimpar](parouimpar) | Diz se o número digitado é par ou ímpar, usando o resto da divisão por 2 numa função com `#define PAR 2`. | [Par ou Ímpar](https://sitec-aramuni.vercel.app/pag12.html) |
| 🧩 [PrimeiraFuncao](PrimeiraFuncao) | A primeira função criada na disciplina: `mensagem()` imprime `Ola!` e é chamada três vezes pelo `main`, seguida de `Tudo Bem?`. |  |
| ✖️ [prod](prod) | Função `prod(x, y)` que **devolve** o produto de dois inteiros. |  |
| 📅 [switch](switch) | Lê um número de 0 a 6 e escreve o dia da semana (0 = Domingo). |  |
| 🔁 [while](while) | O mesmo resultado do for (`Numero:1` a `Numero:5`), agora com `while`. |  |

## Calculadoras e matemática

| Projeto | O que faz | Site C |
| --- | --- | --- |
| 🧮 [Calc2.1](Calc2.1) | Versão 2.1 da calculadora: `Mult`, `Div`, `Soma` e `Sub` agora **devolvem** o resultado com `return`, e o `main` decide como mostrar. | [Calculadoras](https://sitec-aramuni.vercel.app/pag7.html) |
| 👉 [CalcPoint](CalcPoint) | A calculadora de novo, agora com **ponteiros**: cada procedimento recebe os endereços de `x`, `y` e de uma variável de resultado `z`, e escreve a resposta em `*z`. | [Calculadoras](https://sitec-aramuni.vercel.app/pag7.html) |
| 🧮 [Calculadora](Calculadora) | Lê um número e, numa função `square`, mostra o número ao quadrado e as operações dele com ele mesmo: subtração (sempre 0), soma (o dobro) e divisão (sempre 1). | [Calculadoras](https://sitec-aramuni.vercel.app/pag7.html) |
| 🧮 [Calculadora2](Calculadora2) | Lê X e Y e mostra multiplicação, divisão, soma e subtração, cada uma em um procedimento `void` que imprime o próprio resultado. | [Calculadoras](https://sitec-aramuni.vercel.app/pag7.html) |
| ∞ [Calculadora_De_Limites](Calculadora_De_Limites) | O maior projeto da pasta (cerca de 1.400 linhas), feito em grupo por **João Paulo Aramuni, Rafael Lott e Klelvin Carvalho**. | [Limites](https://sitec-aramuni.vercel.app/pag15.html) |
| 📏 [Distancia](Distancia) | Lê dois pontos `(x0, y0)` e `(x1, y1)` e calcula a distância entre eles pelo teorema de Pitágoras, devolvendo o resultado por ponteiro. | [Distância](https://sitec-aramuni.vercel.app/pag16.html) |
| 🔵 [Esfera](Esfera) | Lê o raio e calcula a área da superfície (`4πr²`) e o volume (`4/3 πr³`) de uma esfera, cada um em um procedimento que devolve o resultado por ponteiro. | [Esfera](https://sitec-aramuni.vercel.app/pag18.html) |
| #️⃣ [ExerRevi3](ExerRevi3) | Uma função `gerahash(arg1, arg2)` que devolve `arg1 % arg2`. |  |
| 📐 [ExerRevi4](ExerRevi4) | Uma bateria de funções matemáticas, cada uma testada em sequência: raiz quadrada, potência, soma, subtração, divisão, multiplicação e resto. |  |
| ➗ [MDC](MDC) | Calcula o máximo divisor comum de dois números com o algoritmo de Euclides, de forma recursiva. |  |
| ▭ [Retangulo](Retangulo) | Lê dois cantos opostos de um retângulo e um ponto, e diz se o ponto está **no centro**, **dentro**, **na borda** ou **fora**. | [Retângulo](https://sitec-aramuni.vercel.app/pag17.html) |

## Ponteiros

| Projeto | O que faz | Site C |
| --- | --- | --- |
| 👉 [ExerPonteiros](ExerPonteiros) | Lê uma string e a passa para `lestring`, uma função que recebe `char *` e devolve o mesmo ponteiro. |  |
| 👉 [Ponteiros](Ponteiros) | Cria `y = 35` e um ponteiro `ptr` que guarda o endereço de `y`, e imprime o valor, o endereço, o conteúdo do ponteiro e o valor acessado **através** do ponteiro. |  |
| 🧪 [testesPtrs](testesPtrs) | Aprofunda o Ponteiros: além do endereço de `x` e do valor por `*ptr`, mostra o **endereço do próprio ponteiro** (`&ptr`) e uma função que recebe uma string, um ponteiro para `int`, um vetor de `char` e um `int`. |  |

## Strings

| Projeto | O que faz | Site C |
| --- | --- | --- |
| 🔢 [exerciciocharint](exerciciocharint) | Percorre um vetor de inteiros e uma string usando o mesmo truque: **parar no zero**. |  |
| 🔎 [frases](frases) | Lê uma frase e conta quantas vezes aparece a letra `c` minúscula. |  |
| 🧵 [FuncoesStr](FuncoesStr) | Reúne três funções de string escritas com ponteiros: `StrCpy` (copiar), `StrCat` (concatenar, reaproveitando a `StrCpy`) e `StrLen` (tamanho). | [Funções STR](https://sitec-aramuni.vercel.app/pag6.html) |
| ↩️ [Inverte String Rec](Inverte%20String%20Rec) | Imprime uma string de trás para frente com duas funções recursivas: uma calcula o índice do último caractere e a outra imprime do fim para o começo. |  |
| 📐 [lenght](lenght) | Implementação própria do `strlen`: conta os caracteres de uma palavra andando com um ponteiro até o `'\0'`. |  |
| 📋 [Letra](Letra) | Um menu que conta as letras de uma palavra (opção 1), escreve a palavra ao contrário (2), faz as duas coisas (3) ou sai (4). |  |
| 📋 [MenuOpcoes](MenuOpcoes) | O mesmo programa do Letra, salvo em outro projeto com o arquivo `MENU_OPCOES.c`: contar letras, inverter a palavra, as duas coisas ou sair. |  |
| 🔄 [pali](pali) | Verifica se uma frase é palíndromo copiando-a de trás para frente em `string2` e comparando as duas, caractere por caractere. | [Palíndromo](https://sitec-aramuni.vercel.app/pag13.html) |
| 📝 [strcpy](strcpy) | Implementação própria do `strcpy`: copia caractere por caractere com dois ponteiros e coloca o `'\0'` no final. |  |
| 🔁 [String_Recursivo](String_Recursivo) | Verifica palíndromos com uma função recursiva de **uma linha**, comparando as pontas e chamando a si mesma para o miolo. | [Palíndromo](https://sitec-aramuni.vercel.app/pag13.html) |
| 📐 [StrLenght](StrLenght) | O mesmo `strlen` do lenght, agora **recursivo e em uma linha**, com operador ternário e operador vírgula. |  |

## Recursão

| Projeto | O que faz | Site C |
| --- | --- | --- |
| ❗ [fatorial](fatorial) | Calcula o fatorial de `n` com recursão. | [Fatorial](https://sitec-aramuni.vercel.app/pag3.html) |
| 🔁 [Fatorial_Normal](Fatorial_Normal) | O fatorial **sem recursão**, com um laço `while` que multiplica e decrementa `x` até chegar a 1. |  |
| 🧙 [FunRecUmReturn](FunRecUmReturn) | O desafio que virou a marca deste repositório: **12 funções recursivas escritas com um único `return` em uma linha**, reunidas num menu. | [Otimizadas](https://sitec-aramuni.vercel.app/pag19.html) |
| 🗼 [hanoi](hanoi) | A mesma Torre de Hanói do Torre, mas com a função recursiva escrita em **uma única linha**, usando três macros (`A`, `B` e `C`) e o operador ternário. | [Otimizadas](https://sitec-aramuni.vercel.app/pag19.html) |
| 🚀 [Pow_Recursivo](Pow_Recursivo) | Calcula `base^expoente` recursivamente, multiplicando a base pela potência com expoente uma unidade menor. |  |
| 🐚 [Recursividade](Recursividade) | Lê um número e mostra o fatorial e o termo de Fibonacci dele, ambos recursivos. | [Fibonacci](https://sitec-aramuni.vercel.app/pag4.html) |
| 🗼 [Torre](Torre) | Resolve a Torre de Hanói para até 10 discos, imprimindo cada movimento e o total de movimentos (2ⁿ − 1). | [Torre de Hanói](https://sitec-aramuni.vercel.app/pag1.html) |
| 🧙 [Aramuni.c](Aramuni.c) | Arquivo solto com as 12 funções recursivas de uma linha (o mesmo código do [FunRecUmReturn](FunRecUmReturn), sem o cabeçalho). | [Otimizadas](https://sitec-aramuni.vercel.app/pag19.html) |

## Structs

| Projeto | O que faz | Site C |
| --- | --- | --- |
| 🔗 [exerstruct](exerstruct) | Dá o passo entre structs e listas encadeadas: a `struct cliente` ganha um campo `TCli *prox`, dois clientes são criados com `malloc` e **ligados** (`cli1->prox = cli2`), e um `for` percorre a corrente até o `NULL`. |  |
| 🗂️ [exerstruct2](exerstruct2) | Cadastro de clientes em que o tamanho do vetor é perguntado ao usuário e alocado com `malloc(tam * sizeof(TCli))`. |  |
| 🏠 [Struct](Struct) | Define uma `struct endereco` e uma `struct cliente` que **contém** um endereço (struct aninhada), com apelidos criados por `typedef` (`TEnd` e `TCli`). |  |

## Estruturas de dados

| Projeto | O que faz | Site C |
| --- | --- | --- |
| 🌳 [arvorebinaria](arvorebinaria) | Uma **árvore binária de busca** de caracteres, em `arvore.h` e `arvorebinaria.c`: criar árvore vazia, testar se está vazia, criar nó, inserir respeitando a ordem e imprimir em **pré-ordem** com parênteses. | [Árvores](https://sitec-aramuni.vercel.app/pag9.html) |
| 🚶 [FilaDinamica](FilaDinamica) | Uma **fila** com lista encadeada e dois ponteiros, `ini` e `fim`, em `lista.h` (criado pelo Prof. | [Filas](https://sitec-aramuni.vercel.app/pag10.html) |
| 💀 [josephus](josephus) | Resolve o **problema de Josephus** com uma lista circular de inteiros. | [Josephus](https://sitec-aramuni.vercel.app/pag5.html) |
| ⭕ [ListaCi](ListaCi) | Lista **circular** simplesmente encadeada: o último nó aponta de volta para o primeiro. | [Listas](https://sitec-aramuni.vercel.app/pag8.html) |
| 🔗 [ListaDi](ListaDi) | A primeira lista encadeada completa: inserir no início, imprimir (recursivo), verificar se está vazia, procurar uma letra (recursivo, com a versão iterativa comentada), remover o primeiro, remover qualquer nó e liberar. | [Listas](https://sitec-aramuni.vercel.app/pag8.html) |
| ↔️ [ListaDupEnc](ListaDupEnc) | Lista em que cada nó aponta para o próximo **e** para o anterior (`prox` e `ant`). | [Listas](https://sitec-aramuni.vercel.app/pag8.html) |
| 🔄 [ListaDupEncCi](ListaDupEncCi) | Junta as duas ideias anteriores: cada nó tem `prox` e `ant`, e a lista é circular nos dois sentidos. | [Listas](https://sitec-aramuni.vercel.app/pag8.html) |
| 📚 [Pilha](Pilha) | Uma **pilha** construída sobre a lista encadeada, separada em `pilha.h` (estrutura e operações) e `Pilha.c` (o `main`). | [Pilhas](https://sitec-aramuni.vercel.app/pag11.html) |
| 📈 [polinomio](polinomio) | Representa um **polinômio** como uma lista circular em que cada nó é um termo (coeficiente e expoente). | [Polinômio](https://sitec-aramuni.vercel.app/pag2.html) |

## Jogos

| Projeto | O que faz | Site C |
| --- | --- | --- |
| ⭕ [ed1_velha](ed1_velha) | O jogo da velha do trabalho de ED1, com modo **Multiplayer** e modo **Single Player** contra o computador em três níveis: | [Jogo da Velha](https://sitec-aramuni.vercel.app/pag14.html) |

## 🙏 Créditos

- Exercícios e aulas: **Prof. Dr. Rafael Nunes Linhares Papa** ([Lattes](http://lattes.cnpq.br/7047033804750383)). As aulas em PDF estão em [`Site C/pdf`](https://github.com/joaopauloaramuni/c/tree/main/Site%20C/pdf).
- A **Calculadora de Limites** foi feita em grupo com Rafael Lott e Klelvin Carvalho.

## 📄 Licença

Todos os projetos estão licenciados sob a **MIT License**. Veja o arquivo [LICENSE](../LICENSE) na raiz do repositório.
