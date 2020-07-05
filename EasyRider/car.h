#ifndef CAR_H
#define CAR_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <cmath>
#include <QGraphicsRectItem>
#include "position.h"

/**
 * \class Car
 * \brief Klasa służąca do obsługi grafiki samochodu.
 *
 * Klasa ta dziedziczy po QGraphicsPixmapItem. Dzięki temu możliwe jest poruszanie grafikami nadając im konretne współrzędne oraz rotacje.
 * Jest to klasa ogólna, po której dziedziczą inne klasy. Zawiera podstawowe funkcjonalności samochodu w programie.
 */

class Car:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Car();
    /**
     * \brief Funkcja służąca do zmniejszania prędkości samochodu w czasie jazdy.
     *
     * Funkcja po wywołaniu zmniejsza aktualną prędkośc samochodu o 1 poziom.
     * Przy osiągnięciu prędkości 0 nie następuje dalsze zmniejszanie.
     */
    void slow_down();
    /**
     * \brief Funkcja służąca do zwiększania prędkości samochodu w czasie jazdy.
     *
     * Funkcja po wywołaniu zmniejsza aktualną prędkośc samochodu o 1 poziom.
     * Przy osiągnięciu limitu prędkości prędkość nie jest dalej zwiększana.
     */
    void speed_up();
    /**
     * \brief Funkcja służąca do ustalenia prędkości.
     *
     * Funkcja ustawia aktualną prędkość. Jeśli ustawiana jest prędkość powyżej maksymalnej to zamiast podanej wartości zostanie ustawiona maksymalna.
     */
    void change_speed(int iSpeedLevel);
    /**
     * \brief Wirtualny destruktor klasy.
     *
     */
    virtual ~Car();
    /**
     * \brief Funkcja służąca do wyboru trybu jeżdżenia samochodu.
     *
     * Zmienna służy do ustawienie trybu jeżdżenia samochodu.
     * \param[in] howdrive ustawia tryb następnego ruchu samochodu
     */
    void set_drive_way(int howdrive);
    /**
     * \brief Funkcja służąca do poruszenia grafiki samochodu.
     *
     * W zależności od zmiennej wejściowej wykonuje inne metody klasy polegające na różnych ruchach samochodu. Jazda do przodu, skręcanie bądź zatrzymywanie się.
     */
    virtual void move();
    /**
     * \brief Funkcja czysto abstrakcyjna, żeby można było ją wywołać w wektorze wskaźników klasy Car
     */
    virtual void damage_car();
    /**
     * \brief Funkcja czysto abstrakcyjna, żeby można było ją wywołać w wektorze wskaźników klasy Car
     */
    virtual  void turn_back();
    /**
     * \brief Funkcja czysto abstrakcyjna, żeby można było ją wywołać w wektorze wskaźników klasy Car
     */
    virtual void change_tow_occupation();
    /**
     * \brief Funkcja zmieniająca następny ruch na zakręt
     *
     * Zmienia ona parametr iHowDrive i wymusza skręt w prawo.
     */
    void turn_right();
    /**
     * \brief Funkcja zmieniająca następny ruch na zakręt
     *
     * Zmienia ona parametr iHowDrive i wymusza skręt w lewo.
     */
    void turn_left();
    /**
     * \brief Funkcja umożliwiająca zmianę pasa przez samochód.
     *
     * Wykonuje ona ruch w zależności od parametru iOnWrongLane albo na pas przeciwny albo powrót na właściwy pas.
     * Przy obróceniu samochodu o 30 stopni i przejechanie okreslonej odległości od punktu startowego.
     */
    void change_lane();
    /**
     * \brief Funkcja zatrzymująca samochód
     *
     * Zmienia ona parametr iHowDrive na zatrzymanie samochodu
     */
    void stop_car();
    /**
     * \brief Funkcja służąca do rozpoczynania ruchu samochodu.
     *
     * Funkcja rozpoczynająca ruch samochodu, który został zatrzymany funkcją stop_car().
     */
    void go();
    /**
     * \brief Funkcja ustawiająca maksymalną prędkość samochodu
     *
     * Funkcja ustawia zmienną iMaxSpeed na podaną wartość.
     * \param[in] _maxSpeed prędkość, która zostanie ustawiona
     */
    void set_maxspeed(int _maxSpeed);
    /**
     * \brief Wyświetlenie prędkości maksymalnej
     *
     * \param[out] iMaxSpeed
     */
    int get_maxspeed();
    /**
     * \brief Wyświetlenie maksymalnego dystansu
     *
     * Funkcja zwraca maksymalny dystans hamowania jaki samochód może przejechać.
     * \param[out] iMaxSpeed*SpeedValue
     */
    int get_maxdistance();
    /**
     * \brief Wyświetlenie aktualnej prędkości samochodu
     *
     * \param[out] iActualSpeed
     */
    int get_actualspeed();
    /**
     * \brief Wyświetlenie stanu technicznego samochodu
     *
     * \param[out] iStatus 1 oznacza stan dobry. Natomiast 0 oznacza uszkodzenie samochodu.
     */
    int get_status();
    /**
     * \brief Wyświetlenie typu samochodu
     *
     * \param[out] iType W przypadku samochodów zwykłych będzie to 0. Dla samochodów priorytetowych będzie to 1.
     */
    int get_type();
    /**
     * \brief Wyświetlenie licznika czasu jaki samochód spędził zatrzymany.
     *
     * \param[out] iStuckCounter
     */
    int get_stuck_counter();
    /**
     * \brief Zerowanie licznika czasu postoju samochodu.
     */
    void reset_stuck_counter();
    /**
     * \brief Wyświetlenie zmiennej iOnWrongLane.
     */
    int get_position_onLane();
    /**
     * \brief Mnożnik prędkości samochodu.
     *
     * \param[out] iOnWrongLane
     */
    const static int speedValue=1;



protected:
    int iDirection=1;
    int iHowDrive=1;
    int iSpeed=0;
    int iMaxSpeed=2;
    bool bRightofWay;
    int iRightOrLeft=1;
    int iBehaviour=1;
    int iCarWidth=0;
    int iCarHeight=0;
    int iOrientation=0;
    int iPositionOnNextLane=0;
    int iChangeLaneX=0;
    int iOnWrongLane=0;
    QRectF Rect;
    QPointF CenterPoint;
    int iStatus=1;
    int iType;
    int istuckCounter=0;

    /**
     * \brief Funkcja służąca do poruszenia grafiki samochodu.
     *
     * Funkcja porusza samochód o konkretną ilość pikseli zależną od prędkości samochodu i mnożnika szybkości.
     * Jeśli to możliwe w czasie ruchu samochód przyśpiesza.
     */
    void move_forward();
    /**
     * \brief Funkcja służąca do wykonania zakrętu przez samochód
     *
     * Funkcja porusza samochód o konkretną ilość pikseli zależną od prędkości samochodu i mnożnika szybkości.
     * Jednocześnie wykonywany jest obrót samochodu wokół osi samochodu i zmieniana jest wartość zmiennej iHowdrive na jazdę prosto.
     */
    void turn();
    /**
     * \brief Funkcja służąca do pobrania parametrów skrętu
     *
     * Funkcja zwraca przez referencję kąt o jaki obraca się samochód w pojedyńzym ruchu,
     * jaki będzie kolejny kierunek jazdy oraz o ile trzeba przesunąć grafikę w osiach X i Y.
     * \param[in] RotationAngle Kąt obrotu grafiki samochodu
     * \param[in] NextDirection Kierunek następnego ruchu liniowego samochodu
     * \param[in] MoveX
     * \param[in] MoveX
     */
    void turn_Parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
    /**
     * \brief Funkcja służąca do pobrania parametrów zmiany pasa ruchu
     *
     * Funkcja zwraca przez referencję kąt o jaki obraca się samochód w pojedyńzym ruchu,
     * jaki będzie kolejny kierunek jazdy oraz o ile trzeba przesunąć grafikę w osiach X i Y.
     * \param[in] RotationAngle Kąt obrotu grafiki samochodu
     * \param[in] NextDirection Kierunek następnego ruchu liniowego samochodu
     * \param[in] MoveX
     * \param[in] MoveX
     */
    void change_lane_parameters(int &RotationAngle,int &NextDirection,int &MoveX,int &MoveY);
    /**
     * \brief Funkcja służąca do zmiany trybu jazdy na zmianę pasa
     *
     * Funkcja rozpoczynająca ruch samochodu po przekątnej w celu zmiany pasa ruchu.
     */
    void change_traffic_lane();
    /**
     * \brief Funkcja służąca do zatrzymania samochodu
     *
     * Funkcja wykorzystuje metodę slow_down() do zatrzymania pelnego samochodu.
     */
    void stop();
    /**
     * \brief Funkcja wyznaczająca kierunek ruchu samochodu
     *
     * Funkcja wyznacza kierunek ruchu samochodu na podstawie orientacji samochodu iOrientation.
     */
    int choose_direction();

private:





};

#endif // CAR_H
