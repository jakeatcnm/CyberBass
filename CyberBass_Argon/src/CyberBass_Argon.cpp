/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/jake/Documents/IoT/CyberBass/CyberBass_Argon/src/CyberBass_Argon.ino"
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

#include <Adafruit_MQTT.h>
#include "Adafruit_MQTT/Adafruit_MQTT_SPARK.h" 
#include "credentials.h"


void setup();
void loop();
#line 22 "c:/Users/jake/Documents/IoT/CyberBass/CyberBass_Argon/src/CyberBass_Argon.ino"
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
int i = 0;

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3C 
Adafruit_SSD1306 display(OLED_RESET);

Adafruit_BME280 bme;


TCPClient TheClient; 

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details. 
Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY); 
Adafruit_MQTT_Publish humidityPub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Humidity");
Adafruit_MQTT_Publish pressurePub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Pressure");
Adafruit_MQTT_Publish temperaturePub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Temperature");
Adafruit_MQTT_Publish NotePub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Note");


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
  display.setRotation(2);

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);
  display.println("CYBERBASS BOOTING UP!");
  display.display();

  delay(2000);
  Serial.printf("Connecting to Internet \n");
  display.clearDisplay();
  display.setCursor(0,0);
  display.printf("Connecting to Infonet\n");
  display.display();
  WiFi.connect();
  while(WiFi.connecting()) {
    Serial.printf(".");
    delay(100);
  }
  Time.zone(-6);
  Particle.syncTime();
  delay(100); //wait for Serial Monitor to startup


  //Setup BME
  bme.begin(0x76);


}


/*
  Select mode
    normal
    judaspriest
    deathmetal

  receive note data
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

