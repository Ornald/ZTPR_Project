#ifndef PRIORITYCAR_H
#define PRIORITYCAR_H

#include <QObject>
#include "car.h"

class PriorityCar :public Car
{
public:
    PriorityCar(int _orientation,int _maxspeed);
    void damage_car();
    ~PriorityCar();
public slots:
    void move();
private:
    int iStatus;
    void turn_around();
    void turn_around_parameters();


};

#endif // PRIORITYCAR_H
