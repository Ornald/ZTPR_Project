#ifndef DRIVER_H
#define DRIVER_H

#include <QGraphicsScene>
#include <car.h>
class Driver
{
private:
    int iWayTable[5];
    int iExitIndex;
    int iStartIndex;
    void start_postion();
protected:
    Car *DriverCar;

public:
    Driver();
    virtual ~Driver();
    void check_right_of_way();
    void check_right_to_overtake();
    void check_traffic_light();
    void find_way();
    void next_move();




};

#endif // DRIVER_H
