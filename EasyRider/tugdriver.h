#ifndef TUGDRIVER_H
#define TUGDRIVER_H

#include "driver.h"
#include "tugcar.h"
class TugDriver : public Driver
{
public:
    TugDriver(int _orientation, int _maxspeed,QGraphicsScene& _scene);
    ~TugDriver();
private:

};

#endif // TUGDRIVER_H
