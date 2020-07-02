#include "map.h"
const int speed=1;
Map::Map(QGraphicsScene & _scene)
{
    Scene=&_scene;

    int adjustment= 9*speed;

    load_crossroad(0,0,(pTurnsPositions(7).get_Y()+adjustment),(pTurnsPositions(2).get_Y()+adjustment));
    load_crossroad(1,0,(pTurnsPositions(7).get_Y()+adjustment),(pTurnsPositions(2).get_Y()+adjustment));
    load_crossroad(2,270,(pTurnsPositions(1).get_X()+adjustment),(pTurnsPositions(4).get_X()+adjustment));
    load_crossroad(3,270,(pTurnsPositions(1).get_X()+adjustment),(pTurnsPositions(4).get_X()+adjustment));
    load_crossroad(4,180,(pTurnsPositions(3).get_Y()-adjustment),(pTurnsPositions(6).get_Y()-adjustment));
    load_crossroad(5,180,(pTurnsPositions(3).get_Y()-adjustment),(pTurnsPositions(6).get_Y()-adjustment));
    load_crossroad(6,90,(pTurnsPositions(5).get_X()-adjustment),(pTurnsPositions(0).get_X()-adjustment));
    load_crossroad(7,90,(pTurnsPositions(5).get_X()-adjustment),(pTurnsPositions(0).get_X()-adjustment));
    load_crossroad(8,90,(pTurnsPositions(4).get_X()-adjustment),(pTurnsPositions(1).get_X()-adjustment));
    load_crossroad(8,270,(pTurnsPositions(0).get_X()+adjustment),(pTurnsPositions(5).get_X()+adjustment));
    load_crossroad(9,0,(pTurnsPositions(6).get_Y()+adjustment),(pTurnsPositions(3).get_Y()+adjustment));
    load_crossroad(9,180,(pTurnsPositions(2).get_Y()-adjustment),(pTurnsPositions(7).get_Y()-adjustment));
    load_crossroad(10,90,(pTurnsPositions(4).get_X()-adjustment),(pTurnsPositions(1).get_X()-adjustment));
    load_crossroad(10,270,(pTurnsPositions(0).get_X()+adjustment),(pTurnsPositions(5).get_X()+adjustment));
    load_crossroad(11,0,(pTurnsPositions(6).get_Y()+adjustment),(pTurnsPositions(3).get_Y()+adjustment));
    load_crossroad(11,180,(pTurnsPositions(2).get_Y()-adjustment),(pTurnsPositions(7).get_Y()-adjustment));



    load_trafficlight(Position(420,650),0,0,0,620);
    load_trafficlight(Position(420,540),2,270,8,430);
    load_trafficlight(Position(310,540),0,180,11,500);
    load_trafficlight(Position(310,650),2,90,7,310);

    load_trafficlight(Position(870,650),2,0,1,620);
    load_trafficlight(Position(870,540),0,270,2,870);
    load_trafficlight(Position(760,540),2,180,9,500);
    load_trafficlight(Position(760,650),0,90,8,750);

    load_trafficlight(Position(420,310),2,0,11,280);
    load_trafficlight(Position(420,200),0,270,10,430);
    load_trafficlight(Position(310,200),2,180,5,160);
    load_trafficlight(Position(310,310),0,90,6,310);

    load_trafficlight(Position(870,310),0,0,9,280);
    load_trafficlight(Position(870,200),2,270,3,870);
    load_trafficlight(Position(760,200),0,180,4,160);
    load_trafficlight(Position(760,310),2,90,10,750);

    add_traffics_light_to_scene();

}

Map::~Map()
{

    for (size_t it=0;it<vTrafficLVector.size();it++)
    {
        TrafficLight *TrafficLightToDelete=vTrafficLVector[it];
        delete TrafficLightToDelete;
    }
    vTrafficLVector.clear();

    for (size_t it=0;it<vAllCarSensor.size();it++)
    {
        Sensors*SensorToDelete=vAllCarSensor[it];
        delete SensorToDelete;
    }
    vAllCarSensor.clear();


}
int Map::check_if_turn(int _way, int _roadID, int _orientation, Position _carPosition)
{
        std::vector<CrossRoad>::iterator  it= find_crossroad(_roadID,_orientation);

     if(check_if_exit(_roadID,_orientation))
        return -1000;
    if(check_if_X_Y(_roadID))
    {
        return (it->get_cross_position(_way))-_carPosition.get_Y();
    }
    else
    {
        return (it->get_cross_position(_way))-_carPosition.get_X();
    }

}

int Map::next_road_id(int _way, int _roadID, int _orientation)
{
    int parameter=0;
    switch (_roadID){
    case 0:
        parameter=returnParameter(_way,8,11,7);
        break;
    case 1:
        parameter=returnParameter(_way,2,9,8);
        break;
    case 2:
        parameter=returnParameter(_way,9,8,1);
        break;
    case 3:
        parameter=returnParameter(_way,4,10,9);
        break;
    case 4:
        parameter=returnParameter(_way,10,9,3);
        break;
    case 5:
        parameter=returnParameter(_way,6,11,10);
        break;
    case 6:
        parameter=returnParameter(_way,11,10,5);
        break;
    case 7:
        parameter=returnParameter(_way,0,8,11);
        break;
    case 8:
        (_orientation==90)? parameter=returnParameter(_way,1,2,9) : parameter=returnParameter(_way,11,7,0);
        break;
    case 9:
        (_orientation==0)? parameter=returnParameter(_way,3,4,10) : parameter=returnParameter(_way,8,1,2);
        break;
    case 10:
        (_orientation==90)? parameter=returnParameter(_way,9,3,4) : parameter=returnParameter(_way,5,6,11);
        break;
    case 11:
        (_orientation==0)? parameter=returnParameter(_way,10,5,6) : parameter=returnParameter(_way,7,0,8);
        break;

    }
    return parameter;
}

void Map::change_lights()
{
    for(size_t it=0;it<vTrafficLVector.size();it++)
    {
        if (vTrafficLVector[it]->get_previous_status()==2)
        {
        vTrafficLVector[it]->change_light();
        vTrafficLVector[it]->set_recent_change(1);

        }
    }
    delay(400);

    for(size_t it=0;it<vTrafficLVector.size();it++)
    {
        if (vTrafficLVector[it]->get_previous_status()!=2 && vTrafficLVector[it]->get_if_recently_changed()==0)
        {
        vTrafficLVector[it]->change_light();
        vTrafficLVector[it]->set_recent_change(1);
        }

    }

    for(size_t it=0;it<vTrafficLVector.size();it++)
    {
        vTrafficLVector[it]->set_recent_change(0);

    }

}

void Map::load_crossroad(int _crossroadID,int _orientation,int _posR,int _posL)
{
    CrossRoad MyCrossroad( _crossroadID, _orientation, _posR, _posL);
    vCrossRoadVector.push_back(MyCrossroad);

}

Position Map::pTurnsPositions(int _index)
{

        Position _startPosition(0,0);
        switch (_index)
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

int Map::returnParameter(int _way,int _R, int _F, int _L)
{
    int parameter=0;

    if(1==_way)
        return _R;
    if(0==_way)
        return _F;
    if (2==_way)
        return _L;
    return parameter;
}

std::vector<CrossRoad>::iterator  Map::find_crossroad(int _roadID, int _orientation)
{
    std::vector<CrossRoad>::iterator it;
    it = std::find(vCrossRoadVector.begin(),vCrossRoadVector.end(),_roadID);
    return (it+check_roadID_condition(_roadID,_orientation));
}

bool Map::check_if_X_Y(int _roadID)
{
    if (0 == _roadID ||1 == _roadID ||4 == _roadID ||5 == _roadID ||9 == _roadID ||11 == _roadID )
        return 1;
    return 0;
}

bool Map::check_if_exit(int _roadID, int _orientation)
{
    if ((0==_roadID || 1==_roadID) && 180==_orientation)
        return 1;
    if ((2==_roadID || 3==_roadID) && 90==_orientation)
        return 1;
    if ((4==_roadID || 5==_roadID) && 0==_orientation)
        return 1;
    if ((6==_roadID || 7==_roadID) && 270==_orientation)
        return 1;
    return 0;

}

void Map::load_trafficlight(Position _position,int _startStatus,int _orientation,int _roadID,int _stopPoint)
{
    vTrafficLVector.push_back(new TrafficLight(_position,_startStatus,_orientation,_roadID,_stopPoint));
}

void Map::add_traffics_light_to_scene()
{
    for (auto it:vTrafficLVector)
    {
        Scene->addItem(it);
    }
}

void Map::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

int Map::check_if_stop_on_lights(Position _position, int _orientation, int _roadID)
{

   TrafficLight* it= find_trafficlight(_roadID,_orientation);


   if(check_if_exit(_roadID,_orientation))
   {

      return -1000;
   }
  if(check_if_X_Y(_roadID))
  {
      return (it->get_stopPoint())-_position.get_Y();
  }
  else
  {
      return (it->get_stopPoint())-_position.get_X();
  }


  return 0;
}

int Map::check_light_status(int _orientation, int _roadID)
{
    TrafficLight* it= find_trafficlight(_roadID,_orientation);
    return it->get_status();
}

bool Map::check_if_can_overtake(int _carID, int &_brokenCarID)
{
    Sensors *baseCar=find_Car_Sensor(_carID);
    Position CurrentPosition = baseCar->get_CarPosition();
    int orientation = baseCar->get_Orientation();
    int roadID=baseCar->get_RoadID();
    int lightDistance = check_if_stop_on_lights(CurrentPosition, orientation,roadID);

    int nextCarID = find_Next_Car(_carID,0,5);
    Sensors *nextCar = find_Car_Sensor(nextCarID);

    if(nextCar->get_status()==0)
    {
        _brokenCarID = nextCar->get_CarID();
        int distance = distance_to_next_car(_carID,1);
        int brokenCarDistance = distance_to_next_car(nextCarID,0);

        if ((distance>300 || distance==-1) && 80<abs(lightDistance))
            if(brokenCarDistance>100 || brokenCarDistance==-1)
            return 1;


    }

    return 0;
}

bool Map::check_if_can_return(int _carID, int _brokenCarID)
{
    Sensors *baseCar= find_Car_Sensor(_carID);
    Sensors *brokenCar = find_Car_Sensor(_brokenCarID);
    int X;
    int Y;
    check_distance_between(baseCar,brokenCar,X,Y);

    bool x_or_y = check_if_X_Y(baseCar->get_RoadID());

    if (x_or_y)
    {
        if (Y<-10)
            return 1;
    }
    else
    {
        if(X<-10)
            return 1;
    }
    return 0;

}

bool Map::check_if_can_turn_back(int _carID)
{
    Sensors *baseCar=find_Car_Sensor(_carID);
    Position CurrentPosition = baseCar->get_CarPosition();
    int orientation = baseCar->get_Orientation();
    int roadID=baseCar->get_RoadID();
    int lightDistance = check_if_stop_on_lights(CurrentPosition, orientation,roadID);

    int distance = distance_to_next_car(_carID,1);

    if((distance>200 || distance==-1) && 80<abs(lightDistance) && 280>abs(lightDistance) && !(check_if_exit(baseCar->get_RoadID(),baseCar->get_Orientation())))
        return 1;
    return 0;
}


TrafficLight* Map::find_trafficlight(int _roadID, int _orientation)
{
     TrafficLight *it;

     for (size_t i=0;i<vTrafficLVector.size();i++)
     {
         if(vTrafficLVector[i]->get_roadID()==_roadID)
         {
             if(1==check_roadID_condition(_roadID,_orientation))
             {

                it=vTrafficLVector[i-6];
             }
            else
             {
                it=vTrafficLVector[i];
             }
         }

     }


     return it;

}

int Map::find_Next_Car(int _carID, int _sndMinDistance, int _sndMaxDistance)
{
    Sensors *baseCarSensor = find_Car_Sensor(_carID);
    bool x_or_y = check_if_X_Y(baseCarSensor->get_RoadID());
    int min = 1500;
    int minID=-1;
    int Ydif;
    int Xdif;

    for(size_t it=0;it<vAllCarSensor.size();it++)
    {
        check_distance_between(baseCarSensor,vAllCarSensor[it],Xdif,Ydif);


        if(x_or_y)
        {
            if (Ydif>0 && Ydif<min && abs(Xdif)<_sndMaxDistance && abs(Xdif)>=_sndMinDistance && baseCarSensor->get_CarID()!=vAllCarSensor[it]->get_CarID())
            {
                min=Ydif;
                minID = vAllCarSensor[it]->get_CarID();

            }
        }
        else
        {
            if (Xdif >0 && Xdif<min && abs(Ydif)<_sndMaxDistance && abs(Ydif)>=_sndMinDistance && baseCarSensor->get_CarID()!=vAllCarSensor[it]->get_CarID())
            {
                min=Xdif;
                minID = vAllCarSensor[it]->get_CarID();

            }

        }
    }

    return minID;
}

Sensors *Map::find_Car_Sensor(int _carID)
{
    for(size_t it=0;it<vAllCarSensor.size();it++)
    {
        if(vAllCarSensor[it]->get_CarID()==_carID)
        {

            return vAllCarSensor[it];
        }
    }
    return 0;

}

int Map::distance_to_next_car(int _carID, int _lane)
{
    Sensors *baseSensor= find_Car_Sensor(_carID);
    int nextCarID;
    if (_lane==0)
    nextCarID = find_Next_Car(_carID,0,5);
    else
      nextCarID=find_Next_Car(_carID,20,40);
    if (-1==nextCarID)
        return -1;

    Sensors* NextCarSensor=find_Car_Sensor(nextCarID);
   bool x_or_y = check_if_X_Y(baseSensor->get_RoadID());
   int Xdis;
   int Ydis;

    check_distance_between(baseSensor,NextCarSensor,Xdis,Ydis);
   if(x_or_y)
   {
       return Ydis;
   }
   else
   {
       return Xdis;
   }


   return -1;
}

int Map::get_next_car_speed(int _carID)
{
    int nextCarID = find_Next_Car(_carID,0,5);
    if(-1==nextCarID)
        return -1;
    Sensors *baseCarSensor = find_Car_Sensor(nextCarID);

    return baseCarSensor->get_ActualSpeed();
}

void Map::check_distance_between(Sensors *_fstSensor, Sensors *_sndSensor, int &_Xdiff, int &_Ydiff)
{
    if (_fstSensor->get_CarPosition().get_Y()>0)
    {
     _Ydiff= _sndSensor->get_CarPosition().get_Y()-_fstSensor->get_CarPosition().get_Y();
    }
    else
    {
      _Ydiff = _sndSensor->get_CarPosition().get_Y()+_fstSensor->get_CarPosition().get_Y();

    }
    if (_fstSensor->get_CarPosition().get_X()>0)
    {
           _Xdiff = _sndSensor->get_CarPosition().get_X()-_fstSensor->get_CarPosition().get_X();
    }
    else
    {
        _Xdiff = _sndSensor->get_CarPosition().get_X()+_fstSensor->get_CarPosition().get_X();
    }
    if (_fstSensor->get_Orientation()==270 || _fstSensor->get_Orientation()==0)
     {
        _Ydiff=_Ydiff*(-1);
        _Xdiff=_Xdiff*(-1);

    }
}

int Map::get_trafficLight_position(int _nextRoadID,int _orientation)
{

    switch(_nextRoadID)
    {

    case 0:
    case 1:
        return 620;
        break;
    case 2:
    case 3:
        return 870;
        break;
    case 4:
    case 5:
        return 160;
        break;
    case 6:
    case 7:
        return 310;
        break;
    case 8:
        if(270==_orientation)
            return 750;
        return 430;
        break;
    case 9:
        if(180==_orientation)
            return 280;;
        return 500;
        break;
    case 10:
        if(270==_orientation)
            return 750;
        return 430;
        break;
    case 11:
        if(180==_orientation)
            return 280;;
        return 500;
        break;


    }

    return 0;
}

int Map::get_next_orientation(int _way, int _orientation)
{
    int tmp=0;
    switch (_way)
    {
    case 0:
        return _orientation;
        break;
     case 1:
        (0==_orientation)? tmp=90 : (90==_orientation)? tmp=180 : (180==_orientation)? tmp=270 : tmp =0;
        return tmp;
        break;
    case 2:
       (0==_orientation)? tmp=270 : (90==_orientation)? tmp=0 : (180==_orientation)? tmp=90 : tmp =180;
        return tmp;
       break;
    }
    return 0;
}





bool Map::check_if_on_crossroad(Position _carPosition, int _xmin,int _xmax,int _ymin,int _ymax)
{


    if(_carPosition.get_X()<_xmax && _carPosition.get_X()>_xmin)
    {
        if(_carPosition.get_Y()<_ymax && _carPosition.get_Y()>_ymin)
        {

            return 1;
        }
    }

    return 0;

}

void Map::get_crossroad_positions(int _ID, int &_xmin, int &_xmax, int &_ymin, int &_ymax)
{
    switch (_ID) {
    case 0:
        _xmin=330;
        _xmax=410;
        _ymin=520;
        _ymax=600;
        break;
    case 1:
        _xmin=770;
        _xmax=850;
        _ymin=520;
        _ymax=600;
        break;
    case 2:
        _xmin=770;
        _xmax=850;
        _ymin=180;
        _ymax=260;
        break;
    case 3:
        _xmin=330;
        _xmax=410;
        _ymin=180;
        _ymax=260;
        break;
    }
}

int Map::get_closest_crossroad(int _roadID, int _orientation)
{
    switch(_roadID)
    {
    case 0:
    case 7:
        return 0;
        break;
    case 1:
    case 2:
        return 1;
        break;
    case 3:
    case 4:
        return 2;
        break;
    case 5:
    case 6:
        return 3;
        break;
    case 8:
        if(90==_orientation)
                return 1;
        return 0;
                break;
    case 9:
        if(0==_orientation)
                return 2;
        return 1;
                break;
    case 10:
        if(90==_orientation)
                return 2;
        return 3;
                break;
    case 11:
        if(0==_orientation)
                return 3;
        return 0;
                break;

    }
    return 0;
}

bool Map::check_if_crossroad_free(int _carID)
{
    Sensors *baseCar=find_Car_Sensor(_carID);

    int closestCrossroad = get_closest_crossroad(baseCar->get_RoadID(),baseCar->get_Orientation());



    int Xmin,Xmax,Ymin,Ymax;
    get_crossroad_positions(closestCrossroad,Xmin,Xmax,Ymin,Ymax);

    for(size_t it=0;it<vAllCarSensor.size();it++)
    {
        if(vAllCarSensor[it]->get_CarID()!=_carID)
        {
            if (check_if_on_crossroad(vAllCarSensor[it]->get_CarPosition(),Xmin,Xmax,Ymin,Ymax))
            {

                return 0;
            }
        }
    }

    return 1;
}

bool Map::check_if_close_to_target(int _carID, int _targetCarID)
{
    Sensors * baseCar= find_Car_Sensor(_carID);
    Sensors *TargetCar = find_Car_Sensor(_targetCarID);
    int X;
    int Y;
    bool x_or_y;
    if(baseCar->get_RoadID()==TargetCar->get_RoadID())
    {
     check_distance_between(baseCar,TargetCar,X,Y);
     x_or_y = check_if_X_Y(baseCar->get_RoadID());

     if(x_or_y)
     {
         if(Y<10)
             return 1;
     }
     else
     {
         if(X<10)
             return 1;
     }
    }
    return 0;
}

bool Map::check_if_can_drive(int _carID)
{
    Sensors *baseCar=find_Car_Sensor(_carID);
    int nextRoad=next_road_id(0,baseCar->get_RoadID(),baseCar->get_Orientation());
    int min=1500;
    int minID=-1;


    find_car_on_next_road(_carID,nextRoad,min,minID,180);


   if ((min>50 || -1==minID) && check_if_crossroad_free(_carID))
   {

       if((baseCar->get_CarNextMove()==2 && check_if_crossroad_free(_carID)))
       {
        return 1;
       }
       else if(baseCar->get_CarNextMove()==2)
       {

           return 0;

       }
       return 1;
   }
    if (minID>=0)
    {
        Sensors *nextCar= find_Car_Sensor(minID);

        if(nextCar->get_CarNextMove()==baseCar->get_CarNextMove()&& min<50)
        {
            if(nextCar->get_CarNextMove()==2)
            {
                int fstCarRoadID= next_road_id(baseCar->get_CarNextMove(),baseCar->get_RoadID(),baseCar->get_Orientation());
                int sndCarRoadID = next_road_id(nextCar->get_CarNextMove(),nextCar->get_RoadID(),nextCar->get_Orientation());
                if(fstCarRoadID<sndCarRoadID)
                    return 1;
                return 0;
            }
            else {
                return 1;
            }

        }
        if(nextCar->get_carType()==1 && baseCar->get_carType()==0)
            return 0;
        if(nextCar->get_carType()==0 && baseCar->get_carType()==1)
            return 1;

        if(nextCar->get_CarNextMove()==0 && (baseCar->get_CarNextMove()==1 || baseCar->get_CarNextMove()==0) && min<50)
        {
            return 1;
        }
        if (nextCar->get_CarNextMove()==1 && (baseCar->get_CarNextMove()==1 || baseCar->get_CarNextMove()==0) && min<50)
        {
            return 1;
        }
        if(baseCar->get_CarNextMove()==2 && nextCar->get_CarNextMove()!=2 && min<50)
            return 0;
        if (baseCar->get_CarNextMove()!=2 && nextCar->get_CarNextMove()==2 && min<50 && check_if_crossroad_free(_carID))
            return 1;

    }

    return 0;

}




void Map::addCarSensor(Sensors *_sensorToAdd)
{
    vAllCarSensor.push_back(_sensorToAdd);
}
bool Map::check_if_stuck(int _carID)
{
    Sensors *baseCar=find_Car_Sensor(_carID);

    int min;
    int minID;
    int  nextRoadID = next_road_id(baseCar->get_CarNextMove(),baseCar->get_RoadID(),baseCar->get_Orientation());
    find_car_on_next_road(_carID,nextRoadID,min,minID,0);

    if (minID>=0)
    {
        Sensors *lastCars = find_Car_Sensor(minID);
        if(min<=20 && lastCars->get_ActualSpeed()==0)
        {

            return 1;
        }

    }
    return 0;
}

void Map::find_car_on_next_road(int _carID,int _nextRoadID, int & _min, int & _minID, int _orienDiff)
{
    Sensors *baseCar=find_Car_Sensor(_carID);


    Sensors *sndCar;
     _min =1500;
     _minID=-1;
     int orientation;


    int lightPosition=get_trafficLight_position(_nextRoadID,get_next_orientation(baseCar->get_CarNextMove(),baseCar->get_Orientation()));
    bool x_or_y = check_if_X_Y(_nextRoadID);

    if (check_if_exit(baseCar->get_RoadID(),baseCar->get_Orientation()))
    {

       _minID=-1;
    }
    else
    {
        for (size_t it =0 ;it<vAllCarSensor.size();it++)
        {
            sndCar=find_Car_Sensor(it);
           if(sndCar!=0)
            {
                if(sndCar->get_RoadID()==_nextRoadID)
                 {
                    if(_orienDiff==180)
                    {
                     orientation= abs(sndCar->get_Orientation()-baseCar->get_Orientation());
                    }
                    else
                    {
                        orientation= abs(sndCar->get_Orientation()-get_next_orientation(baseCar->get_CarNextMove(),baseCar->get_Orientation()));
                    }


                    if (x_or_y)
                    {
                        if(abs(abs(sndCar->get_CarPosition().get_Y())-abs(lightPosition))<_min && orientation==_orienDiff)
                        {
                            _min = abs(abs(sndCar->get_CarPosition().get_Y())-abs(lightPosition));
                            _minID = sndCar->get_CarID();

                        }
                    }
                    else
                    {
                        if(abs(abs(sndCar->get_CarPosition().get_X())-abs(lightPosition))<_min && orientation==_orienDiff)
                        {

                        _min = abs(abs(sndCar->get_CarPosition().get_X())-abs(lightPosition));
                        _minID = sndCar->get_CarID();

                        }
                    }
                }
            }
        }
    }



}

void Map::deleteCarSensor(int _carID)
{
    for(size_t it=0;it<vAllCarSensor.size();it++)
    {
        if(vAllCarSensor[it]->get_CarID()==_carID)
        {
            Sensors *sensorToDelete = vAllCarSensor[it];
        delete sensorToDelete;
            vAllCarSensor.erase(vAllCarSensor.begin()+it);
            it--;
        }

    }
}




int Map::check_roadID_condition(int _roadID, int _orientation)
{
    if ((8==_roadID || 10==_roadID) && 270==_orientation)
        return 1;
    if ((9==_roadID || 11==_roadID)&& 180==_orientation)
        return 1;
    return 0;


}
