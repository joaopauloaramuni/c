# Projeto Prj_ClasseCarro_Cpp (C++) 🚗

> **C++: classe Carro**. Tema: **C++ (bônus)**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Primeiro contato com **orientação a objetos em C++**: a classe `Carro` com atributos (marca, modelo, ano), dois construtores e o método `exibirInformacoes`.

## 🎯 Conceitos trabalhados

- `class` e `public`
- Construtor com lista de inicialização
- Sobrecarga de construtores
- `std::string` e `std::cout`

## 🧠 Como funciona

```cpp
// Definição da classe Carro
class Carro {
public:
    // Membros da classe
    std::string marca;
    std::string modelo;
    int ano;

    // Construtor
    Carro(const std::string &m, const std::string &mod, int a) :
            marca(m), modelo(mod), ano(a) {
    }

    // Construtor para criar um carro vazio
    Carro() : marca(""), modelo(""), ano(0) {
    }

    // Método para exibir informações sobre o carro
    void exibirInformacoes() {
        std::cout << "Marca: " << marca << ", Modelo: " << modelo << ", Ano: "
                << ano << std::endl;
    }
};
```

É o passo seguinte às structs: além dos dados, a classe junta as **funções** que trabalham com eles (métodos). C++ aceita dois construtores com o mesmo nome porque tem sobrecarga, o que C não permite (veja o [Prj_Calculadora_Ponteiros](../Prj_Calculadora_Ponteiros)). A linha comentada `//Carro meuCarro("Toyota", "Corolla", 2022);` cria o carro já preenchido com o outro construtor.

## 💻 Exemplo de execução

```text
Marca: Toyota, Modelo: Corolla, Ano: 2022
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ClasseCarro_Cpp` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o G++ instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ClasseCarro_Cpp`:

```bash
g++ src/Prj_ClasseCarro_Cpp.cpp -o Prj_ClasseCarro_Cpp
./Prj_ClasseCarro_Cpp
```

No Windows, rode `Prj_ClasseCarro_Cpp.exe` (ou `.\Prj_ClasseCarro_Cpp.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C++**.

## 📂 Estrutura do projeto

```text
📁 Prj_ClasseCarro_Cpp
│
├── 📁 src
│   └── Prj_ClasseCarro_Cpp.cpp
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_ClasseVeiculo_Cpp](../Prj_ClasseVeiculo_Cpp): C++: herança Veiculo → Carro
- [Prj_Struct_Livro](../Prj_Struct_Livro): Struct Livro

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
