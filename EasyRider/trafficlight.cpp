#include "trafficlight.h"

TrafficLight::TrafficLight(Position _position, int _startStatus, int _orientation, int _roadID,int _stopPoint)
{
    iStopPoint=_stopPoint;
    iRoadID=_roadID;
    iStatus=_startStatus;
    place_trafficlight(_position,_startStatus,_orientation);



}

void TrafficLight::change_light()
{
    if (0==iStatus)
    {   iPreviousStatus=iStatus;
        iStatus=1;
        setPixmap(QPixmap(":/Graphics/YellowLight.png"));
    }
    else if (1==iStatus)
    {

        if (0==iPreviousStatus)
        {
            iStatus=2;
            setPixmap(QPixmap(":/Graphics/RedLight.png"));
        }
        else
        {
            setPixmap(QPixmap(":/Graphics/GreenLight.png"));
            iStatus=0;
        }
    }
    else
    {
        setPixmap(QPixmap(":/Graphics/YellowLight.png"));
        iPreviousStatus=iStatus;
        iStatus=1;
    }

}

int TrafficLight::get_status()
{
    return iStatus;
}

int TrafficLight::get_stopPoint()
{
    return iStopPoint;
}

int TrafficLight::get_previous_status()
{
    return iPreviousStatus;
}

int TrafficLight::get_roadID()
{
    return iRoadID;
}

bool TrafficLight::get_if_recently_changed()
{
    if(iRecentlyChanged==1)
        return 1;
    return 0;

}

void TrafficLight::set_recent_change(int _change)
{
    iRecentlyChanged=_change;
}

void TrafficLight::place_trafficlight(Position _position, int _startStatus,int _orientation)
{
    switch(_startStatus)
    {case 0:
        iPreviousStatus=2;
        setPixmap(QPixmap(":/Graphics/GreenLight.png"));
        break;
    case 1:
        iPreviousStatus=0;
        setPixmap(QPixmap(":/Graphics/YellowLight.png"));
        break;
    case 2:
        iPreviousStatus=0;
        setPixmap(QPixmap(":/Graphics/RedLight.png"));
        break;
    }
    setScale(0.3);
    setPos(_position.get_X(),_position.get_Y());
    QGraphicsItem::setTransformOriginPoint(50,55);

    setRotation(_orientation);
}
