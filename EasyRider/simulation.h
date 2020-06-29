#ifndef SIMULATION_H
#define SIMULATION_H

#include<vector>
#include <QObject>
#include "normaldriver.h"
#include <QGraphicsScene>
#include "prioritydriver.h"
#include "map.h"

class Simulation: public QObject
{
    Q_OBJECT
private:
    Map *mMainMap;
    QGraphicsScene *MainScene;
    std::vector<Driver*> vCarVector;
    void random_parameters(int &_maxSpeed, int &_startIndex);
    int iDriversIDs=0;
    public:
    Simulation(QGraphicsScene *_Scene);
    ~Simulation();
    int prepare_car_to_add(int _startPosition);
    void deleteCars();
    void delay (int _milisecounds);
public slots:
    void add_car();
    void move_cars();
    void change_trafficlights();

};

#endif // SIMULATION_H
