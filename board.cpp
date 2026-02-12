#include "board.h"
#include "pieces.h"
#include <iostream>
#include "moves.h"

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

//computing if a certain piece is ours or opponent's
char pieceType(int color, Piece *p){
    if (color == p->color)
        return p->name + 'A' - 'a';
    return p->name;
}

//UI
void displayBoard(int color){
    cout << "\033[2J\033[H"; // TODO: find something that actually works
    //order we display board, we reverse this for the opposite color
    int index[] = {1, 2, 3, 4, 5, 6, 7, 8};
    if(color == 1)
        reverse1(index, 7);

    cout << "  +---+---+---+---+---+---+---+---+\n";
    for(int i = 0; i < 8 ; i++){
        cout << index[i] << " |";
        for(int j = 7; j >= 0; j--){
            if(board[index[i]][index[j]] != NULL)
                cout << " " << pieceType(color, board[index[i]][index[j]]) << " |";
            else
                cout << "   |";
        }
        cout << "\n";
        cout << "  +---+---+---+---+---+---+---+---+\n";
    }
    cout <<"  +";
    for(int i = 7; i >= 0; i--)
        cout << " " << char('a' + index[i] - 1) << " +";
    cout << "\n\n";
}

void initBoard(){
    //standard chess board
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

void handleInput(int color){
    char notation[100];
    bool moved = false;

    while(!moved){
        cin.getline(notation, 100);

        Square moveTo = {notation[1] - '0', notation[0] - 'a' + 1}, moveFrom;
        char piceType;

        if(canMove(notation, moveTo, moveFrom, color)){
            board[moveFrom.row][moveFrom.col]->movePiece(moveTo);
            moved = true;
        }
    }
}

