#include "normaldriver.h"

NormalDriver::NormalDriver (int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map & _map)
{
    iTotalMaxSpeed=_maxspeed;
    iCurrentMaxSpeed=_maxspeed;
    DriverMap=&_map;
    iDriverID=_ID;
    set_start_index(_startIndex);
    iRoadID=_startIndex;
    Position _startPosition=start_postion();
    DriverCar=new NormalCar(_orientation,_maxspeed,_startPosition);
    _scene.addItem(DriverCar);
    set_current_position();
    sCarSensor=new Sensors(pCurrentPosition,iWayTable[iCrossRoadCnt],iRoadID,DriverCar->get_actualspeed(),iDriverID,DriverCar->rotation(),iCarType,iTotalMaxSpeed);
    DriverMap->addCarSensor(sCarSensor);

}

NormalDriver::~NormalDriver()
{
    delete DriverCar;
    DriverMap->deleteCarSensor(iDriverID);

}


