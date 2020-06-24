#include "tugcar.h"

TugCar::TugCar(int _orientation,int _maxspeed)
{
    setPixmap(QPixmap(":/Graphics/carTow.png"));

    setScale(0.2);
    iCarWidth = pixmap().size().width()*0.2;
    iCarHeight = pixmap().size().height()*0.2;

    setPos(500,500);
    Rect= mapToScene(boundingRect()).boundingRect();
    CenterPoint=Rect.center();
    QGraphicsItem::setTransformOriginPoint(50,87.5);
    iOrientation=_orientation;
    setRotation(iOrientation);
    iDirection=choose_direction();
    iMaxSpeed=_maxspeed;



     QTimer *MoveTimer = new QTimer(this);
     connect(MoveTimer,SIGNAL(timeout()),this,SLOT(move()));
     MoveTimer->start(50);
}

TugCar::~TugCar()
{

}

void TugCar::change_tow_occupation()
{
    if (iOccupation==0)
    {
        setPixmap(QPixmap(":/Graphics/carTowWithcarBlack.png"));
        iOccupation=1;
    }
    else
    {
        setPixmap(QPixmap(":/Graphics/carTow.png"));
        iOccupation=0;
    }
}
