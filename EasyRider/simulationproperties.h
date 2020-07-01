#ifndef SIMULATIONPROPERTIES_H
#define SIMULATIONPROPERTIES_H

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ownslider.h"


class SimulationProperties :public QWidget
{
    Q_OBJECT
public:
    SimulationProperties(QGraphicsView *MainView);
    ~SimulationProperties();
    int get_simSpeed();
    int get_spwnTime();
    int get_changLighTime();
    int get_maxCar();
    int get_maxSpeed();
    int get_precToDam();
    int get_precToAmb();
    bool get_start();
    bool get_stop();
    bool get_exit();
    bool get_bAmbulance();
    bool get_bDamage();

private slots:
    void change_simulationSpeed(int _value);
    void change_spawnTime(int _value);
    void change_LightTime(int _value);
    void change_maxCarsNumber(int _value);
    void change_maxCarsSpeed(int _value);
    void change_precentageToDamage(int _value);
    void change_precentageToAmbulance(int _value);
    void press_start();
    void press_stop();
    void press_pause();
    void press_exit();
    void checked_ambulance();
    void checked_destroyed();

private:
    OwnSlider* SimulationSpeed;
    OwnSlider* SpawnTime;
    OwnSlider* ChangeLightsTime;
    OwnSlider* MaxCarsNumber;
    OwnSlider* MaxCarsSpeed;
    OwnSlider* PrecentageToDamage;
    OwnSlider* PrecentageToAmbulance;

    QLabel *SimSpeedTitle;
    QLabel *SimSpeedMin;
    QLabel *SimSpeedMax;
    QLabel *SpwTimTitle;
    QLabel *SpwTimeMin;
    QLabel *SpwTimeMax;
    QLabel *ChngLigTimTitle;
    QLabel *ChngLigTimMin;
    QLabel *ChngLigTimMax;
    QLabel *MaxCarNumberTitle;
    QLabel *MaxCarNumberMin;
    QLabel *MaxCarNumberMax;
    QLabel *MaxCarSpeedTitle;
    QLabel *MaxCarSpeedMin;
    QLabel *MaxCarSpeedMax;
    QLabel *PrecentageToDamageTitle;
    QLabel *PrecentageToDamageMin;
    QLabel *PrecentageToDamageMax;
    QLabel *PrecentageToAmbulanceTitle;
    QLabel *PrecentageToAmbulanceMin;
    QLabel *PrecentageToAmbulanceMax;



    QPushButton* StartBtn;
    QPushButton* StopBtn;
    QPushButton* PauseBtn;
    QPushButton *ExitBtn;

    QCheckBox* TurnDamage;
    QCheckBox* TurnAmbulance;

    QWidget *SimulationPropertiesWidget;

    QGridLayout *Layout;



    void add_sliders(OwnSlider *_sliderToAdd, int _row, int _column, int _min, int _max, int _step, QString _title,QLabel *_titleLabel,QLabel *_minLabel,QLabel *_maxLabel);
    void setSlider(OwnSlider *_slider, int _min,int _max, int _step);
    void add_buttons(QPushButton *_fstBtn, QPushButton *_sndBtn, int _row, int _column);
    void add_checkBoxes(QCheckBox *_checkBoxToAdd, int _row, int _column);

    int iSimSpeed=1;
    int iSpwnTime=2000;
    int iChangeLights=10000;
    int iMaxCarNumber=5;
    int iMaxCarSpeed=3;
    int iPrecentageToDamage=1;
    int iPrecentageToAmbulance=1;

    bool bStart=1;
    bool bStop=0;
    bool bExit=0;

    bool bAmbulance=0;
    bool bDamage=0;


};



#endif // SIMULATIONPROPERTIES_H
