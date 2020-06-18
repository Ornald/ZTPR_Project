
#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include "car.h"
#include "prioritycar.h"
#include "normalcar.h"
#include "tugcar.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *ScreenScene = new QGraphicsScene();

     TugCar *createCar = new TugCar();



    ScreenScene->addItem(createCar);

    //createCar->iDirection=0;


    QGraphicsView *MainView = new QGraphicsView(ScreenScene);

    MainView->setAlignment(Qt::AlignTop | Qt::AlignLeft);


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


 /* QPushButton *ExitButton = new QPushButton(MainView);
  ExitButton->setText("Close the Simulation");
   ExitButton->setGeometry(1720,1030,200,50);
   QObject::connect(ExitButton, SIGNAL (clicked()), MainView, SLOT (close()));

*/

    MainView->setFixedSize(1200,1024);
    MainView->setSceneRect(0,0,1200,1024);
    //MainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //MainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    MainView->show();




    return a.exec();
}
