#ifndef TUGCAR_H
#define TUGCAR_H

#include <QObject>
#include "car.h"

class TugCar : public Car
{
    Q_OBJECT
public:
    TugCar(int _orientation, int _maxspeed, Position _startPosition);
    ~TugCar();

public slots:
    void change_tow_occupation();
private:
    int iOccupation=0;
};

#endif // TUGCAR_H
