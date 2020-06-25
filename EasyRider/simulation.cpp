#include "simulation.h"



Simulation::Simulation(QGraphicsScene *_Scene)
{
    MainScene=_Scene;
    srand (time(NULL));

//         QTimer *MoveTimer = new QTimer(this);
//         connect(MoveTimer,SIGNAL(timeout()),this,SLOT(move_cars()));
//         MoveTimer->start(50);
}

Simulation::~Simulation()
{

}
void Simulation::random_parameters(int &_orientation,int &_maxSpeed,int &_startIndex)
{   _startIndex=1;
    _maxSpeed=1;
    _orientation=0;
}

void Simulation::add_car()
{
    int _orientation=0;
    int _maxSpeed=1;
     int _startIndex=0;


    vCarVector.push_back(new NormalDriver(_orientation,_maxSpeed,*MainScene,_startIndex,iDriversIDs));
    iDriversIDs++;
}

void Simulation::move_cars()
{
    for (auto it:vCarVector)
    {
    it->next_move();
    }
}
