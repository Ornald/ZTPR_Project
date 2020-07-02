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
    int iOrientation;
    int iMaxSpeed;
    int iStatus=1;
public:
    Sensors(Position _carPosition,int _carNectMove,int _roadID,int _actualSpeed,int _carID,int _orientation,int _carType, int _maxSpeed);
    void set_CarPosition(Position _carPosition);
    void set_CarNextMove(int _nextMove);
    void set_RoadID(int _roadID);
    void set_ActualSpeed(int _actualspeed);
    void set_CarID(int _ID);
    void set_Orientation(int _orientation);
    void set_status(int _status);
    int get_CarNextMove();
    int get_RoadID();
    int get_ActualSpeed();
    int get_CarID();
    int get_Orientation();
    int get_MaxSpeed();
    int get_carType();
    int get_status();
    Position get_CarPosition();
    bool operator== (int _carID){return this->iCarID==_carID;};


};

#endif // SENSORS_H
