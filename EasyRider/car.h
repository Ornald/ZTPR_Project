#ifndef CAR_H
#define CAR_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <cmath>

class Car:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Car();

    void slow_down();
    void speed_up();
    void change_speed();


    void set_drive_way(int howdrive);

public slots:
    void move();
    void temp_turn_right();
    void temp_turn_left();

protected:
    int iDirection=1;
    int iHowDrive;
    int iSpeed;
    int iMaxSpeed;
    bool bRightofWay;
    int iExitIndex;
    int iRightOrLeft=1;
    int iBehaviour;
    int iCarWidth=100;
    int iCarHeight=50;
    int iOrientation;
    QRectF Rect;
    QPointF CenterPoint;
    void move_forward();
    void turn();
    void turn_Parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
    void change_traffic_lane();
private:





};

#endif // CAR_H
