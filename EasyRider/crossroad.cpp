#include "crossroad.h"

CrossRoad::CrossRoad(int _crossroadID, int _orientation, int _posR, int _posL)
{
    iCrossroadID=_crossroadID;
    iOrientation=_orientation;
    iPosR=_posR;
    iPosL=_posL;
}

int CrossRoad::get_cross_position(int _way)
{
    if (_way==1)
        return iPosR;
    else if (_way==2)
        return  iPosL;
    return 0;
}

int CrossRoad::get_crossroadID()
{
    return iCrossroadID;
}

int CrossRoad::get_orientation()
{
    return iOrientation;
}
