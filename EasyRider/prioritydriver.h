#ifndef PRIORITYDRIVER_H
#define PRIORITYDRIVER_H
#include "driver.h"

#include "normalcar.h"

/**
 * \class PriorityDriver
 * \brief Klasa służąca do obsługi samochodów z priorytetem
 *
 * W tym przypadku obsługiwane są karetki. Klasa dziedziczy po klasie Driver. Rozszerze i implementuje metody z klasy bazowej.
 */
class PriorityDriver : public Driver
{
public:
    /**
     * \brief Konstruktor klasy
     *
     * Poza przypisaniem wartości prędkości i orientacji startowej samochodu tworzona jest instancja klasy NormalCar oraz Sensors.
     *  A takżde utworzony samochód jest do sceny graficznej. Przekazywany jest wektor na wskaźnik do klasy Map oraz tworzona jest droga samochodu metodą find_way.
     * \param[in] _orientation Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     * \param[in] _maxspeed Przyjmuje parametr będący stanem świateł na skrzyżowaniu.
     * \param[in] _scene Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     * \param[in] _startIndex Przyjmuje parametr będący stanem świateł na skrzyżowaniu.
     * \param[in] _ID Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     * \param[in] _map Przyjmuje parametr będący stanem świateł na skrzyżowaniu.
     */
    PriorityDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map &_map);
    /**
     * \brief Destruktor
     *
     * Zwalnia pamięć na wskaźniki do klasy Car i Sensors.
     */
    ~PriorityDriver();
    /**
     * \brief Funkcja definiująca kolejne ruchy samochodu
     *
     * Korzystując z metod klasy Map wyznaczane są odległości do kolejnych samochodów, świateł i skrzyżowań.
     * W zależnosci od tych parametrów wykonywane są kolejne ruchy samochodu.
     * Oprócz ruchów analogicznych do samochodu zwykłego ten samochód ma mozliwośc zawracania.
     * Przez to konieczne jest sprawdzanie pól naprzeciwo karetki, odległości od skrzyżowań i świateł pod względem miejsca.
     * Po dwóch zakrętach karetka będzie próbowała nawrócić i wrócić tą samą drogą.
     */
    void next_move() override;
private:
    /**
     * \brief Funkcja sprawdzająca czy samochód może przekroczyć światła będące na skrzyżowaniu.
     *
     * W zależności od stanu światła i informacji czy skrzyżowanie jest wolne,
     * a także jakie ruchy wykonują samochody z naprzeciwka podejmuje decyzje czy samochód ma się zatrzymać czy ruszyć.
     * W przeciwieństwie do samochodów zwykłych karetki ignorują światła żółte.
     * \param[in] _difference Przyjmuje parametr będący odległością od punktu zakrętu na skrzyżowaniu.
     * \param[in] _lightStatus Przyjmuje parametr będący stanem świateł na skrzyżowaniu.
     */
    void check_trafficlights(int _difference, int _lightStatus) override;
    /**
     * \brief Funkcja definiująca kolejne ruchy samochodu
     *
     * Uzupełniana jest tabela ruchów samochodu w postaci losowych liczb z zakresu 0-2, gdzie 0 to prosto, 1 skręt w prawo i 2 skręt w lewo.
     * W tym przypadku 2 pierwsze ruchy samochodu są losowe. Natomiast kolejne ruchy są uzależnione od tych pierwszych dwóch.
     */
    void find_way() override;
    /**
     * \brief Funkcja wykonująca nawracanie karetki
     *
     * Funkcja po sprawdzeniu, że może wykonać nawrót korzystając z metod klasy NormalCar wykonuja nawrót samochodu.
     */
    void turn_back();
    /**
     * \brief Funkcja zwracająca ruchy samochodu tak, aby karetka wróciła po swoich śladach na pozycje startową
     */
    int return_move(int _move);
    int iTurned=0;


};

#endif // PRIORITYDRIVER_H
