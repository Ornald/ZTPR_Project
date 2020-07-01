#ifndef DRIVER_H
#define DRIVER_H

#include <QGraphicsScene>
#include <car.h>
#include "position.h"
#include "map.h"
#include "sensors.h"

class Driver
{
private:


protected:

    int iWayTable[5];
    int iStartIndex;
    int iDriverID=0;
    Car *DriverCar;
    Sensors *sCarSensor;
    int iRoadID=0;
    int iCrossRoadCnt=0;
    int iCarType;
    int iTotalMaxSpeed=0;
    int iCurrentMaxSpeed=0;
    Map *DriverMap;
    Position pCurrentPosition;
    void set_current_position();
    void check_crossroad_position(int _diffPosition);
    void check_trafficlights(int _difference, int _lightStatus);
    void adjust_speed(int _diff);

public:
    Driver();
    virtual ~Driver();
    void check_right_of_way();
    void check_right_to_overtake();
    void find_way();
    void next_move();
    Position start_postion();
    void set_start_index(int _startIndex);
    int get_start_index();
    bool check_if_out_board();
    static int iCarnumber;







};

#endif // DRIVER_H
