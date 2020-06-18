#ifndef CAR_H
#define CAR_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <cmath>
#include <QGraphicsRectItem>

class Car:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Car();

    void slow_down();
    void speed_up();
    void change_speed();


    void set_drive_way(int howdrive);

public slots:
    virtual void move();
    void turn_right();
    void turn_left();
    void change_lane();
    void stop_car();
    void go();

protected:
    int iDirection=1;
    int iHowDrive;
    int iSpeed;
    int iMaxSpeed;
    bool bRightofWay;
    int iExitIndex;
    int iRightOrLeft=1;
    int iBehaviour;
    int iCarWidth;
    int iCarHeight;
    int iOrientation;
    int iPositionOnNextLane=0;
    int iChangeLaneX;
    int iOnWrongLane=0;
    QRectF Rect;
    QPointF CenterPoint;

    void move_forward();
    void turn();
    void turn_Parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
    void change_lane_parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
    void change_traffic_lane();
    void stop();

private:





};

#endif // CAR_H
