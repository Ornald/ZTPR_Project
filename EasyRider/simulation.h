#ifndef SIMULATION_H
#define SIMULATION_H

#include<vector>
#include <QObject>
#include "normaldriver.h"
#include <QGraphicsScene>

class Simulation: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *MainScene;
    std::vector<Driver*> vCarVector;
    void random_parameters(int &_orientation,int &_maxSpeed,int &_startIndex);
    int iDriversIDs=0;
    public:
    Simulation(QGraphicsScene *_Scene);
    ~Simulation();
public slots:
    void add_car();
    void move_cars();

};

#endif // SIMULATION_H
