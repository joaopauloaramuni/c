import { Link } from "react-router-dom";
import CodeBlock from "../components/CodeBlock/CodeBlock.jsx";

export default function NaoEncontrada() {
  return (
    <div className="container page">
      <h1>Página não encontrada</h1>
      <p className="muted">O endereço digitado não existe neste site. Ele pode ter mudado na versão 2.0.</p>
      <CodeBlock
        arquivo="404.c"
        codigo={`#include <stdio.h>\n\nint main(void) {\n    printf("Erro 404: pagina nao encontrada\\n");\n    return 404;\n}`}
      />
      <Link className="btn btn--primary" to="/">
        Voltar ao início
      </Link>
    </div>
  );
}
