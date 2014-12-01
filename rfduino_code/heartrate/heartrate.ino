/*
The sketch demonstrates how to do accept a Bluetooth Low Energy 4
Advertisement connection with the RFduino, then send CPU temperature
updates once a second.

It is suppose to be used with the rfduinoTemperature iPhone application.
*/

#include <RFduinoBLE.h>
int bpm = 20;
int up = 1;

void setup() {
  // this is the data we want to appear in the advertisement
  // (the deviceName length plus the advertisement length must be <= 18 bytes)
  RFduinoBLE.advertisementData = "temp";

  // start the BLE stack
  RFduinoBLE.deviceName = "FreeMotion";
  RFduinoBLE.begin();
}

void loop() {
  // sample once per second
  RFduino_ULPDelay( SECONDS(1) );

  // get a cpu temperature sample
  // degrees c (-198.00 to +260.00)
  // degrees f (-128.00 to +127.00)
  //float temp = RFduino_temperature(CELSIUS);

  // send the sample to the iPhone
  RFduinoBLE.sendInt(bpm);
  bpm+=(20*up);
  if(bpm >=240 || bpm <=20){
    up *= -1;
  }
  
}
