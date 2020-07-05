#ifndef NORMALCAR_H
#define NORMALCAR_H

#include <QObject>
#include "car.h"
/**
  * \class NormalCar
 * \brief Klasa obsługująca normalne i priorytetowe samochody
 *
 * Klasa dziedziczy po klasie Car. Rozszerza natomiast niektóre jej metody i posiada kilka własnych.
 */
class NormalCar: public Car
{
public:
    /**
     * \brief Konstruktor klasy NormalCar
     *
     * Następuje przypisanie pól iMaxSpeed, iType.
     * Wczytywana jest odpowiednia grafika z zasobów oraz umieszczona na kordynatach _startposition. Następnie jest skalowana i obracana.
     * \param[in] _orientation
     * \param[in] _maxspeed
     * \param[in] _startPosition Pozycja startowa samochodu
     * \param[in] _type Typ samochodu. 0 dla samochodu normalnego i 1 dla priorytetowego
     */
    NormalCar(int _orientation,int _maxspeed, Position _startPosition, int _type);
    /**
     * \brief Funkcja uszkadzająca samochód
     *
     * Ustawiany jest status na 0 oraz maksymalna prędkość na 0.
     */
    void damage_car() override;
    /**
     * \brief Funkcja zwracająca status samochodu
     *
     * \param[out] iStatus
     */
    int get_car_status();
    /**
     * \brief Destruktor klasy NormalCar
     */
    ~NormalCar();
    /**
     * \brief Funkcja nadpisująca metodę z klasy Car. Służy do wyboru trybu poruszania samochodem
     *
     * Funkcja działa w zależności od zmiennej iHowDrive. Od 0 do 4 działa ona tak samo jak dla klasy Car.
     * Natomiast dla wartości 5 następuje nawrót samchodu.
     */
    void move() override;
private:

    /**
     * \brief Metoda przesuwa i obraca grafikę samochodu tak jakby samochód zawracał
     *
     * Korzysta z metody turn_around_parameters w celu wykonania obrotu o 180 stopni w lewo.
     */
    void turn_around();
    /**
     * \brief Metoda zmienia wartość iHowDrive
     *
     * Metoda zmienia wartość zmiennej iHowDrive na 5 w celu wykonania zawracania.
     */
    void turn_back() override;
    /**
     * \brief Metoda zwraca parametry potrzebne do wykonania nawrotu
     *
     * Zwraca kąt pojedyńczego obrotu, następny kierunek jazdy oraz o ile ma się samochód przesuwać w osiach X i Y
     * \param[in] RotationAngle Kąt obrotu samochodu
     * \param[in] NextDirection Kierunek jazdy po wykonaniu nawrotu
     * \param[in] MoveX
     * \param[in] MoveY
     */
    void turn_around_parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
};

#endif // NORMALCAR_H
