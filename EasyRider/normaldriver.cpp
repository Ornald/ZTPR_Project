#include "normaldriver.h"

NormalDriver::NormalDriver (int _orientation, int _maxspeed,QGraphicsScene& _scene,int _startIndex,int _ID)
{
    iDriverID=_ID;
    set_start_index(_startIndex);
    iRoadID=_startIndex;
    Position _startPosition=start_postion();
    DriverCar=new NormalCar(_orientation,_maxspeed,_startPosition);
    _scene.addItem(DriverCar);
}

NormalDriver::~NormalDriver()
{
    delete DriverCar;
}


