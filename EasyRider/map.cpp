#include "map.h"
const int speed=1;
Map::Map()
{

    int adjustment= 9*speed;

    load_crossroad(0,0,(pTurnsPositions(7).get_Y()+adjustment),(pTurnsPositions(2).get_Y()+adjustment));
    load_crossroad(1,0,(pTurnsPositions(7).get_Y()+adjustment),(pTurnsPositions(2).get_Y()+adjustment));
    load_crossroad(2,270,(pTurnsPositions(1).get_X()+adjustment),(pTurnsPositions(4).get_X()+adjustment));
    load_crossroad(3,270,(pTurnsPositions(1).get_X()+adjustment),(pTurnsPositions(4).get_X()+adjustment));
    load_crossroad(4,180,(pTurnsPositions(3).get_Y()-adjustment),(pTurnsPositions(6).get_Y()-adjustment));
    load_crossroad(5,180,(pTurnsPositions(3).get_Y()-adjustment),(pTurnsPositions(6).get_Y()-adjustment));
    load_crossroad(6,90,(pTurnsPositions(5).get_X()-adjustment),(pTurnsPositions(0).get_X()-adjustment));
    load_crossroad(7,90,(pTurnsPositions(5).get_Y()-adjustment),(pTurnsPositions(0).get_Y()-adjustment));
    load_crossroad(8,90,(pTurnsPositions(4).get_X()-adjustment),(pTurnsPositions(1).get_X()-adjustment));
    load_crossroad(8,270,(pTurnsPositions(0).get_X()+adjustment),(pTurnsPositions(5).get_X()+adjustment));
    load_crossroad(9,0,(pTurnsPositions(6).get_Y()+adjustment),(pTurnsPositions(3).get_Y()+adjustment));
    load_crossroad(9,180,(pTurnsPositions(7).get_Y()-adjustment),(pTurnsPositions(2).get_Y()-adjustment));
    load_crossroad(10,90,(pTurnsPositions(4).get_X()-adjustment),(pTurnsPositions(1).get_X()-adjustment));
    load_crossroad(10,270,(pTurnsPositions(5).get_X()+adjustment),(pTurnsPositions(0).get_X()+adjustment));
    load_crossroad(11,0,(pTurnsPositions(6).get_Y()+adjustment),(pTurnsPositions(3).get_Y()+adjustment));
    load_crossroad(11,180,(pTurnsPositions(2).get_Y()-adjustment),(pTurnsPositions(7).get_Y()-adjustment));




}

void Map::load_crossroad(int _crossroadID,int _orientation,int _posR,int _posL)
{
    CrossRoad MyCrossroad( _crossroadID, _orientation, _posR, _posL);
    vCrossRoadVector.push_back(MyCrossroad);
}

Position Map::pTurnsPositions(int _index)
{

        Position _startPosition(0,0);
        switch (_index)
        {
        case 0:
            _startPosition.set_X(384);
            _startPosition.set_Y(880);
            break;
        case 1:
            _startPosition.set_X(830);
            _startPosition.set_Y(880);
            break;
        case 2:
            _startPosition.set_X(1210);
            _startPosition.set_Y(546);
            break;
        case 3:
            _startPosition.set_X(1210);
            _startPosition.set_Y(206);
            break;
        case 4:
            _startPosition.set_X(796);
            _startPosition.set_Y(-90);
            break;
        case 5:
            _startPosition.set_X(350);
            _startPosition.set_Y(-90);
            break;
        case 6:
            _startPosition.set_X(-50);
            _startPosition.set_Y(240);
            break;
        case 7:
            _startPosition.set_X(-50);
            _startPosition.set_Y(580);
            break;

        }
        return _startPosition;
    }

