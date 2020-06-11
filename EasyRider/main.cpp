
#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>

class MyQGraphicsView : public QGraphicsView
{
    Q_OBJECT
    public:
    MyQGraphicsView(QGraphicsScene *scene);

    public slots:
     void close();

    private:
    int m_click;


};
void MyQGraphicsView:: close()
{
    qDebug()<<"It works fine";
    QGraphicsView::close();

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *ScreenScene = new QGraphicsScene();
    QWidget *Parent = NULL;
    MyQGraphicsView *MainView = new MyQGraphicsView(ScreenScene);
    QPushButton *ExitButton = new QPushButton(MainView);
    ExitButton->setText("Close the Simulation");
    ExitButton->setGeometry(100,100,50,50);
    QObject::connect(ExitButton, SIGNAL (clicked()), MainView, SLOT (close()));

    MainView->showFullScreen();




    return a.exec();
}
