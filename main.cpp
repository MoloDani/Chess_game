#include "pieces.h"
#include "board.h"
#include <iostream>

using namespace std;

int main(){
    //TODO: a whole game of chess
    //TODO: a piece class with different functions for movement, capture
    //TODO: display system
    //TODO: don't let pieces move in check
    //TODO: don't allow illegal moves
    int turn = 1, color;
    initBoard();
    while(true){
        if(turn % 2)
            color = 1;
        else 
            color = 2;
        cout << color << "\n";
        displayBoard(color);
        handleInput(color);
        turn++;
    }
}