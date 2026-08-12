# Chess

A two-player chess game for the terminal, written from scratch in C++ with no external libraries. Moves are entered in algebraic notation and the board redraws after each turn, oriented toward whichever player is to move.

<!-- A terminal GIF sells this better than anything else. Record one with asciinema or
     a screen recorder and drop it here:
     ![Gameplay](docs/demo.gif) -->

## The board

```
  +---+---+---+---+---+---+---+---+
8 | R | N | B | Q | K | B | N | R |
  +---+---+---+---+---+---+---+---+
7 | P | P | P | P | P | P | P | P |
  +---+---+---+---+---+---+---+---+
  ...
  + a + b + c + d + e + f + g + h +
```

Your own pieces are shown in uppercase and your opponent's in lowercase, so you can tell sides apart without colour support. The board flips between turns so the side to move always looks up the board.

## Move input

Moves use standard algebraic notation:

| Input | Meaning |
|---|---|
| `e4` | pawn to e4 — destination only |
| `Nf3` | knight to f3 |
| `Bc4` | bishop to c4 |

Illegal input is rejected and re-prompted; the turn doesn't advance until a legal move is accepted.

## Design

The code is split into three modules with a header each, so move legality, board state, and piece behaviour stay independent of one another:

| Module | Responsibility |
|---|---|
| `pieces` | `Piece` base class and the `Pawn`, `Knight`, `Bishop`, `Rock`, `Queen`, `King` subclasses — position, colour, material value, and whether the piece has moved |
| `board` | The 8×8 board as an array of `Piece*`, initial setup, rendering, and reading input |
| `moves` | Move legality: parsing notation, resolving which piece can reach a square, and validating the move |

Pieces are polymorphic and stored as base-class pointers, so the board manipulates them without knowing concrete types. Each piece tracks a `notMoved` flag — the state castling and double pawn pushes depend on — and en passant is tracked across turns as a pointer to the pawn that just became capturable.

## Building

Requires a C++ compiler; no dependencies.

```bash
git clone https://github.com/MoloDani/Chess_game.git
cd Chess_game
g++ -std=c++17 -O2 main.cpp board.cpp pieces.cpp moves.cpp -o chess
./chess
```

On Windows with MinGW, substitute `-o chess.exe`.

## Implemented

- [x] Full board setup and turn loop
- [x] Piece hierarchy with per-type movement
- [x] Algebraic notation parsing
- [x] Board rendering that flips per side
- [x] En passant state tracking

## Roadmap

- [] Check detection, and forbidding moves that leave your own king in check
- [ ] Checkmate and stalemate — the game currently has no terminal condition
- [ ] Castling
- [ ] Pawn promotion
- [ ] Disambiguating notation (`Nbd2`) and capture/check suffixes (`exd5`, `Qh5+`)
- [ ] Draw by repetition and the fifty-move rule
- [ ] Move history and undo
