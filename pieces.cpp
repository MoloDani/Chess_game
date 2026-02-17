#include "pieces.h"
#include <iostream>
#include "board.h"

using namespace std;

Piece::Piece(int a, int b, int c, char n, int sc) : row(a), col(b), color(c), name(n), score(sc), notMoved(true){}

Piece::~Piece(){
    cout << "You took my piece!\n";
}

void Piece::movePiece(Square move){
    if(board[move.row][move.col] != NULL){
        delete board[move.row][move.col];
    }

    //move the actual piece
    board[move.row][move.col] = this;

    //remove the last instance
    board[row][col] = NULL;

    row = move.row;
    col = move.col;
    notMoved = false;

    //TODO: add move to log
}

Square Piece::getPos(){
    return {row, col};
}

Pawn::Pawn(int a, int b, int c) : Piece(a, b, c, 'p', 1){}

Knight::Knight(int a, int b, int c) : Piece(a, b, c, 'n', 3){}

//TODO: add en-passant logic