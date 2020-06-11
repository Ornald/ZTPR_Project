
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

    qDebug()<<ScreenScene->width()<<" "<<ScreenScene->height();

    Car *createCar = new Car();

    /*createCar->setRect(0,0,50,100);
    QRectF rect;
    rect=createCar->mapToScene(createCar->boundingRect()).boundingRect();
    QPointF center = rect.center();
      qreal angle = 20;
      QTransform t;
      t.translate(center.x(), center.y());
      t.rotate(angle);
      t.translate(-center.x(), -center.y());
      //createCar->setPos(t.map(createCar->pos()));
      createCar->setRotation(createCar->rotation() + angle);
   */

    ScreenScene->addItem(createCar);
    createCar->iDirection=0;


    QGraphicsView *MainView = new QGraphicsView(ScreenScene);

    MainView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
 /* QPushButton *ExitButton = new QPushButton(MainView);
  ExitButton->setText("Close the Simulation");
   ExitButton->setGeometry(1720,1030,200,50);
   QObject::connect(ExitButton, SIGNAL (clicked()), MainView, SLOT (close()));

*/
    MainView->show();




    return a.exec();
}
