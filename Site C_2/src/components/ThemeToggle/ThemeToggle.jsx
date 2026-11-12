import { FiMoon, FiSun } from "react-icons/fi";

export default function ThemeToggle({ tema, alternar }) {
  const escuro = tema === "dark";
  return (
    <button
      type="button"
      className="btn btn--ghost btn--icon"
      onClick={alternar}
      aria-label={escuro ? "Usar tema claro" : "Usar tema escuro"}
      title={escuro ? "Tema claro" : "Tema escuro"}
    >
      {escuro ? <FiSun aria-hidden /> : <FiMoon aria-hidden />}
    </button>
  );
}
