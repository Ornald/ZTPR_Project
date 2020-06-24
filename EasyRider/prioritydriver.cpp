#include "prioritydriver.h"

PriorityDriver::PriorityDriver(int _orientation, int _maxspeed,QGraphicsScene& _scene)
{
    DriverCar=new PriorityCar(_orientation,_maxspeed);
    _scene.addItem(DriverCar);
}

PriorityDriver::~PriorityDriver()
{
    delete  DriverCar;
}
