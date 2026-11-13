// Ponto único de acesso ao conteúdo do site (JSON + arquivos .c/.md carregados sob demanda).
import material from "../content/professor/material.json";
import projetosIndex from "../content/professor/projetos.json";
import artigos from "../content/artigos.json";
import paginasAluno from "../content/aluno/paginas.json";
import aulasAluno from "../content/aluno/aulas.json";
import codigosAluno from "../content/aluno/codigos.json";

export const AULAS = material.aulas;
export const TAREFAS = material.tarefas;
export const TEMAS = projetosIndex.temas;
export const PROJETOS = [...projetosIndex.projetos].sort(
  (a, b) => TEMAS.indexOf(a.tema) - TEMAS.indexOf(b.tema) || a.slug.localeCompare(b.slug),
);
export const ARTIGOS = artigos;
export const PAGINAS_ALUNO = paginasAluno;
export const AULAS_ALUNO = aulasAluno;
export const CODIGOS_ALUNO = codigosAluno;

// Coleções de PDF que o leitor (/ler/:colecao/:id) sabe abrir
export const COLECOES = {
  aulas: { nome: "Aulas de 2024", itens: AULAS, voltar: "/professor/aulas" },
  tarefas: { nome: "Tarefas", itens: TAREFAS, voltar: "/professor/tarefas" },
  artigos: { nome: "Artigos", itens: ARTIGOS, voltar: "/artigos" },
  "aulas-2011": { nome: "Aulas de 2010–2011", itens: AULAS_ALUNO, voltar: "/aluno/aulas" },
};

// Arquivos dos projetos de 2024: README.md, src/*.c|*.cpp e exemplo.txt (texto puro, lazy)
const arquivosProjetos = import.meta.glob("../content/professor/projetos/**/*.{md,c,cpp,h,txt}", {
  query: "?raw",
  import: "default",
});

export function arquivosDoProjeto(slug) {
  const prefixo = `../content/professor/projetos/${slug}/`;
  return Object.keys(arquivosProjetos)
    .filter((caminho) => caminho.startsWith(prefixo))
    .map((caminho) => ({ caminho: caminho.slice(prefixo.length), carregar: arquivosProjetos[caminho] }))
    .sort((a, b) => ordem(a.caminho) - ordem(b.caminho) || a.caminho.localeCompare(b.caminho));
}

function ordem(caminho) {
  if (caminho === "README.md") return 0;
  if (caminho.startsWith("src/")) return 1;
  return 2;
}

// Códigos de 2010–2011 (salvos como .txt para o Vite não tentar interpretar)
const arquivosAluno = import.meta.glob("../content/aluno/codigos/**/*.txt", { query: "?raw", import: "default" });

export function carregarCodigoAluno(slug, nome) {
  const carregar = arquivosAluno[`../content/aluno/codigos/${slug}/${nome}.txt`];
  return carregar ? carregar() : Promise.reject(new Error("Arquivo não encontrado"));
}

export function linguagemDoArquivo(nome) {
  if (nome.endsWith(".cpp") || nome.endsWith(".hpp")) return "cpp";
  if (nome.endsWith(".c") || nome.endsWith(".h")) return "c";
  if (nome.endsWith(".md")) return "markdown";
  return "plaintext";
}
