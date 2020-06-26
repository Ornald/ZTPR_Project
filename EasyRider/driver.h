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
    Position pCurrentPosition;
    void set_current_position();
    void check_crossroad_position(int _diffPosition);

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
    bool check_if_out_board();







};

#endif // DRIVER_H
