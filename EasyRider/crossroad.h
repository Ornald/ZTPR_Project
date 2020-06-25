#ifndef CROSSROAD_H
#define CROSSROAD_H


class CrossRoad
{
public:
    CrossRoad(int _crossroadID,int _orientation,int _posR,int _posL);
    int get_cross_position(int _way);
    int get_crossroadID();
    int get_orientation();

private:

    int iCrossroadID;
    int iOrientation;
    int iPosR;
    int iPosL;
};

#endif // CROSSROAD_H
