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
#include <Adafruit_SSD1306.h>
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


float tempC = 0;
float tempF = 0;
float pressPA = 0;
float pressIH = 0;
float humidRH = 0;

int count = 0;


#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3C 
Adafruit_SSD1306 display(OLED_RESET);

Adafruit_BME280 bme;

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

  for (i = 0; i <= 127; i++)
  {
    Wire.beginTransmission (i);
    //Serial.printf("Wire transmission end returned: %i \n",Wire.endTransmission());
    if (Wire.endTransmission () == 0)
      {
      Serial.printf("Found address: %03i (0x%02X) \n",i,i);  
      count++;
      delay (1);
      } 
  }
  Serial.printf("Done: Found %i device(s). \n",count);

  //setup Display
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.setRotation(0);

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);
  display.println("Robopot\nPart Container\nPart Computer\nAll Pot");
  display.display();
  // Draw a single pixel in white

  delay(2000);
  Time.zone(-6);


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

