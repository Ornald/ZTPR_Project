#include "position.h"



Position::Position(int X, int Y)
{
    iX=X;
    iY=Y;
}

Position::Position()
{

}

void Position::set_X(int X)
{
    iX=X;

}

void Position::set_Y(int Y)
{
    iY=Y;
}

int Position::get_X()
{
    return iX;
}

int Position::get_Y()
{
    return iY;
}
