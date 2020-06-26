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
    load_crossroad(7,90,(pTurnsPositions(5).get_X()-adjustment),(pTurnsPositions(0).get_X()-adjustment));
    load_crossroad(8,90,(pTurnsPositions(4).get_X()-adjustment),(pTurnsPositions(1).get_X()-adjustment));
    load_crossroad(8,270,(pTurnsPositions(0).get_X()+adjustment),(pTurnsPositions(5).get_X()+adjustment));
    load_crossroad(9,0,(pTurnsPositions(6).get_Y()+adjustment),(pTurnsPositions(3).get_Y()+adjustment));
    load_crossroad(9,180,(pTurnsPositions(2).get_Y()-adjustment),(pTurnsPositions(7).get_Y()-adjustment));
    load_crossroad(10,90,(pTurnsPositions(4).get_X()-adjustment),(pTurnsPositions(1).get_X()-adjustment));
    load_crossroad(10,270,(pTurnsPositions(0).get_X()+adjustment),(pTurnsPositions(5).get_X()+adjustment));
    load_crossroad(11,0,(pTurnsPositions(6).get_Y()+adjustment),(pTurnsPositions(3).get_Y()+adjustment));
    load_crossroad(11,180,(pTurnsPositions(2).get_Y()-adjustment),(pTurnsPositions(7).get_Y()-adjustment));

}

int Map::check_if_turn(int _way, int _roadID, int _orientation, Position _carPosition)
{
        std::vector<CrossRoad>::iterator  it= find_crossroad(_roadID,_orientation);
     if(check_if_exit(_roadID,_orientation))
        return 1;
    if(check_if_X_Y(_roadID))
    {   //qDebug()<<(it->get_cross_position(_way));
        return (it->get_cross_position(_way))-_carPosition.get_Y();
    }
    else
    {   //qDebug()<<(it->get_cross_position(_way));
        return (it->get_cross_position(_way))-_carPosition.get_X();
    }

}

int Map::next_road_id(int _way, int _roadID, int _orientation)
{
    int parameter=0;
    switch (_roadID){
    case 0:
        parameter=returnParameter(_way,8,11,7);
        break;
    case 1:
        parameter=returnParameter(_way,2,9,8);
        break;
    case 2:
        parameter=returnParameter(_way,9,8,1);
        break;
    case 3:
        parameter=returnParameter(_way,4,10,9);
        break;
    case 4:
        parameter=returnParameter(_way,10,9,3);
        break;
    case 5:
        parameter=returnParameter(_way,6,11,10);
        break;
    case 6:
        parameter=returnParameter(_way,11,10,5);
        break;
    case 7:
        parameter=returnParameter(_way,0,8,11);
        break;
    case 8:
        (_orientation==90)? parameter=returnParameter(_way,1,2,9) : parameter=returnParameter(_way,11,7,0);
        break;
    case 9:
        (_orientation==0)? parameter=returnParameter(_way,3,4,10) : parameter=returnParameter(_way,8,1,2);
        break;
    case 10:
        (_orientation==90)? parameter=returnParameter(_way,9,3,4) : parameter=returnParameter(_way,5,6,11);
        break;
    case 11:
        (_orientation==0)? parameter=returnParameter(_way,10,5,6) : parameter=returnParameter(_way,7,0,8);
        break;

    }
    return parameter;
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

int Map::returnParameter(int _way,int _R, int _F, int _L)
{
    int parameter=0;

    if(1==_way)
        return _R;
    if(0==_way)
        return _F;
    if (2==_way)
        return _L;
    return parameter;
}

std::vector<CrossRoad>::iterator  Map::find_crossroad(int _roadID, int _orientation)
{
    std::vector<CrossRoad>::iterator it;
    it = std::find(vCrossRoadVector.begin(),vCrossRoadVector.end(),_roadID);


    return (it+check_roadID_condition(_roadID,_orientation));
}

bool Map::check_if_X_Y(int _roadID)
{
    if (0 == _roadID ||1 == _roadID ||4 == _roadID ||5 == _roadID ||9 == _roadID ||11 == _roadID )
        return 1;
    return 0;
}

bool Map::check_if_exit(int _roadID, int _orientation)
{
    if ((0==_roadID || 1==_roadID) && 180==_orientation)
        return 1;
    if ((2==_roadID || 3==_roadID) && 90==_orientation)
        return 1;
    if ((4==_roadID || 5==_roadID) && 0==_orientation)
        return 1;
    if ((6==_roadID || 7==_roadID) && 270==_orientation)
        return 1;
    return 0;

}

int Map::check_roadID_condition(int _roadID, int _orientation)
{
    if ((8==_roadID || 10==_roadID) && 270==_orientation)
        return 1;
    if ((9==_roadID || 11==_roadID)&& 180==_orientation)
        return 1;
    return 0;


}
