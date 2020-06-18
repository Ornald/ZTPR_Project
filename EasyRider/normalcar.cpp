#include "normalcar.h"

NormalCar::NormalCar()
{
    setPixmap(QPixmap(":/Graphics/carBlack.png"));
    setScale(0.2);
    iCarWidth = pixmap().size().width()*0.2;
    iCarHeight = pixmap().size().height()*0.2;
    iStatus=1;
    setPos(500,500);
}

void NormalCar::damage_car()
{
    iStatus=0;
    iMaxSpeed=0;
}
