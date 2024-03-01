#include "SoftwareSerial.h"

const int tx_pin = 4;
const int rx_pin = 3;

SoftwareSerial bluetooth(rx_pin,tx_pin);

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  delay(1000);
  bluetooth.println("AT");
}

void loop(){
  if (bluetooth.available()){
    Serial.write(bluetooth.read());
  }

  if (Serial.available()){
    bluetooth.write(Serial.read());
  }
}