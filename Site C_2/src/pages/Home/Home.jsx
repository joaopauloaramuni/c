import { Link } from "react-router-dom";
import { FiArrowUpRight } from "react-icons/fi";
import LabScene from "../../components/LabScene/LabScene.jsx";
import {
  ARTIGOS,
  AULAS,
  AULAS_ALUNO,
  CODIGOS_ALUNO,
  PAGINAS_ALUNO,
  PROJETOS,
  TAREFAS,
} from "../../data/conteudo.js";
import { LINKS } from "../../config/site.js";
import "./Home.css";

const destaques = ["turing-1936", "shannon-1937", "cook-1971", "hoare-1961"];

// Uma época como um arquivo .c aberto: cada contador é uma linha de código clicável
function ArquivoEpoca({ arquivo, titulo, comentario, linhas, rodape }) {
  const largura = Math.max(...linhas.map((l) => l.nome.length));
  return (
    <article className="painel epoca">
      <div className="painel__aba">
        <span className="painel__arquivo">{arquivo}</span>
        <span className="painel__meta">{rodape}</span>
      </div>
      <div className="epoca__corpo">
        <h3 className="epoca__titulo">{titulo}</h3>
        <ol className="epoca__codigo">
          {comentario.map((c, i) => (
            <li key={`c${i}`} className="epoca__linha epoca__linha--comentario">
              <span>{`${i === 0 ? "/* " : "   "}${c}${i === comentario.length - 1 ? " */" : ""}`}</span>
            </li>
          ))}
          <li className="epoca__linha" aria-hidden>
            {" "}
          </li>
          {linhas.map((l) => (
            <li key={l.nome} className="epoca__linha">
              <Link to={l.to} className="epoca__link">
                <span className="tk-tipo">int</span> <span className="tk-var">{l.nome.padEnd(largura)}</span>{" "}
                <span className="tk-op">=</span> <span className="tk-num">{l.valor}</span>
                <span className="tk-op">;</span>
                <span className="tk-comentario"> {"//"} {l.descricao}</span>
              </Link>
            </li>
          ))}
        </ol>
      </div>
    </article>
  );
}

export default function Home() {
  const leituras = destaques.map((id) => ARTIGOS.find((a) => a.id === id)).sort((a, b) => a.ano - b.ano);
  return (
    <>
      <section className="hero">
        <LabScene className="hero__lab" />
        <div className="hero__veu" aria-hidden />
        <div className="container hero__conteudo">
          <p className="hero__include">
            <span className="tk-pre">#include</span> <span className="tk-str">&lt;memorias.h&gt;</span>
          </p>
          <h1 className="hero__titulo">
            Programas em C, do aluno ao professor
            <span className="cursor" aria-hidden />
          </h1>
          <p className="hero__lead">
            Os códigos que escrevi como aluno de Ciência da Computação, em 2011, e os que escrevi como professor de
            Engenharia de Software, em 2024. No mesmo site, separados por época, com as aulas, os projetos e os artigos
            para ler sem sair daqui.
          </p>
          <div className="hero__acoes">
            <Link className="btn btn--primary" to="/professor">
              Material de 2024
            </Link>
            <Link className="btn" to="/aluno">
              Códigos de 2011
            </Link>
          </div>
        </div>
      </section>

      <section className="container epocas" aria-labelledby="epocas-titulo">
        <h2 id="epocas-titulo" className="comentario epocas__titulo">
          Duas épocas, 13 anos de diferença
        </h2>
        <div className="epocas__grade">
          <ArquivoEpoca
            arquivo="aluno_2011.c"
            titulo="Como aluno"
            rodape="2010–2011"
            comentario={["Universidade FUMEC, Ciência da Computação.", "ED1 e ED2 com o Prof. Rafael Nunes."]}
            linhas={[
              { nome: "programas", valor: PAGINAS_ALUNO.length, descricao: "do site original", to: "/aluno" },
              { nome: "codigos", valor: CODIGOS_ALUNO.length, descricao: "fontes de 2011", to: "/aluno/codigos" },
              { nome: "aulas", valor: AULAS_ALUNO.length, descricao: "PDFs do Prof. Rafael", to: "/aluno/aulas" },
            ]}
          />
          <ArquivoEpoca
            arquivo="professor_2024.c"
            titulo="Como professor"
            rodape="1º sem. 2024"
            comentario={["PUC Minas, Engenharia de Software.", "Algoritmos e Estruturas de Dados I."]}
            linhas={[
              { nome: "aulas", valor: AULAS.length, descricao: "slides em PDF", to: "/professor/aulas" },
              { nome: "projetos", valor: PROJETOS.length, descricao: "com README", to: "/professor/projetos" },
              { nome: "tarefas", valor: TAREFAS.length, descricao: "com resolução", to: "/professor/tarefas" },
            ]}
          />
        </div>
      </section>

      <section className="container leituras" aria-labelledby="leituras-titulo">
        <div className="leituras__cabeca">
          <h2 id="leituras-titulo" className="comentario">
            Leituras clássicas
          </h2>
          <Link to="/artigos" className="leituras__todos">
            Ver os {ARTIGOS.length} artigos →
          </Link>
        </div>
        <ol className="leituras__lista">
          {leituras.map((a) => (
            <li key={a.id}>
              <Link to={`/ler/artigos/${a.id}`}>
                <span className="leituras__ano num">{a.ano}</span>
                <span className="leituras__titulo">{a.titulo}</span>
                <span className="leituras__autor">{a.autor}</span>
              </Link>
            </li>
          ))}
        </ol>
      </section>

      <section className="container antes">
        <figure className="antes__figura">
          <img src="/img/site-c-2011.png" alt="Captura de tela do Site C original, de 2011, com menu lateral cinza e azul" loading="lazy" />
          <figcaption>sitec-v1.vercel.app, 03/09/2011</figcaption>
        </figure>
        <div className="antes__texto">
          <h2 className="comentario">A primeira versão continua no ar</h2>
          <p className="muted">
            O Site C nasceu em 2011, em HTML 4.01 com tabelas, CSS e um pouco de JavaScript para trocar o banner. Esta
            versão guarda o cinza e o azul daquela época, agora em React e Vite.
          </p>
          <div className="hero__acoes">
            <Link className="btn" to="/nostalgia">
              Como era em 2011
            </Link>
            <a className="btn btn--ghost" href={LINKS.siteAntigo} target="_blank" rel="noreferrer">
              Abrir o site original <FiArrowUpRight aria-hidden />
            </a>
          </div>
        </div>
      </section>
    </>
  );
}
