#ifndef NORMALCAR_H
#define NORMALCAR_H

#include <QObject>
#include "car.h"

class NormalCar: public Car
{
public:
    NormalCar(int _orientation,int _maxspeed, Position _startPosition, int _type);
    void damage_car() override;
    int get_car_status();
    ~NormalCar();
    void move() override;
private:


    void turn_around();
    void turn_back() override;
    void turn_around_parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
};

#endif // NORMALCAR_H
