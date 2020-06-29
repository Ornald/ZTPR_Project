#include "prioritydriver.h"

PriorityDriver::PriorityDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map &_map)
{
    iTotalMaxSpeed=_maxspeed;
    iCurrentMaxSpeed=_maxspeed;
    DriverMap=&_map;
    iDriverID=_ID;
    set_start_index(_startIndex);
    iRoadID=_startIndex;
    Position _startPosition=start_postion();
    DriverCar=new PriorityCar(_orientation,_maxspeed, _startPosition);
    _scene.addItem(DriverCar);
}

PriorityDriver::~PriorityDriver()
{
    delete  DriverCar;

}
