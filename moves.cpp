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

int sgn(int a){
    return (a < 0 ? -1 : 1);
}

bool onBoard(Square move){
    return (move.col >= 1 && move.col <= 8) && (move.row >= 1 && move.row <= 8);
}

bool canEnPassant(Square to, int pawnCoef){
    if(prevEnPassant == NULL)
        return false;
    if(board[to.row - pawnCoef][to.col] == prevEnPassant)
        return true;
    return false;
}

bool knightMove(Square from, Square to){
    if(!onBoard(from) || !onBoard(to))
        return false;

    int difR = from.row - to.row, difC = from.col - to.col;
    if(difR < 0)
        difR = -difR;
    if(difC < 0)
        difC = -difC;

    if(difC + difR == 3 && difC != difR && difC && difR)
        return true;

    return false;
}

bool bishopMove(Square from, Square to){
    if(!onBoard(from) || !onBoard(to) || from == to)
        return false;

    int difR = to.row - from.row, difC = to.col - from.col;
    if(difR != difC && difR != -difC)
        return false;
    
    Square aux = from;
    while(!(aux == to)){
        aux.row += sgn(difR);
        aux.col += sgn(difC);

        if(!(aux == to))
            if(board[aux.row][aux.col] != NULL)
                return false;
    }

    return true;
}

bool rockMove(Square from, Square to){
    if(!onBoard(from) || !onBoard(to) || from == to)
        return false;

    int difR = to.row - from.row, difC = to.col - from.col;
    if(difR != 0 && difC != 0)
        return false;
    
    Square aux = from;
    if(difR == 0){
        while(!(aux == to)){
            aux.col += sgn(difC);

            if(!(aux == to))
                if(board[aux.row][aux.col] != NULL)
                    return false;
        }
    }else{
        while(!(aux == to)){
            aux.row += sgn(difR);

            if(!(aux == to))
                if(board[aux.row][aux.col] != NULL)
                    return false;
        }
    }

    return true;
}

bool queenMove(Square from, Square to){
    if(!onBoard(from) || !onBoard(to) || from == to)
        return false;

    int difR = to.row - from.row, difC = to.col - from.col;
    if(difR != 0 && difC != 0 && difR != difC && difR != -difC)
        return false;
    
    Square aux = from;
    if(difR == 0){
        while(!(aux == to)){
            aux.col += sgn(difC);

            if(!(aux == to))
                if(board[aux.row][aux.col] != NULL)
                    return false;
        }
    }else if(difC == 0){
        while(!(aux == to)){
            aux.row += sgn(difR);

            if(!(aux == to))
                if(board[aux.row][aux.col] != NULL || !onBoard(aux))
                    return false;
        }
    }else{
        while(!(aux == to)){
        aux.row += sgn(difR);
        aux.col += sgn(difC);

        if(!(aux == to))
            if(board[aux.row][aux.col] != NULL || !onBoard(aux))
                return false;
        }
    }

    return true;
}

bool canMove(char *s, Square to, Square &from, int color){
    int pawnCoef = 1;
    if(color == 2)
        pawnCoef = -1;

    if(s[0] == 'N'){
        if(!isPiece(board[from.row][from.col], color, 'n'))
            return false;
        if(board[to.row][to.col] != NULL)
            if(board[to.row][to.col]->color == color)
                return false;

        if(knightMove(from, to)){
            delete board[to.row][to.col];
            board[to.row][to.col] = NULL;
            return true;
        }

        return false;
    }

    if(s[0] == 'B'){
        if(!isPiece(board[from.row][from.col], color, 'b'))
            return false;

        if(board[to.row][to.col] != NULL)
            if(board[to.row][to.col]->color == color)
                return false;

        if(bishopMove(from, to)){
            delete board[to.row][to.col];
            board[to.row][to.col] = NULL;
            return true;
        }

        return false;
    }

    if(s[0] == 'R'){
        if(!isPiece(board[from.row][from.col], color, 'r'))
            return false;

        if(board[to.row][to.col] != NULL)
            if(board[to.row][to.col]->color == color)
                return false;

        if(rockMove(from, to)){
            delete board[to.row][to.col];
            board[to.row][to.col] = NULL;
            return true;
        }

        return false;
    }

    if(s[0] == 'Q'){
        if(!isPiece(board[from.row][from.col], color, 'q'))
            return false;

        if(board[to.row][to.col] != NULL)
            if(board[to.row][to.col]->color == color)
                return false;

        if(queenMove(from, to)){
            delete board[to.row][to.col];
            board[to.row][to.col] = NULL;
            return true;
        }

        return false;
    }
    
    if((board[to.row][to.col] != NULL || canEnPassant(to, pawnCoef))){//trying to capture a piece
        Piece *goingToCapture;
        if(board[to.row][to.col] != NULL)
            goingToCapture = board[to.row][to.col];
        else
            goingToCapture = prevEnPassant;

        if(goingToCapture->color == color)//you can't capture your own piece
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
            Square aux = goingToCapture->getPos();
            delete goingToCapture;
            board[aux.row][aux.col] = NULL;
            return true;
        }

        if(isOwnPawn2){
            from = {to.row - pawnCoef, to.col + 1};
            Square aux = goingToCapture->getPos();
            delete goingToCapture;
            board[aux.row][aux.col] = NULL;
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
            enPassant = a2;
            return true;
        }

        return false;
    }

    return false;
}