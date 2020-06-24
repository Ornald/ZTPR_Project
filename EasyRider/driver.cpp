#include "driver.h"


Driver::Driver()
{

}

Driver::~Driver()
{

}
void Driver::start_postion(Position _startPosition)
{//Pozycja 1
    //setPos(384,880);
    //pozycja 2
    //setPos(350,-90);
    //pozycja 3
    //setPos(830,880);
    //pozycja 4
    //setPos(796,-90);
    //pozycja 5
    //setPos(-50,240);
    //pozycja 6
    //setPos(-50,580);
    //pozycja 7
    //setPos(1210,206);
    //pozycja 8
    //setPos(1210,546);
    switch (iStartIndex)
    {
    case 0:
        _startPosition=384;
        _y=880;
        break;
    case 1:
        _startPosition=384;
        _y=880;
        break;
    case 2:
        _startPosition=384;
        _y=880;
        break;
    case 3:
        _startPosition=384;
        _y=880;
        break;
    case 4:
        _startPosition=384;
        _y=880;
        break;
    case 5:
        _startPosition=384;
        _y=880;
        break;
    case 6:
        _startPosition=384;
        _y=880;
        break;
    case 7:
        _startPosition=384;
        _y=880;
        break;
    case 8:
        _startPosition=384;
        _y=880;
        break;
    }
}

void Driver::next_move()
{
 DriverCar->move();
}
