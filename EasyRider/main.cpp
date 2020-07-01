
#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include "normaldriver.h"
#include <vector>
#include "driver.h"
#include "prioritydriver.h"
#include "simulation.h"
#include <QImage>
#include <QBrush>
#include "map.h"
#include "crossroad.h"
#include <QSlider>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *ScreenScene = new QGraphicsScene();
    ScreenScene->setSceneRect(0,0,1500,960);
    ScreenScene->setBackgroundBrush(QBrush(QImage(":/Graphics/Board.png")));



    QGraphicsView *MainView = new QGraphicsView(ScreenScene);
    Simulation Game(ScreenScene,MainView);

//    MainView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    QPushButton *AddCarButton = new QPushButton(MainView);
    AddCarButton->setGeometry(1150,100,100,50);
    AddCarButton->setText("Add Car");

    QObject::connect(AddCarButton,SIGNAL(clicked()),&Game,SLOT(add_car()));

    QPushButton *MoveCars = new QPushButton(MainView);
    MoveCars->setGeometry(1150,200,100,50);
    MoveCars->setText("Move Cars");
    QObject::connect(MoveCars,SIGNAL(clicked()),&Game,SLOT(move_cars()));

    QPushButton *Lights = new QPushButton(MainView);
    Lights->setGeometry(1150,300,100,50);
    Lights->setText("Change Lights");
    QObject::connect(Lights,SIGNAL(clicked()),&Game,SLOT(change_trafficlights()));




/*
    QPushButton *TurnButtonRight = new QPushButton(MainView);
    TurnButtonRight->setGeometry(400,100,100,50);
    TurnButtonRight->setText("Turn Right");
    QObject::connect(TurnButtonRight,SIGNAL(clicked()),createCar,SLOT(turn_right()));
   // QObject::connect(TurnButtonRight,SIGNAL(clicked()),createCar,SLOT(move()));

    QPushButton *TurnButtonLeft = new QPushButton(MainView);
    TurnButtonLeft->setGeometry(400,200,100,50);
    TurnButtonLeft->setText("Turn Left");
    QObject::connect(TurnButtonLeft,SIGNAL(clicked()),createCar,SLOT(turn_left()));

    QPushButton *ChangeLaneButton = new QPushButton(MainView);
    ChangeLaneButton->setGeometry(400,300,100,50);
    ChangeLaneButton->setText("Change Lane");
    QObject::connect(ChangeLaneButton,SIGNAL(clicked()),createCar,SLOT(change_lane()));

    QPushButton *StopButton = new QPushButton(MainView);
    StopButton->setGeometry(400,400,100,50);
    StopButton->setText("Stop Car");
    QObject::connect(StopButton,SIGNAL(clicked()),createCar,SLOT(stop_car()));

    QPushButton *StartButton = new QPushButton(MainView);
    StartButton->setGeometry(500,400,100,50);
    StartButton->setText("Start Car");
    QObject::connect(StartButton,SIGNAL(clicked()),createCar,SLOT(go()));

    QPushButton *ChangeButton = new QPushButton(MainView);
    ChangeButton->setGeometry(600,300,100,50);
    ChangeButton->setText("Change Car");
    QObject::connect(ChangeButton,SIGNAL(clicked()),createCar,SLOT(change_tow_occupation()));


     QPushButton *ExitButton = new QPushButton(MainView);
  ExitButton->setText("Close the Simulation");
   ExitButton->setGeometry(1720,1030,200,50);
   QObject::connect(ExitButton, SIGNAL (clicked()), MainView, SLOT (close()));

*/

    MainView->setFixedSize(1500,960);

    MainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    MainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    MainView->show();






    return a.exec();
}
