#ifndef POSITION_H
#define POSITION_H


class Position
{
public:

    Position(int X,int Y);
private:
    int iX;
    int iY;
public:
    void set_X(int X);
    void set_Y(int Y);
    int get_X();
    int get_Y();
};

#endif // POSITION_H
