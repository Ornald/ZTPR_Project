#ifndef TUGDRIVER_H
#define TUGDRIVER_H

#include "driver.h"
#include "tugcar.h"
class TugDriver : public Driver
{
public:
    TugDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map &_map, int _targetID, int _targetRoadID);
    ~TugDriver();
    void next_move() override;
    int picked_up_id() override;
private:

    int iTargetID;
    int iTargetRoadID;
    int iPicked=0;
    void find_way() override;
    void prepare_table_close(int _startIndex,int _target);
    void prepare_table_middle(int _startIndex,int _target);
    void prepare_table_long(int _startIndex,int _target);

    void pick_up_target();




};

#endif // TUGDRIVER_H
