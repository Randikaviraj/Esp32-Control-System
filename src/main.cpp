#include <Arduino.h>
#define ALERT_PORT 18
#define FEED_PORT  17
#define WATER_REMOVE_PORT  16
#define WATER_FILL_PORT 15
#define TEMPO_PIN  14
#define PH_PIN 12
#define WATER_RENEW_DELAY 60000


int feed_time=1000;

unsigned char checkTemarature(){
  // check the temparature
  
}

unsigned char checkPh(){
  //check the ph value
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
  // put your setup code here, to run once:
  pinMode(WATER_REMOVE_PORT,OUTPUT);
  pinMode(ALERT_PORT,OUTPUT);
  pinMode(FEED_PORT,OUTPUT);
  pinMode(WATER_FILL_PORT,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}