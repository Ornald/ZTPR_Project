#ifndef NORMALCAR_H
#define NORMALCAR_H

#include <QObject>
#include "car.h"

class NormalCar: public Car
{
public:
    NormalCar();
    void damage_car();

private:
    int iStatus;
};

#endif // NORMALCAR_H
