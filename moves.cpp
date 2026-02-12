#include "moves.h"
#include "pieces.h"
#include "board.h"
#include <iostream>

using namespace std;

bool isPiece(Piece *a, int color, char p){
    if(a == NULL)
        return false;
    return a->color == color && a->name == p;
}

bool onBoard(Square move){
    return (move.col >= 1 && move.col <= 8) && (move.row >= 1 && move.row <= 8);
}

bool canMove(char *s, Square to, Square &from, int color){
    int pawnCoef = 1;
    if(color == 2)
        pawnCoef = -1;
    
    if(board[to.row][to.col] != NULL){//trying to capture a piece
        if(board[to.row][to.col]->color == color)//you can't capture your own piece
            return false;

        Piece *a1 = NULL, *a2 = NULL;

        if(onBoard({to.row - pawnCoef, to.col - 1}))
            a1 = board[to.row - pawnCoef][to.col - 1];
        if(onBoard({to.row - pawnCoef, to.col + 1}))
            a2 = board[to.row - pawnCoef][to.col + 1];

        bool isOwnPawn1 = isPiece(a1, color, 'p'), isOwnPawn2 = isPiece(a2, color, 'p');

        if(isOwnPawn1 && isOwnPawn2){
            cout << "Be more specific";
            return false;
        }

        if(isOwnPawn1){
            from = {to.row - pawnCoef, to.col - 1};
            return true;
        }

        if(isOwnPawn2){
            from = {to.row - pawnCoef, to.col - 2};
            return true;
        }
        
        return false;
    }else{
        Piece *a1 = NULL, *a2 = NULL;

        if(onBoard({to.row - pawnCoef, to.col}))
            a1 = board[to.row - pawnCoef][to.col];
        if(onBoard({to.row - 2 * pawnCoef, to.col}))
            a2 = board[to.row - 2 * pawnCoef][to.col];

        if(isPiece(a1, color, 'p')){
            from = {to.row - pawnCoef, to.col};
            return true;
        }

        if(isPiece(a2, color, 'p')){
            from = {to.row - 2 * pawnCoef, to.col};
            return true;
        }

        return false;
    }

    return false;
}