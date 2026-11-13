import { Link } from "react-router-dom";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import { AULAS_ALUNO, CODIGOS_ALUNO, PAGINAS_ALUNO } from "../../data/conteudo.js";
import { LINKS } from "../../config/site.js";
import { GRUPOS_2011 } from "./programas.js";

export default function Aluno() {
  const porSlug = Object.fromEntries(PAGINAS_ALUNO.map((p) => [p.slug, p]));
  return (
    <div className="container page">
      <PageTitle
        ano="2010–2011"
        titulo="Como aluno"
        subtitulo="Códigos escritos nas disciplinas de Estruturas de Dados I e II do curso de Ciência da Computação da Universidade FUMEC, em Belo Horizonte."
      />

      <pre className="comentario-2011">
        {`/* Todos os códigos deste site foram escritos por João Paulo Aramuni entre
   os anos de 2010 e 2011 durante as disciplinas de ED1 e ED2 (Estrutura de
   Dados I e II) do curso de Ciência da Computação da Universidade FUMEC,
   disciplinas lecionadas pelo Prof. Rafael Nunes.

   Os exercícios apresentados neste site, tal como as aulas, foram
   planejados pelo Prof. Rafael Nunes e sua publicação foi autorizada. */`}
      </pre>
      <p className="muted pequeno">
        Texto da página inicial do Site C original, de 03/09/2011. Prof. Dr. Rafael Nunes Linhares Papa:{" "}
        <a href={LINKS.rafaelLattes}>Lattes</a> e <a href={LINKS.rafaelLinkedin}>LinkedIn</a>.
      </p>

      <section className="bloco" aria-labelledby="menu-c">
        <h2 id="menu-c" className="comentario">
          Menu.c
        </h2>
        <p className="muted">Os {PAGINAS_ALUNO.length} programas do site de 2011, com os enunciados e os códigos da época.</p>
        <div className="grupos-2011">
          {GRUPOS_2011.map((g) => (
            <section key={g.nome} className="grupo-2011">
              <h3>{g.nome}</h3>
              <ul className="menu-c">
                {Object.entries(g.itens).map(([slug, resumo]) => (
                  <li key={slug}>
                    <Link to={`/aluno/programas/${slug}`}>
                      <span className="menu-c__nome">{porSlug[slug]?.menu}</span>
                      <span className="menu-c__resumo">{resumo}</span>
                    </Link>
                  </li>
                ))}
              </ul>
            </section>
          ))}
        </div>
      </section>

      <section className="bloco atalhos">
        <Link className="atalho" to="/aluno/codigos">
          <span className="atalho__num">{CODIGOS_ALUNO.length}</span>
          <span>
            <strong>Códigos-fonte</strong>
            <span className="muted">Todos os projetos do repositório de 2010–2011, para ler no navegador.</span>
          </span>
        </Link>
        <Link className="atalho" to="/aluno/aulas">
          <span className="atalho__num">{AULAS_ALUNO.length}</span>
          <span>
            <strong>Aulas do Prof. Rafael Nunes</strong>
            <span className="muted">Os PDFs da seção Material do site antigo: linguagem C, listas, ordenação, árvores.</span>
          </span>
        </Link>
      </section>
    </div>
  );
}
