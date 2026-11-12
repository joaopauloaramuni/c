import { Link } from "react-router-dom";
import { FiBookOpen, FiDownload } from "react-icons/fi";
import "./DocList.css";

// Lista de PDFs com "Ler no site" e "Baixar". Cada item: { id, titulo, descricao?, paginas, mb, arquivo }
export default function DocList({ itens, colecao, numerar = false, extra }) {
  return (
    <ol className={`docs ${numerar ? "docs--numerada" : ""}`}>
      {itens.map((d) => (
        <li key={d.id} className="docs__item">
          <div className="docs__texto">
            <h3 className="docs__titulo">
              <Link to={`/ler/${colecao}/${d.id}`}>{d.titulo}</Link>
            </h3>
            {d.descricao && <p className="docs__desc">{d.descricao}</p>}
            {extra?.(d)}
            <p className="docs__meta">
              {d.paginas} {d.paginas === 1 ? "página" : "páginas"}, {String(d.mb).replace(".", ",")} MB
            </p>
          </div>
          <div className="docs__acoes">
            <Link className="btn btn--primary" to={`/ler/${colecao}/${d.id}`}>
              <FiBookOpen aria-hidden /> Ler
            </Link>
            <a className="btn btn--icon" href={d.arquivo} download aria-label={`Baixar ${d.titulo}`}>
              <FiDownload aria-hidden />
            </a>
          </div>
        </li>
      ))}
    </ol>
  );
}
