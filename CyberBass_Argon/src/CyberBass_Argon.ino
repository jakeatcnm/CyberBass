/*
 * Project CyberBass_Argon
 * Description:
 * Author:
 * Date:
 */

#include <particle.h>
#include <Adafruit_BME280.h>
#include <Wire.h>
#include <MPU6050.h>
#include <Encoder.h>
//#include <wemo.h>
#include <neopixel.h>

SYSTEM_MODE(SEMI_AUTOMATIC);

const int PIXELCOUNT = 64;

const int ENCODERPIN = D5;        
const int GREENPIN = D11;
const int REDPIN = D12;
const int ENCODERSWITCH = D13;
const int PUMPBUTTON = D14;
const int TRIGPIN = D15;
const int ECHOPIN = D16;
const int PUMPOUT = D17;



// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(GREENPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode (ENCODERSWITCH, INPUT);
  pinMode (PUMPBUTTON, INPUT_PULLDOWN);
  pinMode(PUMPOUT, OUTPUT);

}


/*
  Select mode
    normal
    judaspriest
    deathmetal

  receive midi data
  light up

  operate pump.

*/

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  

  //enable blood spewing
  bool bloody = digitalRead(PUMPBUTTON);
  if(bloody){
    digitalWrite(PUMPOUT, HIGH);
  }
  else{
    digitalWrite(PUMPOUT, LOW);
  }

  
}

