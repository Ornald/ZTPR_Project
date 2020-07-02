#include "tugcar.h"

TugCar::TugCar(int _orientation,int _maxspeed,Position _startPosition)
{
    setPixmap(QPixmap(":/Graphics/carTow.png"));
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

TugCar::~TugCar()
{

}

void TugCar::change_tow_occupation()
{
    if (iOccupation==0)
    {
        setPixmap(QPixmap(":/Graphics/carTowWithcar.png"));
        iOccupation=1;
    }

}
