import { Link, useParams, useSearchParams } from "react-router-dom";
import PdfViewer from "../../components/PdfViewer/PdfViewer.jsx";
import NaoEncontrada from "../NaoEncontrada.jsx";
import { COLECOES } from "../../data/conteudo.js";

export default function Leitor() {
  const { colecao, id } = useParams();
  const [params, setParams] = useSearchParams();
  const grupo = COLECOES[colecao];
  const indice = grupo ? grupo.itens.findIndex((d) => d.id === id) : -1;
  if (indice < 0) return <NaoEncontrada />;

  const doc = grupo.itens[indice];
  const anterior = grupo.itens[indice - 1];
  const proximo = grupo.itens[indice + 1];
  const pagina = Math.max(1, Number(params.get("p")) || 1);
  const titulo = doc.autor ? `${doc.titulo} (${doc.autor}, ${doc.ano})` : doc.titulo;

  return (
    <div className="container page page--leitor">
      <nav className="trilha" aria-label="Você está em">
        <Link to={grupo.voltar}>{grupo.nome}</Link>
        <span aria-hidden>/</span>
        {doc.titulo}
      </nav>
      <header className="leitor-cabeca">
        <h1>{doc.titulo}</h1>
        {doc.autor && (
          <p className="leitor-autor">
            {doc.autor}, {doc.ano}
          </p>
        )}
        {doc.descricao && <p className="muted prose">{doc.descricao}</p>}
      </header>

      <PdfViewer
        key={doc.arquivo}
        arquivo={doc.arquivo}
        titulo={titulo}
        pagina={pagina}
        onPagina={(n) => setParams(n > 1 ? { p: String(n) } : {}, { replace: true })}
      />

      <nav className="vizinhos" aria-label={`Outros itens em ${grupo.nome}`}>
        {anterior ? (
          <Link to={`/ler/${colecao}/${anterior.id}`}>
            <small>Anterior</small>
            {anterior.titulo}
          </Link>
        ) : (
          <span />
        )}
        {proximo && (
          <Link to={`/ler/${colecao}/${proximo.id}`} className="vizinhos__prox">
            <small>Próximo</small>
            {proximo.titulo}
          </Link>
        )}
      </nav>
    </div>
  );
}
