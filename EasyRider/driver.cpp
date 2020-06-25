#include "driver.h"


Driver::Driver()
{

    find_way();

}

Driver::~Driver()
{

}

void Driver::find_way()
{
    //to do normal car
    srand (time(NULL));

    for (int it=0;it<5;it++)
    {
        iWayTable[it]=rand()%3;
        qDebug()<<iWayTable[it]<<endl;
    }


}
Position Driver::start_postion()
{
    Position _startPosition(0,0);
    switch (iStartIndex)
    {
    case 0:
        _startPosition.set_X(384);
        _startPosition.set_Y(880);
        break;
    case 1:
        _startPosition.set_X(830);
        _startPosition.set_Y(880);
        break;
    case 2:
        _startPosition.set_X(1210);
        _startPosition.set_Y(546);
        break;
    case 3:
        _startPosition.set_X(1210);
        _startPosition.set_Y(206);
        break;
    case 4:
        _startPosition.set_X(796);
        _startPosition.set_Y(-90);
        break;
    case 5:
        _startPosition.set_X(350);
        _startPosition.set_Y(-90);
        break;
    case 6:
        _startPosition.set_X(-50);
        _startPosition.set_Y(240);
        break;
    case 7:
        _startPosition.set_X(-50);
        _startPosition.set_Y(580);
        break;

    }
    return _startPosition;
}

void Driver::set_start_index(int _startIndex)
{
    iStartIndex=_startIndex;

}

int Driver::get_start_index()
{
    return iStartIndex;
}

void Driver::next_move()
{



 DriverCar->move();
 qDebug()<<DriverCar->pos().y()<<endl;
}
