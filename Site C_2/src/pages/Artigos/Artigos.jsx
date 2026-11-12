import { Link } from "react-router-dom";
import { FiBookOpen, FiDownload } from "react-icons/fi";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import { ARTIGOS } from "../../data/conteudo.js";
import "./Artigos.css";

export default function Artigos() {
  const grupos = [...new Set(ARTIGOS.map((a) => a.grupo))];
  return (
    <div className="container page">
      <PageTitle
        titulo="Artigos sugeridos"
        subtitulo="Textos clássicos que vão das origens teóricas da computação aos algoritmos de ordenação que usamos até hoje. Todos em inglês, no original."
      />
      {grupos.map((g) => (
        <section key={g} className="bloco" aria-labelledby={`g-${g}`}>
          <h2 id={`g-${g}`} className="comentario">
            {g}
          </h2>
          <ol className="artigos">
            {ARTIGOS.filter((a) => a.grupo === g)
              .sort((a, b) => a.ano - b.ano)
              .map((a) => (
                <li key={a.id} className="artigo">
                  <p className="artigo__ano">{a.ano}</p>
                  <div className="artigo__corpo">
                    <h3 className="artigo__titulo">
                      <Link to={`/ler/artigos/${a.id}`}>{a.titulo}</Link>
                    </h3>
                    <p className="artigo__autor">{a.autor}</p>
                    <p className="artigo__desc">{a.descricao}</p>
                    <p className="artigo__meta">
                      {a.paginas} páginas, {String(a.mb).replace(".", ",")} MB
                    </p>
                  </div>
                  <div className="artigo__acoes">
                    <Link className="btn btn--primary" to={`/ler/artigos/${a.id}`}>
                      <FiBookOpen aria-hidden /> Ler
                    </Link>
                    <a className="btn btn--icon" href={a.arquivo} download aria-label={`Baixar ${a.titulo}`}>
                      <FiDownload aria-hidden />
                    </a>
                  </div>
                </li>
              ))}
          </ol>
        </section>
      ))}
    </div>
  );
}
