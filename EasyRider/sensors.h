#ifndef SENSORS_H
#define SENSORS_H

#include "position.h"

/**
 * \class Sensors
 * \brief Klasa przechowująca istotne informacje o samochodzie.
 *
 * W tej klasie przechowywane są informacje o pozycji, następnym ruchu, aktualnej drodze, prędkości, typie i orientacji samochodu.
 * Wykorzystywana jest w czasie interakcji między samochodami.
 */

class Sensors
{
private:
    Position pCarPosition;
    int iCarNextMove;
    int iRoadID;
    int iActualSpeed;
    int iCarID;
    int iCarType;
    int iOrientation;
    int iMaxSpeed;
    int iStatus=1;
public:
    /**
     * \brief Konstruktor klasy
     *
     * W konstruktorze następuje tylko przypisanie wartości do pól zmiennych.
     * \param[in] _carPosition Pozycja samochodu
     * \param[in] _carNectMove Kolejny ruch samochodu
     * \param[in] _roadID Numer drogi na której jest samochód
     * \param[in] _actualSpeed Aktualna prędkość samochodu
     * \param[in] _carID ID samochodu
     * \param[in] _orientation Orientacja samochodu.
     * \param[in] _carType Typ samochodu
     * \param[in] _maxSpeed Maksymalna prędkość samochodu
     */
    Sensors(Position _carPosition,int _carNectMove,int _roadID,int _actualSpeed,int _carID,int _orientation,int _carType, int _maxSpeed);

    void set_CarPosition(Position _carPosition);
    void set_CarNextMove(int _nextMove);
    void set_RoadID(int _roadID);
    void set_ActualSpeed(int _actualspeed);
    void set_CarID(int _ID);
    void set_Orientation(int _orientation);
    void set_status(int _status);
    int get_CarNextMove();
    int get_RoadID();
    int get_ActualSpeed();
    int get_CarID();
    int get_Orientation();
    int get_MaxSpeed();
    int get_carType();
    int get_status();
    Position get_CarPosition();



};

#endif // SENSORS_H
