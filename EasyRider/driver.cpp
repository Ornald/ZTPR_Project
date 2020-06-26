#include "driver.h"



Driver::Driver()
{

    find_way();



}

Driver::~Driver()
{

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
    if (0==_diffPosition)
    {
        if(iWayTable[iCrossRoadCnt]==1)
        {
            DriverCar->turn_right();
            iRoadID=DriverMap.next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;

        }
        else if (iWayTable[iCrossRoadCnt]==2)
        {
            DriverCar->turn_left();
            iRoadID=DriverMap.next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;

        }
        else
        {   iRoadID=DriverMap.next_road_id(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation());
            if(iCrossRoadCnt<4)
              iCrossRoadCnt++;

        }
    }
}

void Driver::find_way()
{
    //to do normal car
    srand (time(NULL));

    for (int it=0;it<5;it++)
    {
        iWayTable[it]=rand()%3;
        //iWayTable[it]=0;
       // qDebug()<<iWayTable[it]<<endl;
    }
//        iWayTable[0]=2;
//        iWayTable[1]=2;
//        iWayTable[2]=1;
//        iWayTable[3]=0;
//        iWayTable[4]=0;


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
  int result =DriverMap.check_if_turn(iWayTable[iCrossRoadCnt],iRoadID,DriverCar->rotation(),pCurrentPosition);
//  qDebug()<<result<<iRoadID;
    check_crossroad_position(result);


 DriverCar->move();
 //qDebug()<<DriverCar->pos()<<endl;
}
