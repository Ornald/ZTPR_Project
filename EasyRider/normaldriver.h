#ifndef NORMALDRIVER_H
#define NORMALDRIVER_H
#include "driver.h"
#include "normalcar.h"

class NormalDriver : public Driver
{
public:
    NormalDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map & _map);
    ~NormalDriver();
    void next_move() override;
    void engine_malfunction() override;
    bool can_be_damaged() override;

private:
    void find_way() override;
    int counter =0;


};

#endif // NORMALDRIVER_H
