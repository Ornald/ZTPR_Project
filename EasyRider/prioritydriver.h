#ifndef PRIORITYDRIVER_H
#define PRIORITYDRIVER_H
#include "driver.h"
#include "prioritycar.h"
class PriorityDriver : public Driver
{
public:
    PriorityDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID);
    ~PriorityDriver();
private:

};

#endif // PRIORITYDRIVER_H
