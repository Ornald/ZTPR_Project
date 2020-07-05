#ifndef MAP_H
#define MAP_H

#include "position.h"
#include <vector>
#include "crossroad.h"
#include <QDebug>
#include <cmath>
#include "trafficlight.h"
#include <QObject>
#include <QGraphicsScene>
#include <QTime>
#include <QCoreApplication>
#include "sensors.h"

/**
  * \class Map
 * \brief Klasa obsługująca mapę.
 *
 * Uwzględnia ona światła, skrzyżowania i poruszanie się różnych samochodów względem siebie.
 */

class Map:public QObject
{
Q_OBJECT

public:
    /**
     * \brief Konstruktor klasy
     *
     *  W konstruktorze tworzone są wektory świateł oraz skrzyżowań korzystające z klas Crossroad i TrafficLight
     * \param[in] _scene Przyjmuje parametr będący sceną
     */
    Map(QGraphicsScene &_scene);
    /**
     * \brief Destruktor klasy
     *
     *  Zwalnianie jest miejsce na wektory wskaźników do sensorów i świateł drogowych
     */
    virtual ~Map();
    /**
     * \brief Funkcja zwracająca odległość od punktu zakrętu
     *
     *  W zależności od pozycji, orientacji i kierunku funkcja zwraca odległość od punktu, w którym samochód powinien skręcić by trafić w odpowiednią drogę.
     * \param[in] _way Kierunek, w którym będzie jechał samochód
     * \param[in] _roadID Identyfikator drogi na którym jest samochód
     * \param[in] _orientation Orientacje samochodu
     * \param[in] _carPosition Pozycja samochodu
     */
    int check_if_turn(int _way,int _roadID,int _orientation,Position _carPosition);
    /**
     * \brief Funkcja zwracająca identyfikator następnej drogi samochodu
     *
     *  Na podstawie aktualnej drogi, nastepnego ruchu oraz orientacji wyznaczany jest identyfikator kolejnej drogi.
     * \param[in] _way Kierunek, w którym będzie jechał samochód
     * \param[in] _roadID Identyfikator drogi na którym jest samochód
     * \param[in] _orientation Orientacje samochodu
     */
    int next_road_id(int _way,int _roadID, int _orientation);
    /**
     * \brief Funkcja zmieniająca wszystkie światła jednocześnie
     *
     *  Funkcja zmienia wszystkie światła w wektorze świateł drogowych.
     */
    void change_lights();
    /**
     * \brief Funkcja zwracająca odległość od miejsca na którym samochody się zatrzymują na światłach
     *
     *  W zależności od pozycji, orientacji i drogi zwracana jest odległość od miejsca, w którym samochody stają na światłach.
     * \param[in] _roadID Identyfikator drogi na którym jest samochód
     * \param[in] _orientation Orientacje samochodu
     * \param[in] _carPosition Pozycja samochodu
     */
    int check_if_stop_on_lights(Position _position,int _orientation,int _roadID);
    /**
     * \brief Funkcja zwracająca status świateł na drodze
     *
     *  W zależności od orientacji i drogi zwracany jest status świateł przy konkretnej drodze.
     * \param[in] _roadID Identyfikator drogi na którym jest samochód
     * \param[in] _orientation Orientacje samochodu
     */
    int check_light_status(int _orientation,int _roadID);
    /**
     * \brief Funkcja sprawdzająca czy jest dość miejsca by wyminąć uszkodzony pojazd
     *
     *  Funkcja znajduje najbliższe pojazdy zarówno przed jak i naprzeciwko uszkodzonego pojazdu i sprawdza czy są odpowiednio daleko.
     * \param[in] _carID Identyfikator samochodu, który chce wyminąć uszkodzony
     * \param[in] _brokenCarID Identyfikator uszkodzonego samochodu
     */
    bool check_if_can_overtake(int _carID, int &_brokenCarID);
    /**
     * \brief Funkcja sprawdzająca czy jest dość miejsca by wrócić na własny tor
     *
     *  Funkcja sprawdza czy na oryginalnym torze jest dość miejsca by wrócić na miejsce.
     * \param[in] _carID Identyfikator samochodu, który chce wyminąć uszkodzony
     * \param[in] _brokenCarID Identyfikator uszkodzonego samochodu
     */
    bool check_if_can_return(int _carID, int _brokenCarID);
    /**
     * \brief Funkcja sprawdzająca czy jest dość miejsca by zawrócić
     *
     *  Funkcja znajduje najbliższe pojazdy przed pojazdem i jeśli jest wystarczająco miejsca pozwala na zawracanie.
     * \param[in] _carID Identyfikator samochodu, który chce zawrócić
     */
    bool check_if_can_turn_back(int _carID);
    /**
     * \brief Funkcja sprawdzająca czy droga po której jedzie samochód jest drogą wyjściową
     *
     *  Funkcja zwraca na podstawie identyfikatora drogi i orientacji czy dana droga prowadzi do wyjścia czy nie.
     * \param[in] _roadID Identyfikator drogi
     * \param[in] _orientation Orientacja samochodu
     */
    bool check_if_exit(int _roadID,int _orientation);
    /**
     * \brief Funkcja dodająca wskaźnik na sensor do wektora wskaźników sensorów
     *
     * \param[in] _sensorToAdd wskaźnik na sensor, który ma zostać dodany
     */
    void addCarSensor(Sensors * _sensorToAdd);
    /**
     * \brief Funkcja usuwająca sensor samochodu
     *
     * Funkcja wyszukuje w wektorze sensorów tego o odpowiednim numerze ID samochodu i go usuwa. Zarówno zwalniając pamięć jak i z wektora.
     * \param[in] _carID ID szukanego samochodu
     */
    void deleteCarSensor(int _carID);

    /**
     * \brief Funkcja zwracająca prędkośc następnego samochodu
     *
     * Funkcja wyszukuje w wektorze sensorów następny samochód i zwraca jego prędkość.
     * \param[in] _carID ID szukanego samochodu
     */
    int get_next_car_speed(int _carID);
    /**
     * \brief Funkcja wyszukująca następny samochód
     *
     * Funkcja wyszukuje w wektorze sensorów następny samochód oddalony o zadane wartości oddalony w drugiej osi.
     * \param[in] _carID ID szukanego samochodu
     * \param[in] _sndMinDistance Minimalna odległość
     * \param[in] _sndMaxDistance Maksymalna odległość
     */
    int find_Next_Car(int _carID, int _sndMinDistance, int _sndMaxDistance);
    /**
     * \brief Funkcja sprawdzająca czy holownik jest blisko celu
     *
     * Funkcja wyszukuje w wektorze sensorów holownik i samochód docelowy i wyznacza odległość między nimi.
     * Gdy oba są na tej samej ulicy i odległość jest odpowienia mała zwraca true.
     * \param[in] _carID ID holownika
     * \param[in] _targetCarID ID szukanego samochodu
     */
    bool check_if_close_to_target(int _carID, int _targetCarID);
    /**
     * \brief Funkcja sprawdzająca czy samochód może wjechać na skrzyżowanie
     *
     * Funkcja wyszukuje samochód naprzeciwko i w zależności od jego typu i wykonywanego ruchu pozwala jednemu z nich lub obydwu na wjechanie na skrzyżowanie.
     * Pierwszeństwo mają samochody priorytetowe.
     * \param[in] _carID ID samochodu
     */
    bool check_if_can_drive(int _carID);
    /**
     * \brief Funkcja uniemożliwiająca wjechanie na skrzyżowanie jeśli nie będzie mógł on zjechać.
     *
     * Funkcja wyszukuje ostatnią pozycję samochodu na drodze na którą skręca samochód i
     *  jeśli jest ona odpowiednio mała od świateł to następny samochód nie wjedzie na skrzyżowanie.
     * \param[in] _carID ID samochodu
     */
    bool check_if_stuck(int _carID);
    /**
     * \brief Funkcja zwracającą następną orientacje samochodu
     *
     * Funkcja wyznacza na podstawie aktualnej orientacji i kierunku jazdy kolejną orientację samochodu.
     * \param[in] _way Kierunek jazdy
     * \param[in] _orientation Aktualna orientacja samochodu
     */
    int get_next_orientation(int _way,int _orientation);

    /**
     * \brief Funkcja zwracającą dystans do kolejnego samochodu
     *
     * Funkcja wyznacza dystans do kolejnego samochodu biorąc pod uwagę lub nie sąsiednie pasy.
     * Jest ona w postacie szablonu, chociaż nie ma takiej potrzeby, ponieważ takie było wymaganie projektowe.
     * \param[in] _carID ID samochodu
     * \param[in] _lane Wartośc odnosząca się do aktualnego pasu lub przeciwnego
     */

    template< typename T> T distance_to_next_car (T _carID, T _lane){
        Sensors *baseSensor= find_Car_Sensor(_carID);
            T nextCarID;
            if (_lane==0)
            nextCarID = find_Next_Car(_carID,0,5);
            else
              nextCarID=find_Next_Car(_carID,20,40);
            if (-1==nextCarID)
                return -1;

            Sensors* NextCarSensor=find_Car_Sensor(nextCarID);
           bool x_or_y = check_if_X_Y(baseSensor->get_RoadID());
           T Xdis;
           T Ydis;

            check_distance_between(baseSensor,NextCarSensor,Xdis,Ydis);
           if(x_or_y)
           {
               return Ydis;
           }
           else
           {
               return Xdis;
           }


           return -1;

    }


private:
    QGraphicsScene *Scene;

    /**
     * \brief Funkcja dodająca do wektora klasy Crossroad nowe instancje
     *
     * \param[in] _crossroadID ID skrzyżowania
     * \param[in] _orientation Orientacja do której się odności skrzyżowanie
     * \param[in] _posXR Pozycja do skrętu w prawo
     * \param[in] _posXL Pozucja do skrętu w lewo
     */

    void load_crossroad(int _crossroadID, int _orientation, int _posXR, int _posXL);
    std::vector<CrossRoad> vCrossRoadVector;
    /**
     * \brief Funkcja zwracająca pozycje, gdzie następuje pojawienie się nowych samochodów
     *
     * Funkcja przyjmuje indeks drogi wjazdowej i zwraca pozycje punktu, w którym pojawi się samochód.
     * \param[in] _index indeks drogi startowej
     */
    Position pTurnsPositions(int _index);
    /**
     * \brief Funkcja zwracająca jedną z trzech wartości w zależności od zmiennej wybierającej
     *
     * Funkcja _R,_F lub _L w zależności od _way.
     * \param[in] _way Kierunek jazdy samochodu
     * \param[in] _R Numer drogi po skręcie w prawo
     * \param[in] _F Numer drogi po jeździe prosto
     * \param[in] _L Numer drogi po skręcie w lewo
     */
    int returnParameter(int _way,int _R,int _F,int _L);
    /**
     * \brief Funkcja sprawdzająca czy dana droga jest w środku mapy
     *
     * Funkcja zwraca 1 jeśli droga jest w środku mapy i ma orietnację 180 lub 270.
     * \param[in] _roadID Numer drogi
     * \param[in] _orientation Orientacja drogi
     */
    int check_roadID_condition(int _roadID, int _orientation);
    /**
     * \brief Funkcja zwracająca iterator wektora wskazujący na skrzyżowanie
     *
     * Funkcja zwraca iterator wektora wskazujący na skrzyżowanie o zadanej wartości ID drogi i orientacji.
     * \param[in] _roadID Numer drogi
     * \param[in] _orientation Orientacja drogi
     */
    std::vector<CrossRoad>::iterator  find_crossroad(int _roadID,int _orientation);
    /**
     * \brief Funkcja sprawdzająca czy dana droga jest pozioma czy pionowa
     *
     * W przypadku drogi pionowej wynik będzie 1, a w przypadku poziomej 0.
     * \param[in] _roadID Numer drogi
     */
    bool check_if_X_Y(int _roadID);


    std::vector<TrafficLight*> vTrafficLVector;
    /**
     * \brief Funkcja dodająca do wektora TrafficLight instancje
     *
     * \param[in] _position Pozycja świateł drogowych
     * \param[in] _startStatus Status startowy lamp drogowych
     * \param[in] _orientation Orientacja lampy
     * \param[in] _roadID Numer drogi przy której stoi lampa
     * \param[in] _stopPoint Punkt przy którym mają sie zatrzymywać samochody
     */
    void load_trafficlight(Position _position,int _startStatus,int _orientation,int _roadID,int _stopPoint);
    /**
     * \brief Funkcja dodająca światła drogowe do sceny
     */
    void add_traffics_light_to_scene();
    /**
     * \brief Funkcja wprowadzająca pauzę w czasie wykonania innych funkcji
     *
     * Funkcja wprowadza pazuę w aktualnej funkcji przy jednoczesnym zachowaniu działania pozostałych aktywnych funkcji, timerów i sygnałów.
     * \param[in] _milisecounds Czas jaki ma trwać zadana pauza
     */
    void delay( int millisecondsToWait );

    /**
     * \brief Funkcja zwracająca wskaźnik na klasę TrafficLight
     *
     * Funkcja znajduje w wektorze instancję klasy o zadanym indeksie klasy i orientacji i ją zwraca.
     * \param[in] _orientation Orientacja lampy
     * \param[in] _roadID Numer drogi przy której stoi lampa
     */
    TrafficLight *find_trafficlight(int _roadID,int _orientation);

    std::vector<Sensors*> vAllCarSensor;
    /**
     * \brief Funkcja zwracająca wskaźnik na klasę Sensors
     *
     * Funkcja znajduje w wektorze instancję klasy o zadanym indeksie sensora.
     * \param[in] _carID Identyfikator samochodu
     */
    Sensors *find_Car_Sensor(int _carID);

    /**
     * \brief Funkcja zwracająca odległośc między dwoma samochodami
     *
     * Funkcja znajduje dwa samochody i sprawdza odległość między nimi w osi X i Y.
     * \param[in] _fstSensor Sensor pierwszego samochodu
     * \param[in] _sndSensor Sensor drugiego samochodu
     * \param[in] _Xdiff Współrzędna X
     * \param[in] _Ydiff Współrzędna Y
     */
    void check_distance_between(Sensors *_fstSensor,Sensors* _sndSensor,int &_Xdiff,int &_Ydiff);
    /**
     * \brief Funkcja zwracająca pozycje światła ze względu na następną drogę i orientację samochodu
     *
     * \param[in] _orientation Orientacja lampy
     * \param[in] _nextRoadID Numer drogi w którą skręci samochód
     */
    int get_trafficLight_position(int _nextRoadID, int _orientation);
    /**
     * \brief Funkcja zwracająca odległość do najbliższego samochodu na następnej drodze oraz jego ID
     *
     * \param[in] _carID ID badanego samochodu
     * \param[in] _nextRoadID ID drogi po skręcie
     * \param[in] _min Minimalna odległość do następnego samochodu
     * \param[in] _minID ID najbliższego samochodu
     * \param[in] _orienDiff różnica w badanej orientacji. 180 dla samochodu z naprzeciwka
     */
    void find_car_on_next_road(int _carID, int _nextRoadID, int &_min, int &_minID, int _orienDiff);
    /**
     * \brief Funkcja sprawdza czy skrzyżowanie jest zajęte przez samochód
     *
     * Jeśli jakiś samochód ma pozycję we wnątrz podanego przedziału zmiennych funkcja zwraca 1.
     * W przeciwnym przypadku zwraca 0.
     * \param[in] _carPosition Pozycja samochodu
     * \param[in] _xmin
     * \param[in] _xmax
     * \param[in] _ymin
     * \param[in] _ymax
     */
    bool check_if_on_crossroad(Position _carPosition, int _xmin, int _xmax, int _ymin, int _ymax);
    /**
     * \brief Funkcja zwraca współrzędne skrzyżowania (Współrzędne tworzą mniejszy kwadrat wewnątrz skrzyżowania.
     *
     * \param[in] _ID ID skrzyżowania
     * \param[in] _xmin
     * \param[in] _xmax
     * \param[in] _ymin
     * \param[in] _ymax
     */

    void get_crossroad_positions(int _ID,int &_xmin, int &_xmax, int &_ymin, int &_ymax);
    /**
     * \brief Funkcja zwraca ID najbliższego skrzyżowania
     *
     * Funkcja na podstawie pozycji samcohodu i jego orientacji sprawdza, które skrzyżowanie jest najbliżej.
     * \param[in] _orientation Orientacja samochodu
     * \param[in] _carID Identyfikator samochodu
     */
    int get_closest_crossroad(int _carID, int _orientation);
    /**
     * \brief Funkcja sprawdza czy skrzyżowanie jest wolne czy też nie.
     *
     * Sprawdza czy inny samochód niż ten, który wywołuje tę funkcje nie znajduje się już na skrzyżowaniu.
     * \param[in] _carID Identyfikator samochodu
     */
    bool check_if_crossroad_free(int _carID);








};

#endif // MAP_H
