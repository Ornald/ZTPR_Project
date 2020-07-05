#ifndef NORMALDRIVER_H
#define NORMALDRIVER_H
#include "driver.h"
#include "normalcar.h"
/**
 * \class NormalDriver
 * \brief Klasa, która obsługuje kierowców normalnych samochodów
 *
 * Implementuje i nadpisuje metody virtualne z klasy bazowej Driver. Służy do obsługi zwykłych samochodów.
 */
class NormalDriver : public Driver
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
     */
    NormalDriver(int _orientation, int _maxspeed, QGraphicsScene& _scene, int _startIndex, int _ID, Map & _map);
    /**
     * \brief Destruktor
     *
     * Zwalnia pamięć na wskaźniki do klasy Car i Sensors.
     */
    ~NormalDriver();
    /**
     * \brief Funkcja definiująca kolejne ruchy samochodu
     *
     * Korzystując z metod klasy Map wyznaczane są odległości do kolejnych samochodów, świateł i skrzyżowań.
     * W zależnosci od tych parametrów wykonywane są kolejne ruchy samochodu.
     */
    void next_move() override;
    /**
     * \brief Funkcja zmieniająca status samochodu na zepsuty
     *
     * Ustawia status w samochodzi na zepsuty i ogranicza maksymalną prędkość samochodu do 0.
     */
    void engine_malfunction() override;
    /**
     * \brief Funkcja sprawdzająca czy dany samochód może ulec uszkodzeniu
     *
     * W zależności od odległości od skrzyżowań i początków mapy stwierdza czy dany samochód może ulec uszkodzeniu czy nie.
     */
    bool can_be_damaged() override;

private:
    /**
     * \brief Funkcja definiująca kolejne ruchy samochodu
     *
     * Uzupełniana jest tabela ruchów samochodu w postaci losowych liczb z zakresu 0-2, gdzie 0 to prosto, 1 skręt w prawo i 2 skręt w lewo.
     */
    void find_way() override;
    int counter =0;


};

#endif // NORMALDRIVER_H
