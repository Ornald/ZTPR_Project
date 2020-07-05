#ifndef CROSSROAD_H
#define CROSSROAD_H

/**
  * \class CrossRoad
 * \brief Klasa będąca przedstawieniem skrzyżowań na mapie
 *
 * Klasa jest wykorzystywana w postaci wektora w klasie Map. Jest ona tworzona i zarządzania przez tę klasę.
 */
class CrossRoad
{
public:
    /**
     * \brief Konstruktor z parametrami
     *
     * Konstruktor funkcji z parametrami klasy. Każde skrzyżowanie składa się z 4 pól tej klasy.
     * \param[in] _crossroadID ID każdego z wjazdów ze skrzyżowań.
     * \param[in] _orientation Pokazanie jakie samochodu o jakiej orientacji będą oddziaływać z tym skrzyżowaniem
     * \param[in] _posR Pozycja do skrętu wprawo
     * \param[in] _posL Pozycja do skrętu w lewo
     */
    CrossRoad(int _crossroadID,int _orientation,int _posR,int _posL);
    /**
     * \brief Konstruktor domyślny
     */
    CrossRoad();
    /**
     * \brief Funkcja zwracająca pozycję do skrętu
     *
     * Funkcja zwracała zmienną iPosR lub iPosL w zależności od parametru _way.
     * \param[in] _way Przekazanie w którą stronę będzie skręcał samochód
     */
    int get_cross_position(int _way);
    /**
     * \brief Funkcja zwracająca ID skrzyżowania
     *
     * \param[out] iCrossroadID
     */
    int get_roadID();
    /**
     * \brief Funkcja zwracająca orientację skrzyżowania
     *
     * \param[out] iOrientation
     */
    int get_orientation();
    /**
     * \brief Nadpisany opearator porównania
     *
     * Został on stworzony w celu wykorzystania metody find
     */
    bool operator== (const int & _temp){ return this->iCrossroadID==_temp;   };

private:

    int iCrossroadID;
    int iOrientation;
    int iPosR;
    int iPosL;


};

#endif // CROSSROAD_H
