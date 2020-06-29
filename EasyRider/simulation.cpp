#include "simulation.h"



Simulation::Simulation(QGraphicsScene *_Scene)
{

    MainScene=_Scene;
     mMainMap = new Map(*MainScene);

    srand (time(NULL));

         QTimer *MoveTimer = new QTimer(this);
         connect(MoveTimer,SIGNAL(timeout()),this,SLOT(move_cars()));
         MoveTimer->start(40);
//         QTimer *AddTimer = new QTimer(this);
//         connect(AddTimer,SIGNAL(timeout()),this,SLOT(add_car()));
//         AddTimer->start(2000);

//         QTimer *TrafficLightTimer = new QTimer(this);
//          connect(TrafficLightTimer,SIGNAL(timeout()),this,SLOT(change_trafficlights()));
//          TrafficLightTimer->start(2000);

}

Simulation::~Simulation()
{
    for (size_t it=0;it<vCarVector.size();it++)
    {

           Driver *DriverToDelete=vCarVector.at(it);

        delete DriverToDelete;
        vCarVector.erase(vCarVector.begin()+it);
        it--;



    }
    delete mMainMap;
}

int Simulation::prepare_car_to_add(int _startPosition)
{
  switch(_startPosition){
  case 0:
  case 1:
      return 0;
      break;
  case 2:
  case 3:
      return 270;
      break;
  case 4:
  case 5:
      return 180;
      break;
  case 6:
  case 7:
      return 90;
      break;
  default:
      return 0;
  }
}

void Simulation::deleteCars()
{
    for (size_t it=0;it<vCarVector.size();it++)
    {
        if((*vCarVector[it]).check_if_out_board())
        {
           Driver *DriverToDelete=vCarVector.at(it);

        delete DriverToDelete;
        vCarVector.erase(vCarVector.begin()+it);
        it--;


        }
    }


}


void Simulation::delay(int _milisecounds)
{
    QTime dieTime = QTime::currentTime().addMSecs( _milisecounds );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void Simulation::random_parameters(int &_maxSpeed,int &_startIndex)
{   _startIndex=rand()%8;
    _maxSpeed=4;

}

void Simulation::add_car()
{
    int _startIndex,_maxSpeed;
   _startIndex=6;
    _maxSpeed=5;
    //random_parameters(_maxSpeed,_startIndex);
    int _orientation=prepare_car_to_add(_startIndex);
    //int randomCarNumber = rand()%100;
    int randomCarNumber = 1;
    if (randomCarNumber>75)
    vCarVector.push_back(new PriorityDriver(_orientation,_maxSpeed,*MainScene,_startIndex,iDriversIDs,*mMainMap));
    else
     vCarVector.push_back(new NormalDriver(_orientation,_maxSpeed,*MainScene,_startIndex,iDriversIDs,*mMainMap));

    iDriversIDs++;
}

void Simulation::move_cars()
{
    for (auto it:vCarVector)
    {
    it->next_move();
    }
    deleteCars();


}

void Simulation::change_trafficlights()
{
    mMainMap->change_lights();
    delay(1000);
    mMainMap->change_lights();
}
