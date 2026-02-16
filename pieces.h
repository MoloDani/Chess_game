#ifndef PIECES_H
#define PIECES_H

/*
    Class for a square on the board;
*/
struct Square{
    int row, col;
};

/*
    Class for a generic piece
*/
class Piece{
    protected:
        int row, col;
    public:
        bool notMoved;
        int color; //1 - white, 2 - black
        char name;
        Piece(int a, int b, int c, char n);
        void movePiece(Square move);
        void captured();
        Square getPos();
        ~Piece();
};

class Pawn : public Piece{
    public:
        Pawn(int a, int b, int c);
};

#endif