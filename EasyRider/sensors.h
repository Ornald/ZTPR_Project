#ifndef SENSORS_H
#define SENSORS_H

#include "position.h"

class Sensors
{
private:
    Position pCarPosition;
    int iCarNextMove;
    int iRoadID;
    int iActualSpeed;
    int iCarID;
    int iCarType;
public:
    Sensors(Position _carPosition,int _carNectMove,int _roadID,int _actualSpeed,int _carID,int _carType);
    void set_CarPosition(Position _carPosition);
    void set_CarNextMove(int _nextMove);
    void set_RoadID(int _roadID);
    void set_ActualSpeed(int _actualspeed);
    void set_CarID(int _ID);
    int get_CarNextMove();
    int get_RoadID();
    int get_ActualSpeed();
    int get_CarID();
    Position get_CarPosition();


};

#endif // SENSORS_H
