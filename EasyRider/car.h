#ifndef CAR_H
#define CAR_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <cmath>
#include <QGraphicsRectItem>
#include "position.h"

class Car:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Car();

    void slow_down();
    void speed_up();
    void change_speed(int iSpeedLevel);
    virtual ~Car();
    void set_drive_way(int howdrive);

    virtual void move();
    virtual void damage_car();
    virtual  void turn_back();
    virtual void change_tow_occupation();
    void turn_right();
    void turn_left();
    void change_lane();
    void stop_car();
    void go();
    void set_maxspeed(int _maxSpeed);
    int get_maxspeed();
    int get_maxdistance();
    int get_actualspeed();
    int get_status();
    int get_type();
    int get_stuck_counter();
    void reset_stuck_counter();
    int get_position_onLane();
    const static int speedValue=1;



protected:
    int iDirection=1;
    int iHowDrive=1;
    int iSpeed=0;
    int iMaxSpeed=2;
    bool bRightofWay;
    int iRightOrLeft=1;
    int iBehaviour=1;
    int iCarWidth=0;
    int iCarHeight=0;
    int iOrientation=0;
    int iPositionOnNextLane=0;
    int iChangeLaneX=0;
    int iOnWrongLane=0;
    QRectF Rect;
    QPointF CenterPoint;
    int iStatus=1;
    int iType;
    void move_forward();
    int istuckCounter=0;


    void turn();
    void turn_Parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
    void change_lane_parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
    void change_traffic_lane();
    void stop();
    int choose_direction();

private:





};

#endif // CAR_H
