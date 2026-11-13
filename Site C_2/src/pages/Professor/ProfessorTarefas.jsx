import { Link } from "react-router-dom";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import DocList from "../../components/DocList/DocList.jsx";
import { PROJETOS, TAREFAS } from "../../data/conteudo.js";

export default function ProfessorTarefas() {
  const titulo = Object.fromEntries(PROJETOS.map((p) => [p.slug, p.titulo]));
  return (
    <div className="container page">
      <nav className="trilha" aria-label="Você está em">
        <Link to="/professor">Professor 2024</Link>
        <span aria-hidden>/</span>
        Tarefas
      </nav>
      <PageTitle
        ano="1º semestre de 2024"
        titulo="Tarefas"
        subtitulo="Cada enunciado tem a resolução em um projeto C, com README explicando a solução."
      />
      <DocList
        itens={TAREFAS}
        colecao="tarefas"
        extra={(t) => (
          <p className="docs__resolucao">
            Resolução:{" "}
            {t.projetos.map((p, i) => (
              <span key={p}>
                {i > 0 && ", "}
                <Link to={`/professor/projetos/${p}`}>
                  {p}
                </Link>
              </span>
            ))}
            <span className="visually-hidden"> ({t.projetos.map((p) => titulo[p]).join(", ")})</span>
          </p>
        )}
      />
    </div>
  );
}
