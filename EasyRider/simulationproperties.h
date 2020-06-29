#ifndef SIMULATIONPROPERTIES_H
#define SIMULATIONPROPERTIES_H

#include <QWidget>
#include <QSlider>
#include <QComboBox>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
class SimulationProperties :public QWidget
{
    Q_OBJECT
public:
    SimulationProperties(QGraphicsView *MainView);

private:
    QSlider* SimulationTime;
    QSlider* SpawnTime;
    QSlider* ChangeLightsTime;
    QSlider* MaxCarsNumber;
    QSlider* MaxCarsSpeed;
    QSlider* MinCarsSpeed;
    QSlider* PrecentageToDamage;
    QSlider* PrecentageToAmbulance;


    QPushButton* StartBtn;
    QPushButton* StopBtn;
    QPushButton* PauseBtn;

    QComboBox* TurnDamage;
    QComboBox* TurnAmbulance;

    void add_sliders(QGraphicsView *MainView);
    void add_buttons(QGraphicsView *MainView);
    void add_comboboxes(QGraphicsView *MainView);



};

#endif // SIMULATIONPROPERTIES_H
