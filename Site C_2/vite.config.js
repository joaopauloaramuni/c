import fs from "node:fs";
import path from "node:path";
import react from "@vitejs/plugin-react";
import { defineConfig } from "vite";

// Arquivos auxiliares do pdf.js (wasm, cmaps e fontes padrão). Os PDFs escaneados dos artigos
// usam imagens JBIG2, que só são decodificadas com o jbig2.wasm. Servimos esses arquivos direto
// de node_modules em /pdfjs/ (dev) e copiamos para dist/pdfjs/ no build, sempre na mesma versão
// do pdf.js usada pelo react-pdf.
const PDFJS_DIR = path.dirname(fileURLToPathSafe(import.meta.resolve("pdfjs-dist/package.json")));
const PASTAS = ["wasm", "cmaps", "standard_fonts", "iccs"];

function fileURLToPathSafe(url) {
  return decodeURIComponent(new URL(url).pathname);
}

function pdfjsAssets() {
  return {
    name: "pdfjs-assets",
    configureServer(server) {
      server.middlewares.use("/pdfjs", (req, res, next) => {
        const arquivo = path.join(PDFJS_DIR, decodeURIComponent(req.url.split("?")[0]));
        if (!arquivo.startsWith(PDFJS_DIR) || !fs.existsSync(arquivo) || fs.statSync(arquivo).isDirectory()) return next();
        if (arquivo.endsWith(".wasm")) res.setHeader("Content-Type", "application/wasm");
        fs.createReadStream(arquivo).pipe(res);
      });
    },
    writeBundle(opcoes) {
      for (const pasta of PASTAS) {
        const origem = path.join(PDFJS_DIR, pasta);
        if (fs.existsSync(origem)) fs.cpSync(origem, path.join(opcoes.dir, "pdfjs", pasta), { recursive: true });
      }
    },
  };
}

// https://vite.dev/config/
export default defineConfig({
  plugins: [react(), pdfjsAssets()],
  build: {
    chunkSizeWarningLimit: 1200,
  },
});
