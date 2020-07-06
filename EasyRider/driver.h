#ifndef DRIVER_H
#define DRIVER_H

#include <QGraphicsScene>
#include <car.h>
#include "position.h"
#include "map.h"
#include "sensors.h"

/**
 * \class Driver
 * \brief Klasa, która implementuje wspólne metody dla róznych kierowców
 *
 * Jest ona tworzona i zarządzana przez klasę Simulation. Tworzy ona instancje klas Car i Sensors i nimi zarządza. Wykorzystuję klasę Map, ale jej nie tworzy.
 */

class Driver
{
private:


protected:

    int iWayTable[5];
    int iStartIndex;
    int iDriverID=0;
    Car *DriverCar;
    Sensors *sCarSensor;
    int iRoadID=0;
    int iCrossRoadCnt=0;
    int iCarType;
    int iTotalMaxSpeed=0;
    int iCurrentMaxSpeed=0;
    Map *DriverMap;
    Position pCurrentPosition;
    bool bStuck=0;
    int iLane=0;
    int iNextBrokenCarID=-1;
    int iPicked=0;
    int iTowCarID=-1;
    bool bStatus=1;

    /**
     * \brief Funkcja odczytuje pozycje grafiki samochodu
     *
     * Funkcja odczytuje pozycję samochodu korzystając z QPoint i zapisuje je wykorzystując stworzoną klasę Position.
     */
    void set_current_position();
    /**
     * \brief Funkcja sprawdzająca czy samochód jest w odpowiedniej pozycji do skrętu
     *
     * Funkcja w zależnosci od odległości i następnego ruchu samochodu sprawdza czy można już wykonać ten ruch czy nie.
     * W pobliżu punktu zakrętu zmniejsza prędkość. A także aktualizuje prędkośći i pozycję samochodu w klasie Sensors.
     * \param[in] _diffPosition Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     */
    void check_crossroad_position(int _diffPosition);
    /**
     * \brief Funkcja wirtualna sprawdzająca czy samochód może przekroczyć światła będące na skrzyżowaniu.
     *
     * W zależności od stanu światła i informacji czy skrzyżowanie jest wolne,
     * a także jakie ruchy wykonują samochody z naprzeciwka podejmuje decyzje czy samochód ma się zatrzymać czy ruszyć.
     * \param[in] _difference Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     * \param[in] _lightStatus Przyjmuje parametr będący stanem świateł na skrzyżowaniu.
     */
    virtual void check_trafficlights(int _difference, int _lightStatus);
    /**
     * \brief Funkcja dostosowująca prędkość samochodu do prędkości samochodu z przodu
     *
     * W zależności od odległości od samochodu z przodu dostosowuje prędkość lub przyśpiesza do wartości maksymalnej samochodu.
     * \param[in] _diff Przyjmuje parametr będący odległością od następnego samochodu na tym samym pasie.
     */
    void adjust_speed(int _diff);
    /**
     * \brief Funkcja wirtualna służąca do stworzenia drogi samochodu
     *
     * Funkcja jest nadpisywana w klasach pochodnych.
     */
    virtual void find_way();
    /**
     * \brief Funkcja zmieniająca stan samochodu po podniesieniu przez holownik
     *
     * Jeśli holownik przejedzie odpowiednio blisko zostaje zmieniony stan samochodu na podniesiony na holownik.
     */
    void set_picked();

public:
    /**
     * \brief Konstruktor domyślny
     */
    Driver();
    /**
     * \brief Wirtualny destruktor
     */
    virtual ~Driver();

    /**
     * \brief Funkcja wymuszająca na samochodzie zmianę pasa
     *
     * Korzysta ona z metod klasy Car by zmienić pas jazdy samochodu.
     */
     void overtake();
     /**
      * \brief Funkcja sprawdzjąca czy samochód nie utknął na skrzyżowaniu
      *
      * \param[out] zwraca 1 gdy samochód nie może się ruszyć i 0 gdy jest to możliwe
      */
    bool check_if_stuck();
    /**
     * \brief Funkcja wirtualna służaca do wykonywania kolejnych ruchów samochodu.
     *
     * Nadpisywana jest przez klasy pochodne.
     */
    virtual void next_move();
    /**
     * \brief Funkcja zwracająca pozycje startową samochodu
     *
     * W zależności od indeksu startowego nadawne są samochodowi różne pozycje startowe na mapie.
     */
    Position start_postion();

    /**
     * \brief Funkcja wirtualna służaca do ustawienie indeksu startowego samochodu
     *
     * \param[in] _startIndex Jest to Index drogi wejściowej na mapę od 0 do 7.
     */
    void set_start_index(int _startIndex);
    /**
     * \brief Fukcja zwracająca indeks startowy samochodu
     *
     * \param[out] iStartIndex
     */
    int get_start_index();
    /**
     * \brief Fukcja sprawdzająca czy samochód wyjechał poza mapę.
     *
     * Sprawdza czy samochód jest na mapie.
     * \param[out] Zwraca 1 w przypadku gdy samochód już wyjechał poza mapę i 0 gdy jest na mapie
     */
    bool check_if_out_board();
    /**
     * \brief Fukcja zwracająca indeks drogi na której aktualnie znajduje się samochód
     *
     * \param[out] iRoadID
     */
    int get_roadID();
    /**
     * \brief Fukcja zwracająca indeks kierowcy
     *
     * \param[out] iDriverID
     */
    int get_DriverID();
    /**
     * \brief Fukcja ustawiająca ID holownika
     *
     * Funkcja ustawia ID holownika, który będzie holował dany samochód
     * \param[in] _towCarID
     */
    void set_TowCarID(int _towCarID);
    /**
     * \brief Fukcja zwracająca czy samochód został zabrany przez holownik
     *
     * \param[out] iPicked
     */
    int get_picked();
    static int iCarnumber;
    /**
     * \brief Fukcja sprawdzająca czy dany samochód może zostać uszkodzony
     *
     * Funkcja nadpisana przez klasy pochodne
     * \param[out] funckja domyślnie zwraca wartość 0
     */
   virtual bool can_be_damaged();
    /**
     * \brief Fukcja zmieniająca stan samochdu na zepsuty
     *
     * Funkcja nadpisana przez klasy pochodne.
     */
    virtual void engine_malfunction();
    /**
     * \brief Fukcja podająca ID samochodu, który został podniesiony przez holownik
     *
     * Funkcja nadpisana przez klasy pochodne.
     */
    virtual int picked_up_id();

    int get_carType();
    bool get_status();





};

#endif // DRIVER_H
