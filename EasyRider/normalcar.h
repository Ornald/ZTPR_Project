#ifndef NORMALCAR_H
#define NORMALCAR_H

#include <QObject>
#include "car.h"

class NormalCar: public Car
{
public:
    NormalCar(int _orientation,int _maxspeed);
    void damage_car();
    int get_car_status();
    ~NormalCar();
private:
    int iStatus=1;
};

#endif // NORMALCAR_H
