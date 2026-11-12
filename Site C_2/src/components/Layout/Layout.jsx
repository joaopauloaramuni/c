import { useEffect, useState } from "react";
import { Link, NavLink, Outlet, useLocation } from "react-router-dom";
import { FiGithub, FiMail, FiMenu, FiX } from "react-icons/fi";
import ThemeToggle from "../ThemeToggle/ThemeToggle.jsx";
import { useTheme } from "../../hooks/useTheme.js";
import { AUTOR, LINKS, NAV } from "../../config/site.js";
import "./Layout.css";

// Nome do "arquivo" aberto, mostrado na barra de status
function arquivoAtual(pathname) {
  const item = [...NAV].reverse().find((n) => (n.fim ? pathname === n.to : pathname.startsWith(n.to)));
  if (pathname.startsWith("/ler/")) return "leitor.pdf";
  return item ? item.arquivo : "404.c";
}

export default function Layout() {
  const { tema, alternar } = useTheme();
  const [aberto, setAberto] = useState(false);
  const { pathname } = useLocation();
  const [rota, setRota] = useState(pathname);

  // Fecha o menu do celular a cada troca de página
  if (rota !== pathname) {
    setRota(pathname);
    setAberto(false);
  }

  // Volta ao topo a cada troca de página
  useEffect(() => {
    window.scrollTo(0, 0);
  }, [pathname]);

  return (
    <>
      <a className="pular" href="#conteudo">
        Pular para o conteúdo
      </a>
      <header className="topo">
        <div className="container topo__barra">
          <Link to="/" className="marca" aria-label="Site C, página inicial">
            <span className="marca__c" aria-hidden>
              C
            </span>
            <span className="marca__nome">
              site<span className="marca__ponto">.</span>c
            </span>
            <span className="marca__versao">v2.0</span>
          </Link>

          <nav className={`abas-nav ${aberto ? "abas-nav--aberta" : ""}`} aria-label="Principal">
            <ul>
              {NAV.map((item) => (
                <li key={item.to}>
                  <NavLink to={item.to} end={item.fim}>
                    <span className="abas-nav__rotulo">{item.rotulo}</span>
                    <span className="abas-nav__arquivo" aria-hidden>
                      {item.arquivo}
                    </span>
                  </NavLink>
                </li>
              ))}
            </ul>
          </nav>

          <div className="topo__acoes">
            <ThemeToggle tema={tema} alternar={alternar} />
            <button
              type="button"
              className="btn btn--ghost btn--icon topo__hamburguer"
              aria-expanded={aberto}
              aria-label={aberto ? "Fechar menu" : "Abrir menu"}
              onClick={() => setAberto((v) => !v)}
            >
              {aberto ? <FiX aria-hidden /> : <FiMenu aria-hidden />}
            </button>
          </div>
        </div>
      </header>

      <main id="conteudo">
        <Outlet />
      </main>

      <footer className="rodape">
        <div className="container rodape__grade">
          <div>
            <p className="rodape__marca">
              <span>
                site<span className="marca__ponto">.</span>c
              </span>
              <span className="marca__versao">v2.0</span>
            </p>
            <p className="muted rodape__texto">
              Códigos em C escritos por {AUTOR.nome} como aluno (FUMEC, 2010–2011) e como professor (PUC Minas,
              2024). Feito com React e Vite.
            </p>
          </div>
          <div>
            <p className="rodape__titulo comentario">Repositórios</p>
            <ul className="rodape__links">
              <li>
                <a href={LINKS.repoAluno}>
                  <FiGithub aria-hidden /> joaopauloaramuni/c
                </a>
              </li>
              <li>
                <a href={LINKS.repoProfessor}>
                  <FiGithub aria-hidden /> algoritmos-e-estruturas-de-dados-i
                </a>
              </li>
            </ul>
          </div>
          <div>
            <p className="rodape__titulo comentario">Contato</p>
            <ul className="rodape__links">
              <li>
                <a href={`mailto:${AUTOR.email}`}>
                  <FiMail aria-hidden /> {AUTOR.email}
                </a>
              </li>
              <li>
                <a href={LINKS.siteAntigo}>Site C de 2011</a>
              </li>
            </ul>
          </div>
        </div>

        {/* A barra de status, no #61849C do site de 2011 */}
        <div className="status" aria-label="Barra de status">
          <div className="status__lado">
            <span className="status__item status__item--forte">⎇ main</span>
            <span className="status__item">{arquivoAtual(pathname)}</span>
          </div>
          <div className="status__lado">
            <span className="status__item status__item--some">Ln 2011, Col 2024</span>
            <span className="status__item status__item--some">UTF-8</span>
            <span className="status__item">C (ANSI)</span>
            <span className="status__item">{tema === "dark" ? "Tema escuro" : "Tema claro"}</span>
          </div>
        </div>
      </footer>
    </>
  );
}
