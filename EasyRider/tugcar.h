#ifndef TUGCAR_H
#define TUGCAR_H

#include <QObject>
#include "car.h"

class TugCar : public Car
{
    Q_OBJECT
public:
    TugCar();

public slots:
    void change_tow_occupation();
private:
    int iOccupation=0;
};

#endif // TUGCAR_H
