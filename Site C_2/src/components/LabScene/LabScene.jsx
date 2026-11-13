import laboratorio from "../../assets/laboratorio.svg?raw";
import "../../styles/lab.css";

// Ilustração do laboratório (gerada em perspectiva a partir das fotos do laboratório da PUC Minas,
// só com bancadas, monitores e móveis, sem pessoas). Fica inline para herdar as cores do tema.
export default function LabScene({ className = "" }) {
  return <div className={`lab ${className}`} aria-hidden dangerouslySetInnerHTML={{ __html: laboratorio }} />;
}
