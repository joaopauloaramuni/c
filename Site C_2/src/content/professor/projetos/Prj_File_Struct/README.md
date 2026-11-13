# Projeto Prj_File_Struct (C) 💾

> **Arquivo binário com struct**. Tema: **Arquivos**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Grava uma struct inteira em um **arquivo binário** (`exemplo_struct.bin`) com `fwrite` e lê de volta com `fread`.

## 🎯 Conceitos trabalhados

- Modos binários `"wb"` e `"rb"`
- `fwrite` e `fread`
- `sizeof(struct ...)`

## 🧠 Como funciona

```c
int main(void) {
    // Abre o arquivo para escrita binária
    FILE *arquivo = fopen("exemplo_struct.bin", "wb");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo != NULL) {
        // Cria uma instância da estrutura
        struct ExemploStruct dadosParaGravar = { 13, 3.14,
                "Estrutura de exemplo" };

        // Escreve a estrutura no arquivo
        fwrite(&dadosParaGravar, sizeof(struct ExemploStruct), 1, arquivo);

        // Fecha o arquivo
        fclose(arquivo);
        printf("Estrutura gravada com sucesso.\n");
    } else {
        // Se houver erro na abertura do arquivo
        printf("Erro ao abrir o arquivo para escrita.\n");
    }

    // Abre o arquivo para leitura binária
    FILE *arquivoLeitura = fopen("exemplo_struct.bin", "rb");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivoLeitura != NULL) {
        // Cria uma instância da estrutura para armazenar os dados lidos
        struct ExemploStruct dadosLidos;

        // Lê a estrutura do arquivo
        fread(&dadosLidos, sizeof(struct ExemploStruct), 1, arquivoLeitura);

        // Fecha o arquivo de leitura
        fclose(arquivoLeitura);

        // Exibe os dados lidos
        printf("Dados lidos da estrutura: Numero: %d, Decimal: %.2f, Texto: %s\n",
                dadosLidos.numero, dadosLidos.decimal, dadosLidos.texto);
    } else {
        // Se houver erro na abertura do arquivo de leitura
        printf("Erro ao abrir o arquivo para leitura.\n");
    }

    return 0;
}
```

Em vez de transformar cada campo em texto, o `fwrite` copia os bytes da struct direto para o disco. Por isso o `.bin` não é legível em um editor de texto. O arquivo depende da máquina (tamanho dos tipos, alinhamento, *endianness*): um `.bin` gravado em um computador pode não ser lido corretamente em outro.

## 💻 Exemplo de execução

```text
Estrutura gravada com sucesso.
Dados lidos da estrutura: Numero: 13, Decimal: 3.14, Texto: Estrutura de exemplo
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_File_Struct` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o GCC instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_File_Struct`:

```bash
gcc src/Prj_File_Struct.c -o Prj_File_Struct
./Prj_File_Struct
```

No Windows, rode `Prj_File_Struct.exe` (ou `.\Prj_File_Struct.exe` no PowerShell).

> 📂 Rode o programa de dentro da pasta do projeto: o arquivo é criado na pasta atual do terminal.

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C**.

## 📂 Estrutura do projeto

```text
📁 Prj_File_Struct
│
├── 📁 src
│   └── Prj_File_Struct.c
├── exemplo_struct.bin            └── Arquivo binário gerado pelo programa ao rodar
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_File](../Prj_File): Arquivo texto: gravar e ler
- [Prj_Struct_Livro](../Prj_Struct_Livro): Struct Livro

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
