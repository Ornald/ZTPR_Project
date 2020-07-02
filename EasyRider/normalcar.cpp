#include "normalcar.h"

NormalCar::NormalCar(int _orientation, int _maxspeed, Position _startPosition, int _type)
{
    if (_type==0)
        setPixmap(QPixmap(":/Graphics/carDarkRed.png"));
    if(_type==1)
        setPixmap(QPixmap(":/Graphics/carAmbulance.png"));
    iType=_type;

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

void NormalCar::move()
{
   if(iHowDrive<5)
   {
       Car::move();
   }
   else if(iHowDrive==5)
   {
       turn_around();
   }
}

void NormalCar::turn_around_parameters(int &RotationAngle, int &NextDirection, int &MoveX, int &MoveY)
{
    if (iOrientation==0)
    {

                 RotationAngle=-10;
                 NextDirection=2;
                 MoveX=-speedValue*2;
                 MoveY=-speedValue;


     }
      else if (iOrientation==180)
    {

                 RotationAngle=-10;
                 NextDirection=1;
                 MoveX=speedValue*2;
                 MoveY=speedValue;

  }
 else if (iOrientation==90)
 {

                 RotationAngle=-10;
                 NextDirection=3;
                 MoveX=speedValue*1;
                 MoveY=-speedValue*2;


   }
   else if (iOrientation==270)
    {

                 RotationAngle=-10;
                 NextDirection=4;
                 MoveX=-speedValue*1;
                 MoveY=speedValue*2;

     }
}

void NormalCar::turn_around()
{

    iRightOrLeft=2;
    int RotationAngle;
    int NextDirection;
    int MoveX=0;
    int MoveY=0;
    CenterPoint=Rect.center();
    turn_around_parameters(RotationAngle,NextDirection,MoveX,MoveY);
    setRotation(rotation()+RotationAngle);
    setPos(x()+MoveX,y()+MoveY);
    if(abs(abs(rotation())-abs(iOrientation))==180 || (abs(abs(rotation())-abs(iOrientation))==0 && iOrientation==90))
    {
        setPos(x()-MoveX,y()-MoveY);
        iHowDrive=1;
        iOrientation=rotation();
        iDirection=NextDirection;
        if(rotation()==-360 || rotation()==360)
        {
            setRotation(0);
            iOrientation=0;
        }

        if(rotation()==-180 )
        {
            setRotation(180);
            iOrientation=180;
        }
        if(rotation()==-90 )
        {
            setRotation(270);
            iOrientation=270;
        }
    }
}
void NormalCar::turn_back()
{
    iHowDrive=5;

}
