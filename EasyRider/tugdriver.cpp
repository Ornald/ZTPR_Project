#include "tugdriver.h"

TugDriver::TugDriver(int _orientation, int _maxspeed,QGraphicsScene& _scene)
{
    DriverCar=new TugCar(_orientation,_maxspeed);
    _scene.addItem(DriverCar);
}

TugDriver::~TugDriver()
{

}
