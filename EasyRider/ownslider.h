#ifndef OWNSLIDER_H
#define OWNSLIDER_H


#include <QSlider>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>



class OwnSlider : public QSlider
{
    Q_OBJECT
public:
    explicit OwnSlider(QWidget *parent = 0);
    explicit OwnSlider(Qt::Orientation orientation, QWidget *parent = 0);


protected:
    virtual void sliderChange(SliderChange change);


};

#endif // OWNSLIDER_H
