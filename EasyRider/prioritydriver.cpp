#include "prioritydriver.h"

PriorityDriver::PriorityDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map &_map)
{
    iTotalMaxSpeed=_maxspeed;
    iCurrentMaxSpeed=_maxspeed;
    DriverMap=&_map;
    iDriverID=_ID;
    set_start_index(_startIndex);
    iRoadID=_startIndex;
    Position _startPosition=start_postion();
    DriverCar=new NormalCar(_orientation,_maxspeed,_startPosition,1);
    _scene.addItem(DriverCar);
    set_current_position();
    iCarType=1;
    sCarSensor=new Sensors(pCurrentPosition,iWayTable[iCrossRoadCnt],iRoadID,DriverCar->get_actualspeed(),iDriverID,DriverCar->rotation(),iCarType,iTotalMaxSpeed);
    DriverMap->addCarSensor(sCarSensor);
    find_way();

}

PriorityDriver::~PriorityDriver()
{
    delete  DriverCar;
    DriverMap->deleteCarSensor(iDriverID);

}

void PriorityDriver::find_way()
{
    for(int i =0;i<2;i++)
    {
        iWayTable[i]=rand()%3;
    }
    iWayTable[2]=return_move(iWayTable[1]);
    iWayTable[3]=return_move(iWayTable[0]);
    iWayTable[4]=rand()%3;

}

void PriorityDriver::turn_back()
{
    if(iCrossRoadCnt>=2 && iTurned==0)
    {
    if((DriverMap->check_if_can_turn_back(iDriverID)) && (!((iRoadID==10)) && (sCarSensor->get_Orientation()==0)==1))
    {

        DriverCar->turn_back();
        iTurned=1;
    }
    }
}

int PriorityDriver::return_move(int _move)
{
    switch(_move)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 2;
        break;
    case 2:
        return 1;
        break;
    default:
    return 0;
    }

}

void PriorityDriver::next_move()
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
    turn_back();



    DriverCar->move();
}

void PriorityDriver::check_trafficlights(int _difference, int _lightStatus)
{
    if(0==_lightStatus && DriverCar->get_stuck_counter()>2800)
    {
        DriverCar->go();
    }
    else {
        if (DriverCar->get_maxdistance()*2>=abs(_difference) )
        {

            if (2==_lightStatus || DriverMap->check_if_stuck(iDriverID) || !DriverMap->check_if_can_drive(iDriverID))
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
