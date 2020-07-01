#ifndef CROSSROAD_H
#define CROSSROAD_H


class CrossRoad
{
public:
    CrossRoad(int _crossroadID,int _orientation,int _posR,int _posL);
    CrossRoad();
    int get_cross_position(int _way);
    int get_roadID();
    int get_orientation();
    bool operator== (const int & _temp){ return this->iCrossroadID==_temp;   };

private:

    int iCrossroadID;
    int iOrientation;
    int iPosR;
    int iPosL;


};

#endif // CROSSROAD_H
