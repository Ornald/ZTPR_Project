#include "normaldriver.h"

NormalDriver::NormalDriver(int _orientation, int _maxspeed,QGraphicsScene& _scene)
{
    DriverCar=new NormalCar(_orientation,_maxspeed);
    _scene.addItem(DriverCar);
}

NormalDriver::~NormalDriver()
{
    delete DriverCar;
}
