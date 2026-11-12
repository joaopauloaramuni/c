# Projeto Site C 2.0 (React + Vite) 💾

## 📖 Descrição

O **Site C** nasceu em 2011, em HTML, CSS e JavaScript puros, para organizar os códigos em C que escrevi como aluno de **Ciência da Computação na Universidade FUMEC**, nas disciplinas de **Estruturas de Dados I e II** do Prof. Rafael Nunes.

Esta é a **versão 2.0**, reconstruída em **React + Vite**. Ela junta, em um único site e separados por época:

- **Aluno (2010–2011):** os 19 programas comentados do site original, os 62 códigos-fonte do repositório de 2011 e as 28 aulas em PDF do Prof. Rafael Nunes.
- **Professor (1º semestre de 2024):** as aulas, as tarefas e os 87 projetos da disciplina **Algoritmos e Estruturas de Dados I**, do curso de **Engenharia de Software da PUC Minas**, cada um com README próprio.
- **Artigos:** 10 artigos clássicos da computação (Turing, Shannon, von Neumann, Cook, Hoare, Sedgewick e Martin).

Tudo é lido **dentro do site**: os PDFs abrem em um leitor próprio (pdf.js), os READMEs são renderizados a partir do Markdown e os códigos aparecem com destaque de sintaxe. Ninguém precisa ir ao GitHub para estudar.

O visual é uma evolução do site de 2011, pensado como uma **IDE do Site C**: tudo em **JetBrains Mono**, o menu como abas de editor, o rodapé como a barra de status (no aço `#61849C` de 2011), os títulos de seção como comentários `//` (os textos de 2011 já eram escritos assim) e os painéis como arquivos abertos, com nome na aba e números de linha. O azul `#96B0E5` daquela época é a cor de destaque, com tema claro e escuro. A página inicial tem uma ilustração do laboratório de informática, desenhada a partir das fotos do laboratório, só com bancadas, monitores, cadeiras e móveis, **sem nenhuma pessoa**.

A primeira versão continua no ar em https://sitec-aramuni.vercel.app/ e aparece aqui na página **Nostalgia**.

## ✨ Funcionalidades

- 🏫 **Página inicial** com a ilustração do laboratório ao fundo e as duas épocas lado a lado.
- 🗂️ **Menu.c de 2011**: os 19 programas do site original, com enunciados, imagens e códigos reindentados (o HTML de 2011 tinha perdido a indentação).
- 📜 **Códigos-fonte de 2010–2011** com busca, lidos direto no navegador.
- 📚 **Projetos de 2024** com busca (atalho **Ctrl+K**), filtro por tema (13 temas, na ordem das aulas) e navegação anterior/próximo.
- 📝 **README de cada projeto** renderizado no site, com um **explorador de arquivos** de IDE para abrir os `.c`/`.cpp` e o `exemplo.txt`. Os links entre projetos e para os enunciados das tarefas abrem dentro do próprio site.
- 📄 **Leitor de PDF** com troca de página pelas setas do teclado, zoom, tela cheia, abrir em outra aba e download. Os slides abrem com a página inteira à vista, e os artigos na largura de leitura. A página atual fica na URL (`?p=12`), para compartilhar.
- 🧾 **Tarefas** ligadas aos projetos que as resolvem.
- 🕰️ **Nostalgia**: a captura do site de 2011, os três banners originais, a paleta, um trecho do `style.css` antigo, os agradecimentos e o rodapé com o Orkut.
- 🌗 **Tema claro e escuro**, que segue o sistema na primeira visita e fica salvo no navegador.
- 📱 **Responsivo**, com menu de celular.
- ♿ Link para pular ao conteúdo, foco visível, `aria-*` nos controles e respeito a `prefers-reduced-motion`.

## 🖼️ Capturas de Tela

| Home | Home - Tema escuro |
| :---: | :---: |
| ![Home](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Home.png) | ![HomeDark](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/HomeDark.png) |

| Aluno 2011 | Programa de 2011 (Menu.c) |
| :---: | :---: |
| ![Aluno](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Aluno.png) | ![AlunoPrograma](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/AlunoPrograma.png) |

| Códigos-fonte de 2011 | Aulas do Prof. Rafael Nunes |
| :---: | :---: |
| ![AlunoCodigos](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/AlunoCodigos.png) | ![AlunoAulas](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/AlunoAulas.png) |

| Professor 2024 | Aulas de 2024 |
| :---: | :---: |
| ![Professor](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Professor.png) | ![Aulas](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Aulas.png) |

| Projetos | Projetos - Filtro por tema (escuro) |
| :---: | :---: |
| ![Projetos](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Projetos.png) | ![ProjetosFiltro](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/ProjetosFiltro.png) |

| Projeto - README | Projeto - Código (escuro) |
| :---: | :---: |
| ![ProjetoReadme](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/ProjetoReadme.png) | ![ProjetoCodigo](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/ProjetoCodigo.png) |

| Tarefas | Leitor de PDF - Aula |
| :---: | :---: |
| ![Tarefas](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Tarefas.png) | ![LeitorAula](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/LeitorAula.png) |

| Artigos | Leitor de PDF - Artigo (escuro) |
| :---: | :---: |
| ![Artigos](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Artigos.png) | ![LeitorArtigo](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/LeitorArtigo.png) |

| Nostalgia | Página não encontrada |
| :---: | :---: |
| ![Nostalgia](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Nostalgia.png) | ![NotFound](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/NotFound.png) |

| Mobile | Mobile - Projeto (escuro) | Mobile - Leitor de PDF |
| :---: | :---: | :---: |
| ![Mobile](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/Mobile.png) | ![MobileDark](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/MobileDark.png) | ![MobileLeitor](https://joaopauloaramuni.github.io/react-imgs/SiteC/imgs/MobileLeitor.png) |

## 🚀 Como rodar

```bash
npm install
npm run dev
```

Abra http://localhost:5173/.

Não há chave de API nem variável de ambiente: o site é 100% estático.

## 🗺️ Rotas

| Rota | Página |
| --- | --- |
| `/` | Início |
| `/aluno` | Aluno 2011: o texto original e o Menu.c com os 19 programas |
| `/aluno/programas/:slug` | Um programa de 2011 (ex.: `/aluno/programas/torre-de-hanoi`) |
| `/aluno/codigos` e `/aluno/codigos/:slug` | Códigos-fonte de 2010–2011 |
| `/aluno/aulas` | Aulas em PDF do Prof. Rafael Nunes |
| `/professor` | Professor 2024: atalhos e o caminho da disciplina por tema |
| `/professor/aulas` | Aulas de 2024 |
| `/professor/tarefas` | Tarefas, com link para as resoluções |
| `/professor/projetos` | Lista dos 87 projetos (`?tema=Recursão&q=ponteiro`) |
| `/professor/projetos/:slug` | README e arquivos de um projeto (`?arquivo=src/Prj_X.c`) |
| `/artigos` | Artigos sugeridos |
| `/ler/:colecao/:id` | Leitor de PDF (`aulas`, `tarefas`, `artigos` ou `aulas-2011`; `?p=` para a página) |
| `/nostalgia` | Como era o site de 2011 |

## 🧠 Como funciona

### Conteúdo

Todo o conteúdo fica em arquivos, sem banco de dados nem back-end:

- **JSON** em `src/content/` descreve as aulas, os artigos, os projetos e as páginas de 2011 (título, descrição, número de páginas, tamanho).
- Os **READMEs e códigos** dos projetos ficam em `src/content/professor/projetos/<Projeto>/`, iguais aos do repositório da disciplina.
- O `src/data/conteudo.js` carrega esses arquivos com `import.meta.glob(..., { query: "?raw" })`. Cada README e cada código vira um pedacinho separado do bundle, baixado só quando a página do projeto é aberta.
- Os **PDFs** e as imagens de 2011 ficam em `public/` e são servidos como arquivos estáticos.

### Leitor de PDF

O leitor usa o [react-pdf](https://github.com/wojtekmaj/react-pdf), que usa o [pdf.js](https://mozilla.github.io/pdf.js/) da Mozilla. Ele renderiza uma página por vez, então até a Aula 01 (140 páginas, 14 MB) abre rápido.

Os artigos antigos são **escaneados** e usam imagens JBIG2, que o pdf.js só decodifica com o `jbig2.wasm`. Por isso o `vite.config.js` tem um pequeno plugin (`pdfjs-assets`) que serve as pastas `wasm`, `cmaps`, `standard_fonts` e `iccs` do `pdfjs-dist` em `/pdfjs/` durante o desenvolvimento e as copia para `dist/pdfjs/` no build, sempre na mesma versão usada pelo react-pdf. Sem isso, as páginas escaneadas apareceriam em branco.

As páginas do leitor e dos projetos (que carregam o pdf.js e o renderizador de Markdown) são carregadas com `React.lazy`, então a página inicial não baixa esse código.

### READMEs dentro do site

Os READMEs foram escritos para o GitHub, com links como `../Prj_Soma_Recursiva` e links para os PDFs das tarefas no repositório. O componente `Markdown` reescreve esses links para as rotas do próprio site (`/professor/projetos/Prj_Soma_Recursiva` e `/ler/tarefas/tarefa-2`). Links externos abrem em outra aba.

### A ilustração do laboratório

O `src/assets/laboratorio.svg` foi gerado em perspectiva de um ponto a partir das fotos do laboratório: teto com luminárias e ar-condicionado, quadro com projeção na parede da esquerda, janelas, persianas ao fundo, seis fileiras de bancadas com monitores, gabinetes, teclados e cadeiras vazias. Ele é inserido inline (`?raw`) e as cores vêm de variáveis CSS (`--lab-*`), por isso muda junto com o tema claro/escuro.

### Design system

O site inteiro usa a [JetBrains Mono](https://www.jetbrains.com/lp/mono/) (versão variável, pesos 100 a 800, com ligaduras), servida pelo próprio site via Fontsource. Para trocar só o texto corrido (READMEs e textos de 2011) por uma fonte sem serifa, basta mudar a variável `--font-prose` em `src/index.css`.

Os elementos se repetem em todo o site:

| Elemento | Onde aparece |
| --- | --- |
| Abas de editor com nome de arquivo (`aluno_2011.c`, `professor_2024.c`...) | Menu do topo |
| Barra de status no aço `#61849C` de 2011 (branch, arquivo aberto, `C (ANSI)`, tema) | Rodapé |
| Comentário `//` antes dos títulos de seção e `/* ano */` acima do título da página | Todas as páginas |
| Caminho `~/` na trilha de navegação | Páginas internas |
| Painel com aba de arquivo e números de linha na calha | Home, listas de PDFs, artigos, códigos |
| Explorador de arquivos | Página de cada projeto |
| Cores de sintaxe na interface: números em laranja, comentários em cinza itálico | Contadores, anos, títulos |

O menu lateral cinza com a borda azul de 10px foi mantido como era em 2011 nas páginas da seção Aluno.

### Tema

O `index.html` aplica `data-theme` no `<html>` **antes** do React carregar (lendo `localStorage` ou `prefers-color-scheme`), para a página não piscar. Todas as cores são variáveis em `src/index.css`. Os blocos de código são sempre escuros, como um terminal.

## 📂 Estrutura do Projeto

```text
📁 SiteC
│
├── 📁 imgs                              └── Capturas de tela usadas neste README
├── 📁 public
│   ├── favicon.svg                      └── O "C" com a borda azul de 2011
│   ├── 📁 img
│   │   ├── site-c-2011.png              └── Captura do site original
│   │   └── 📁 2011                      └── Imagens do site original (banners, Torre de Hanói, ícones...)
│   └── 📁 pdf
│       ├── 📁 professor                 └── Apresentação e Aulas 01 a 05 (2024)
│       ├── 📁 tarefas                   └── Tarefas 1 a 4 e Exercício de Revisão
│       ├── 📁 artigos                   └── 10 artigos clássicos
│       └── 📁 aluno                     └── 28 aulas do Prof. Rafael Nunes (2010–2011)
│
├── 📁 src
│   ├── 📁 assets
│   │   └── laboratorio.svg              └── Ilustração do laboratório (bancadas, cadeiras, sem pessoas)
│   │
│   ├── 📁 components
│   │   ├── 📁 CodeBlock                 └── Código com destaque (highlight.js), numeração e copiar
│   │   ├── 📁 DocList                   └── Lista de PDFs com "Ler" e "Baixar"
│   │   ├── 📁 LabScene                  └── Insere o laboratorio.svg inline
│   │   ├── 📁 Layout                    └── Topo com abas de editor, menu do celular, rodapé com barra de status
│   │   ├── 📁 Markdown                  └── README com GFM, destaque e links reescritos
│   │   ├── 📁 PageTitle                 └── Título da página com o período em /* comentário */
│   │   ├── 📁 PdfViewer                 └── Leitor de PDF (react-pdf)
│   │   └── 📁 ThemeToggle               └── Botão claro/escuro
│   │
│   ├── ⚙️ config
│   │   └── site.js                      └── Autor, links e itens do menu
│   │
│   ├── 📁 content
│   │   ├── artigos.json
│   │   ├── 📁 aluno
│   │   │   ├── paginas.json             └── Os 19 programas do site de 2011
│   │   │   ├── aulas.json               └── As 28 aulas do Prof. Rafael Nunes
│   │   │   ├── codigos.json             └── Índice dos 62 projetos de 2011
│   │   │   └── 📁 codigos               └── Os códigos de 2011 (.c/.h salvos como .txt)
│   │   └── 📁 professor
│   │       ├── material.json            └── Aulas e tarefas de 2024
│   │       ├── projetos.json            └── Índice dos 87 projetos (tema, emoji, resumo)
│   │       └── 📁 projetos              └── README.md, src/*.c|*.cpp e exemplo.txt de cada projeto
│   │
│   ├── 📁 data
│   │   └── conteudo.js                  └── Carrega os JSON e os arquivos sob demanda
│   │
│   ├── 🪝 hooks
│   │   └── useTheme.js
│   │
│   ├── 📁 pages
│   │   ├── 📁 Home
│   │   ├── 📁 Aluno                     └── Aluno, AlunoPrograma, AlunoCodigos, AlunoAulas
│   │   ├── 📁 Professor                 └── Professor, ProfessorAulas, ProfessorTarefas
│   │   ├── 📁 Projetos                  └── Projetos (lista) e Projeto (explorador + README + arquivos)
│   │   ├── 📁 Artigos
│   │   ├── 📁 Leitor                    └── Página do leitor de PDF
│   │   ├── 📁 Nostalgia
│   │   ├── NaoEncontrada.jsx            └── 404 (com um printf, claro)
│   │   └── pages.css                    └── Estilos compartilhados
│   │
│   ├── 📁 styles
│   │   └── lab.css                      └── Cores da ilustração do laboratório
│   │
│   ├── 🛠️ utils
│   │   └── storage.js                   └── localStorage com try/catch
│   │
│   ├── App.jsx                          └── Rotas (React Router) e páginas lazy
│   ├── index.css                        └── Design system: tokens de cor, JetBrains Mono, painéis, botões
│   └── main.jsx
│
├── .oxlintrc.json
├── index.html                           └── Aplica o tema antes do React carregar
├── package.json
├── vercel.json                          └── Reescreve as rotas do React Router para o index.html
└── vite.config.js                       └── Plugin que publica os arquivos auxiliares do pdf.js
```

## ➕ Adicionando conteúdo

- **Novo projeto:** crie `src/content/professor/projetos/<Prj_Nome>/` com `README.md` e `src/*.c`, e adicione o projeto em `src/content/professor/projetos.json` (`slug`, `titulo`, `emoji`, `tema`, `linguagem`, `resumo`, `arquivos`). O tema precisa estar na lista `temas` do mesmo arquivo.
- **Nova aula ou tarefa:** coloque o PDF em `public/pdf/professor/` (ou `tarefas/`) e adicione um item em `src/content/professor/material.json` com `id`, `titulo`, `descricao`, `arquivo`, `paginas` e `mb`.
- **Novo artigo:** PDF em `public/pdf/artigos/` e um item em `src/content/artigos.json` (com `autor`, `ano` e `grupo`).

## ☁️ Deploy na Vercel

1. Suba o projeto para um repositório no GitHub.
2. Em [vercel.com/new](https://vercel.com/new), clique em **Import** no repositório (preset **Vite**).
3. Em **Project Name**, use **`sitec-v2`** (ou outro nome livre).
4. Clique em **Deploy**.

O `vercel.json` manda todas as rotas do React Router para o `index.html`, exceto `/pdf/`, `/pdfjs/`, `/img/` e `/assets/`. Assim, abrir direto `/professor/projetos/Prj_Smith` ou recarregar a página funciona.

> Os PDFs somam cerca de 112 MB. A Vercel e o GitHub aceitam bem esse tamanho (o maior arquivo tem 14 MB, abaixo do limite de 100 MB por arquivo do GitHub).

## 📦 Dependências

```json
"dependencies": {
  "@fontsource-variable/jetbrains-mono": "^5.3.0",
  "highlight.js": "^11.12.0",
  "react": "^19.3.1",
  "react-dom": "^19.3.1",
  "react-icons": "^5.7.0",
  "react-markdown": "^10.1.0",
  "react-pdf": "^11.0.0",
  "react-router-dom": "^7.18.5",
  "rehype-highlight": "^7.0.2",
  "remark-gfm": "^4.0.1"
}
```

- [`react-router-dom`](https://reactrouter.com/): rotas.
- [`react-pdf`](https://github.com/wojtekmaj/react-pdf): leitor de PDF (pdf.js).
- [`react-markdown`](https://github.com/remarkjs/react-markdown) + [`remark-gfm`](https://github.com/remarkjs/remark-gfm): os READMEs, com tabelas do GitHub.
- [`highlight.js`](https://highlightjs.org/) + [`rehype-highlight`](https://github.com/rehypejs/rehype-highlight): destaque de C e C++ (só as linguagens usadas são registradas).
- [`@fontsource-variable/jetbrains-mono`](https://fontsource.org/fonts/jetbrains-mono): JetBrains Mono servida pelo próprio site, sem Google Fonts.
- [`react-icons`](https://react-icons.github.io/react-icons/): ícones do [Feather](https://feathericons.com/) (`react-icons/fi`).

## 🧪 Scripts

| Comando | O que faz |
| --- | --- |
| `npm run dev` | Servidor de desenvolvimento |
| `npm run build` | Build de produção em `dist/` |
| `npm run preview` | Testa o build localmente |
| `npm run lint` | Lint com o oxlint (padrão do template atual do Vite) |

## 🔗 Urls do projeto

http://localhost:5173/

https://sitec-aramuni.vercel.app/ (versão de 2011)

## 📚 Documentação e Links Úteis

**Repositórios**

- [Site C de 2011 e os códigos de aluno](https://github.com/joaopauloaramuni/c)
- [Algoritmos e Estruturas de Dados I (PUC Minas, 2024)](https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i)

**React, Vite e bibliotecas**

- [Documentação do React](https://react.dev/)
- [Documentação do Vite](https://vite.dev/)
- [Glob import no Vite](https://vite.dev/guide/features#glob-import)
- [React Router](https://reactrouter.com/)
- [react-pdf](https://github.com/wojtekmaj/react-pdf)
- [pdf.js](https://mozilla.github.io/pdf.js/)
- [JetBrains Mono](https://www.jetbrains.com/lp/mono/)
- [Vite na Vercel](https://vercel.com/docs/frameworks/frontend/vite)

**C**

- [Eclipse IDE for C/C++ Developers](https://www.eclipse.org/downloads/packages/)
- [MinGW-w64 (GCC no Windows)](https://www.mingw-w64.org/downloads/)
- [OnlineGDB](https://www.onlinegdb.com/)
- [cppreference: linguagem C](https://en.cppreference.com/w/c)

## 🙏 Créditos

- Exercícios e aulas de 2010–2011: **Prof. Dr. Rafael Nunes Linhares Papa** ([Lattes](http://lattes.cnpq.br/7047033804750383)), com publicação autorizada.
- Artigos: dos respectivos autores e editoras, disponibilizados para fins de estudo.

## 📄 Licença
Este projeto está licenciado sob a MIT License.
