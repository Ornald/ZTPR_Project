#ifndef SIMULATION_H
#define SIMULATION_H

#include<vector>
#include <QObject>
#include "normaldriver.h"
#include <QGraphicsScene>
#include "prioritydriver.h"
#include "map.h"
#include "tugdriver.h"
#include "simulationproperties.h"
#include <QGraphicsView>
#include <QKeyEvent>

/**
 * \class Simulation
 * \brief Klasa obsługująca cała symulację
 *
 * W tej klasie znajdują się timery, które wprawiają w ruch samochody. Tworzona i usuwana jest mapa oraz wszyscy kierowcy wraz z samochodami.
 */

class Simulation: public QObject
{
    Q_OBJECT
private:
    Map *mMainMap;
    QGraphicsScene *MainScene;
    QGraphicsView *View;
    SimulationProperties *Properties;
    std::vector<Driver*> vCarVector;

    QTimer *MoveTimer;
    QTimer *AddTimer;
    QTimer *TrafficLightTimer;
    QTimer *CheckPropertiesTimer;


    int iDriversIDs=0;
    int iSimSpeed=1;
    int iSpwnTime=2000;
    int iChangeLights=10000;
    int iMaxCarNumber=5;
    int iMaxCarSpeed=3;
    int iPrecentageToDamage=1;
    int iPrecentageToAmbulance=1;
    int iNumberOfDamaged=0;
    int iDamagedCarsNumber=0;
    int iLastRoadDamaged=10;
    int iLastRoadSpawn=10;
    int iCounter=0;

    bool bStart=1;
    bool bStop=0;
    bool bExit=0;
    bool bDestory=0;

    bool bAmbulance=0;
    bool bDamage=0;

    /**
     * \brief Funkcja losująca punkt startowy i maksymalną prędkość samochodu
     *
     * Punkt startowy jest losowany z zakresu 0-7. Natomiast prędkośc maksymalna od 1 do limitu ustawionego na suwaku w czasie symulacji.
     */
    void random_parameters(int &_maxSpeed, int &_startIndex);
    /**
     * \brief Funkcja zmieniająca interwał między kolejnymi sygnałami z timera
     *
     * Funkcja przyjmuje timer, który ma zostać zmieniony oraz interwał jaki ma zostać ustawiony w timerze.
     * \param[in] _timerToChange Timer, którego interwał ma zostać zmieniony
     * \param[in] _interval Wartość interwału jaki ma zostać ustawiony
     */
    void changeTimer(QTimer *_timerToChange, int _interval);
    /**
     * \brief Funkcja kasująca samochody, które utkneły w czasie symulacji
     *
     * Funkcja kasuje samochody, które utknęły w czasie symulacji. Ma to na celu utrzymanie płynności ruchu w symulatorze i uodpornieniu na błędy programu.
     */
    void check_stuck_cars();
    /**
     * \brief Funkcja zwracająca orientację jaką powinien mieć samochód w różnych pozycjach startowych.
     *
     * \param[in] _startPosition Pozycja startowa
     * \param[out] orientation orientacja samochodu w pozycji startowej
     */
    int prepare_car_to_add(int _startPosition);
    /**
     * \brief Funkcja kasująca samochody, które wyjechały poza mapę
     *
     * Funkcja kasuje samochody, które przejechały już swoje trasy i wyjeżdżają poza mapę.
     */
    void deleteCars();
    /**
     * \brief Funkcja wprowadzająca pauzę w czasie wykonania innych funkcji
     *
     * Funkcja wprowadza pazuę w aktualnej funkcji przy jednoczesnym zachowaniu działania pozostałych aktywnych funkcji, timerów i sygnałów.
     * \param[in] _milisecounds Czas jaki ma trwać zadana pauza
     */
    void delay (int _milisecounds);
    /**
     * \brief Funkcja sprawdzająca czy zmieniły się wartości typu bool pochodzace od przycisków
     *
     * W przypadku zmiany wartości przycisków wykonywane są odpowiednio pauza, stop, start bądź zamykany jest cały program.
     */
    void check_buttons();
    /**
     * \brief Funkcja sprawdzająca czy zmieniły się wartości ze sliderów
     *
     * W przypadku zmiany wartości suwaków zmieniane są parametry symulacji takie jak ilość samochodów, prędkość symulacji, prędkość zmian światła.
     */
    void check_sliders();
    /**
     * \brief Funkcja sprawdzająca czy zmieniły się wartości checkboxów
     *
     * W przypadku zmiany wartości suwaków zmieniane są parametry symulacji takie jak typy dopuszczalnych samochodów oraz wprowadzana jest możliwość niszczenia się samochodów.
     */
    void check_checkboxes();
    /**
     * \brief Funkcja zatrzymuje cała symulację
     *
     * W przypadku zatrzymania całej symulacji usuwane są również wszystkie samochody niezależnie od stanu i pozycji.
     */
    void stop_simulation();
    /**
     * \brief Funkcja służąca do usunięcia wszystkich samochodów na planszy
     *
     * Występuje równoczene czyszczenie wektora samochdów.
     */
    void delete_all_cars();
    /**
     * \brief Funkcja po znalezieniu odpowiedniego samochodu uszkadza go
     *
     * W przypadku,gdy któryś samochód ulegie uszkodzeniu zostaje on zatrzymany i tworzony jest holownik, które ma za zadanie zabrać ten samochód poza mapę.
     */
    void damage_some_cars();
    /**
     * \brief Funkcja usuwająca samochody z planszy jeśli zostały podniesione przez holownik
     *
     * W przypadku, gdy któryś samochód ma wartość iPicked =1 zostaje usunięty z planszy.
     */
    void delete_picked_cars();
    public:
    /**
     * \brief Konstruktor klasy
     *
     * Zostaje w tym miejscu stworzona mapa, załadowane i dodane obiekty graficzne jak przyciski, slidery oraz stworzone zostają timery.
     */
    Simulation(QGraphicsScene *_Scene, QGraphicsView *View);
    /**
     * \brief Destruktor klasy
     *
     * Niszczone są wszystkie wskaźniki oraz wektory wskaźników po uprzednim usunięciu oddzielnie ich zawartości.
     */
    ~Simulation();

private slots:
    /**
     * \brief Funkcja, która dodaje samochód
     *
     * Funkcja będąca slotem, który po upływie timera dodaje samochód do planszy pod warunkiem, że symulacja jest aktywna i nie ma osiągnietego limitu samochodów na planszy.
     */
    void add_car();
    /**
     * \brief Funkcja poruszająca wszystkimi samochodami na planszy
     *
     * Funkcja przechodzi po wektorze samochodów i wykonuje metody move.
     */
    void move_cars();
    /**
     * \brief Funkcja zmieniająca światła oraz statusy dróg
     *
     * Slot, który po upływie czasu zmienia światła z zielonego na czerwony i odwrotnie. W środku wykorzystana jest funkcja opóźnienia, by szybciej zmienić światło żółte.
     */
    void change_trafficlights();
    /**
     * \brief Funkcja sprawdzająca czy zmieniły się wartości symulacji
     *
     * Timer sprawdza czy zmieniły się wartości symulacji.
     */
    void check_properties();
    /**
     * \brief Funkcja do niszczenia 2 samochodów
     *
     * Funkcja niszczy 2 samochody. Przy czym nie mogą to być karetki ani holowniki, ponieważ nie mają one odpowiednich metod.
     * A to za długo by trwało w czasie obrony. Zepsucie tym sposobem nie powoduje pojawienie się holownika,
     * ponieważ holownik nie znalazłby celu gdy samochód psuje się w nieprzewidziaym wcześniej miejscu.
     * Inne samochody będa dalej wymijać uszkodzone samochody, gdy to będzie możliwe.
     */
    void damage_two_cars();

};

#endif // SIMULATION_H
