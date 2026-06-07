# 🗡️ Dungeon

> Um roguelike de terminal escrito **do zero em C** — projeto de aprendizado pra entender a linguagem desde os fundamentos.

## Sobre

Depois de construir uma API em Go, este projeto desce uma camada: aprender **C** de baixo pra cima, construindo um dungeon crawler de terminal. O foco não é o jogo em si, e sim entender o que linguagens de mais alto nível escondem — memória, ponteiros, gerência manual de recursos e como o computador funciona de fato.

O projeto é construído **card a card**, cada um amarrando um fundamento do C a uma peça do jogo, sempre com a teoria por trás.

## Status

🚧 Em construção (projeto de aprendizado).

**Concluído:**
- ✅ **Card 0 — Ambiente e o primeiro programa:** toolchain configurada, primeiro programa compilado e rodando (`Hello, World!`), e o modelo de compilação do C entendido (pré-processador → compilador → assembler → linker → binário ELF).

## Como compilar e rodar

Pré-requisitos: `gcc` (pacote `build-essential`) num ambiente Linux ou WSL.

```bash
gcc -Wall dungeon.c -o dungeon
./dungeon
```

- `-Wall` liga os avisos do compilador (bom hábito).
- `-o dungeon` nomeia o executável de saída.
- `./dungeon` executa o binário gerado.

## Roadmap

| Card | Tema | Fundamento de C |
| ---- | ---- | --------------- |
| 0 | Ambiente e primeiro programa | compilação, ELF, toolchain |
| 1 | Tipos, variáveis e a memória | tipos primitivos, `sizeof`, ASCII |
| 2 | Controle de fluxo e game loop | `if`/`switch`/laços, entrada de teclado |
| 3 | Arrays e o mapa | arrays 1D/2D, strings, `\0` |
| 4 | Ponteiros | `&`, `*`, aritmética de ponteiros |
| 5 | Funções e organização | protótipos, headers, stack, linker |
| 6 | Structs e memória dinâmica | `struct`, `malloc`/`free`, heap |
| 7 | Combate e jogo completo | estado do jogo, colisão |
| 8 | Terminal de verdade (extra) | `ncurses`, modos de terminal |

## Nota de ambiente (WSL)

Compile e rode **dentro do sistema de arquivos do Linux** (`~/...`), **não** em `/mnt/c` ou `/mnt/d`. Binários ELF compilados na partição montada do Windows podem ser corrompidos e falhar com `exec format error` ao executar.

---

_Projeto de fim de semana feito para aprender C, dos fundamentos pra cima._