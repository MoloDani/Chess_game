#include "pieces.h"
#include <iostream>
#include "board.h"

using namespace std;

bool onBoard(Square move){
    return (move.col >= 1 && move.col <= 8) && (move.row >= 1 && move.row <= 8);
}

Piece::Piece(int a, int b, int c, char n) : row(a), col(b), color(c), name(n), notMoved(true){}

Piece::~Piece(){
    cout << "You took my piece!\n";
}

bool Piece::legalMove(Square move){ }

void Piece::movePiece(Square move){
    if(board[move.row][move.col] != NULL){
        delete board[move.row][move.col];
    }

    row = move.row;
    col = move.col;

    notMoved = false;

    board[move.row][move.col] = this;
}

Pawn::Pawn(int a, int b, int c) : Piece(a, b, c, 'p'), coef(c == 1 ? 1 : -1){}

//TODO: add en-passant logic