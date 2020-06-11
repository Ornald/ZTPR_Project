#include "car.h"

const int speedValue=2;

Car::Car(): QObject(), QGraphicsRectItem()
{


setRect(0,0,50,100);

    iSpeed=2;
    iMaxSpeed=3;
QTimer *MoveTimer = new QTimer(this);
connect(MoveTimer,SIGNAL(timeout()),this,SLOT(turn()));
MoveTimer->start(50);

}

void Car::slow_down()
{
    if(iSpeed>0)
        iSpeed--;
}

void Car::speed_up()
{   if(iSpeed<iMaxSpeed)
        iSpeed++;
}

void Car::change_speed()
{

}

void Car::move_forward()
{
    int iAccelerate = iSpeed*speedValue;
    if(iDirection==1)
        setPos(x(),y()-iAccelerate);
    else if (iDirection==2)
        setPos(x(),y()+iAccelerate);
    else if (iDirection==3)
        setPos(x()-iAccelerate,y());
    else
        setPos(x()+iAccelerate,y());
}

void Car::turn()
{

    setRotation(rotation()+10);
   /*if(iTurn==1)
        setPos(x()+speedValue,y()+speedValue);
    else
        setPos(x()+speedValue,y()+speedValue);
*/
}

