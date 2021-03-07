#include <Arduino.h>
#include <OneWire.h> 
#include <DallasTemperature.h>

#define ALERT_PORT 18
#define FEED_PORT  17
#define WATER_REMOVE_PORT  16
#define WATER_FILL_PORT 15
#define TEMPO_PIN  14 //pH meter Analog output to ESP Analog Input 14
#define PH_PIN 12
#define WATER_RENEW_DELAY 60000

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
// temparature stable range
float stable_temp=120.0;

// ph stable range
int stable_ph=140;

// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);


int feed_time=1000;

unsigned char checkTemarature(){
  // check the temparature
  // call sensors.requestTemperatures() to issue a global temperature 
 // request to all devices on the bus 
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  if( stable_temp-10<sensors.getTempCByIndex(0)<stable_temp+10){
  return '1';

  }else{
    return '0';
  }
}

unsigned char checkPh(){
  //check the ph value
  if(stable_ph-5<analogRead(PH_PIN)<stable_ph+5){
   return '1'; 
  }else{
    return '0';
  }
}

void alertOn(){
  // alert signal on
  digitalWrite(ALERT_PORT,HIGH);
}

void alertOff(){
  // alert signal off
  digitalWrite(ALERT_PORT,LOW);
}

void renewWater(){
  // switch water solinid walve to fill the water and remove water from other valve
  digitalWrite(WATER_REMOVE_PORT,HIGH);
  digitalWrite(WATER_FILL_PORT,HIGH);
  delay(WATER_RENEW_DELAY);
  digitalWrite(WATER_REMOVE_PORT,LOW);
  digitalWrite(WATER_FILL_PORT,LOW);
}

void feedFish(){
  // feed the fishes
  digitalWrite(FEED_PORT,HIGH);
  delay(feed_time); 
  digitalWrite(FEED_PORT,LOW);
}

void setup() {
  pinMode(WATER_REMOVE_PORT,OUTPUT);
  pinMode(ALERT_PORT,OUTPUT);
  pinMode(FEED_PORT,OUTPUT);
  pinMode(WATER_FILL_PORT,OUTPUT);
  // Start up the library 
  sensors.begin(); 
}

void loop() {
  
}