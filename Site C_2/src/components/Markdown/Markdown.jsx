import ReactMarkdown from "react-markdown";
import remarkGfm from "remark-gfm";
import rehypeHighlight from "rehype-highlight";
import { Link } from "react-router-dom";
import { TAREFAS } from "../../data/conteudo.js";
import "../CodeBlock/CodeBlock.css";
import "./Markdown.css";

// Os READMEs foram escritos para o GitHub. Aqui, os links entre projetos (../Prj_X)
// e os PDFs das tarefas passam a abrir dentro do próprio site.
function rotaInterna(href = "") {
  const projeto = href.match(/^\.\.\/(Prj_[^/#?]+)\/?$/);
  if (projeto) return `/professor/projetos/${decodeURIComponent(projeto[1])}`;
  if (href.includes("/TAREFAS/PDF/")) {
    const nome = decodeURIComponent(href.split("/").pop()).replace(/\.pdf$/, "");
    const mapa = { "Tarefa 1": "tarefa-1", "Tarefa 2": "tarefa-2", "Tarefa 3": "tarefa-3", "Tarefa 4": "tarefa-4", "Exercício de Revisão": "revisao" };
    const id = mapa[nome];
    if (id && TAREFAS.some((t) => t.id === id)) return `/ler/tarefas/${id}`;
  }
  return null;
}

const componentes = {
  a({ href, children }) {
    const rota = rotaInterna(href);
    if (rota) return <Link to={rota}>{children}</Link>;
    return (
      <a href={href} target="_blank" rel="noreferrer">
        {children}
      </a>
    );
  },
  pre({ children }) {
    return <pre className="md__pre">{children}</pre>;
  },
  table({ children }) {
    return (
      <div className="md__tabela">
        <table>{children}</table>
      </div>
    );
  },
};

export default function Markdown({ texto }) {
  return (
    <div className="md">
      <ReactMarkdown remarkPlugins={[remarkGfm]} rehypePlugins={[[rehypeHighlight, { detect: false }]]} components={componentes}>
        {texto}
      </ReactMarkdown>
    </div>
  );
}
