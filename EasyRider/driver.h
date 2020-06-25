#ifndef DRIVER_H
#define DRIVER_H

#include <QGraphicsScene>
#include <car.h>
#include "position.h"
#include "map.h"

class Driver
{
private:


protected:
    int iWayTable[5];
    int iStartIndex;
    int iDriverID=0;
    Car *DriverCar;
    int iRoadID;
    int iCrossRoadCnt=0;
    Map DriverMap;

public:
    Driver();
    virtual ~Driver();
    void check_right_of_way();
    void check_right_to_overtake();
    void check_traffic_light();
    void find_way();
    void next_move();
    Position start_postion();
    void set_start_index(int _startIndex);
    int get_start_index();




};

#endif // DRIVER_H
