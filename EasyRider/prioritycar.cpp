#include "prioritycar.h"

PriorityCar::PriorityCar(int _orientation, int _maxspeed, Position _startPosition)
{
    setPixmap(QPixmap(":/Graphics/carAmbulance.png"));
    setScale(0.2);
    iCarWidth = pixmap().size().width()*0.2;
    iCarHeight = pixmap().size().height()*0.2;
    setPos(_startPosition.get_X(),_startPosition.get_Y());
    Rect= mapToScene(boundingRect()).boundingRect();
    CenterPoint=Rect.center();
    QGraphicsItem::setTransformOriginPoint(50,87.5);
    iOrientation=_orientation;
    setRotation(iOrientation);
    iDirection=choose_direction();
    iMaxSpeed=_maxspeed;




}



PriorityCar::~PriorityCar()
{

}

//void PriorityCar::move()
//{
//    switch (iHowDrive) {

//     case 1:
//        if (iSpeed<iMaxSpeed)
//            speed_up();
//         move_forward();
//         break;
//     case 2:
//         turn();
//         break;

//     case 3:
//        change_traffic_lane();
//        break;
//    case 4:
//        stop();
//        break;
//    case 5:
//        turn_around();
//        break;
//    }
//}

void PriorityCar::turn_around()
{

}

void PriorityCar::turn_around_parameters()
{

}

