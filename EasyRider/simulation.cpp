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

         AddTimer = new QTimer(this);
         connect(AddTimer,SIGNAL(timeout()),this,SLOT(add_car()));
         AddTimer->setInterval(iSpwnTime);
         AddTimer->start();
         TrafficLightTimer = new QTimer(this);
         connect(TrafficLightTimer,SIGNAL(timeout()),this,SLOT(change_trafficlights()));
         TrafficLightTimer->setInterval(iChangeLights);
         TrafficLightTimer->start();
         CheckPropertiesTimer = new QTimer(this);
         connect(CheckPropertiesTimer,SIGNAL(timeout()),this,SLOT(check_properties()));
         CheckPropertiesTimer->start(40);

}

Simulation::~Simulation()
{
    delete_all_cars();
    delete mMainMap;
    delete MoveTimer;
    delete AddTimer;
    delete CheckPropertiesTimer;
    delete TrafficLightTimer;
    delete MainScene;
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
    bool tmpDestory = Properties->get_destroy();

    if(tmpStart!=bStart)
    {
        bStart=tmpStart;
    }
    if(tmpStop!=bStop)
    {
        bStop=tmpStop;
        iDamagedCarsNumber=0;
        stop_simulation();
    }
    if(tmpExit!=bExit)
    {
        bExit=tmpExit;
        bStop=1;


        qApp->quit();


    }
    if( bDestory!=tmpDestory)
    {

        Properties->set_destroyed(0);

        damage_two_cars();
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

void Simulation::check_checkboxes()
{

    bool tmpAmbulance=Properties->get_bAmbulance();
    bool tmpDamage=Properties->get_bDamage();


    if(tmpAmbulance!=bAmbulance)
    {
        bAmbulance=tmpAmbulance;
    }
    if(tmpDamage!=bDamage)
    {
        bDamage=tmpDamage;

    }

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

void Simulation::damage_some_cars()
{
    int DamagedCarID=-1;
    int TowDriverID;
    if(bDamage)
    {
        if(iCounter>2000)
        {
            if(iDamagedCarsNumber<2)
            {
                int randomNumber = (rand()&100);

                if(randomNumber>100-iPrecentageToDamage)
                {
                    for (size_t it =0 ;it <vCarVector.size();it++)
                    {
                        if(iDamagedCarsNumber<2)
                        {

                            if (vCarVector[it]->can_be_damaged()&&vCarVector[it]->get_roadID()!=iLastRoadDamaged && iCounter>2000)
                            {

                                vCarVector[it]->engine_malfunction();
                                iDamagedCarsNumber++;
                                TowDriverID=iDriversIDs;
                                vCarVector[it]->set_TowCarID(TowDriverID);
                                iDriversIDs++;
                                iLastRoadDamaged=vCarVector[it]->get_roadID();
                                iCounter=0;
                                DamagedCarID=vCarVector[it]->get_DriverID();


                            }
                        }
                    }
                    if(DamagedCarID!=-1)
                    {

                    int _startIndex = rand()%8;

                    int _maxSpeed=rand()%iMaxCarSpeed+1;
                    if(_startIndex==iLastRoadDamaged)
                    {
                        int randomNumber=(rand()%2)+1;
                        if(randomNumber==1)
                        { _startIndex--;
                            if(_startIndex==-1)
                                _startIndex=7;
                        }
                        else {
                            _startIndex++;
                            if(_startIndex==8)
                                _startIndex=0;
                        }
                    }
                    int _orientation=prepare_car_to_add(_startIndex);
                    vCarVector.push_back(new TugDriver(_orientation,_maxSpeed,*MainScene,_startIndex,TowDriverID,*mMainMap,DamagedCarID,iLastRoadDamaged));

                            DamagedCarID=-1;
                    }
                }

            }

        }
        else
            iCounter++;
    }
}


void Simulation::delete_picked_cars()
{


    for (size_t it =0 ;it <vCarVector.size();it++)
    {
        if(vCarVector[it]->get_picked())
        {
           Driver *DriverToDelete=vCarVector.at(it);

        delete DriverToDelete;
        vCarVector.erase(vCarVector.begin()+it);
        it--;
        iDamagedCarsNumber--;

        }
    }

}

void Simulation::random_parameters(int &_maxSpeed,int &_startIndex)
{
    _startIndex=rand()%8;
    _maxSpeed=rand()%iMaxCarSpeed+1;

    if(_startIndex==iLastRoadSpawn)
    {
        int randomNumber=(rand()%2)+1;
        if(randomNumber==1)
        { _startIndex--;
            if(_startIndex==-1)
                _startIndex=7;
        }
        else {
            _startIndex++;
            if(_startIndex==8)
                _startIndex=0;
        }

    }

    iLastRoadSpawn=_startIndex;



}

void Simulation::changeTimer(QTimer *_timerToChange, int _interval)
{
    _timerToChange->setInterval(_interval);
}

void Simulation::check_stuck_cars()
{
    for(size_t it =0 ;it<vCarVector.size();it++)
    {
        if((*vCarVector[it]).check_if_stuck())
        {
           Driver *DriverToDelete=vCarVector.at(it);

        delete DriverToDelete;
        vCarVector.erase(vCarVector.begin()+it);
        it--;


        }
    }
}

void Simulation::add_car()
{
    if(bStart)
    {
        int randomCarNumber;

    if(Driver::iCarnumber<iMaxCarNumber)
    {
    int _startIndex,_maxSpeed;

    random_parameters(_maxSpeed,_startIndex);
    int _orientation=prepare_car_to_add(_startIndex);
    if(bAmbulance)
    {

        randomCarNumber = rand()%100+1;

         if (randomCarNumber>(100-iPrecentageToAmbulance))
         vCarVector.push_back(new PriorityDriver(_orientation,_maxSpeed,*MainScene,_startIndex,iDriversIDs,*mMainMap));
         else
          vCarVector.push_back(new NormalDriver(_orientation,_maxSpeed,*MainScene,_startIndex,iDriversIDs,*mMainMap));
    }
    else
    {
       vCarVector.push_back(new NormalDriver(_orientation,_maxSpeed,*MainScene,_startIndex,iDriversIDs,*mMainMap));

    }


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
        damage_some_cars();
        delete_picked_cars();
        deleteCars();
        check_stuck_cars();

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
    check_checkboxes();
}



void Simulation::damage_two_cars()
{
 int iCarDestroyed=0;
 if(vCarVector.size()>2)
 {
    while(iCarDestroyed<2)
    {
    int randomCar=rand()%vCarVector.size();


    if(vCarVector[randomCar]->get_carType()==0 && vCarVector[randomCar]->get_status()==1)
    {
       vCarVector[randomCar]->engine_malfunction();
        iCarDestroyed++;

    }


    }
 }


}




