#include "crossroad.h"

CrossRoad::CrossRoad(int _crossroadID, int _orientation, int _posR, int _posL)
{
    iCrossroadID=_crossroadID;
    iOrientation=_orientation;
    iPosR=_posR;
    iPosL=_posL;
}

CrossRoad::CrossRoad()
{

}

int CrossRoad::get_cross_position(int _way)
{
    if (_way==1)
        return iPosR;
    return iPosL;
}

int CrossRoad::get_roadID()
{
    return iCrossroadID;
}

int CrossRoad::get_orientation()
{
    return iOrientation;
}


