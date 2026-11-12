// highlight.js só com as linguagens usadas no site (bundle menor)
import hljs from "highlight.js/lib/core";
import c from "highlight.js/lib/languages/c";
import cpp from "highlight.js/lib/languages/cpp";
import bash from "highlight.js/lib/languages/bash";
import plaintext from "highlight.js/lib/languages/plaintext";

hljs.registerLanguage("c", c);
hljs.registerLanguage("cpp", cpp);
hljs.registerLanguage("bash", bash);
hljs.registerLanguage("plaintext", plaintext);

export function destacar(codigo, linguagem) {
  const lang = hljs.getLanguage(linguagem) ? linguagem : "plaintext";
  return hljs.highlight(codigo, { language: lang }).value;
}
