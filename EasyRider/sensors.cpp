#include "sensors.h"

Sensors::Sensors()
{

}

void Sensors::set_CarPosition(Position _carPosition)
{
 pCarPosition=_carPosition;
}

void Sensors::set_CarNextMove(int _nextMove)
{
    iCarNextMove=_nextMove;
}

void Sensors::set_RoadID(int _roadID)
{
    iRoadID=_roadID;
}

void Sensors::set_ActualSpeed(int _actualspeed)
{
    iActualSpeed=_actualspeed;
}

void Sensors::set_CarID(int _ID)
{
    iCarID=_ID;
}

int Sensors::get_CarNextMove()
{
    return iCarNextMove;
}

int Sensors::get_RoadID()
{
    return iRoadID;
}

int Sensors::get_ActualSpeed()
{
    return iActualSpeed;
}

int Sensors::get_CarID()
{
    return iCarID;

}

Position Sensors::get_CarPosition()
{
 return pCarPosition;
}
