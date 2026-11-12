# Projeto Prj_ClasseAnimal_Cpp (C++) 🐶

> **C++: polimorfismo com virtual**. Tema: **C++ (bônus)**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra **polimorfismo**: dois ponteiros do tipo `Animal*`, um apontando para um `Animal` e outro para um `Cachorro`. Por causa do `virtual`, cada um chama a sua própria versão de `emitirSom()`.

## 🎯 Conceitos trabalhados

- Método `virtual`
- Sobrescrita de método na classe filha
- Ponteiro da classe base apontando para objeto da filha
- `new`

## 🧠 Como funciona

```cpp
class Animal {
public:
    virtual void emitirSom() const {
        cout << "Animal emite um som" << endl;
    }
};
```

```cpp
class Cachorro : public Animal {
public:
    void emitirSom() const {
        cout << "Cachorro late" << endl;
    }
};
```

Sem o `virtual`, `a2->emitirSom()` olharia só o tipo do ponteiro (`Animal*`) e imprimiria "Animal emite um som" duas vezes. Com o `virtual`, a decisão é feita durante a execução, pelo tipo real do objeto.

## 💻 Exemplo de execução

```text
Animal emite um som
Cachorro late
```

## ⚠️ Pontos de atenção

- Os objetos criados com `new` nunca são liberados com `delete`. Em um programa que termina logo isso não causa problema, mas o certo é `delete a1; delete a2;` antes do `return`, e a classe base deveria ter um destrutor `virtual ~Animal() {}`.

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_ClasseAnimal_Cpp` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o G++ instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_ClasseAnimal_Cpp`:

```bash
g++ src/Prj_ClasseAnimal_Cpp.cpp -o Prj_ClasseAnimal_Cpp
./Prj_ClasseAnimal_Cpp
```

No Windows, rode `Prj_ClasseAnimal_Cpp.exe` (ou `.\Prj_ClasseAnimal_Cpp.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C++**.

## 📂 Estrutura do projeto

```text
📁 Prj_ClasseAnimal_Cpp
│
├── 📁 src
│   └── Prj_ClasseAnimal_Cpp.cpp
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_ClasseVeiculo_Cpp](../Prj_ClasseVeiculo_Cpp): C++: herança Veiculo → Carro
- [Prj_Excecoes_Cpp](../Prj_Excecoes_Cpp): C++: tratamento de exceções

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
