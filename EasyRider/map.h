#ifndef MAP_H
#define MAP_H

#include "position.h"
#include <vector>
#include "crossroad.h"
#include <QDebug>
#include <cmath>

class Map
{


public:
    Map();
    int check_if_turn(int _way,int _roadID,int _orientation,Position _carPosition);
    int next_road_id(int _way,int _roadID, int _orientation);



private:
    void load_crossroad(int _crossroadID, int _orientation, int _posXR, int _posXL);
    std::vector<CrossRoad> vCrossRoadVector;
    Position pTurnsPositions(int _index);
    int returnParameter(int _way,int _R,int _F,int _L);
    int check_roadID_condition(int _roadID, int _orientation);
    std::vector<CrossRoad>::iterator  find_crossroad(int _roadID,int _orientation);
    bool check_if_X_Y(int _roadID);
    bool check_if_exit(int _roadID,int _orientation);



};

#endif // MAP_H
