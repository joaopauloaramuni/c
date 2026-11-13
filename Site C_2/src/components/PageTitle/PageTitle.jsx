import "./PageTitle.css";

// Título de página: um comentário com o período, o título e o subtítulo
export default function PageTitle({ titulo, subtitulo, children, ano }) {
  return (
    <header className="titulo-pagina">
      {ano && (
        <p className="titulo-pagina__ano">
          <span className="titulo-pagina__barra">{"/*"}</span> {ano} <span className="titulo-pagina__barra">{"*/"}</span>
        </p>
      )}
      <h1>{titulo}</h1>
      {subtitulo && <p className="titulo-pagina__sub">{subtitulo}</p>}
      {children}
    </header>
  );
}
