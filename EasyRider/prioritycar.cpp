#include "prioritycar.h"

PriorityCar::PriorityCar()
{
    setPixmap(QPixmap(":/Graphics/carAmbulance.png"));

    setScale(0.2);
    iCarWidth = pixmap().size().width()*0.2;
    iCarHeight = pixmap().size().height()*0.2;
    iStatus=1;
    setPos(500,500);
}

void PriorityCar::damage_car()
{
    iStatus=0;
    iMaxSpeed=0;
}

void PriorityCar::move()
{
    switch (iHowDrive) {

     case 1:
        if (iSpeed<iMaxSpeed)
            speed_up();
         move_forward();
         break;
     case 2:
         turn();
         break;

     case 3:
        change_traffic_lane();
        break;
    case 4:
        stop();
        break;
    case 5:
        turn_around();
        break;
    }
}

void PriorityCar::turn_around()
{

}

void PriorityCar::turn_around_parameters()
{

}
