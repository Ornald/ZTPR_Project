#include "simulationproperties.h"
#include <QDebug>
SimulationProperties::SimulationProperties(QGraphicsView *MainView)
{

    SimulationPropertiesWidget=new QWidget(MainView);
    SimulationPropertiesWidget->setGeometry(1280,0,220,800);
    Layout = new QGridLayout(SimulationPropertiesWidget);

    SimulationSpeed = new OwnSlider(Qt::Horizontal);
    SpawnTime = new OwnSlider(Qt::Horizontal);
    ChangeLightsTime = new OwnSlider(Qt::Horizontal);
    MaxCarsNumber = new OwnSlider(Qt::Horizontal);
    MaxCarsSpeed = new OwnSlider(Qt::Horizontal);
    PrecentageToDamage = new OwnSlider(Qt::Horizontal);
    PrecentageToAmbulance = new OwnSlider(Qt::Horizontal);

    StartBtn = new QPushButton("Start");
    StopBtn = new QPushButton("Stop");
    PauseBtn = new QPushButton("Pauza");
    ExitBtn = new QPushButton("Zamknij");
    DamageBtn = new QPushButton("Uszkodz samochody");

    TurnDamage = new QCheckBox("Wlacz niszczenie samochodow");
    TurnAmbulance= new QCheckBox("Wlacz karetki");
    add_one_button(DamageBtn,0,0);
    add_buttons(StartBtn,StopBtn,1,0);
    add_buttons(PauseBtn,ExitBtn,2,0);
    add_checkBoxes(TurnDamage,3,0);
    add_checkBoxes(TurnAmbulance,4,0);
    add_sliders(SimulationSpeed,6,0,1,4,1,"Predkosc Symulacji",SimSpeedTitle,SimSpeedMin,SimSpeedMax);
    add_sliders(SpawnTime,8,0,1000,5000,200,"Czas do nowego samochodu [ms]",SpwTimTitle,SpwTimeMin,SpwTimeMax);
    add_sliders(ChangeLightsTime,10,0,8000,16000,400,"Czas na zmiane swiatel [ms]",ChngLigTimTitle,ChngLigTimMin,ChngLigTimMax);
    add_sliders(MaxCarsNumber,12,0,5,20,1,"Maksymalna ilosc samochodow",MaxCarNumberTitle,MaxCarNumberMin,MaxCarNumberMax);
    add_sliders(MaxCarsSpeed,14,0,1,5,1,"Maksymalna predkosc samochodu",MaxCarSpeedTitle,MaxCarSpeedMin,MaxCarSpeedMax);
    add_sliders(PrecentageToDamage,16,0,1,10,1,"% szansa na zepsucie samochodu",PrecentageToDamageTitle,PrecentageToDamageMin,PrecentageToDamageMax);
    add_sliders(PrecentageToAmbulance,18,0,1,10,1,"% szansa na pojawienie sie karetki",PrecentageToAmbulanceTitle,PrecentageToAmbulanceMin,PrecentageToAmbulanceMax);

    ChangeLightsTime->setValue(iChangeLights);
    SpawnTime->setValue(iSpwnTime);
    MaxCarsSpeed->setValue(3);
    connect(SimulationSpeed,&OwnSlider::valueChanged,this,&SimulationProperties::change_simulationSpeed);
    connect(SpawnTime,&OwnSlider::valueChanged,this,&SimulationProperties::change_spawnTime);
    connect(ChangeLightsTime,&OwnSlider::valueChanged,this,&SimulationProperties::change_LightTime);
    connect(MaxCarsNumber,&OwnSlider::valueChanged,this,&SimulationProperties::change_maxCarsNumber);
    connect(MaxCarsSpeed,&OwnSlider::valueChanged,this,&SimulationProperties::change_maxCarsSpeed);
    connect(PrecentageToDamage,&OwnSlider::valueChanged,this,&SimulationProperties::change_precentageToDamage);
    connect(PrecentageToAmbulance,&OwnSlider::valueChanged,this,&SimulationProperties::change_precentageToAmbulance);

    connect(StartBtn,SIGNAL(clicked()),this,SLOT(press_start()));
    connect(StopBtn,SIGNAL(clicked()),this,SLOT(press_stop()));
    connect(PauseBtn,SIGNAL(clicked()),this,SLOT(press_pause()));
    connect(ExitBtn,SIGNAL(clicked()),this,SLOT(press_exit()));
    connect(DamageBtn,SIGNAL(clicked()),this,SLOT(destroy_two_cars()));


    connect(TurnAmbulance,&QCheckBox::stateChanged,this,&SimulationProperties::checked_ambulance);
    connect(TurnDamage,&QCheckBox::stateChanged,this,&SimulationProperties::checked_destroyed);
}

SimulationProperties::~SimulationProperties()
{
    delete TurnAmbulance;
    delete TurnDamage;
    delete ExitBtn;
    delete PauseBtn;
    delete StopBtn;
    delete StartBtn;
    delete PrecentageToAmbulance;
    delete PrecentageToDamage;
    delete MaxCarsSpeed;
    delete MaxCarsNumber;
    delete ChangeLightsTime;
    delete SpawnTime;
    delete SimulationSpeed;

    delete SimSpeedTitle;
    delete SimSpeedMin;
    delete SimSpeedMax;
    delete SpwTimTitle;
    delete SpwTimeMin;
    delete SpwTimeMax;
    delete ChngLigTimTitle;
    delete ChngLigTimMin;
    delete ChngLigTimMax;
    delete MaxCarNumberTitle;
    delete MaxCarNumberMin;
    delete MaxCarNumberMax;
    delete MaxCarSpeedTitle;
    delete MaxCarSpeedMin;
    delete MaxCarSpeedMax;
    delete PrecentageToDamageTitle;
    delete PrecentageToDamageMin;
    delete PrecentageToDamageMax;
    delete PrecentageToAmbulanceTitle;
    delete PrecentageToAmbulanceMin;
    delete PrecentageToAmbulanceMax;

    delete Layout;
    delete SimulationPropertiesWidget;
}

int SimulationProperties::get_simSpeed()
{
    return iSimSpeed;
}

int SimulationProperties::get_spwnTime()
{
    return iSpwnTime;
}

int SimulationProperties::get_changLighTime()
{
    return iChangeLights;
}

int SimulationProperties::get_maxCar()
{
    return iMaxCarNumber;
}

int SimulationProperties::get_maxSpeed()
{
    return iMaxCarSpeed;
}

int SimulationProperties::get_precToDam()
{
    return iPrecentageToDamage;
}

int SimulationProperties::get_precToAmb()
{
    return iPrecentageToAmbulance;
}

bool SimulationProperties::get_destroy()
{
    return bDestroy;
}

void SimulationProperties::set_destroyed(bool _damaged)
{
    bDestroy=_damaged;
}

bool SimulationProperties::get_start()
{
    return bStart;
}

bool SimulationProperties::get_stop()
{
    return bStop;
}

bool SimulationProperties::get_exit()
{
    return bExit;
}

bool SimulationProperties::get_bAmbulance()
{
    return bAmbulance;
}

bool SimulationProperties::get_bDamage()
{
    return bDamage;
}

void SimulationProperties::change_simulationSpeed(int _value)
{
    iSimSpeed=_value;

}

void SimulationProperties::change_spawnTime(int _value)
{
    iSpwnTime=_value;

}

void SimulationProperties::change_LightTime(int _value)
{
    iChangeLights=_value;
}

void SimulationProperties::change_maxCarsNumber(int _value)
{
    iMaxCarNumber=_value;

}

void SimulationProperties::change_maxCarsSpeed(int _value)
{
    iMaxCarSpeed=_value;

}

void SimulationProperties::change_precentageToDamage(int _value)
{
    iPrecentageToDamage=_value;

}

void SimulationProperties::change_precentageToAmbulance(int _value)
{
    iPrecentageToAmbulance=_value;

}

void SimulationProperties::press_start()
{
    bStart=1;
    bStop=0;
}

void SimulationProperties::press_stop()
{
    bStop=1;
    bStart=0;
}

void SimulationProperties::press_pause()
{
    bStart=0;
}

void SimulationProperties::press_exit()
{
    bExit=1;
}

void SimulationProperties::checked_ambulance()
{
    if(bAmbulance==0)
        bAmbulance=1;
    else
        bAmbulance=0;
}

void SimulationProperties::checked_destroyed()
{
    if(bDamage==0)
        bDamage=1;
    else
        bDamage=0;
}

void SimulationProperties::destroy_two_cars()
{
    bDestroy=1;
}

void SimulationProperties::add_sliders(OwnSlider *_sliderToAdd, int _row, int _column, int _min, int _max, int _step,QString _title,QLabel *_titleLabel,QLabel *_minLabel,QLabel *_maxLabel)
{
    setSlider(_sliderToAdd,_min,_max,_step);
   _titleLabel = new QLabel(_title);
    QHBoxLayout *TitleLayout= new QHBoxLayout();
    TitleLayout->addWidget(_titleLabel);
    _minLabel = new QLabel(QString::number(_min));
    _maxLabel = new QLabel(QString::number(_max));
    QHBoxLayout *HLayout = new QHBoxLayout();
    HLayout->addWidget(_minLabel);
    HLayout->addWidget(_sliderToAdd);
    HLayout->addWidget(_maxLabel);
    Layout->addLayout(TitleLayout,_row-1,_column);
    Layout->addLayout(HLayout,_row,_column);


}

void SimulationProperties::setSlider(OwnSlider *_slider, int _min,int _max, int _step)
{
    _slider->setRange(_min,_max);
    _slider->setSingleStep(_step);
}

void SimulationProperties::add_buttons(QPushButton *_fstBtn, QPushButton* _sndBtn,int _row,int _column)
{
    QHBoxLayout *HLayout = new QHBoxLayout();
    HLayout->addWidget(_fstBtn);
    HLayout->addWidget(_sndBtn);
    Layout->addLayout(HLayout,_row,_column);
}

void SimulationProperties::add_one_button(QPushButton *_Btn, int _row, int _column)
{
     QHBoxLayout *HLayout = new QHBoxLayout();
     HLayout->addWidget(_Btn);
     Layout->addLayout(HLayout,_row,_column);
}

void SimulationProperties::add_checkBoxes(QCheckBox *_checkBoxToAdd,int _row,int _column)
{
    QHBoxLayout *HLayout = new QHBoxLayout();
    HLayout->addWidget(_checkBoxToAdd);
    Layout->addLayout(HLayout,_row,_column);
}
