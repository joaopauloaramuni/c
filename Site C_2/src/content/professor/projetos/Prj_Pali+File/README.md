# Projeto Prj_Pali+File (C) 🗂️

> **Palíndromos gravados em arquivo**. Tema: **Arquivos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Junta dois assuntos: verifica palavras com a função recursiva de palíndromo e grava o resultado de cada uma em `exemplo.txt`. No final, lê o arquivo e mostra tudo.

## 🎯 Conceitos trabalhados

- Função recursiva de palíndromo
- `sprintf` para montar uma frase
- Gravação em arquivo dentro de um laço

## 🧠 Como funciona

```c
int isPalindrome(char str[], int left, int right) {
    return (left >= right) ?
            1 :
            (str[left] == str[right]) && isPalindrome(str, left + 1, right - 1);
}
```

O `sprintf` funciona como um `printf`, mas escreve em uma string (`resultado`) em vez de na tela; a string é então gravada no arquivo. O `exemplo.txt` que acompanha o projeto tem o resultado de uma execução com ARARA, OVO e OTTO.

## 💻 Exemplo de execução

```text
Digite uma palavra: ARARA
Deseja continuar? sim=1, sair=0: 1
Digite uma palavra: OVO
Deseja continuar? sim=1, sair=0: 1
Digite uma palavra: CASA
Deseja continuar? sim=1, sair=0: 0
Texto gravado com sucesso.
A palavra ARARA é um palíndromo.
A palavra OVO é um palíndromo.
A palavra CASA não é um palíndromo.
```

## ⚠️ Pontos de atenção

- `fprintf(arquivo, resultado)` usa o texto lido como **formato**. Se a palavra tiver um `%`, o `fprintf` vai tentar interpretá-lo. O seguro é `fprintf(arquivo, "%s", resultado)` ou `fputs(resultado, arquivo)`.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Pali+File` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Pali+File`:

```bash
gcc src/Prj_Pali+File.c -o Prj_Pali_File
./Prj_Pali_File
```

No Windows, rode `Prj_Pali_File.exe` (ou `.\Prj_Pali_File.exe` no PowerShell).

> 📂 Rode o programa de dentro da pasta do projeto: o arquivo é criado na pasta atual do terminal.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_Pali+File
│
├── 📁 src
│   └── Prj_Pali+File.c
├── exemplo.txt                   └── Arquivo gerado pelo programa ao rodar
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Palindromo_Recursivo](../Prj_Palindromo_Recursivo): Palíndromo recursivo
- [Prj_File](../Prj_File): Arquivo texto: gravar e ler

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
