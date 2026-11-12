# Site C v1 (HTML + CSS + JavaScript) 💾

<img src="https://joaopauloaramuni.github.io/c-imgs/site_c_v1.png"/>

🔗 **Acesse:** https://sitec-v1.vercel.app/

## 📖 Descrição

O **Site C** é o site que criei em 2011, como aluno de **Ciência da Computação na Universidade FUMEC**, para organizar e compartilhar os códigos em C que escrevi nas disciplinas de **Estruturas de Dados I e II** do Prof. Dr. Rafael Nunes Linhares Papa.

Os exercícios e as aulas foram planejados pelo Prof. Rafael Nunes, e a publicação foi autorizada por ele.

Esta é a **versão 1**, de 2011, feita em HTML 4.01, CSS e JavaScript puros, sem *frameworks* e sem etapa de build. Os textos imitam comentários em C (`//Este site tem o objetivo de compartilhar códigos em C - ANSI Style.`), e o título da aba é **Programas em C - ANSI Style**.

A **versão 2**, reconstruída em React + Vite, reúne também os códigos que escrevi como professor em 2024: https://sitec-v2.vercel.app/

## ✨ Funcionalidades

- 📋 **Menu.c** lateral com 19 programas, cada um em uma página com o enunciado, imagens e o código-fonte.
- 📚 Seção **Material** com as aulas em PDF do Prof. Rafael Nunes.
- 🖼️ **Banner rotativo** no topo: três imagens que se alternam a cada 3 segundos (`banner_change`).
- 🔗 Ícones das redes sociais da época (LinkedIn, YouTube, Twitter, Facebook e Orkut) que mudam de imagem ao passar o mouse (`mouse_dentro` e `mouse_fora`), com pré-carregamento das imagens.
- 📬 Páginas **Contato** e **Agradecimentos**.

## 🗂️ Páginas

| Página | Conteúdo |
| --- | --- |
| `index.html` | Home: apresentação do site e da linguagem C |
| `pag1.html` | Torre de Hanói |
| `pag2.html` | Polinômio |
| `pag3.html` | Fatorial |
| `pag4.html` | Fibonacci |
| `pag5.html` | Josephus |
| `pag6.html` | Funções STR |
| `pag7.html` | Calculadoras |
| `pag8.html` | Listas |
| `pag9.html` | Árvores |
| `pag10.html` | Filas |
| `pag11.html` | Pilhas |
| `pag12.html` | Par ou Ímpar |
| `pag13.html` | Palíndromo |
| `pag14.html` | Jogo da Velha |
| `pag15.html` | Limites |
| `pag16.html` | Distância |
| `pag17.html` | Retângulo |
| `pag18.html` | Esfera |
| `pag19.html` | Otimizadas (funções recursivas em uma linha) |
| `pag20.html` | Material: aulas em PDF |
| `contato.html` | Contato |
| `agrad.html` | Agradecimentos |

Os códigos completos de cada programa estão na pasta [PROJETOS](https://github.com/joaopauloaramuni/c/tree/main/PROJETOS) deste repositório, cada um com o seu README.

## 🛠️ Tecnologias

- **HTML 4.01 Transitional**, com o layout montado em tabelas (`<TABLE>`), como era comum na época.
- **CSS** em um único arquivo (`css/style.css`), com a paleta cinza e azul: `#61849C`, `#96B0E5`, `#A0A0A0`, `#919191`, `#F0F0F0` e `#161616`.
- **JavaScript** puro (`js/efeitos.js`) para o banner rotativo e os ícones com efeito de *mouseover*.

## 🚀 Como rodar

Não há instalação nem build. Basta abrir o `index.html` no navegador.

Para servir a pasta localmente (recomendado, para os PDFs abrirem no navegador):

```bash
cd "Site C"
python3 -m http.server 8000
```

Abra http://localhost:8000/.

## 📂 Estrutura do Projeto

```text
📁 Site C
│
├── index.html                    └── Home
├── pag1.html ... pag19.html      └── Os 19 programas do Menu.c
├── pag20.html                    └── Material (aulas em PDF)
├── contato.html                  └── Contato
├── agrad.html                    └── Agradecimentos
│
├── 📁 css
│   └── style.css                 └── Estilos do site (paleta cinza e azul)
│
├── 📁 js
│   └── efeitos.js                └── Banner rotativo e efeitos de mouseover
│
├── 📁 img                        └── Banners, ícones das redes sociais e imagens dos enunciados
│
└── 📁 pdf                        └── 28 aulas em PDF do Prof. Rafael Nunes
```

## ☁️ Deploy na Vercel

1. Em [vercel.com/new](https://vercel.com/new), clique em **Import** no repositório `joaopauloaramuni/c`.
2. Em **Root Directory**, selecione a pasta `Site C`.
3. Em **Framework Preset**, escolha **Other** (o site é estático e não tem comando de build).
4. Em **Project Name**, use **`sitec-v1`**.
5. Clique em **Deploy**.

## 🔗 Urls do projeto

https://sitec-v1.vercel.app/ (v1, 2011)

https://sitec-v2.vercel.app/ (v2, React + Vite)

## 🙏 Créditos

- Exercícios e aulas: **Prof. Dr. Rafael Nunes Linhares Papa**: [Lattes](http://lattes.cnpq.br/7047033804750383) e [LinkedIn](https://www.linkedin.com/in/rafael-papa-4b16a510/).
- Última atualização do site: **03/09/2011**.

## 📄 Licença

Este projeto está licenciado sob a [MIT License](../LICENSE).
