#include "simulationproperties.h"

SimulationProperties::SimulationProperties(QGraphicsView *MainView)
{

    SimulationTime = new QSlider(Qt::Horizontal);

    SpawnTime = new QSlider(Qt::Horizontal);
    ChangeLightsTime = new QSlider(Qt::Horizontal);
    MaxCarsNumber = new QSlider(Qt::Horizontal);
    MaxCarsSpeed = new QSlider(Qt::Horizontal);
    MinCarsSpeed = new QSlider(Qt::Horizontal);
    PrecentageToDamage = new QSlider(Qt::Horizontal);
    PrecentageToAmbulance = new QSlider(Qt::Horizontal);

    StartBtn = new QPushButton("Start");
    StopBtn = new QPushButton("Stop");
    PauseBtn = new QPushButton("Pauza");

    TurnDamage = new QComboBox();
    TurnAmbulance= new QComboBox();

}

void SimulationProperties::add_sliders(QGraphicsView *MainView)
{

}

void SimulationProperties::add_buttons(QGraphicsView *MainView)
{

}

void SimulationProperties::add_comboboxes(QGraphicsView *MainView)
{

}
