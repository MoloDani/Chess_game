#include "pieces.h"
#include <iostream>
#include "board.h"

using namespace std;

Piece::Piece(int a, int b, int c, char n) : row(a), col(b), color(c), name(n), notMoved(true){}

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
}

Pawn::Pawn(int a, int b, int c) : Piece(a, b, c, 'p'){}

//TODO: add en-passant logic