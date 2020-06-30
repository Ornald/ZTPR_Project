#include "simulation.h"



Simulation::Simulation(QGraphicsScene *_Scene,QGraphicsView *View)
{

    MainScene=_Scene;
    Properties=new SimulationProperties(View);



     mMainMap = new Map(*MainScene);

    srand (time(NULL));

        MoveTimer = new QTimer(this);
        connect(MoveTimer,SIGNAL(timeout()),this,SLOT(move_cars()));
        MoveTimer->setInterval(40/iSimSpeed);
        MoveTimer->start();

//         AddTimer = new QTimer(this);
//         connect(AddTimer,SIGNAL(timeout()),this,SLOT(add_car()));
//         AddTimer->setInterval(iSpwnTime);
//         AddTimer->start();
//         TrafficLightTimer = new QTimer(this);
//         connect(TrafficLightTimer,SIGNAL(timeout()),this,SLOT(change_trafficlights()));
//         TrafficLightTimer->setInterval(iChangeLights);
//         TrafficLightTimer->start();
//         CheckPropertiesTimer = new QTimer(this);
//         connect(CheckPropertiesTimer,SIGNAL(timeout()),this,SLOT(check_properties()));
//         CheckPropertiesTimer->start(40);

}

Simulation::~Simulation()
{
    delete_all_cars();
    delete mMainMap;
    delete MoveTimer;
    delete AddTimer;
    delete CheckPropertiesTimer;
    delete TrafficLightTimer;
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

void Simulation::check_buttons()
{
    bool tmpStart=Properties->get_start();
    bool tmpStop=Properties->get_stop();
    bool tmpExit = Properties->get_exit();

    if(tmpStart!=bStart)
    {
        bStart=tmpStart;
    }
    if(tmpStop!=bStop)
    {
        bStop=tmpStop;
        stop_simulation();
    }
    if(tmpExit!=bExit)
    {
        bExit=tmpExit;
        bStop=1;

        qApp->quit();
    }


}

void Simulation::check_sliders()
{
    int tmpSimSpeed=Properties->get_simSpeed();
    int tmpSpwnTime=Properties->get_spwnTime();
    int tmpChangeLights=Properties->get_changLighTime();
    int tmpMaxCarNumber=Properties->get_maxCar();
    int tmpMaxCarSpeed=Properties->get_maxSpeed();
    int tmpPrecentageToDamage=Properties->get_precToDam();
    int tmpPrecentageToAmbulance=Properties->get_precToAmb();


    if(tmpSimSpeed!=iSimSpeed)
    {
        iSimSpeed=tmpSimSpeed;
        changeTimer(MoveTimer,40/iSimSpeed);
    }
    if(tmpSpwnTime!=iSpwnTime)
    {
        iSpwnTime=tmpSpwnTime;
        changeTimer(AddTimer,iSpwnTime);
    }
    if(tmpChangeLights!=iChangeLights)
    {
        iChangeLights=tmpChangeLights;
        changeTimer(TrafficLightTimer,tmpChangeLights);
    }


    if(tmpMaxCarNumber!=iMaxCarNumber)
    {
        iMaxCarNumber=tmpMaxCarNumber;
    }
    if(tmpMaxCarSpeed!=iMaxCarSpeed)
    {
        iMaxCarSpeed=tmpMaxCarSpeed;

    }
    if(tmpPrecentageToDamage!=iPrecentageToDamage)
    {
        iPrecentageToDamage=tmpPrecentageToDamage;

    }
    if(tmpPrecentageToAmbulance!=iPrecentageToAmbulance)
    {
        iPrecentageToAmbulance=tmpPrecentageToAmbulance;

    }

}

void Simulation::close_all()
{
    delete this;
}

void Simulation::stop_simulation()
{
    delete_all_cars();
}

void Simulation::delete_all_cars()
{
    for (size_t it=0;it<vCarVector.size();it++)
    {

           Driver *DriverToDelete=vCarVector.at(it);

        delete DriverToDelete;
        vCarVector.erase(vCarVector.begin()+it);
        it--;



    }
}

void Simulation::random_parameters(int &_maxSpeed,int &_startIndex)
{   _startIndex=rand()%8;
    _maxSpeed=rand()%iMaxCarSpeed+1;

}

void Simulation::changeTimer(QTimer *_timerToChange, int _interval)
{
    _timerToChange->setInterval(_interval);
}

void Simulation::add_car()
{
    if(bStart)
    {
    if(Driver::iCarnumber<iMaxCarNumber)
    {
    int _startIndex,_maxSpeed;
   _startIndex=6;
    _maxSpeed=5;
    //random_parameters(_maxSpeed,_startIndex);
    int _orientation=prepare_car_to_add(_startIndex);
    //int randomCarNumber = rand()%iPrecentageToAmbulance+1;
    int randomCarNumber=1;
    if (randomCarNumber>75)
    vCarVector.push_back(new PriorityDriver(_orientation,_maxSpeed,*MainScene,_startIndex,iDriversIDs,*mMainMap));
    else
     vCarVector.push_back(new NormalDriver(_orientation,_maxSpeed,*MainScene,_startIndex,iDriversIDs,*mMainMap));

    iDriversIDs++;
    }
    }
}

void Simulation::move_cars()
{

    if(bStart)
    {
        for (auto it:vCarVector)
        {
            it->next_move();
        }
        deleteCars();
    }


}

void Simulation::change_trafficlights()
{
    if(bStart)
    {
    mMainMap->change_lights();
    delay(1000);
    mMainMap->change_lights();
    }
}

void Simulation::check_properties()
{

    check_sliders();
    check_buttons();
}

void Simulation::close_simulation()
{

}
