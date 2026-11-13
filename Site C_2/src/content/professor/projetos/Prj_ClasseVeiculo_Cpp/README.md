# Projeto Prj_ClasseVeiculo_Cpp (C++) 🚙

> **C++: herança Veiculo → Carro**. Tema: **C++ (bônus)**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra **herança** em C++: `Carro` herda de `Veiculo` e reaproveita o construtor e o método `exibirInformacoes` da classe base. Também mostra os três níveis de acesso: `private`, `protected` e `public`.

## 🎯 Conceitos trabalhados

- Herança pública (`class Carro : public Veiculo`)
- Chamada do construtor da classe base
- Modificadores `private`, `protected` e `public`

## 🧠 Como funciona

```cpp
// Classe derivada: Carro (herda de Veiculo)
class Carro: public Veiculo {
private:
    std::string marca;

public:
    Carro(const std::string &m, const std::string &mod, int a) :
            Veiculo(mod, a), marca(m) {
    }

    void exibirDetalhes() {
        std::cout << "Marca: " << marca << ", ";
        exibirInformacoes();  // Chama o método da classe base
    }
};
```

| Membro | Acesso | Quem enxerga |
| --- | --- | --- |
| `modelo` | `private` | Só a própria classe `Veiculo` |
| `ano` | `protected` | `Veiculo` e as classes filhas, como `Carro` |
| `exibirInformacoes()` | `public` | Qualquer código |

Dentro de `Carro`, `exibirDetalhes()` não consegue ler `modelo` diretamente, mas chama `exibirInformacoes()`, que pode.

## 💻 Exemplo de execução

```text
Marca: Toyota, Modelo: Corolla, Ano: 2022
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ClasseVeiculo_Cpp` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o G++ instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ClasseVeiculo_Cpp`:

```bash
g++ src/Prj_ClasseVeiculo_Cpp.cpp -o Prj_ClasseVeiculo_Cpp
./Prj_ClasseVeiculo_Cpp
```

No Windows, rode `Prj_ClasseVeiculo_Cpp.exe` (ou `.\Prj_ClasseVeiculo_Cpp.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C++**.

## 📂 Estrutura do projeto

```text
📁 Prj_ClasseVeiculo_Cpp
│
├── 📁 src
│   └── Prj_ClasseVeiculo_Cpp.cpp
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_ClasseCarro_Cpp](../Prj_ClasseCarro_Cpp): C++: classe Carro
- [Prj_ClasseAnimal_Cpp](../Prj_ClasseAnimal_Cpp): C++: polimorfismo com virtual

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
