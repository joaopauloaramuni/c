import { lazy, Suspense } from "react";
import { Route, Routes } from "react-router-dom";
import Layout from "./components/Layout/Layout.jsx";
import Home from "./pages/Home/Home.jsx";
import Aluno from "./pages/Aluno/Aluno.jsx";
import AlunoPrograma from "./pages/Aluno/AlunoPrograma.jsx";
import AlunoCodigos from "./pages/Aluno/AlunoCodigos.jsx";
import AlunoAulas from "./pages/Aluno/AlunoAulas.jsx";
import Professor from "./pages/Professor/Professor.jsx";
import ProfessorAulas from "./pages/Professor/ProfessorAulas.jsx";
import ProfessorTarefas from "./pages/Professor/ProfessorTarefas.jsx";
import Projetos from "./pages/Projetos/Projetos.jsx";
import Artigos from "./pages/Artigos/Artigos.jsx";
import Nostalgia from "./pages/Nostalgia/Nostalgia.jsx";
import NaoEncontrada from "./pages/NaoEncontrada.jsx";
import "./pages/pages.css";

// Páginas pesadas (pdf.js e o renderizador de Markdown) só carregam quando abertas
const Leitor = lazy(() => import("./pages/Leitor/Leitor.jsx"));
const Projeto = lazy(() => import("./pages/Projetos/Projeto.jsx"));

function Carregando() {
  return (
    <div className="container page muted" role="status">
      Carregando…
    </div>
  );
}

export default function App() {
  return (
    <Suspense fallback={<Carregando />}>
      <Routes>
        <Route element={<Layout />}>
          <Route index element={<Home />} />
          <Route path="aluno" element={<Aluno />} />
          <Route path="aluno/programas/:slug" element={<AlunoPrograma />} />
          <Route path="aluno/codigos" element={<AlunoCodigos />} />
          <Route path="aluno/codigos/:slug" element={<AlunoCodigos />} />
          <Route path="aluno/aulas" element={<AlunoAulas />} />
          <Route path="professor" element={<Professor />} />
          <Route path="professor/aulas" element={<ProfessorAulas />} />
          <Route path="professor/tarefas" element={<ProfessorTarefas />} />
          <Route path="professor/projetos" element={<Projetos />} />
          <Route path="professor/projetos/:slug" element={<Projeto />} />
          <Route path="artigos" element={<Artigos />} />
          <Route path="ler/:colecao/:id" element={<Leitor />} />
          <Route path="nostalgia" element={<Nostalgia />} />
          <Route path="*" element={<NaoEncontrada />} />
        </Route>
      </Routes>
    </Suspense>
  );
}
