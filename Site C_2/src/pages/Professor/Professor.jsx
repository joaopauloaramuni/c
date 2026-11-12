import { Link } from "react-router-dom";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import { AULAS, PROJETOS, TAREFAS, TEMAS } from "../../data/conteudo.js";
import { LINKS } from "../../config/site.js";

export default function Professor() {
  const contagem = Object.fromEntries(TEMAS.map((t) => [t, PROJETOS.filter((p) => p.tema === t).length]));
  return (
    <div className="container page">
      <PageTitle
        ano="1º semestre de 2024"
        titulo="Como professor"
        subtitulo="Algoritmos e Estruturas de Dados I, no curso de Engenharia de Software da PUC Minas. Aulas, projetos em C com README e as tarefas resolvidas."
      />

      <section className="bloco atalhos atalhos--tres">
        <Link className="atalho" to="/professor/aulas">
          <span className="atalho__num">{AULAS.length}</span>
          <span>
            <strong>Aulas</strong>
            <span className="muted">Apresentação da disciplina e as cinco aulas em PDF.</span>
          </span>
        </Link>
        <Link className="atalho" to="/professor/projetos">
          <span className="atalho__num">{PROJETOS.length}</span>
          <span>
            <strong>Projetos</strong>
            <span className="muted">Cada projeto do Eclipse com README, código e exemplo de execução.</span>
          </span>
        </Link>
        <Link className="atalho" to="/professor/tarefas">
          <span className="atalho__num">{TAREFAS.length}</span>
          <span>
            <strong>Tarefas</strong>
            <span className="muted">Os enunciados em PDF ao lado das resoluções.</span>
          </span>
        </Link>
      </section>

      <section className="bloco" aria-labelledby="ementa">
        <h2 id="ementa" className="comentario">
          O caminho da disciplina
        </h2>
        <p className="muted prose">
          Os projetos seguem a ordem das aulas: cada tema abre a lista de projetos já filtrada.
        </p>
        <ol className="trilha-temas">
          {TEMAS.map((t) => (
            <li key={t}>
              <Link to={`/professor/projetos?tema=${encodeURIComponent(t)}`}>
                <span>{t}</span>
                <span className="muted">
                  {contagem[t]} {contagem[t] === 1 ? "projeto" : "projetos"}
                </span>
              </Link>
            </li>
          ))}
        </ol>
      </section>

      <p className="muted pequeno">
        Tudo também está no <a href={LINKS.repoProfessor}>repositório da disciplina no GitHub</a>.
      </p>
    </div>
  );
}
