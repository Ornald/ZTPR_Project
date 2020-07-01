#ifndef PRIORITYCAR_H
#define PRIORITYCAR_H

#include <QObject>
#include "car.h"

class PriorityCar :public Car
{
public:
    PriorityCar(int _orientation,int _maxspeed,Position _startPosition);

    ~PriorityCar();
public slots:
//    void move();
private:

    void turn_around();
    void turn_around_parameters();


};

#endif // PRIORITYCAR_H
