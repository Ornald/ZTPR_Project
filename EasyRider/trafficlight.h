#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "position.h"
#include <QDebug>

/**
  \class TrafficLight
 * \brief Klasa dodająca graficzne odwzorowanie lamp drogowych
 */
class TrafficLight: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * \brief Konstruktor klasy
     *
     * Zostaje w tym miejscu wczytane wartości do pól klasy.
     */
    TrafficLight(Position _position,int _startStatus,int _orientation,int _roadID, int _stopPoint);
    /**
     * \brief Metoda, która zmienia światła
     *
     * Zostaje zmieniona grafika świateł na tę z odpowiednim kolorem świateł.
     * Jednocześnie zmieniany jest status drogi, przy której stoi światło albo z przejezdnej na zablokowaną albo odwrotnie.
     */
   void change_light();
   int get_status();
   int get_stopPoint();
   int get_previous_status();
   int get_roadID();
   bool get_if_recently_changed();
   void set_recent_change(int _change);

private:
   /**
    * \brief Funkcja dodająca światło do mapy
    *
    * Funkcja wykorzystana w konstruktorze. Dodaje konkretne światło na zadanej pozycji, orientacji i statusie światła.
    */
    void place_trafficlight(Position _position, int _startStatus,int _orientation);
    int iStatus=0;
    int iPreviousStatus=0;
    int iRoadID=0;
    int iStopPoint;
    int iRecentlyChanged=0;


};

#endif // TRAFFICLIGHT_H
