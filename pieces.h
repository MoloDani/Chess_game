#ifndef PIECES_H
#define PIECES_H

/*
    Class for a square on the board;
*/
struct Square{
    int row, col;

    bool operator==(const Square &other) const{
        return row == other.row && col == other.col;
    }
};

/*
    Class for a generic piece
*/
class Piece{
    protected:
        int row, col, score;
    public:
        bool notMoved;
        int color; //1 - white, 2 - black
        char name;
        Piece(int a, int b, int c, char n, int sc);
        void movePiece(Square move);
        void captured();
        Square getPos();
        ~Piece();
};

class Pawn : public Piece{
    public:
        Pawn(int a, int b, int c);
};

class Knight : public Piece{
    public:
        Knight(int a, int b, int c);
};

class Bishop : public Piece{
    public:
        Bishop(int a, int b, int c);
};

class Rock : public Piece{
    public:
        Rock(int a, int b, int c);
};

class Queen : public Piece{
    public:
        Queen(int a, int b, int c);
};

class King : public Piece{
    public:
        King(int a, int b, int c);
};

#endif