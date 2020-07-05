#include "tugdriver.h"

TugDriver::TugDriver(int _orientation, int _maxspeed,QGraphicsScene& _scene,int _startIndex,int _ID, Map &_map, int _targetID, int _targetRoadID)
{
    iTotalMaxSpeed=_maxspeed;
    iCurrentMaxSpeed=_maxspeed;
    DriverMap=&_map;
    iDriverID=_ID;
    set_start_index(_startIndex);
    iRoadID=_startIndex;
    Position _startPosition=start_postion();
    DriverCar=new TugCar(_orientation,_maxspeed,_startPosition);
    _scene.addItem(DriverCar);
    set_current_position();
    iCarType=0;
    sCarSensor=new Sensors(pCurrentPosition,iWayTable[iCrossRoadCnt],iRoadID,DriverCar->get_actualspeed(),iDriverID,DriverCar->rotation(),iCarType,iTotalMaxSpeed);
    DriverMap->addCarSensor(sCarSensor);
    iTargetID=_targetID;
    iTargetRoadID=_targetRoadID;

    find_way();

}

TugDriver::~TugDriver()
{
    delete DriverCar;
    DriverMap->deleteCarSensor(iDriverID);

}

void TugDriver::find_way()
{
            iWayTable[0]=0;
            iWayTable[1]=0;
            iWayTable[2]=0;
            iWayTable[3]=0;
            iWayTable[4]=0;
            prepare_table_close(iStartIndex,iTargetRoadID);
            prepare_table_middle(iStartIndex,iTargetRoadID);
            prepare_table_long(iStartIndex,iTargetRoadID);



}

void TugDriver::prepare_table_close(int _startIndex, int _target)
{
    if((0==_startIndex && 7==_target) || (6==_startIndex && 5==_target) || (4==_startIndex && 3==_target) || (2==_startIndex && 1==_target))
    {
        iWayTable[0]=2;
        iWayTable[1]=0;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((7==_startIndex && 0==_target) || (5==_startIndex && 6==_target) || (3==_startIndex && 4==_target) || (1==_startIndex && 2==_target))
    {
        iWayTable[0]=1;
        iWayTable[1]=0;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }


}

void TugDriver::prepare_table_middle(int _startIndex, int _target)
{
    if((7==_startIndex && 6==_target) || (5==_startIndex && 4==_target) || (3==_startIndex && 2==_target) || (1==_startIndex && 0==_target))
    {
        iWayTable[0]=2;
        iWayTable[1]=2;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((0==_startIndex && 1==_target) || (2==_startIndex && 3==_target) || (4==_startIndex && 5==_target) || (6==_startIndex && 7==_target))
    {
        iWayTable[0]=1;
        iWayTable[1]=1;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((0==_startIndex && 5==_target) || (1==_startIndex && 4==_target) || (2==_startIndex && 7==_target) || (3==_startIndex && 6==_target))
    {
        iWayTable[0]=0;
        iWayTable[1]=0;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }
    if((5==_startIndex && 0==_target) || (4==_startIndex && 1==_target) || (7==_startIndex && 2==_target) || (6==_startIndex && 3==_target))
    {
        iWayTable[0]=0;
        iWayTable[1]=0;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((0==_startIndex && 6==_target) || (4==_startIndex && 2==_target) || (2==_startIndex && 0==_target) || (6==_startIndex && 4==_target))
    {
        iWayTable[0]=0;
        iWayTable[1]=2;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((7==_startIndex && 1==_target) || (5==_startIndex && 7==_target) || (3==_startIndex && 5==_target) || (1==_startIndex && 3==_target))
    {
        iWayTable[0]=0;
        iWayTable[1]=1;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((0==_startIndex && 2==_target) || (6==_startIndex && 0==_target) || (4==_startIndex && 6==_target) || (2==_startIndex && 4==_target))
    {
        iWayTable[0]=1;
        iWayTable[1]=0;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }
    if((1==_startIndex && 7==_target) || (7==_startIndex && 5==_target) || (5==_startIndex && 3==_target) || (3==_startIndex && 1==_target))
    {
        iWayTable[0]=2;
        iWayTable[1]=0;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }


}

void TugDriver::prepare_table_long(int _startIndex, int _target)
{

    if((0==_startIndex && 3==_target) || (2==_startIndex && 5==_target) || (6==_startIndex && 1==_target) || (4==_startIndex && 7==_target))
    {
        iWayTable[0]=0;
        iWayTable[1]=1;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((1==_startIndex && 6==_target) || (5==_startIndex && 2==_target) || (3==_startIndex && 0==_target) || (7==_startIndex && 4==_target))
    {
        iWayTable[0]=0;
        iWayTable[1]=2;
        iWayTable[2]=0;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((0==_startIndex && 4==_target) || (2==_startIndex && 6==_target) || (4==_startIndex && 0==_target) || (6==_startIndex && 2==_target))
    {
        iWayTable[0]=0;
        iWayTable[1]=1;
        iWayTable[2]=2;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }

    if((1==_startIndex && 5==_target) || (3==_startIndex && 7==_target) || (5==_startIndex && 1==_target) || (7==_startIndex && 3==_target))
    {
        iWayTable[0]=0;
        iWayTable[1]=2;
        iWayTable[2]=1;
        iWayTable[3]=0;
        iWayTable[4]=0;
    }
}

void TugDriver::pick_up_target()
{
    if(iPicked == 0 && DriverMap->check_if_close_to_target(iDriverID,iTargetID))
    {
        DriverCar->change_tow_occupation();
        iTotalMaxSpeed=1;
        DriverCar->set_maxspeed(iTotalMaxSpeed);
        iPicked=1;
    }
}



void TugDriver::next_move()
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
    pick_up_target();



    DriverCar->move();
}

int TugDriver::picked_up_id()
{
    if(iPicked==1)
    {
        return iTargetID;

    }
    return -1;
}
