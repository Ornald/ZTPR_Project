#ifndef MAP_H
#define MAP_H

#include "position.h"
#include <vector>
#include "crossroad.h"
#include <QDebug>

class Map
{


public:
    Map();
    bool check_if_turn(int _way,int _roadID,int _orientation);

private:
    void load_crossroad(int _crossroadID, int _orientation, int _posXR, int _posXL);
    std::vector<CrossRoad> vCrossRoadVector;
    Position pTurnsPositions(int _index);

};

#endif // MAP_H
