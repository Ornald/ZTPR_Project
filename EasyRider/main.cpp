
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

    MainView->setFixedSize(1500,960);

    MainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    MainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    MainView->show();





    return a.exec();
}
