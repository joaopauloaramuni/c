// Dados gerais do site: autor, links e chave do tema.
export const THEME_KEY = "sitec:theme";

export const AUTOR = {
  nome: "João Paulo Aramuni",
  titulo: "Prof. Dr. João Paulo Aramuni",
  email: "joaopauloaramuni@gmail.com",
  github: "https://github.com/joaopauloaramuni",
};

export const LINKS = {
  repoAluno: "https://github.com/joaopauloaramuni/c",
  repoProfessor: "https://github.com/joaopauloaramuni/algoritmos-e-estruturas-de-dados-i",
  siteAntigo: "https://sitec-v1.vercel.app/",
  rafaelLattes: "http://lattes.cnpq.br/7047033804750383",
  rafaelLinkedin: "https://www.linkedin.com/in/rafael-papa-4b16a510/",
};

// Cada item do menu aparece como uma aba de editor, com o "arquivo" correspondente
export const NAV = [
  { to: "/", rotulo: "Início", arquivo: "main.c", fim: true },
  { to: "/aluno", rotulo: "Aluno", arquivo: "aluno_2011.c" },
  { to: "/professor", rotulo: "Professor", arquivo: "professor_2024.c" },
  { to: "/artigos", rotulo: "Artigos", arquivo: "artigos.h" },
  { to: "/nostalgia", rotulo: "Nostalgia", arquivo: "2011.html" },
];
