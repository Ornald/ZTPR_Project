#include "normalcar.h"

NormalCar::NormalCar()
{
    setPixmap(QPixmap(":/Graphics/carBlack.png"));
    setScale(0.2);
    iCarWidth = pixmap().size().width()*0.2;
    iCarHeight = pixmap().size().height()*0.2;

    setPos(500,500);
}
