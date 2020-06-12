
#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include "car.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *ScreenScene = new QGraphicsScene();

    Car *createCar = new Car();



    ScreenScene->addItem(createCar);

    //createCar->iDirection=0;


    QGraphicsView *MainView = new QGraphicsView(ScreenScene);

    MainView->setAlignment(Qt::AlignTop | Qt::AlignLeft);


    QPushButton *TurnButtonRight = new QPushButton(MainView);
    TurnButtonRight->setGeometry(400,100,100,50);
    TurnButtonRight->setText("Turn Right");
    QObject::connect(TurnButtonRight,SIGNAL(clicked()),createCar,SLOT(temp_turn_right()));

    QPushButton *TurnButtonLeft = new QPushButton(MainView);
    TurnButtonLeft->setGeometry(400,200,100,50);
    TurnButtonLeft->setText("Turn Left");
    QObject::connect(TurnButtonLeft,SIGNAL(clicked()),createCar,SLOT(temp_turn_left()));
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
