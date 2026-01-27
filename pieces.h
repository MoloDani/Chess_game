#ifndef PIECES_H
#define PIECES_H

struct Square{
    int row, col;
};

class Piece{
    protected:
        int row, col;
    public:
        int color; //1 - white, 2 - black
        char name;
        Piece(int a, int b, int c, char n);
        bool legalMove(Square move);
        void movePiece(Square move);
        void captured();
        ~Piece();
};

class Pawn : public Piece{
    private:
        bool firstMove;
    public:
        Pawn(int a, int b, int c);
        bool legalMove(Square move);
        void movePiece(Square move);
};

#endif