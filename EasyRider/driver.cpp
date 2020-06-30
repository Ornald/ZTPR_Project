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
    if(5*iTotalMaxSpeed>=abs(_diffPosition) && 0==iWayTable[iCrossRoadCnt])
    {   iRoadID=DriverMap->next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
        if(iCrossRoadCnt<4)
          iCrossRoadCnt++;
        DriverCar->set_maxspeed(iTotalMaxSpeed);


    }

   else if(5*iTotalMaxSpeed>abs(_diffPosition) && -1000!=_diffPosition )
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
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;
            DriverCar->set_maxspeed(iTotalMaxSpeed);

        }
        else if (iWayTable[iCrossRoadCnt]==2)
        {
            DriverCar->turn_left();
            iRoadID=DriverMap->next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;
            DriverCar->set_maxspeed(iTotalMaxSpeed);

        }

    }
}

void Driver::check_trafficlights(int _difference, int _lightStatus)
{

    if (DriverCar->get_maxdistance()*2>=abs(_difference) )
    {

    if (2==_lightStatus || 1==_lightStatus)
    {
        DriverCar->stop_car();

    }
    if(0==_lightStatus && 0==DriverCar->get_actualspeed())
    {
        DriverCar->go();

    }
    }

}

void Driver::find_way()
{
    //to do normal car
    srand (time(NULL));

//    for (int it=0;it<5;it++)
//    {
//        iWayTable[it]=rand()%3;

//    }
        iWayTable[0]=2;
        iWayTable[1]=2;
        iWayTable[2]=2;
        iWayTable[3]=2;
        iWayTable[4]=0;


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
  int CrossroadDistance =DriverMap->check_if_turn(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation(),pCurrentPosition);
  int TrafficLightDistance=DriverMap->check_if_stop_on_lights(pCurrentPosition, DriverCar->rotation(),iRoadID);
  int TrafficLightStatus=DriverMap->check_light_status(DriverCar->rotation(),iRoadID);

    check_crossroad_position(CrossroadDistance);

    check_trafficlights(TrafficLightDistance,TrafficLightStatus);

 DriverCar->move();
 //qDebug()<<DriverCar->pos()<<endl;
}
