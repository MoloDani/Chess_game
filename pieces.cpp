#include "pieces.h"
#include <iostream>
#include "board.h"

using namespace std;

bool onBoard(Square move){
    return (move.col >= 1 && move.col <= 8) && (move.row >= 1 && move.row <= 8);
}

Piece::Piece(int a, int b, int c, char n) : row(a), col(b), color(c), name(n){}

Piece::~Piece(){
    cout << "You took my piece!\n";
    delete this;
}

void Piece::addPossibleMove(Square move){
    if(onBoard(move))
        canMoveTo[move.row][move.col].insert(this);
}

bool Piece::legalMove(Square move){
    return canMoveTo[move.row][move.col].count(this);
}

void Piece::markPosMoves(){
    return;
}

void Piece::movePiece(Square move){
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            if(canMoveTo[i][j].count(this))
                canMoveTo[i][j].erase(this);
    
    row = move.row;
    col = move.col;

    board[row][col] = this;

    markPosMoves();
}

Pawn::Pawn(int a, int b, int c) : Piece(a, b, c, 'p'), coef(c == 1 ? 1 : -1){
    addPossibleMove({row + 1 * coef, col});
    addPossibleMove({row + 2 * coef, col});
}

void Pawn::markPosMoves(){
    addPossibleMove({col, row + 1 * coef});
}