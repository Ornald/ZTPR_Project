#ifndef TUGCAR_H
#define TUGCAR_H

#include <QObject>
#include "car.h"

/**
  \class TugCar
 * \brief Klasa obsługująca samochody typu holownik
 *
 * Klasa ta dziedziczy po klasie Car.
 */

class TugCar : public Car
{
    Q_OBJECT
public:
    /**
     * \brief Konstruktor klasy NormalCar
     *
     * Następuje przypisanie pól iMaxSpeed, iType.
     * Wczytywana jest odpowiednia grafika z zasobów oraz umieszczona na kordynatach _startposition. Następnie jest skalowana i obracana.
     * \param[in] _orientation
     * \param[in] _maxspeed
     * \param[in] _startPosition Pozycja startowa samochodu
     */
    TugCar(int _orientation, int _maxspeed, Position _startPosition);
    ~TugCar();

public slots:
    /**
     * \brief Funkcja zmieniająca to czy holownik jedzie sam czy z samochodem
     *
     * Funkcja zmienia grafikę holownika w zależności od tego czy ma on samochód na holu czy też nie.
     */
    void change_tow_occupation() override;
private:
    int iOccupation=0;
};

#endif // TUGCAR_H
