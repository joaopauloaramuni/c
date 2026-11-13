import { Link } from "react-router-dom";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import DocList from "../../components/DocList/DocList.jsx";
import { AULAS } from "../../data/conteudo.js";

export default function ProfessorAulas() {
  return (
    <div className="container page">
      <nav className="trilha" aria-label="Você está em">
        <Link to="/professor">Professor 2024</Link>
        <span aria-hidden>/</span>
        Aulas
      </nav>
      <PageTitle
        ano="1º semestre de 2024"
        titulo="Aulas"
        subtitulo="Os slides da disciplina em PDF, na ordem do semestre. Abra no leitor do site ou baixe o arquivo."
      />
      <DocList itens={AULAS} colecao="aulas" numerar />
    </div>
  );
}
