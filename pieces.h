#ifndef PIECES_H
#define PIECES_H

struct Square{
    int row, col;

    bool operator<(const Square& other) const{
        if(row == other.row)
            return col < other.col;
        return row < other.row;
    }
};

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
        ~Piece();
};

class Pawn : public Piece{
    public:
        Pawn(int a, int b, int c);
};

#endif