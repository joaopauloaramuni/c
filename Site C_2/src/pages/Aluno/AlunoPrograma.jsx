import { Fragment } from "react";
import { Link, NavLink, useParams } from "react-router-dom";
import CodeBlock from "../../components/CodeBlock/CodeBlock.jsx";
import NaoEncontrada from "../NaoEncontrada.jsx";
import { PAGINAS_ALUNO } from "../../data/conteudo.js";
import { LINKS } from "../../config/site.js";

// Texto das páginas de 2011 com as imagens no lugar original ([[img:arquivo]])
function TextoAntigo({ texto }) {
  const partes = texto.split(/\[\[img:([^\]]+)\]\]/);
  return partes.map((p, i) =>
    i % 2 ? (
      <img key={i} className="img-2011" src={`/img/2011/${p}`} alt="" loading="lazy" />
    ) : (
      p.trim() && (
        <p key={i} className="texto-2011">
          {p.replace(/^\n+|\n+$/g, "").replace(/\n{3,}/g, "\n\n")}
        </p>
      )
    ),
  );
}

export default function AlunoPrograma() {
  const { slug } = useParams();
  const i = PAGINAS_ALUNO.findIndex((p) => p.slug === slug);
  if (i < 0) return <NaoEncontrada />;
  const pagina = PAGINAS_ALUNO[i];
  const anterior = PAGINAS_ALUNO[i - 1];
  const proxima = PAGINAS_ALUNO[i + 1];

  return (
    <div className="container page">
      <nav className="trilha" aria-label="Você está em">
        <Link to="/aluno">Aluno 2011</Link>
        <span aria-hidden>/</span>
        {pagina.menu}
      </nav>

      <div className="duas-colunas">
        <aside className="lateral-2011" aria-label="Menu.c">
          <p className="lateral-2011__titulo">Menu.c</p>
          <ul className="navbar-2011">
            {PAGINAS_ALUNO.map((p) => (
              <li key={p.slug}>
                <NavLink to={`/aluno/programas/${p.slug}`}>{p.menu}</NavLink>
              </li>
            ))}
          </ul>
        </aside>

        <article className="artigo-2011">
          {pagina.secoes.map((s, k) => (
            <Fragment key={k}>
              {k === 0 ? <h1>{s.titulo}</h1> : <h2 className="comentario">{s.titulo}</h2>}
              {s.texto && <TextoAntigo texto={s.texto} />}
              {s.codigo && (
                <CodeBlock
                  codigo={s.codigo}
                  linguagem="c"
                  arquivo={s.arquivo ? s.arquivo.split("/").pop() : `${pagina.slug}.c`}
                />
              )}
            </Fragment>
          ))}

          <p className="muted pequeno">
            Página original: <a href={`${LINKS.siteAntigo}${pagina.pagina}`}>{pagina.pagina}</a>. Os códigos foram
            reindentados, porque o HTML de 2011 tinha perdido a indentação.
          </p>

          <nav className="vizinhos" aria-label="Outros programas">
            {anterior ? (
              <Link to={`/aluno/programas/${anterior.slug}`}>
                <small>Anterior</small>
                {anterior.menu}
              </Link>
            ) : (
              <span />
            )}
            {proxima && (
              <Link to={`/aluno/programas/${proxima.slug}`} className="vizinhos__prox">
                <small>Próximo</small>
                {proxima.menu}
              </Link>
            )}
          </nav>
        </article>
      </div>
    </div>
  );
}
