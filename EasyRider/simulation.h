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
public:
    Simulation(QGraphicsScene *_Scene);
    ~Simulation();
public slots:
    void add_car();
    void move_cars();

};

#endif // SIMULATION_H
