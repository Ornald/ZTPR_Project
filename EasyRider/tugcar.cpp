#include "tugcar.h"

TugCar::TugCar()
{
    setPixmap(QPixmap(":/Graphics/carTow.png"));

    setScale(0.2);
    iCarWidth = pixmap().size().width()*0.2;
    iCarHeight = pixmap().size().height()*0.2;

    setPos(500,500);
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
