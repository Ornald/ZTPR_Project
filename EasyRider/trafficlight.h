#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "position.h"
#include <QDebug>
class TrafficLight: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    TrafficLight(Position _position,int _startStatus,int _orientation,int _roadID, int _stopPoint);
    void change_light();
   int get_status();
   int get_stopPoint();
   int get_previous_status();
   int get_roadID();
   bool get_if_recently_changed();
   void set_recent_change(int _change);
   bool operator== (const int & _temp){ return this->iRoadID==_temp;   };
private:
    void place_trafficlight(Position _position, int _startStatus,int _orientation);
    int iStatus=0;
    int iPreviousStatus=0;
    int iRoadID=0;
    int iStopPoint;
    int iRecentlyChanged=0;


};

#endif // TRAFFICLIGHT_H
