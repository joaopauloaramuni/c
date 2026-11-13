import { useMemo, useState } from "react";
import { FiCheck, FiCopy } from "react-icons/fi";
import { destacar } from "./highlight.js";
import "./CodeBlock.css";

export default function CodeBlock({ codigo, linguagem = "c", arquivo, numeros = true }) {
  const [copiado, setCopiado] = useState(false);
  const html = useMemo(() => destacar(codigo.replace(/\t/g, "    ").replace(/\s+$/, ""), linguagem), [codigo, linguagem]);
  const linhas = useMemo(() => codigo.replace(/\s+$/, "").split("\n").length, [codigo]);

  async function copiar() {
    try {
      await navigator.clipboard.writeText(codigo);
      setCopiado(true);
      setTimeout(() => setCopiado(false), 1800);
    } catch {
      setCopiado(false);
    }
  }

  return (
    <figure className="codigo">
      <figcaption className="codigo__topo">
        <span className="codigo__arquivo">{arquivo || linguagem.toUpperCase()}</span>
        <span className="codigo__info">{linhas} {linhas === 1 ? "linha" : "linhas"}</span>
        <button type="button" className="codigo__copiar" onClick={copiar} aria-live="polite">
          {copiado ? <FiCheck aria-hidden /> : <FiCopy aria-hidden />}
          {copiado ? "Copiado" : "Copiar"}
        </button>
      </figcaption>
      <div className="codigo__corpo">
        {numeros && (
          <pre className="codigo__numeros" aria-hidden>
            {Array.from({ length: linhas }, (_, i) => i + 1).join("\n")}
          </pre>
        )}
        <pre className="codigo__fonte">
          <code className={`hljs language-${linguagem}`} dangerouslySetInnerHTML={{ __html: html }} />
        </pre>
      </div>
    </figure>
  );
}
