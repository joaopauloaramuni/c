import { useCallback, useEffect, useRef, useState } from "react";
import { Document, Page, pdfjs } from "react-pdf";
import "react-pdf/dist/Page/TextLayer.css";
import "react-pdf/dist/Page/AnnotationLayer.css";
import {
  FiChevronLeft,
  FiChevronRight,
  FiDownload,
  FiExternalLink,
  FiMaximize,
  FiMinimize,
  FiZoomIn,
  FiZoomOut,
} from "react-icons/fi";
import "./PdfViewer.css";

// Worker do pdf.js empacotado pelo Vite (mesma versão usada pelo react-pdf)
pdfjs.GlobalWorkerOptions.workerSrc = new URL("pdfjs-dist/build/pdf.worker.min.mjs", import.meta.url).toString();

const ZOOMS = [0.5, 0.75, 1, 1.25, 1.5, 2];

// Arquivos auxiliares do pdf.js copiados pelo vite.config.js para /pdfjs/
const OPCOES_PDF = {
  wasmUrl: "/pdfjs/wasm/",
  cMapUrl: "/pdfjs/cmaps/",
  cMapPacked: true,
  standardFontDataUrl: "/pdfjs/standard_fonts/",
  iccUrl: "/pdfjs/iccs/",
};

export default function PdfViewer({ arquivo, titulo, pagina = 1, onPagina }) {
  const caixa = useRef(null);
  const palco = useRef(null);
  const [total, setTotal] = useState(0);
  const [largura, setLargura] = useState(800);
  const [altura, setAltura] = useState(600);
  const [proporcao, setProporcao] = useState(0.75);
  const [zoom, setZoom] = useState(1);
  const [cheia, setCheia] = useState(false);
  const [erro, setErro] = useState(null);
  const [digitada, setDigitada] = useState(String(pagina));
  const [base, setBase] = useState(pagina);

  // Página mudou por fora (botões, setas, URL): atualiza o campo durante o render
  if (base !== pagina) {
    setBase(pagina);
    setDigitada(String(pagina));
  }

  // Página ocupa a largura disponível (zoom 100% = largura do palco)
  useEffect(() => {
    const el = palco.current;
    if (!el) return;
    const medir = () => {
      setLargura(Math.max(260, Math.floor(el.clientWidth) - 32));
      // altura útil: janela menos topo do site e barra do leitor
      setAltura(Math.max(320, window.innerHeight - (document.fullscreenElement ? 90 : 170)));
    };
    const ro = new ResizeObserver(medir);
    ro.observe(el);
    window.addEventListener("resize", medir);
    return () => {
      ro.disconnect();
      window.removeEventListener("resize", medir);
    };
  }, []);

  useEffect(() => {
    const aoMudar = () => setCheia(document.fullscreenElement === caixa.current);
    document.addEventListener("fullscreenchange", aoMudar);
    return () => document.removeEventListener("fullscreenchange", aoMudar);
  }, []);

  const ir = useCallback(
    (n) => {
      if (!total) return;
      const alvo = Math.min(Math.max(1, n), total);
      onPagina?.(alvo);
      palco.current?.scrollTo({ top: 0 });
    },
    [total, onPagina],
  );

  function teclado(e) {
    if (e.target.tagName === "INPUT") return;
    if (e.key === "ArrowRight" || e.key === "PageDown") {
      e.preventDefault();
      ir(pagina + 1);
    } else if (e.key === "ArrowLeft" || e.key === "PageUp") {
      e.preventDefault();
      ir(pagina - 1);
    }
  }

  function telaCheia() {
    if (document.fullscreenElement) document.exitFullscreen();
    else caixa.current?.requestFullscreen?.();
  }

  const nivel = ZOOMS.indexOf(zoom);
  // 100% = página inteira visível nos slides (paisagem); nos artigos (retrato), largura de leitura
  const tamanhoBase = proporcao > 1 ? Math.min(largura, altura * proporcao) : Math.min(largura, 900);
  const larguraPagina = Math.round(tamanhoBase * zoom);

  return (
    <section className={`leitor ${cheia ? "leitor--cheio" : ""}`} ref={caixa} aria-label={`Leitor de PDF: ${titulo}`}>
      <div className="leitor__barra" role="toolbar" aria-label="Controles do PDF">
        <div className="leitor__grupo">
          <button type="button" className="btn btn--icon" onClick={() => ir(pagina - 1)} disabled={pagina <= 1} aria-label="Página anterior">
            <FiChevronLeft aria-hidden />
          </button>
          <form
            className="leitor__pagina"
            onSubmit={(e) => {
              e.preventDefault();
              ir(Number(digitada) || 1);
            }}
          >
            <label htmlFor="pagina-pdf" className="visually-hidden">
              Página
            </label>
            <input
              id="pagina-pdf"
              inputMode="numeric"
              value={digitada}
              onChange={(e) => setDigitada(e.target.value.replace(/\D/g, ""))}
              onBlur={() => ir(Number(digitada) || pagina)}
            />
            <span>de {total || "…"}</span>
          </form>
          <button type="button" className="btn btn--icon" onClick={() => ir(pagina + 1)} disabled={!total || pagina >= total} aria-label="Próxima página">
            <FiChevronRight aria-hidden />
          </button>
        </div>

        <div className="leitor__grupo">
          <button type="button" className="btn btn--icon" onClick={() => setZoom(ZOOMS[nivel - 1])} disabled={nivel <= 0} aria-label="Diminuir zoom">
            <FiZoomOut aria-hidden />
          </button>
          <button type="button" className="btn leitor__zoom" onClick={() => setZoom(1)} title="Tamanho padrão">
            {Math.round(zoom * 100)}%
          </button>
          <button type="button" className="btn btn--icon" onClick={() => setZoom(ZOOMS[nivel + 1])} disabled={nivel >= ZOOMS.length - 1} aria-label="Aumentar zoom">
            <FiZoomIn aria-hidden />
          </button>
        </div>

        <div className="leitor__grupo">
          <button type="button" className="btn btn--icon" onClick={telaCheia} aria-label={cheia ? "Sair da tela cheia" : "Tela cheia"}>
            {cheia ? <FiMinimize aria-hidden /> : <FiMaximize aria-hidden />}
          </button>
          <a className="btn btn--icon" href={arquivo} target="_blank" rel="noreferrer" aria-label="Abrir o PDF em outra aba">
            <FiExternalLink aria-hidden />
          </a>
          <a className="btn btn--icon" href={arquivo} download aria-label="Baixar o PDF">
            <FiDownload aria-hidden />
          </a>
        </div>
      </div>

      <div className="leitor__palco" ref={palco} tabIndex={0} onKeyDown={teclado} aria-label="Página do PDF. Use as setas para trocar de página.">
        {erro ? (
          <div className="leitor__msg">
            <p>Não foi possível abrir este PDF no leitor ({erro}).</p>
            <a className="btn btn--primary" href={arquivo} target="_blank" rel="noreferrer">
              Abrir o PDF em outra aba
            </a>
          </div>
        ) : (
          <Document
            file={arquivo}
            options={OPCOES_PDF}
            onLoadSuccess={({ numPages }) => {
              setTotal(numPages);
              if (pagina > numPages) onPagina?.(1);
            }}
            onLoadError={(e) => setErro(e.message)}
            loading={<CarregandoPdf />}
            error={<p className="leitor__msg">Não foi possível carregar o PDF.</p>}
          >
            <Page
              key={pagina}
              pageNumber={pagina}
              width={larguraPagina}
              onLoadSuccess={(pg) => setProporcao(pg.originalWidth / pg.originalHeight)}
              loading={<div className="leitor__fantasma" style={{ width: larguraPagina, height: larguraPagina / proporcao }} />}
              renderAnnotationLayer
              renderTextLayer
            />
          </Document>
        )}
      </div>
      <p className="leitor__dica muted">Dica: use as setas ← e → do teclado para trocar de página.</p>
    </section>
  );
}

function CarregandoPdf() {
  return (
    <div className="leitor__msg" role="status">
      <span className="leitor__spinner" aria-hidden />
      Carregando o PDF…
    </div>
  );
}
