#include "car.h"

const int speedValue=2;


Car::Car(): QObject(), QGraphicsRectItem()
{
    setRect(300,300,iCarHeight,iCarWidth);

    //setRect(100,300,iCarWidth,iCarHeight);
    Rect= mapToScene(boundingRect()).boundingRect();
    CenterPoint=Rect.center();

    iOrientation=0;
    setRotation(iOrientation);


    iDirection=1;
    iSpeed=2;
    iMaxSpeed=3;
    iHowDrive=1;
    qDebug()<<rotation();
    QTimer *MoveTimer = new QTimer(this);
    connect(MoveTimer,SIGNAL(timeout()),this,SLOT(move()));
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

void Car::set_drive_way(int howdrive)
{
    iHowDrive=howdrive;
}

void Car::move_forward()
{

    CenterPoint=Rect.center();
    qDebug()<<Rect.center()<<CenterPoint;
    qDebug()<<pos();


    int iAccelerate = iSpeed*speedValue;
    if(iDirection==1)
        setPos(x(),y()-iAccelerate);
    else if (iDirection==2)
        setPos(x(),y()+iAccelerate);
    else if (iDirection==3)
        setPos(x()-iAccelerate,y());
    else if (iDirection==4)
        setPos(x()+iAccelerate,y());


}

void Car::move()
{
  /*  switch (iHowDrive) {

    case 1:
        move_forward();
        break;
    case 2:
        turn();
        break;
    }
    */
    if(iHowDrive!=0)
    change_traffic_lane();
}

void Car::turn()
{

    int RotationAngle;
    int NextDirection;
    int MoveX=0;
    int MoveY=0;




    CenterPoint=Rect.center();

    turn_Parameters(RotationAngle,NextDirection,MoveX,MoveY);

    setTransformOriginPoint(CenterPoint);

    setRotation(rotation()+RotationAngle);

    setPos(x()+MoveX,y()+MoveY);
    if(abs(abs(rotation())-abs(iOrientation))==90)
    {
        iHowDrive=1;
        iOrientation=rotation();
        iDirection=NextDirection;



        setTransformOriginPoint(CenterPoint);

    }


    if(rotation()==-360 || rotation()==360)
    {
        setRotation(0);
        iOrientation=0;
    }

    if(rotation()==-90 )
    {
        setRotation(270);
        iOrientation=270;
    }


}

void Car::turn_Parameters( int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY)
{
       if (iOrientation==0)
       {
                if(iRightOrLeft==1)
                {
                    RotationAngle=10;
                    NextDirection=4;
                    MoveX=speedValue;
                    MoveY=-speedValue;

                }
              else
                {
                    RotationAngle=-10;
                    NextDirection=3;
                    MoveX=-speedValue;
                    MoveY=-speedValue;
                }

        }
         else if (iOrientation==180)
       {
                if(iRightOrLeft==1)
                {
                    RotationAngle=10;
                    NextDirection=3;
                    MoveX=-speedValue;
                    MoveY=speedValue;
                }
                else
                {
                    RotationAngle=-10;
                    NextDirection=4;
                    MoveX=speedValue;
                    MoveY=speedValue;
                }
     }
    else if (iOrientation==90)
    {
                if(iRightOrLeft==1)
                {
                    RotationAngle=10;
                    NextDirection=2;
                    MoveX=speedValue;
                    MoveY=speedValue;
                }
              else
                {
                    RotationAngle=-10;
                    NextDirection=1;
                    MoveX=speedValue*1;
                    MoveY=-speedValue;
                }

      }
      else if (iOrientation==270)
       {
                if(iRightOrLeft==1)
                {
                    RotationAngle=10;
                    NextDirection=1;
                    MoveX=-speedValue;
                    MoveY=-speedValue;
                }
                else
                {
                    RotationAngle=-10;
                    NextDirection=2;
                    MoveX=-speedValue*1;
                    MoveY=speedValue;
                }

        }

}

void Car::change_traffic_lane()
{
    CenterPoint=Rect.center();
    setTransformOriginPoint(CenterPoint);
    setRotation(rotation()-10);
    setPos(x()+speedValue,y()+speedValue);

}


void Car::temp_turn_right()
{
    iRightOrLeft=1;
    iHowDrive=2;
}

void Car::temp_turn_left()
{
    iRightOrLeft=2;
    iHowDrive=2;
}



