# Game of Life

Implementación en C del autómata celular **Juego de la Vida** de John Conway, visualizado en la terminal con secuencias de escape ANSI.

## 🎮 Características

- Tablero de `50 × 25` celdas configurables mediante macros.
- Doble buffer (`tableroA` / `tableroB`) para actualizar estados sin errores.
- Render en terminal con cursor controlado (`\033[H`).
- Inicialización aleatoria (`rand` + `srand`).

## 📦 Requisitos

- Compilador C (GCC o Clang)
- `make` (opcional, pero recomendado)
- Terminal compatible con secuencias ANSI (Linux / macOS / WSL)

## 🚀 Compilación y ejecución

```bash
# Con Make
make
make run

# O manualmente
gcc -Wall -std=c11 -Iinclude -D_DEFAULT_SOURCE \
    src/functions.c src/program.c -o game-of-life
./game-of-life
```

Salir con `Ctrl + C`.

## 🧠 Reglas implementadas

1. Una célula **viva** con 2 o 3 vecinos vivos **sobrevive**.
2. Una célula **muerta** con exactamente 3 vecinos vivos **nace**.
3. En cualquier otro caso, la célula **muere** o permanece muerta.

## 📁 Estructura

```
.
├── include/
│   └── functions.h
├── src/
│   ├── functions.c
│   └── program.c
├── Makefile
└── README.md
```