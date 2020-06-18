#ifndef PRIORITYCAR_H
#define PRIORITYCAR_H

#include <QObject>
#include "car.h"

class PriorityCar :public Car
{
public:
    PriorityCar();
    void damage_car();
public slots:
    void move();
private:
    int iStatus;
    void turn_around();
    void turn_around_parameters();


};

#endif // PRIORITYCAR_H
