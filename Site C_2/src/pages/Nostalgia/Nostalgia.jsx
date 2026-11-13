import { FiArrowUpRight } from "react-icons/fi";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import CodeBlock from "../../components/CodeBlock/CodeBlock.jsx";
import { LINKS } from "../../config/site.js";
import "./Nostalgia.css";

const comparacao = [
  ["Estrutura", "HTML 4.01 Transitional, layout em <TABLE>", "React 19 com componentes e rotas (React Router)"],
  ["Build", "Nenhum: os arquivos .html iam direto para o servidor", "Vite"],
  ["Páginas", "20 arquivos (pag1.html a pag20.html) com o menu copiado em cada um", "Um menu só, e as páginas geradas a partir de dados JSON"],
  ["Estilo", "Um style.css com -moz-linear-gradient (só funcionava no Firefox) e Verdana", "Design system de IDE em JetBrains Mono, com tema claro e escuro e layout responsivo"],
  ["Código", "Colado no HTML com <br> em cada linha, sem indentação", "Destaque de sintaxe, numeração de linhas e botão de copiar"],
  ["Aulas", "Links para baixar os PDFs", "Leitor de PDF dentro do site (pdf.js)"],
  ["Interação", "JavaScript para trocar o banner e os ícones no mouseover", "Busca, filtros por tema e navegação entre projetos"],
];

const agradecimentos = [
  "Prof. Rafael Nunes",
  "Daniel Morato",
  "Guilherme Reis",
  "Klelvin Carvalho Rodrigues",
  "Lucas Moura Belo",
  "Marcelo Costa",
  "Rafael Andrade Lott",
  "Roberto José",
];

const redes = [
  ["lk0.png", "LinkedIn"],
  ["yt0.png", "YouTube"],
  ["tw0.png", "Twitter"],
  ["fb0.png", "Facebook"],
  ["ok0.png", "Orkut"],
];

const cssAntigo = `body{
  background-color: #61849C;
  background: -moz-linear-gradient(top, #F0F0F0, #61849C) repeat-X;
  height:1024px
}
.TD1{
  border-left: 10px solid #96B0E5;
  background-color: #A0A0A0;
  vertical-align: TOP
}
ul.navbar li{
  padding: 0;
  border-left: 3px solid #61849C;
  margin: 5px
}`;

export default function Nostalgia() {
  return (
    <div className="container page">
      <PageTitle
        ano="03/09/2011"
        titulo="Nostalgia"
        subtitulo="Como era o Site C em 2011: HTML puro, tabelas, um arquivo CSS e um pouco de JavaScript. A versão original continua publicada."
      />

      <section className="nostalgia-tela">
        <figure className="moldura-2011">
          <img src="/img/site-c-2011.png" alt="Página inicial do Site C em 2011: banner no topo, menu Menu.c à esquerda e o texto de apresentação" />
        </figure>
        <div>
          <h2 className="comentario">Programas em C - ANSI Style</h2>
          <p>
            Era esse o título da aba do navegador. O menu Menu.c, à esquerda, levava aos 19 programas; o topo tinha
            Home, Contato e Agradecimentos; e o rodapé, os ícones das redes sociais da época.
          </p>
          <p>
            Os textos imitavam comentários em C: <code>{"//Este site tem o objetivo de compartilhar códigos em C - ANSI Style."}</code>
          </p>
          <a className="btn btn--primary" href={LINKS.siteAntigo} target="_blank" rel="noreferrer">
            Abrir o site de 2011 <FiArrowUpRight aria-hidden />
          </a>
        </div>
      </section>

      <section className="bloco" aria-labelledby="banners">
        <h2 id="banners" className="comentario">
          Os três banners
        </h2>
        <p className="muted prose">
          A função <code>banner_change()</code> trocava o banner do topo. Eram estes:
        </p>
        <div className="banners">
          {["banner.png", "banner2.png", "banner3.png"].map((b, i) => (
            <img key={b} src={`/img/2011/${b}`} alt={`Banner ${i + 1} do Site C de 2011`} loading="lazy" />
          ))}
        </div>
      </section>

      <section className="bloco" aria-labelledby="antes-depois">
        <h2 id="antes-depois" className="comentario">
          De 2011 para hoje
        </h2>
        <div className="tabela-rolagem">
          <table className="comparacao">
            <thead>
              <tr>
                <th scope="col"></th>
                <th scope="col">Site C, 2011</th>
                <th scope="col">Site C 2.0</th>
              </tr>
            </thead>
            <tbody>
              {comparacao.map(([o, a, b]) => (
                <tr key={o}>
                  <th scope="row">{o}</th>
                  <td>{a}</td>
                  <td>{b}</td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </section>

      <section className="bloco duas-metades">
        <div>
          <h2 className="comentario">As cores vieram daqui</h2>
          <p className="muted">
            Trecho do <code>css/style.css</code> original. O aço <code>#61849C</code>, o azul <code>#96B0E5</code> e a
            borda à esquerda continuam no site novo.
          </p>
          <ul className="paleta" aria-label="Paleta de 2011">
            {["#61849C", "#96B0E5", "#A0A0A0", "#919191", "#F0F0F0", "#161616"].map((c) => (
              <li key={c}>
                <span style={{ background: c }} aria-hidden />
                <code>{c}</code>
              </li>
            ))}
          </ul>
        </div>
        <CodeBlock arquivo="css/style.css (2011)" codigo={cssAntigo} linguagem="plaintext" />
      </section>

      <section className="bloco duas-metades">
        <div>
          <h2 className="comentario">Agradecimentos</h2>
          <ul className="agradecimentos">
            {agradecimentos.map((n) => (
              <li key={n}>
                <span>{"//"}</span>
                {n}
              </li>
            ))}
          </ul>
        </div>
        <div>
          <h2 className="comentario">O rodapé de 2011</h2>
          <p className="muted">LinkedIn, YouTube, Twitter, Facebook e, claro, Orkut.</p>
          <ul className="redes-2011">
            {redes.map(([img, nome]) => (
              <li key={img}>
                <img src={`/img/2011/${img}`} alt="" />
                <span>{nome}</span>
              </li>
            ))}
          </ul>
        </div>
      </section>
    </div>
  );
}
