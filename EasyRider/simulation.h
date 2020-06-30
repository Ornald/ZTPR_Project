#ifndef SIMULATION_H
#define SIMULATION_H

#include<vector>
#include <QObject>
#include "normaldriver.h"
#include <QGraphicsScene>
#include "prioritydriver.h"
#include "map.h"
#include "simulationproperties.h"
#include <QGraphicsView>

class Simulation: public QObject
{
    Q_OBJECT
private:
    Map *mMainMap;
    QGraphicsScene *MainScene;
    QGraphicsView *View;
    SimulationProperties *Properties;
    std::vector<Driver*> vCarVector;

    QTimer *MoveTimer;
    QTimer *AddTimer;
    QTimer *TrafficLightTimer;
    QTimer *CheckPropertiesTimer;

    void random_parameters(int &_maxSpeed, int &_startIndex);
    int iDriversIDs=0;
    int iSimSpeed=1;
    int iSpwnTime=2000;
    int iChangeLights=6000;
    int iMaxCarNumber=5;
    int iMaxCarSpeed=3;
    int iPrecentageToDamage=1;
    int iPrecentageToAmbulance=1;

    bool bStart=1;
    bool bStop=0;
    bool bExit=0;

    void changeTimer(QTimer *_timerToChange, int _interval);
    public:
    Simulation(QGraphicsScene *_Scene, QGraphicsView *View);
    ~Simulation();
    int prepare_car_to_add(int _startPosition);
    void deleteCars();
    void delay (int _milisecounds);
    void check_buttons();
    void check_sliders();
    void close_all();
    void stop_simulation();
    void delete_all_cars();
private slots:
    void add_car();
    void move_cars();
    void change_trafficlights();
    void check_properties();

public slots:
    void close_simulation();

};

#endif // SIMULATION_H
