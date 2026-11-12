import { useEffect, useMemo, useState } from "react";
import { Link, useParams } from "react-router-dom";
import { FiSearch } from "react-icons/fi";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import CodeBlock from "../../components/CodeBlock/CodeBlock.jsx";
import { CODIGOS_ALUNO, carregarCodigoAluno } from "../../data/conteudo.js";
import { LINKS } from "../../config/site.js";

function semAcento(s) {
  return s.normalize("NFD").replace(/[\u0300-\u036f]/g, "").toLowerCase();
}

export default function AlunoCodigos() {
  const { slug } = useParams();
  const [busca, setBusca] = useState("");
  const atual = CODIGOS_ALUNO.find((c) => c.slug === slug) || null;
  const filtrados = useMemo(
    () => CODIGOS_ALUNO.filter((c) => semAcento(c.nome).includes(semAcento(busca))),
    [busca],
  );

  return (
    <div className="container page">
      <nav className="trilha" aria-label="Você está em">
        <Link to="/aluno">Aluno 2011</Link>
        <span aria-hidden>/</span>
        {atual ? <Link to="/aluno/codigos">Códigos-fonte</Link> : "Códigos-fonte"}
        {atual && (
          <>
            <span aria-hidden>/</span>
            {atual.nome}
          </>
        )}
      </nav>

      {!atual && (
        <PageTitle
          ano="2010–2011"
          titulo="Códigos-fonte"
          subtitulo={`Os ${CODIGOS_ALUNO.length} projetos da pasta PROJETOS do repositório de 2011, do primeiro aloMundo à árvore binária.`}
        />
      )}

      <div className="duas-colunas">
        <aside className="lateral-2011" aria-label="Lista de códigos">
          <label className="busca busca--compacta">
            <FiSearch aria-hidden />
            <span className="visually-hidden">Buscar código</span>
            <input type="search" placeholder="Buscar" value={busca} onChange={(e) => setBusca(e.target.value)} />
          </label>
          <ul className="navbar-2011 navbar-2011--rolagem">
            {filtrados.map((c) => (
              <li key={c.slug}>
                <Link to={`/aluno/codigos/${c.slug}`} className={c.slug === slug ? "active" : undefined} aria-current={c.slug === slug ? "page" : undefined}>
                  {c.nome}
                </Link>
              </li>
            ))}
            {!filtrados.length && <li className="muted pequeno">Nenhum código com esse nome.</li>}
          </ul>
        </aside>

        <div>
          {atual ? (
            <ArquivosAluno projeto={atual} />
          ) : (
            <div className="vazio">
              <p>Escolha um projeto na lista para ver o código.</p>
              <p className="muted">
                Os mesmos arquivos estão no <a href={`${LINKS.repoAluno}/tree/main/PROJETOS`}>repositório do GitHub</a>.
              </p>
            </div>
          )}
        </div>
      </div>
    </div>
  );
}

function ArquivosAluno({ projeto }) {
  const [textos, setTextos] = useState({});
  useEffect(() => {
    let vivo = true;
    Promise.all(projeto.arquivos.map((a) => carregarCodigoAluno(projeto.slug, a.nome).then((t) => [a.nome, t]))).then(
      (pares) => vivo && setTextos(Object.fromEntries(pares)),
    );
    return () => {
      vivo = false;
    };
  }, [projeto]);

  return (
    <>
      <h1 className="titulo-codigo">{projeto.nome}</h1>
      <p className="muted">
        {projeto.arquivos.length} {projeto.arquivos.length === 1 ? "arquivo" : "arquivos"}.{" "}
        <a href={`${LINKS.repoAluno}/tree/main/PROJETOS/${encodeURIComponent(projeto.nome)}`}>Ver no GitHub</a>
      </p>
      {projeto.arquivos.map((a) =>
        textos[a.nome] != null ? (
          <CodeBlock key={a.nome} arquivo={a.nome} codigo={textos[a.nome]} linguagem="c" />
        ) : (
          <p key={a.nome} className="muted" role="status">
            Carregando {a.nome}…
          </p>
        ),
      )}
    </>
  );
}
