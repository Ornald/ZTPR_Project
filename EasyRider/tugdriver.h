#ifndef TUGDRIVER_H
#define TUGDRIVER_H

#include "driver.h"
#include "tugcar.h"
class TugDriver : public Driver
{
public:
    TugDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID);
    ~TugDriver();
private:

};

#endif // TUGDRIVER_H
