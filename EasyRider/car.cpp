#include "car.h"




Car::Car(): QObject(), QGraphicsPixmapItem()
{


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

void Car::change_speed(int iSpeedLevel)
{
    if(iSpeedLevel<=iMaxSpeed)
    iSpeed=iSpeedLevel;
    else
        iSpeed=iMaxSpeed;
}

Car::~Car()
{

}

void Car::set_drive_way(int howdrive)
{
    iHowDrive=howdrive;
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
    else if (iDirection==4)
        setPos(x()+iAccelerate,y());

}

void Car::move()
{
    if (iSpeed==0)
        istuckCounter++;
   switch (iHowDrive) {

    case 1:
       if (iSpeed<iMaxSpeed)
           speed_up();
       if (iSpeed>iMaxSpeed)
           slow_down();
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


    }



}

void Car::damage_car()
{

}

void Car::turn_back()
{

}

void Car::change_tow_occupation()
{

}

void Car::turn()
{

    int RotationAngle;
    int NextDirection;
    int MoveX=0;
    int MoveY=0;




    CenterPoint=Rect.center();


    turn_Parameters(RotationAngle,NextDirection,MoveX,MoveY);



    setRotation(rotation()+RotationAngle);

    setPos(x()+MoveX,y()+MoveY);
    if(abs(abs(rotation())-abs(iOrientation))==90)
    {
        iHowDrive=1;
        iOrientation=rotation();
        iDirection=NextDirection;


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
                    MoveX=speedValue*2;
                    MoveY=-speedValue;

                }
              else
                {
                    RotationAngle=-10;
                    NextDirection=3;
                    MoveX=-speedValue*2;
                    MoveY=-speedValue;
                }

        }
         else if (iOrientation==180)
       {
                if(iRightOrLeft==1)
                {
                    RotationAngle=10;
                    NextDirection=3;
                    MoveX=-speedValue*2;
                    MoveY=speedValue;
                }
                else
                {
                    RotationAngle=-10;
                    NextDirection=4;
                    MoveX=speedValue*2;
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
                    MoveY=speedValue*2;
                }
              else
                {
                    RotationAngle=-10;
                    NextDirection=1;
                    MoveX=speedValue*1;
                    MoveY=-speedValue*2;
                }

      }
      else if (iOrientation==270)
       {
                if(iRightOrLeft==1)
                {
                    RotationAngle=10;
                    NextDirection=1;
                    MoveX=-speedValue;
                    MoveY=-speedValue*2;
                }
                else
                {
                    RotationAngle=-10;
                    NextDirection=2;
                    MoveX=-speedValue*1;
                    MoveY=speedValue*2;
                }

        }

}

void Car::change_lane_parameters(int &RotationAngle, int &NextDirection, int &MoveX, int &MoveY)
{
    switch (iOrientation)
    {
    case 0:
        if (iOnWrongLane==0)
        {
        RotationAngle=-10;
        MoveX=-speedValue;

        }
        else
        {
            RotationAngle=10;
            MoveX=speedValue;
        }
         NextDirection=1;
         MoveY=-speedValue;
        break;
    case 90:
        if (iOnWrongLane==0)
        {
            RotationAngle=-10;
            MoveY=-speedValue;
        }
        else
        {
            RotationAngle=10;
            MoveY=speedValue;
        }
        NextDirection=4;
        MoveX=speedValue;
        break;
    case 180:
        if (iOnWrongLane==0)
        {
            RotationAngle=-10;
            MoveX=speedValue;
        }
        else
        {
            RotationAngle=10;
            MoveX=-speedValue;
        }
        NextDirection=2;
        MoveY=speedValue;
        break;
    case 270:
        if (iOnWrongLane==0)
        {
            RotationAngle=-10;
            MoveY=speedValue;
        }
        else
        {
            RotationAngle=10;
            MoveY=-speedValue;
        }
        NextDirection=3;
        MoveX=-speedValue;
        break;


    }
}

void Car::change_traffic_lane()
{


    int RotationAngle;
    int NextDirection;
    int MoveX=0;
    int MoveY=0;
    change_lane_parameters(RotationAngle,NextDirection,MoveX,MoveY);

    if(abs(rotation())==abs(iOrientation))
    {
        iChangeLaneX=pos().x();
    }
    if (abs(abs(rotation())-abs(iOrientation))!=30 && iPositionOnNextLane!=1)
    {
        CenterPoint=Rect.center();
        setRotation(rotation()+RotationAngle);
        setPos(x()+MoveX,y()+MoveY);
    }

    if(abs(pos().x()-iChangeLaneX)!=(iCarWidth+10))
    {
        setPos(x()+MoveX,y()+MoveY);

    }
    else
    {
        iPositionOnNextLane=1;
    }
    if(iPositionOnNextLane==1)
    {

        if (abs(rotation())!=abs(iOrientation))
       {




            setRotation(rotation()-RotationAngle);
            setPos(x()-MoveX,y()+MoveY);
        }
        else
        {
            if(iOnWrongLane==0)
                iOnWrongLane=1;
            else
                iOnWrongLane=0;
            iPositionOnNextLane=0;
            iHowDrive=1;
            iDirection=NextDirection;
        }
    }
}

void Car::stop()
{
    if (iSpeed!=0)
    {
    slow_down();
    move_forward();
    }

}

int Car::choose_direction()
{
    switch (iOrientation)
    {
    case 0:
        return 1;
        break;
    case 90:
        return 4;
        break;
    case 180:
        return 2;
        break;
    case 270:
        return 3;
        break;
    }
    return 0;

}

void Car::go()
{
    iHowDrive=1;
    speed_up();
}

void Car::set_maxspeed(int _maxSpeed)
{
    iMaxSpeed=_maxSpeed;
}

int Car::get_maxspeed()
{
    return iMaxSpeed;
}

int Car::get_maxdistance()
{
    return iMaxSpeed*speedValue;
}

int Car::get_actualspeed()
{
    return iSpeed*speedValue;
}

int Car::get_status()
{
    return iStatus;
}

int Car::get_type()
{
    return iType;
}

int Car::get_stuck_counter()
{
    return istuckCounter;
}

void Car::reset_stuck_counter()
{
    istuckCounter=0;

}

int Car::get_position_onLane()
{
    return iOnWrongLane;
}






void Car::turn_right()
{
    iRightOrLeft=1;
    iHowDrive=2;

}

void Car::turn_left()
{
    iRightOrLeft=2;
    iHowDrive=2;

}

void Car::change_lane()
{
    iHowDrive=3;
}

void Car::stop_car()
{
    iHowDrive=4;
}





