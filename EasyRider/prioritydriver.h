#ifndef PRIORITYDRIVER_H
#define PRIORITYDRIVER_H
#include "driver.h"

#include "normalcar.h"
class PriorityDriver : public Driver
{
public:
    PriorityDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map &_map);
    ~PriorityDriver();
    void next_move() override;
private:
    void check_trafficlights(int _difference, int _lightStatus) override;
    void find_way() override;
    void turn_back();
    int return_move(int _move);
    int iTurned=0;


};

#endif // PRIORITYDRIVER_H
