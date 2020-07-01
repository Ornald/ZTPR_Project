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
#include <vector>

class Map:public QObject
{
Q_OBJECT

public:
    Map(QGraphicsScene &_scene);
    virtual ~Map();
    int check_if_turn(int _way,int _roadID,int _orientation,Position _carPosition);
    int next_road_id(int _way,int _roadID, int _orientation);
    void change_lights();
    int check_if_stop_on_lights(Position _position,int _orientation,int _roadID);
    int check_light_status(int _orientation,int _roadID);
    bool check_if_can_cross();

    void addCarSensor(Sensors * _sensorToAdd);
    void deleteCarSensor(int _carID);
    void checkSensors();
    int distance_to_next_car(int _carID);
    int get_next_car_speed(int _carID);
    int find_Next_Car(int _carID);



    bool check_if_can_drive(int _carID);
    bool check_if_stuck(int _carID);
    int get_next_orientation(int _way,int _orientation);



private:
    QGraphicsScene *Scene;



    void load_crossroad(int _crossroadID, int _orientation, int _posXR, int _posXL);
    std::vector<CrossRoad> vCrossRoadVector;
    Position pTurnsPositions(int _index);
    int returnParameter(int _way,int _R,int _F,int _L);
    int check_roadID_condition(int _roadID, int _orientation);
    std::vector<CrossRoad>::iterator  find_crossroad(int _roadID,int _orientation);
    bool check_if_X_Y(int _roadID);
    bool check_if_exit(int _roadID,int _orientation);

    std::vector<TrafficLight*> vTrafficLVector;
    void load_trafficlight(Position _position,int _startStatus,int _orientation,int _roadID,int _stopPoint);
    void add_traffics_light_to_scene();
    void delay( int millisecondsToWait );

    TrafficLight *find_trafficlight(int _roadID,int _orientation);

    std::vector<Sensors*> vAllCarSensor;
    Sensors *find_Car_Sensor(int _carID);

    //int distance_to_next_car(int _carID);
    void check_distance_between(Sensors *_fstSensor,Sensors* _sndSensor,int &_Xdiff,int &_Ydiff);
    int get_trafficLight_position(int _nextRoadID, int _orientation);
    void find_car_on_next_road(int _carID, int _nextRoadID, int &_min, int &_minID, int _orienDiff);
    bool check_if_on_crossroad(Position _carPosition, int _xmin, int _xmax, int _ymin, int _ymax);
    void get_crossroad_positions(int _ID,int &_xmin, int &_xmax, int &_ymin, int &_ymax);
    int get_closest_crossroad(int _carID, int _orientation);
    bool check_if_crossroad_free(int _carID);








};

#endif // MAP_H
