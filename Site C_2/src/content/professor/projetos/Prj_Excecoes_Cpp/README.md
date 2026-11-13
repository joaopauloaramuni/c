# Projeto Prj_Excecoes_Cpp (C++) 🚨

> **C++: tratamento de exceções**. Tema: **C++ (bônus)**. Disciplina **Algoritmos e Estruturas de Dados I**, curso de Engenharia de Software da PUC Minas (1º semestre de 2024).

## 📖 Descrição

Mostra `try`, `throw` e `catch` em C++: antes de dividir por zero, o programa lança uma `std::runtime_error`, que é capturada e mostrada como erro.

## 🎯 Conceitos trabalhados

- `try` / `catch` / `throw`
- `std::runtime_error` de `<stdexcept>`
- Ordem dos `catch` (do mais específico ao mais genérico)
- `catch (...)`

## 🧠 Como funciona

```cpp
int main() {
    try {
        // Código que pode gerar exceções
        int divisor = 0;
        if (divisor == 0) {
            throw std::runtime_error("Divisão por zero não permitida");
        }
        // O código abaixo não será executado se a exceção ocorrer acima
        int resultado = 10 / divisor;
        std::cout << "Resultado: " << resultado << std::endl;
    } catch (const std::runtime_error &e) {
        // Captura e trata exceções do tipo std::runtime_error
        std::cerr << "Erro: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        // Captura e trata outras exceções derivadas de std::exception
        std::cerr << "Exceção: " << e.what() << std::endl;
    } catch (...) {
        // Captura qualquer outra exceção não tratada pelos blocos anteriores
        std::cerr << "Exceção desconhecida" << std::endl;
    }

    return 0;
}
```

Divisão inteira por zero em C/C++ não gera exceção: o programa simplesmente trava (no Linux, com *Floating point exception*). Por isso o código testa o divisor e lança a exceção ele mesmo. Os `catch` são testados na ordem: `runtime_error` primeiro, depois qualquer `std::exception` e, por fim, `...`, que captura qualquer coisa. A mensagem sai em `std::cerr`, a saída de erros.

## 💻 Exemplo de execução

```text
Erro: Divisão por zero não permitida
```

## 🚀 Como executar

### No Eclipse IDE for C/C++ Developers

1. **File → Import → General → Existing Projects into Workspace**.
2. Em **Select root directory**, escolha a pasta `Prj_Excecoes_Cpp` e clique em **Finish**.
3. Compile com **Project → Build Project** (Ctrl + B).
4. Rode com **Run → Run As → Local C/C++ Application** (Ctrl + F11). A saída aparece na aba **Console**.

### No terminal

Com o G++ instalado (no Windows, pelo [MinGW-w64](https://www.mingw-w64.org/downloads/)), dentro da pasta `Prj_Excecoes_Cpp`:

```bash
g++ src/Prj_Excecoes_Cpp.cpp -o Prj_Excecoes_Cpp
./Prj_Excecoes_Cpp
```

No Windows, rode `Prj_Excecoes_Cpp.exe` (ou `.\Prj_Excecoes_Cpp.exe` no PowerShell).

> Também dá para colar o código no [OnlineGDB](https://www.onlinegdb.com/) e rodar no navegador, escolhendo a linguagem **C++**.

## 📂 Estrutura do projeto

```text
📁 Prj_Excecoes_Cpp
│
├── 📁 src
│   └── Prj_Excecoes_Cpp.cpp
├── 📁 Debug                      └── Gerada pelo Eclipse ao compilar (makefile e executável)
├── .project / .cproject          └── Configuração do projeto no Eclipse CDT
├── 📁 .settings                  └── Preferências do Eclipse
└── README.md
```

## 🔗 Projetos relacionados

- [Prj_Calculadora_Ponteiros](../Prj_Calculadora_Ponteiros): Calculadora com ponteiros
- [Prj_ClasseAnimal_Cpp](../Prj_ClasseAnimal_Cpp): C++: polimorfismo com virtual

-----

Prof. Dr. João Paulo Aramuni · [Repositório da disciplina](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)
