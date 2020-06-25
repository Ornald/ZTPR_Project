#include "normalcar.h"

NormalCar::NormalCar(int _orientation, int _maxspeed, Position _startPosition)
{
    setPixmap(QPixmap(":/Graphics/carDarkRed.png"));
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

void NormalCar::damage_car()
{
    iStatus=0;
    iMaxSpeed=0;
}

int NormalCar::get_car_status()
{
    return iStatus;
}

NormalCar::~NormalCar()
{

}
