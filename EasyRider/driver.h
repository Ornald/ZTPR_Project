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
    bool bStuck=0;
    void set_current_position();
    void check_crossroad_position(int _diffPosition);
    virtual void check_trafficlights(int _difference, int _lightStatus);
    void adjust_speed(int _diff);
    virtual void find_way();
    int iLane=0;
    int iNextBrokenCarID=-1;
    int iPicked=0;
    int iTowCarID=-1;
    void set_picked();

public:
    Driver();
    virtual ~Driver();

     void overtake();
    bool check_if_stuck();

    virtual void next_move();
    Position start_postion();
    void set_start_index(int _startIndex);
    int get_start_index();
    bool check_if_out_board();
    int get_roadID();
    int get_DriverID();
    void set_TowCarID(int _towCarID);
    int get_picked();
    static int iCarnumber;
   virtual bool can_be_damaged();
    virtual void engine_malfunction();
    virtual int picked_up_id();







};

#endif // DRIVER_H
