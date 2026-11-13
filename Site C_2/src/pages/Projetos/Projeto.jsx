import { useEffect, useMemo, useState } from "react";
import { Link, useParams, useSearchParams } from "react-router-dom";
import { FiGithub } from "react-icons/fi";
import Markdown from "../../components/Markdown/Markdown.jsx";
import CodeBlock from "../../components/CodeBlock/CodeBlock.jsx";
import NaoEncontrada from "../NaoEncontrada.jsx";
import { PROJETOS, TAREFAS, arquivosDoProjeto, linguagemDoArquivo } from "../../data/conteudo.js";
import { LINKS } from "../../config/site.js";

export default function Projeto() {
  const { slug } = useParams();
  const [params, setParams] = useSearchParams();
  const indice = PROJETOS.findIndex((p) => p.slug === slug);
  const projeto = PROJETOS[indice];
  const arquivos = useMemo(() => (projeto ? arquivosDoProjeto(slug) : []), [projeto, slug]);
  const aba = params.get("arquivo") || "README.md";
  const [carregado, setCarregado] = useState({ slug: null, arquivos: {} });

  useEffect(() => {
    let vivo = true;
    Promise.all(arquivos.map((a) => a.carregar().then((t) => [a.caminho, t]))).then(
      (pares) => vivo && setCarregado({ slug, arquivos: Object.fromEntries(pares) }),
    );
    return () => {
      vivo = false;
    };
  }, [arquivos, slug]);
  const conteudo = carregado.slug === slug ? carregado.arquivos : {};

  if (!projeto) return <NaoEncontrada />;
  const abrir = (caminho) => setParams(caminho === "README.md" ? {} : { arquivo: caminho }, { replace: true });
  const anterior = PROJETOS[indice - 1];
  const proximo = PROJETOS[indice + 1];
  const tarefa = TAREFAS.find((t) => t.projetos.includes(slug));
  const texto = conteudo[aba];

  return (
    <div className="container page">
      <nav className="trilha" aria-label="Você está em">
        <Link to="/professor">Professor 2024</Link>
        <span aria-hidden>/</span>
        <Link to="/professor/projetos">Projetos</Link>
        <span aria-hidden>/</span>
        <Link to={`/professor/projetos?tema=${encodeURIComponent(projeto.tema)}`}>{projeto.tema}</Link>
      </nav>

      <div className="projeto">
        <aside className="projeto__lateral">
          <p className="projeto__emoji" aria-hidden>
            {projeto.emoji}
          </p>
          <p className="projeto__slug">{projeto.slug}</p>
          <h1 className="projeto__titulo">{projeto.titulo}</h1>

          <div className="explorador">
            <p className="explorador__titulo">Explorador</p>
            <div role="group" aria-label="Arquivos do projeto" className="explorador__arvore">
              <p className="explorador__pasta explorador__pasta--raiz">{slug}</p>
              {arquivos
                .filter((a) => !a.caminho.includes("/"))
                .slice(0, 1)
                .map((a) => (
                  <ArquivoAba key={a.caminho} arquivo={a} nivel={1} ativo={aba === a.caminho} abrir={abrir} />
                ))}
              {arquivos.some((a) => a.caminho.startsWith("src/")) && (
                <p className="explorador__pasta" style={{ "--nivel": 1 }}>
                  src
                </p>
              )}
              {arquivos
                .filter((a) => a.caminho.startsWith("src/"))
                .map((a) => (
                  <ArquivoAba key={a.caminho} arquivo={a} nivel={2} ativo={aba === a.caminho} abrir={abrir} />
                ))}
              {arquivos
                .filter((a) => !a.caminho.includes("/"))
                .slice(1)
                .map((a) => (
                  <ArquivoAba key={a.caminho} arquivo={a} nivel={1} ativo={aba === a.caminho} abrir={abrir} />
                ))}
            </div>
          </div>

          {tarefa && (
            <p className="projeto__extra">
              Enunciado: <Link to={`/ler/tarefas/${tarefa.id}`}>{tarefa.titulo} (PDF)</Link>
            </p>
          )}
          <p className="projeto__extra">
            <a href={`${LINKS.repoProfessor}/tree/main/PROJETOS/${encodeURIComponent(slug)}`}>
              <FiGithub aria-hidden /> Ver no GitHub
            </a>
          </p>
        </aside>

        <div className="projeto__conteudo" aria-live="polite">
          {texto == null ? (
            <p className="muted" role="status">
              Carregando {aba}…
            </p>
          ) : aba.endsWith(".md") ? (
            <Markdown texto={texto} />
          ) : (
            <CodeBlock codigo={texto} arquivo={aba} linguagem={linguagemDoArquivo(aba)} numeros={!aba.endsWith(".txt")} />
          )}

          <nav className="vizinhos" aria-label="Outros projetos">
            {anterior ? (
              <Link to={`/professor/projetos/${anterior.slug}`}>
                <small>Anterior</small>
                {anterior.titulo}
              </Link>
            ) : (
              <span />
            )}
            {proximo && (
              <Link to={`/professor/projetos/${proximo.slug}`} className="vizinhos__prox">
                <small>Próximo</small>
                {proximo.titulo}
              </Link>
            )}
          </nav>
        </div>
      </div>
    </div>
  );
}

// Um arquivo no explorador: ícone com a letra do tipo (C, C++, M, T), como nas IDEs
function ArquivoAba({ arquivo, nivel, ativo, abrir }) {
  const nome = arquivo.caminho.split("/").pop();
  const ext = nome.split(".").pop();
  const tipo = { c: "C", h: "H", cpp: "C++", md: "M", txt: "T" }[ext] || "·";
  return (
    <button
      type="button"
      aria-current={ativo ? "true" : undefined}
      className="explorador__arquivo"
      style={{ "--nivel": nivel }}
      onClick={() => abrir(arquivo.caminho)}
      title={arquivo.caminho}
    >
      <span className={`explorador__icone explorador__icone--${ext}`} aria-hidden>
        {tipo}
      </span>
      <span>{nome}</span>
    </button>
  );
}
