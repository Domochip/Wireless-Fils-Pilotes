#ifndef Main_h
#define Main_h

#include <arduino.h>

//DomoChip Informations
//Configuration Web Pages :
//http://IP/
//Fils Pilotes Request Web Pages
//http://IP/setFP?FP1=21

/*
  FilsPilotes States :
  - 0-10 : Arrêt
  - 11-20 : Hors Gel
  - 21-30 : Eco
  - 31-40 : Confort-2
  - 41-50 : Confort-1
  - 51-99 : Confort
*/


//model is 1, 4 or 8
#define MODEL_WFP 8

//include Application header file
#define APPLICATION1_HEADER "WirelessFilsPilotes.h"
#if MODEL_WFP == 1
#define APPLICATION1_NAME "WFP1"
#else
#define APPLICATION1_NAME "WFP4/8"
#endif
#define APPLICATION1_DESC "DomoChip Wireless FilsPilotes"
#define APPLICATION1_CLASS WebFP

#define APPLICATION2_HEADER "WebDS18B20Bus.h"
#define APPLICATION2_NAME "WDS18B20"
#define APPLICATION2_DESC "DomoChip Wireless DS18B20"
#if MODEL_WFP == 1
#define APPLICATION2_CLASS WebDS18B20Bus
#endif

#define VERSION_NUMBER "3.4.1"

#define DEFAULT_AP_SSID "WirelessFP"
#define DEFAULT_AP_PSK "PasswordFP"

//Enable status webpage EventSource
#define ENABLE_STATUS_EVENTSOURCE 1

//Enable developper mode
#define DEVELOPPER_MODE 0

//Log Serial Object
#define LOG_SERIAL Serial
//Choose Log Serial Speed
#define LOG_SERIAL_SPEED 115200

#if MODEL_WFP > 1
//Choose Pin used to boot in Rescue Mode
#define RESCUE_BTN_PIN 16
#endif

//Status LED
//red GPIO14 (LOW level light UP)
//green GPIO12 (LOW level light UP)
#define STATUS_LED_SETUP pinMode(14, OUTPUT);pinMode(12, OUTPUT);
#define STATUS_LED_OFF digitalWrite(14, HIGH);digitalWrite(12, HIGH);
#define STATUS_LED_ERROR digitalWrite(14, LOW);digitalWrite(12, HIGH);
#define STATUS_LED_WARNING digitalWrite(14, LOW);digitalWrite(12, LOW);
#define STATUS_LED_GOOD digitalWrite(14, HIGH);digitalWrite(12, LOW);

//construct Version text
#if DEVELOPPER_MODE
#define VERSION VERSION_NUMBER "-DEV"
#else
#define VERSION VERSION_NUMBER
#endif

#endif


