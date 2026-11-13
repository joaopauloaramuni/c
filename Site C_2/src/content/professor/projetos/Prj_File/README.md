# Projeto Prj_File (C) 📄

> **Arquivo texto: gravar e ler**. Tema: **Arquivos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Grava `Hello, World` no arquivo `exemplo.txt` e depois lê o arquivo linha por linha, mostrando o conteúdo.

## 🎯 Conceitos trabalhados

- `FILE *`, `fopen` e `fclose`
- Modos `"w"` (escrita) e `"r"` (leitura)
- `fprintf` e `fgets`
- Verificar se `fopen` devolveu `NULL`

## 🧠 Como funciona

```c
int main(void) {
    // Abre o arquivo para escrita
    FILE *arquivo = fopen("exemplo.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso para escrita
    if (arquivo != NULL) {
        // Escreve o texto no arquivo
        fprintf(arquivo, "Hello, World\n");

        // Fecha o arquivo de escrita
        fclose(arquivo);
        printf("Texto gravado com sucesso.\n");
    } else {
        // Se houver erro na abertura do arquivo para escrita
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1; // Retorna um código de erro
    }

    // Abre o arquivo para leitura
    arquivo = fopen("exemplo.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso para leitura
    if (arquivo != NULL) {
        char linha[100]; // Define um buffer para armazenar a linha lida

        // Lê e imprime cada linha do arquivo
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            printf("Conteúdo lido do arquivo: %s", linha);
        }

        // Fecha o arquivo de leitura
        fclose(arquivo);
    } else {
        // Se houver erro na abertura do arquivo para leitura
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1; // Retorna um código de erro
    }

    return 0;
}
```

O modo `"w"` cria o arquivo ou **apaga** o conteúdo se ele já existir; para acrescentar no final, use `"a"`. O arquivo é criado na pasta de onde o programa roda: no Eclipse, a raiz do projeto, por isso o `exemplo.txt` está ao lado da pasta `src`.

## 💻 Exemplo de execução

```text
Texto gravado com sucesso.
Conteúdo lido do arquivo: Hello, World
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_File` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_File`:

```bash
gcc src/Prj_File.c -o Prj_File
./Prj_File
```

No Windows, rode `Prj_File.exe` (ou `.\Prj_File.exe` no PowerShell).

> 📂 Rode o programa de dentro da pasta do projeto: o arquivo é criado na pasta atual do terminal.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_File
│
├── 📁 src
│   └── Prj_File.c
├── exemplo.txt                   └── Arquivo gerado pelo programa ao rodar
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_File_Struct](../Prj_File_Struct): Arquivo binário com struct
- [Prj_Pali+File](../Prj_Pali+File): Palíndromos gravados em arquivo

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
