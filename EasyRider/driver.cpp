#include "driver.h"


 int Driver::iCarnumber=0;
Driver::Driver()
{


    iCarnumber++;




}

Driver::~Driver()
{
    iCarnumber--;
}

void Driver::overtake()
{
    DriverCar->change_lane();
}


bool Driver::check_if_stuck()
{
    if (DriverCar->get_stuck_counter()>=4000 && DriverCar->get_status()==1)
        return 1;
    return 0;
}
void Driver::set_current_position()
{
    pCurrentPosition.set_X(DriverCar->pos().x());
    pCurrentPosition.set_Y(DriverCar->pos().y());
}

void Driver::check_crossroad_position(int _diffPosition)
{



   if(6*iTotalMaxSpeed>abs(_diffPosition) && -1000!=_diffPosition )
    {

        DriverCar->set_maxspeed(1);



    }
    if(-1000==_diffPosition)
    {
        DriverCar->set_maxspeed(iTotalMaxSpeed);
    }

    if (0==_diffPosition)
    {
        if(iWayTable[iCrossRoadCnt]==1)
        {
            DriverCar->turn_right();
            iRoadID=DriverMap->next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
            sCarSensor->set_RoadID(iRoadID);
            sCarSensor->set_Orientation(DriverMap->get_next_orientation(iWayTable[iCrossRoadCnt],DriverCar->rotation()));
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;
            if(iCrossRoadCnt==4)
                iWayTable[4]=0;
            sCarSensor->set_CarNextMove(iWayTable[iCrossRoadCnt]);
            DriverCar->set_maxspeed(iTotalMaxSpeed);
            DriverCar->reset_stuck_counter();




        }
        else if (iWayTable[iCrossRoadCnt]==2)
        {
            iRoadID=DriverMap->next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
            sCarSensor->set_Orientation(DriverMap->get_next_orientation(iWayTable[iCrossRoadCnt],DriverCar->rotation()));
            sCarSensor->set_RoadID(iRoadID);
            DriverCar->turn_left();

            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;
            if(iCrossRoadCnt==4)
                iWayTable[4]=0;
            sCarSensor->set_CarNextMove(iWayTable[iCrossRoadCnt]);
            DriverCar->set_maxspeed(iTotalMaxSpeed);
            DriverCar->reset_stuck_counter();

        }
        else if( 0==iWayTable[iCrossRoadCnt] )
        {   iRoadID=DriverMap->next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
            sCarSensor->set_RoadID(iRoadID);
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;
            sCarSensor->set_CarNextMove(iWayTable[iCrossRoadCnt]);
            DriverCar->set_maxspeed(iTotalMaxSpeed);
            DriverCar->reset_stuck_counter();

        }

    }
}

void Driver::check_trafficlights(int _difference, int _lightStatus)
{
    if(0==_lightStatus && DriverCar->get_stuck_counter()>1500 && DriverCar->get_status()==1)
    {
        DriverCar->go();
    }
    else {
    if (DriverCar->get_maxdistance()*2>=abs(_difference) )
    {

    if (2==_lightStatus || 1==_lightStatus || DriverMap->check_if_stuck(iDriverID) || !DriverMap->check_if_can_drive(iDriverID))
    {
        DriverCar->stop_car();

    }
    if(0==_lightStatus && 0==DriverCar->get_actualspeed() && !DriverMap->check_if_stuck(iDriverID) && DriverMap->check_if_can_drive(iDriverID))
    {
        DriverCar->go();

    }
    }
    }

}

void Driver::adjust_speed(int _diff)
{
    int distance =DriverMap->distance_to_next_car<int>(iDriverID,0);


    if (DriverCar->get_position_onLane()==1)
    {
        if (DriverMap->check_if_can_return(iDriverID,iNextBrokenCarID))
       {

            overtake();


        }
    }

    if (distance<60 && distance>0)
    {
        if (DriverCar->get_position_onLane()==0)
        {

            if(DriverMap->check_if_can_overtake(iDriverID,iNextBrokenCarID))
            {
            overtake();
            }
        }
    }

    if(distance<50 && distance >0)
    {

        if (DriverMap->get_next_car_speed(iDriverID)<=iTotalMaxSpeed)
            DriverCar->set_maxspeed(DriverMap->get_next_car_speed(iDriverID));
        else
           DriverCar->set_maxspeed(iTotalMaxSpeed);
    }


    if((distance>50 || distance<0) && abs(_diff)>6*iTotalMaxSpeed)
    {

           DriverCar->set_maxspeed(iTotalMaxSpeed);
    }


}

void Driver::find_way()
{

}
Position Driver::start_postion()
{
    Position _startPosition(0,0);
    switch (iStartIndex)
    {
    case 0:
        _startPosition.set_X(384);
        _startPosition.set_Y(880);
        break;
    case 1:
        _startPosition.set_X(830);
        _startPosition.set_Y(880);
        break;
    case 2:
        _startPosition.set_X(1210);
        _startPosition.set_Y(546);
        break;
    case 3:
        _startPosition.set_X(1210);
        _startPosition.set_Y(206);
        break;
    case 4:
        _startPosition.set_X(796);
        _startPosition.set_Y(-90);
        break;
    case 5:
        _startPosition.set_X(350);
        _startPosition.set_Y(-90);
        break;
    case 6:
        _startPosition.set_X(-50);
        _startPosition.set_Y(240);
        break;
    case 7:
        _startPosition.set_X(-50);
        _startPosition.set_Y(580);
        break;

    }
    return _startPosition;
}

void Driver::set_start_index(int _startIndex)
{
    iStartIndex=_startIndex;


}

int Driver::get_start_index()
{
    return iStartIndex;
}

bool Driver::check_if_out_board()
{
    if(DriverCar->pos().y()>900 || DriverCar->pos().y()<-100 || DriverCar->pos().x()<-70 || DriverCar->pos().x()>1210)
        return 1;
    return 0;
}

int Driver::get_roadID()
{
    return iRoadID;
}

int Driver::get_DriverID()
{
    return iDriverID;
}

void Driver::set_TowCarID(int _towCarID)
{
    iTowCarID=_towCarID;
}

void Driver::set_picked()
{
    if(DriverCar->get_status()==0 && DriverMap->check_if_close_to_target(iDriverID,iTowCarID))
    {
        iPicked=1;

    }

}

int Driver::get_picked()
{
    return iPicked;
}

bool Driver::can_be_damaged()
{
    return 0;
}

void Driver::engine_malfunction()
{

}

int Driver::picked_up_id()
{
    return -1;
}

int Driver::get_carType()
{
    return iCarType;
}

bool Driver::get_status()
{
    return bStatus;
}


void Driver::next_move()
{

}
