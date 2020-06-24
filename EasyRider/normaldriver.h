#ifndef NORMALDRIVER_H
#define NORMALDRIVER_H
#include "driver.h"
#include "normalcar.h"
class NormalDriver : public Driver
{
public:
    NormalDriver(int _orientation,int _maxspeed, QGraphicsScene& _scene);
    ~NormalDriver();
private:


};

#endif // NORMALDRIVER_H
