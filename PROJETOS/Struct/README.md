# Projeto Struct (C, 2010–2011) 🏠

> **Struct cliente com endereço**. Código que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes. Grupo: **Structs**.

## 📖 Descrição

Define uma `struct endereco` e uma `struct cliente` que **contém** um endereço (struct aninhada), com apelidos criados por `typedef` (`TEnd` e `TCli`). O `main` preenche nome, telefone, rua e número e imprime.

## 🎯 Conceitos trabalhados

- `struct` e `typedef`
- Struct dentro de struct (`total.end.rua`)
- `strcpy` para campos de texto
- `long int` com `%ld`

## 📚 Entendendo o conceito

### Structs e typedef

Uma **struct** agrupa dados de tipos diferentes que pertencem à mesma coisa: um aluno tem nome (`char[]`), matrícula (`int`) e nota (`float`). Os campos são acessados com `.` (`aluno.nota`) ou, a partir de um ponteiro, com `->` (`p->nota`, que é o mesmo que `(*p).nota`).

Structs podem ser copiadas inteiras com `=`, passadas para funções e devolvidas por elas, e podem conter outras structs (um cliente tem um endereço). O `typedef` dá um nome curto ao tipo (`typedef struct aluno Aluno;`), dispensando escrever `struct` toda vez. Uma struct que contém um ponteiro para o próprio tipo (`struct no *prox;`) é a base de listas e árvores.

#### 🌍 Onde é usado na prática

- Registros de sistemas: cliente, produto, pedido. É o equivalente em C a uma classe só com atributos, ou a uma linha de tabela de banco de dados.
- APIs do sistema operacional usam structs para tudo: `struct tm` (data e hora), `struct stat` (informações de arquivo), `struct sockaddr` (endereços de rede).
- Formatos binários (cabeçalhos de imagens BMP, pacotes de rede) são lidos direto em structs.

#### 💼 Em processos seletivos

Structs aparecem como a forma de modelar o problema: ao implementar uma lista, uma fila ou um cadastro, a primeira coisa avaliada é a modelagem dos dados. Em vagas de C, perguntam sobre `.` × `->`, cópia de struct e **alinhamento** (por que `sizeof` de uma struct às vezes é maior que a soma dos campos).

Perguntas que costumam aparecer:

- Qual a diferença entre `.` e `->`?
- Passar uma struct por valor ou por ponteiro? Quando cada um?
- Por que `sizeof(struct)` pode ser maior que a soma dos campos?

#### 🐞 Erros comuns

- Usar `.` com ponteiro ou `->` com variável.
- Esquecer que copiar uma struct com um ponteiro dentro copia o endereço, não os dados apontados (cópia rasa).
- Escrever o nome do tipo errado no `typedef` (erro de compilação "unknown type name").

## 🧠 Como funciona o código

```c
int main() {
    setbuf(stdout,NULL);
    //tipo   variavel
    TClip total;

    strcpy(total.nome,"Joao");
    total.tel = 88888888;
    strcpy(total.end.rua,"Rua qualquer");
    total.end.numero = 100;

    printf("%s ",total.nome);
    printf("Tel: %ld\n",total.tel);
    printf("End: %s ",total.end.rua);
    printf("%d\n",total.end.numero);

    return 0;
}
```

O acesso encadeado `total.end.numero` lê o campo `numero` do campo `end` da variável `total`. Os `typedef` vêm **antes** das structs: o C permite dar apelido a um tipo que ainda vai ser definido.

## 💻 Exemplo de execução

> Saída depois de corrigir `TClip` para `TCli`.

```text
Joao Tel: 88888888
End: Rua qualquer 100
```

## ⚠️ Pontos de atenção

- **O arquivo não compila.** No `main` está `TClip total;` em vez de `TCli total;`, e o GCC acusa `unknown type name 'TClip'`. A saída abaixo é da versão corrigida.

## 🚀 Como executar

### No terminal (GCC)

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/), o mesmo compilador usado em 2011), dentro da pasta do projeto:

```bash
gcc src/Struct.c -o Struct
./Struct
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

- [Beecrowd 1048: Aumento de Salário (modele um funcionário como struct)](https://judge.beecrowd.com/pt/problems/view/1048)

## 📂 Estrutura do projeto

```text
📁 Struct
│
├── 📁 src
│   └── Struct.c
├── 📁 Debug                      └── Gerada pelo Eclipse em 2011 (arquivos objeto .o)
└── README.md
```

## 🔗 Projetos relacionados (2010–2011)

- [exerstruct](../exerstruct): Exercício: structs ligadas por ponteiro
- [exerstruct2](../exerstruct2): Exercício: cadastro com alocação dinâmica

## 🔁 O mesmo assunto em 2024

Em 2024, já como professor de Algoritmos e Estruturas de Dados I na PUC Minas, voltei a estes assuntos com novos projetos:

- [Prj_Struct_Livro](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i/tree/main/PROJETOS/Prj_Struct_Livro)

## 📚 Documentação e links úteis

**Sobre o assunto deste projeto**

- [cppreference: struct](https://en.cppreference.com/w/c/language/struct)
- [cppreference: typedef](https://en.cppreference.com/w/c/language/typedef)
- [cppreference: operador -> (acesso a membro)](https://en.cppreference.com/w/c/language/operator_member_access)

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
