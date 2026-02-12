#ifndef BOARD_H
#define BOARD_H

class Piece;

extern Piece *board[9][9];

void displayBoard(int color);//1 - white, 2 - black
void initBoard();
void handleInput(int color);

#endif