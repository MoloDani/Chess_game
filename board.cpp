#include "board.h"
#include "pieces.h"
#include <iostream>

using namespace std;

Piece *board[9][9];

void reverse1(int *sir, int n){
    int aux;
    for(int i = 0; i <= (n - 1) / 2; i++){
        aux = sir[i];
        sir[i] = sir[n - i];
        sir[n - i] = aux;
    }
}

char pieceType(int color, Piece *p){
    if (color == p->color)
        return p->name + 'A' - 'a';
    return p->name;
}

void displayBoard(int color){
    cout << "\033[2J\033[H"; // TODO: find something that actually works
    int indici[] = {1, 2, 3, 4, 5, 6, 7, 8};
    if(color == 1)
        reverse1(indici, 7);

    cout << "  +---+---+---+---+---+---+---+---+\n";
    for(int i = 0; i < 8 ; i++){
        cout << indici[i] << " |";
        for(int j = 7; j >= 0; j--){
            if(board[indici[i]][indici[j]] != NULL)
                cout << " " << pieceType(color, board[indici[i]][indici[j]]) << " |";
            else
                cout << "   |";
        }
        cout << "\n";
        cout << "  +---+---+---+---+---+---+---+---+\n";
    }
    cout <<"  +";
    for(int i = 7; i >= 0; i--)
        cout << " " << char('a' + indici[i] - 1) << " +";
    cout << "\n\n";
}

void initBoard(){
    board[2][1] = new Pawn(2, 1, 1);
    board[2][2] = new Pawn(2, 2, 1);
    board[2][3] = new Pawn(2, 3, 1);
    board[2][4] = new Pawn(2, 4, 1);
    board[2][5] = new Pawn(2, 5, 1);
    board[2][6] = new Pawn(2, 6, 1);
    board[2][7] = new Pawn(2, 7, 1);
    board[2][8] = new Pawn(2, 8, 1);
    board[7][1] = new Pawn(7, 1, 2);
    board[7][2] = new Pawn(7, 2, 2);
    board[7][3] = new Pawn(7, 3, 2);
    board[7][4] = new Pawn(7, 4, 2);
    board[7][5] = new Pawn(7, 5, 2);
    board[7][6] = new Pawn(7, 6, 2);
    board[7][7] = new Pawn(7, 7, 2);
    board[7][8] = new Pawn(7, 8, 2);
}