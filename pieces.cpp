#include "pieces.h"
#include <iostream>

using namespace std;

bool onBoard(Square move){
    return (move.col >= 1 && move.col <= 8) && (move.row >= 1 && move.row <= 8);
}

Piece::Piece(int a, int b, int c) : row(a), col(b), color(c){}

void Piece::movePiece(Square move){
    Piece::col = move.col;
    Piece::row = move.row;
}

Pawn::Pawn(int a, int b, int c) : Piece(a, b, c), firstMove(true){}

bool Pawn::legalMove(Square move){
    if(!onBoard(move))
        return false;
    if(move.col != Pawn::col)
        return false;

    if(Pawn::color == 1) //TODO: verify if i can take the piece(i can move diagonally)
        return ((move.row < Pawn::row) && Pawn::row - move.row <= 1 + Pawn::firstMove);
    else
        return ((move.row > Pawn::row) && move.row - Pawn::row <= 1 + Pawn::firstMove);
}

void Pawn::movePiece(Square move){
    Pawn::col = move.col;
    Pawn::row = move.row;
    Pawn::firstMove = false;
}