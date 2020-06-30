#include "ownslider.h"

#include <QStyleOptionSlider>
#include <QToolTip>


OwnSlider::OwnSlider(QWidget * parent)
    : QSlider(parent)
{
}


OwnSlider::OwnSlider(Qt::Orientation orientation, QWidget * parent)
    : QSlider(orientation, parent)
{

}

void OwnSlider::sliderChange(QAbstractSlider::SliderChange change)
{
    QSlider::sliderChange(change);

    if (change == QAbstractSlider::SliderValueChange )
    {
        QStyleOptionSlider opt;
        initStyleOption(&opt);

        QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);
        QPoint bottomRightCorner = sr.bottomLeft();

        QToolTip::showText(mapToGlobal( QPoint( bottomRightCorner.x(), bottomRightCorner.y() ) ), QString::number(value()), this);
    }
}
