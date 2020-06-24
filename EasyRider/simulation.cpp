#include "simulation.h"

Simulation::Simulation(QGraphicsScene *_Scene)
{
    MainScene=_Scene;
}

Simulation::~Simulation()
{

}

void Simulation::add_car()
{
    vCarVector.push_back(new NormalDriver(0,1,*MainScene));
}

void Simulation::move_cars()
{
    for (auto it:vCarVector)
    {
    it->next_move();
    }
}
