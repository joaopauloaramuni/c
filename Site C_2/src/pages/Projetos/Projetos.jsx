import { useEffect, useMemo, useRef } from "react";
import { Link, useSearchParams } from "react-router-dom";
import { FiSearch } from "react-icons/fi";
import PageTitle from "../../components/PageTitle/PageTitle.jsx";
import { PROJETOS, TEMAS } from "../../data/conteudo.js";

function semAcento(s) {
  return s.normalize("NFD").replace(/[\u0300-\u036f]/g, "").toLowerCase();
}

export default function Projetos() {
  const [params, setParams] = useSearchParams();
  const tema = params.get("tema") || "";
  const busca = params.get("q") || "";
  const campo = useRef(null);

  // Ctrl+K (ou Cmd+K) leva direto à busca, como nos editores
  useEffect(() => {
    function atalho(e) {
      if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === "k") {
        e.preventDefault();
        campo.current?.focus();
      }
    }
    window.addEventListener("keydown", atalho);
    return () => window.removeEventListener("keydown", atalho);
  }, []);

  function mudar(chave, valor) {
    const novo = new URLSearchParams(params);
    if (valor) novo.set(chave, valor);
    else novo.delete(chave);
    setParams(novo, { replace: true });
  }

  const filtrados = useMemo(() => {
    const q = semAcento(busca.trim());
    return PROJETOS.filter(
      (p) =>
        (!tema || p.tema === tema) &&
        (!q || semAcento(`${p.slug} ${p.titulo} ${p.resumo} ${p.tema}`).includes(q)),
    );
  }, [tema, busca]);

  const grupos = TEMAS.map((t) => ({ tema: t, itens: filtrados.filter((p) => p.tema === t) })).filter((g) => g.itens.length);

  return (
    <div className="container page">
      <nav className="trilha" aria-label="Você está em">
        <Link to="/professor">Professor 2024</Link>
        <span aria-hidden>/</span>
        Projetos
      </nav>
      <PageTitle
        ano="1º semestre de 2024"
        titulo="Projetos"
        subtitulo={`${PROJETOS.length} projetos do Eclipse usados em aula. Cada um tem README com explicação, exemplo de execução real e o código completo.`}
      />

      <div className="filtros">
        <label className="busca">
          <FiSearch aria-hidden />
          <span className="visually-hidden">Buscar projeto</span>
          <input
            ref={campo}
            type="search"
            placeholder="Buscar por nome ou assunto: recursão, ponteiro, struct…"
            value={busca}
            onChange={(e) => mudar("q", e.target.value)}
          />
        </label>
        <div className="chips" role="group" aria-label="Filtrar por tema">
          <button type="button" className="chip" aria-pressed={!tema} onClick={() => mudar("tema", "")}>
            Todos<small>{PROJETOS.length}</small>
          </button>
          {TEMAS.map((t) => (
            <button key={t} type="button" className="chip" aria-pressed={tema === t} onClick={() => mudar("tema", tema === t ? "" : t)}>
              {t}
              <small>{PROJETOS.filter((p) => p.tema === t).length}</small>
            </button>
          ))}
        </div>
      </div>

      <p className="muted pequeno" aria-live="polite">
        {filtrados.length === PROJETOS.length
          ? `Mostrando os ${PROJETOS.length} projetos.`
          : `${filtrados.length} de ${PROJETOS.length} projetos.`}
      </p>

      {grupos.length === 0 && (
        <div className="vazio">
          <p>Nenhum projeto encontrado para “{busca}”.</p>
          <button type="button" className="btn" onClick={() => setParams({}, { replace: true })}>
            Limpar a busca
          </button>
        </div>
      )}

      {grupos.map((g) => (
        <section key={g.tema} className="grupo-projetos" aria-labelledby={`tema-${g.tema}`}>
          <h2 id={`tema-${g.tema}`} className="grupo-projetos__titulo">
            {g.tema} <small>{g.itens.length}</small>
          </h2>
          <ul className="lista-projetos">
            {g.itens.map((p) => (
              <li key={p.slug}>
                <Link to={`/professor/projetos/${p.slug}`} className="projeto-linha">
                  <span className="projeto-linha__emoji" aria-hidden>
                    {p.emoji}
                  </span>
                  <span className="projeto-linha__texto">
                    <span className="projeto-linha__titulo">{p.titulo}</span>
                    <span className="projeto-linha__slug">
                      {p.slug}
                      {p.linguagem === "C++" && <span className="selo">C++</span>}
                    </span>
                    <span className="projeto-linha__resumo">{p.resumo}</span>
                  </span>
                </Link>
              </li>
            ))}
          </ul>
        </section>
      ))}
    </div>
  );
}
