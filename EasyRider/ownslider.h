#ifndef OWNSLIDER_H
#define OWNSLIDER_H


#include <QSlider>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>


/**
 * \class OwnSlider
 * \brief Klasa dziedzicząca po Widgecie Slider
 *
 * Klasa dodaje wyświtlacz podpowiedzi w czasie zmiany wartości suwaka w celu wyświetlenia aktualnej wartości na suwaku.
 */
class OwnSlider : public QSlider
{
    Q_OBJECT
public:
    /**
     * \brief Konstruktor domyślny wymagany przez klasę bazową
     */
     OwnSlider(QWidget *parent = 0);
     /**
      * \brief Konstruktor domyślny wymagany przez klasę bazową
      */
     OwnSlider(Qt::Orientation orientation, QWidget *parent = 0);


protected:
    /**
     * \brief Nadpisana metoda wyświetlająca wartość na suwaku
     *
     * Wartość ta jest wyświetlana w polu tooltip w czasie zmiany suwaka.
     */
    virtual void sliderChange(SliderChange change);


};

#endif // OWNSLIDER_H
