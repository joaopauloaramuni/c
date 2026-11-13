// localStorage com try/catch (modo privado e navegadores com storage bloqueado)
export function ler(chave) {
  try {
    return localStorage.getItem(chave);
  } catch {
    return null;
  }
}

export function gravar(chave, valor) {
  try {
    localStorage.setItem(chave, valor);
  } catch {
    // sem storage: o tema volta a seguir o sistema na próxima visita
  }
}
