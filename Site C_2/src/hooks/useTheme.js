import { useCallback, useEffect, useState } from "react";
import { THEME_KEY } from "../config/site.js";
import { gravar } from "../utils/storage.js";

// O index.html já aplica data-theme antes do React carregar; aqui só lemos e alternamos.
export function useTheme() {
  const [tema, setTema] = useState(() => document.documentElement.dataset.theme || "light");

  useEffect(() => {
    document.documentElement.dataset.theme = tema;
  }, [tema]);

  const alternar = useCallback(() => {
    setTema((atual) => {
      const novo = atual === "dark" ? "light" : "dark";
      gravar(THEME_KEY, novo);
      return novo;
    });
  }, []);

  return { tema, alternar };
}
