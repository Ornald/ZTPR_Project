#ifndef CAR_H
#define CAR_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>
#include <QTimer>

class Car:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Car();

    void slow_down();
    void speed_up();
    void change_speed();
    int iDirection=1;
    int iTurn=1;
public slots:
    void move_forward();
    void turn();



protected:
    int iSpeed;
    int iMaxSpeed;
    bool bRightofWay;
    int iExitIndex;
    int iBehaviour;

};

#endif // CAR_H
