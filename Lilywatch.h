#ifndef Lilywatch_h
#define Lilywatch_h

#include <SoftwareSerial.h>  
#include "Arduino.h"
#include "Defines.h"
#include "WatchState.h"
#include "Daemon.h"
#include "Config.h"
#include "Colors.h"
#include "Motor.h"

#include "Accel.h"
#include "Mag.h"
#include "Buttons.h"
#include "Light.h"
#include "Battery.h"
#include "IRDaemon.h"
class IRDaemon;

#include "SelectorState.h"

class Lilywatch
{
  public:
    Lilywatch();
    void setup();
    void run();
    void setState(int state);
    
    int getState();
    Config* getConfig();
    Colors* getColors();
    Motor* getMotor();
    
    Accel* getAccel();
    Mag* getMag();
    Buttons* getButtons();
    Light* getLight();
    Battery* getBattery();
    IRDaemon* getIR();
    
    void setMessageWaiting(bool);
  private:
    void loopState(); // Let's the current app run
    bool loopDaemons(); // Daemons always run
  
    WatchState * states[STATES] = {0};
    Daemon * daemons[DAEMONS] = {0};
    SelectorState * selState;
    SoftwareSerial fakeSerial;
    Config * cfg;
    Colors * colors;
    Motor * motor;
    IRDaemon * ir;
    
    //Sensors
    Accel * accel;
    Mag * mag;
    Buttons * btn;
    Light * light;
    Battery * battery;

    //
    byte lastMin = 0;

    bool messageWaiting = false;
    bool batteryChecked = false;
    bool batteryWarning = false;
    
    byte tickDelay = 15;

    //Counts how long you're holding selector access
    int selectorHoldCounter = 0;

    int state = 0;//What function state we are currently in

    //Config waits for buttons to be released first
    bool buttonsReleased = false;

    int accelReturnDelay = 0;
};

#endif
