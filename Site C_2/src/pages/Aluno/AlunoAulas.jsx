import { Link } from "react-router-dom";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import DocList from "../../components/DocList/DocList.jsx";
import { AULAS_ALUNO } from "../../data/conteudo.js";
import { LINKS } from "../../config/site.js";

export default function AlunoAulas() {
  return (
    <div className="container page">
      <nav className="trilha" aria-label="Você está em">
        <Link to="/aluno">Aluno 2011</Link>
        <span aria-hidden>/</span>
        Aulas
      </nav>
      <PageTitle
        ano="2010–2011"
        titulo="Aulas do Prof. Rafael Nunes"
        subtitulo="Os PDFs da seção Material do Site C original, das disciplinas de ED1 e ED2 da FUMEC. A publicação foi autorizada pelo professor."
      >
        <p className="muted pequeno">
          Prof. Dr. Rafael Nunes Linhares Papa: <a href={LINKS.rafaelLattes}>Lattes</a> e{" "}
          <a href={LINKS.rafaelLinkedin}>LinkedIn</a>.
        </p>
      </PageTitle>
      <DocList itens={AULAS_ALUNO} colecao="aulas-2011" />
    </div>
  );
}
