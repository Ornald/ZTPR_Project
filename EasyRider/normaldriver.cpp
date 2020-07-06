#include "normaldriver.h"

NormalDriver::NormalDriver (int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map & _map)
{
    iTotalMaxSpeed=_maxspeed;
    iCurrentMaxSpeed=_maxspeed;
    DriverMap=&_map;
    iDriverID=_ID;
    set_start_index(_startIndex);
    iRoadID=_startIndex;
    Position _startPosition=start_postion();
    DriverCar=new NormalCar(_orientation,_maxspeed,_startPosition,0);
    _scene.addItem(DriverCar);
    set_current_position();
    iCarType=0;
    sCarSensor=new Sensors(pCurrentPosition,iWayTable[iCrossRoadCnt],iRoadID,DriverCar->get_actualspeed(),iDriverID,DriverCar->rotation(),iCarType,iTotalMaxSpeed);
    DriverMap->addCarSensor(sCarSensor);
    find_way();


}

NormalDriver::~NormalDriver()
{
    delete DriverCar;
    DriverMap->deleteCarSensor(iDriverID);

}

void NormalDriver::find_way()
{

    srand (time(NULL));

    for (int it=0;it<5;it++)
    {
        iWayTable[it]=rand()%3;

    }



}

void NormalDriver::next_move()
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
    set_picked();


     DriverCar->move();
}

void NormalDriver::engine_malfunction()
{
    iTotalMaxSpeed=0;
    bStatus=0;
    sCarSensor->set_status(0);
    //DriverCar->damage_car();


}

bool NormalDriver::can_be_damaged()
{
   int LightDistance= DriverMap->check_if_stop_on_lights(pCurrentPosition, DriverCar->rotation(),iRoadID);

    if(iRoadID<=7 && (abs(LightDistance)>100) && (abs(LightDistance)<180) )
        if(DriverCar->get_position_onLane()==0 && !DriverMap->check_if_exit(iRoadID,sCarSensor->get_Orientation()))
        return 1;
    return 0;

}


