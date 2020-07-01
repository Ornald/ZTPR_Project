#include "driver.h"


 int Driver::iCarnumber=0;
Driver::Driver()
{

    find_way();
    iCarnumber++;




}

Driver::~Driver()
{
 iCarnumber--;
}

void Driver::check_right_to_overtake()
{
    qDebug()<<iDriverID;
}
void Driver::set_current_position()
{
    pCurrentPosition.set_X(DriverCar->pos().x());
    pCurrentPosition.set_Y(DriverCar->pos().y());
}

void Driver::check_crossroad_position(int _diffPosition)
{
    if(6*iTotalMaxSpeed>=abs(_diffPosition) && 0==iWayTable[iCrossRoadCnt])
    {   iRoadID=DriverMap->next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());

        if(iCrossRoadCnt<4)
          iCrossRoadCnt++;
        sCarSensor->set_CarNextMove(iWayTable[iCrossRoadCnt]);
        DriverCar->set_maxspeed(iTotalMaxSpeed);
        sCarSensor->set_RoadID(iRoadID);



    }

   else if(6*iTotalMaxSpeed>abs(_diffPosition) && -1000!=_diffPosition )
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
            sCarSensor->set_Orientation(DriverMap->get_next_orientation(iWayTable[iCrossRoadCnt],DriverCar->rotation()));
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;
            if(iCrossRoadCnt==4)
                iWayTable[4]=0;
            sCarSensor->set_CarNextMove(iWayTable[iCrossRoadCnt]);
            DriverCar->set_maxspeed(iTotalMaxSpeed);
            sCarSensor->set_RoadID(iRoadID);



        }
        else if (iWayTable[iCrossRoadCnt]==2)
        {
            DriverCar->turn_left();
            iRoadID=DriverMap->next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
            sCarSensor->set_Orientation(DriverMap->get_next_orientation(iWayTable[iCrossRoadCnt],DriverCar->rotation()));
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;
            if(iCrossRoadCnt==4)
                iWayTable[4]=0;
            sCarSensor->set_CarNextMove(iWayTable[iCrossRoadCnt]);
            DriverCar->set_maxspeed(iTotalMaxSpeed);
            sCarSensor->set_RoadID(iRoadID);


        }

    }
}

void Driver::check_trafficlights(int _difference, int _lightStatus)
{

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

void Driver::adjust_speed(int _diff)
{
    int distance =DriverMap->distance_to_next_car(iDriverID);

    if(distance<60 && distance >0)
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
    //to do normal car
    srand (time(NULL));

    for (int it=0;it<5;it++)
    {
        iWayTable[it]=rand()%3;

    }
//        iWayTable[0]=0;
//        iWayTable[1]=0;
//        iWayTable[2]=0;
//        iWayTable[3]=1;
//        iWayTable[4]=1;
//        if(iCarnumber==1)
//        {
//            iWayTable[0]=0;
//            iWayTable[1]=2;
//            iWayTable[2]=0;
//            iWayTable[3]=2;
//            iWayTable[4]=0;
//        }
//        if(iCarnumber==2)
//        {
//            iWayTable[0]=0;
//            iWayTable[1]=2;
//            iWayTable[2]=0;
//            iWayTable[3]=2;
//            iWayTable[4]=0;
//        }
//qDebug()<<iWayTable[0]<<iWayTable[1]<<iWayTable[2]<<iWayTable[3]<<iWayTable[4];

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


void Driver::next_move()
{
    set_current_position();
    sCarSensor->set_CarPosition(pCurrentPosition);
    sCarSensor->set_ActualSpeed(DriverCar->get_actualspeed());

  int CrossroadDistance =DriverMap->check_if_turn(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation(),pCurrentPosition);
  int TrafficLightDistance=DriverMap->check_if_stop_on_lights(pCurrentPosition, DriverCar->rotation(),iRoadID);
  int TrafficLightStatus=DriverMap->check_light_status(DriverCar->rotation(),iRoadID);

    adjust_speed(CrossroadDistance);
    check_crossroad_position(CrossroadDistance);
    adjust_speed(CrossroadDistance);
    check_trafficlights(TrafficLightDistance,TrafficLightStatus);

    //if(iDriverID==0)
   // qDebug()<<

    //qDebug()<<iDriverID<<DriverMap->distance_to_next_car(iDriverID)<<DriverMap->get_next_car_speed(iDriverID);

//    if(iDriverID==0)

     DriverCar->move();
 //qDebug()<<DriverCar->pos()<<endl;
}
