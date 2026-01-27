#include "board.h"
#include "pieces.h"
#include <iostream>

using namespace std;

Piece *board[9][9];

void displayBoard(int color){
    cout << "\033[2J";
    cout << "  +---+---+---+---+---+---+---+---+\n";
    for(int i = 8; i >= 1; i--){
        for(int j = 0; j <= 8; j++){
            if(j == 0)
                cout << i << " |";
            else if(board[i][j] != NULL)
                cout << " " << board[i][j]->name << " |";
            else
                cout << "   |";
        }
        cout << "\n";
        cout << "  +---+---+---+---+---+---+---+---+\n";
    }
}

void initBoard(){
    board[1][1] = new Pawn(1, 1, 1);
    board[2][1] = new Pawn(2, 1, 1);
    board[3][1] = new Pawn(3, 1, 1);
}