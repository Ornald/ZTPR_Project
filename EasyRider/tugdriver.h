#ifndef TUGDRIVER_H
#define TUGDRIVER_H

#include "driver.h"
#include "tugcar.h"

/**
 * \class TugDriver
 * \brief Klasa, która obsługuje kierowców normalnych samochodów
 *
 * Implementuje i nadpisuje metody virtualne z klasy bazowej Driver. Służy do obsługi zwykłych samochodów.
 */
class TugDriver : public Driver
{
public:
    /**
     * \brief Konstruktor klasy NormalDriver
     *
     * Poza przypisaniem wartości prędkości i orientacji startowej samochodu tworzona jest instancja klasy NormalCar oraz Sensors.
     *  A takżde utworzony samochód jest do sceny graficznej. Przekazywany jest wektor na wskaźnik do klasy Map oraz tworzona jest droga samochodu metodą find_way.
     * \param[in] _orientation Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     * \param[in] _maxspeed Przyjmuje parametr będący stanem świateł na skrzyżowaniu.
     * \param[in] _scene Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     * \param[in] _startIndex Przyjmuje parametr będący stanem świateł na skrzyżowaniu.
     * \param[in] _ID Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     * \param[in] _map Przyjmuje parametr będący stanem świateł na skrzyżowaniu.
     * \param[in] _targetID Przyjmuje parametr będący indeksem uszkodzonego samochodu
     * \param[in] _targetRoadID Przyjmuje parametr będący indeksem drogi na której znajduje się uszkodzony samochód
     */
    TugDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map &_map, int _targetID, int _targetRoadID);
    /**
     * \brief Destruktor
     *
     * Zwalnia pamięć na wskaźniki do klasy Car i Sensors.
     */
    ~TugDriver();
    /**
     * \brief Funkcja definiująca kolejne ruchy samochodu
     *
     * Korzystując z metod klasy Map wyznaczane są odległości do kolejnych samochodów, świateł i skrzyżowań.
     * W zależnosci od tych parametrów wykonywane są kolejne ruchy samochodu. Sprawdza również odległość od celu.
     * W przypadku, gdy jest on blisko zmienia status holownika.
     */
    void next_move() override;
    /**
     * \brief Funkcja zwraca id samochodu, który został podniesiony na holownik
     *
     * W przypadku gdy holownik jeszcze nie podniósł samochodu zwraca wartość -1. W przypadku, gdy już to zrobił zwraca wartość będącą indeksem samochodu.
     */
    int picked_up_id() override;
private:

    int iTargetID;
    int iTargetRoadID;
    int iPicked=0;
    /**
     * \brief Funkcja definiująca kolejne ruchy samochodu
     *
     * Jest ona całkowicie zależna od indeksu drogi na której znajduje sie uszkodzony samochód oraz losowej wartości będącej indeksem wejściowym.
     *  Wykorzystuje metody prepare_table_close, prepare_table_middle,prepare_table_long.
     */
    void find_way() override;
    /**
     * \brief Funkcja przygotowująca drogę jeśli trzeba wykonać 1 zakręt
     */
    void prepare_table_close(int _startIndex,int _target);
    /**
     * \brief Funkcja przygotowująca drogę jeśli trzeba wykonać 2 zakręty
     */
    void prepare_table_middle(int _startIndex,int _target);
    /**
     * \brief Funkcja przygotowująca drogę jeśli trzeba wykonać 3 zakręty
     */
    void prepare_table_long(int _startIndex,int _target);
    /**
     * \brief Funkcja podnosząca samochód na hol
     *
     * Zmienia grafikę samochodu korzystając z metod TugCar, a także ustawia prędkośc samochodu na 1.
     */
    void pick_up_target();




};

#endif // TUGDRIVER_H
