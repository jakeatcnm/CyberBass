/*
     C     C#    D     Eb    E     F     F#    G     G#    A     Bb    B
 0 16.35 17.32 18.35 19.45 20.60 21.83 23.12 24.50 25.96 27.50 29.14 30.87
 1 32.70 34.65 36.71 38.89 41.20 43.65 46.25 49.00 51.91 55.00 58.27 61.74
 2 65.41 69.30 73.42 77.78 82.41 87.31 92.50 98.00 103.8 110.0 116.5 123.5
 3 130.8 138.6 146.8 155.6 164.8 174.6 185.0 196.0 207.7 220.0 233.1 246.9
 4 261.6 277.2 293.7 311.1 329.6 349.2 370.0 392.0 415.3 440.0 466.2 493.9
 5 523.3 554.4 587.3 622.3 659.3 698.5 740.0 784.0 830.6 880.0 932.3 987.8
 6 1047  1109  1175  1245  1319  1397  1480  1568  1661  1760  1865  1976
 7 2093  2217  2349  2489  2637  2794  2960  3136  3322  3520  3729  3951
 8 4186  4435  4699  4978  5274  5588  5920  6272  6645  7040  7459  7902
 
 Guitar strings are E2=82.41Hz, A2=110Hz, D3=146.8Hz, G3=196Hz, B3=246.9Hz, E4=329.6Hz
 
 Bass strings are (5th string) B0=30.87Hz, (4th string) E1=41.20Hz, A1=55Hz, D2=73.42Hz, G2=98Hz
 
 You can change the frequency by typing "f " + frequency in the serial monitor.
 EX. "f 30.87"
 
 You can change the amplitude by typing "a " + amplitude in the serial monitor. (0,1)
 EX. "a .5"
 */


#include <Adafruit_NeoPixel.h> 
#include <SerialFlash.h>
#include <AudioTuner.h>
#include <Audio.h>
#include <Wire.h>
#include "frequencyToNote.h"
#include "pitchToNote.h"
#include "coeff.h"



const int PIXELPIN = 6;
const int PIXELCOUNT = 12;
int pixelBrightness = 255;
Adafruit_NeoPixel pixel(PIXELCOUNT, PIXELPIN, NEO_GRB + NEO_KHZ800);

AudioTuner                tuner;
//AudioAnalyzePeak          peak1;
AudioSynthWaveformSine    sine;
AudioInputAnalog          adc;
AudioMixer4               mixer;

float freq = 0;
int audioPeakLevel = 0;

AudioConnection patchCord1(adc,  0, mixer, 0);
AudioConnection patchCord2(mixer, 0, tuner, 0);
//AudioConnection patchCord3(mixer, 0, peak1, 0);



// hold serial commands
char buffer[10];

void setup() {
    AudioMemory(30);
    /*
     *  Initialize the yin algorithm's absolute
     *  threshold, this is good number.
     */
    Serial.begin(9600);
    Serial1.begin(9600);
    tuner.begin(.15, fir_22059_HZ_coefficients, sizeof(fir_22059_HZ_coefficients), 2);
    
    sine.frequency(30.87);
    sine.amplitude(1);
      //initialize pixel
    pixel.begin();
    pixel.show();
      for (int i = 0; i < PIXELCOUNT; i++){
    pixel.clear();
    pixel.show();
    pixel.setPixelColor(i, random(255), random(255), random(255));
    pixel.setBrightness(pixelBrightness);
    pixel.show();
    delay(100);
    pixel.clear();
    pixel.show();
  }
}

void loop() {
    // read back fundamental frequency
    if (tuner.available()) {
        freq = tuner.read();
        float prob = tuner.probability();
        //audioPeakLevel = peak1.read();
        Serial.printf("Note: %3.2f\n", freq);
    }
    
    Serial1.printf("%3.2f\n", freq);
    
    
    //Bass strings are (4th string) E1=41.20Hz, A1=55Hz, D2=73.42Hz, G2=98Hz
    pixel.setBrightness(255);
    if(freq > 38 && freq < 44.2){
      if (freq < 39){
        pixel.clear();
        pixel.setPixelColor(0, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 40){
        pixel.clear();
        pixel.setPixelColor(1, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 40.3){
        pixel.clear();
        pixel.setPixelColor(2, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 40.6){
        pixel.clear();
        pixel.setPixelColor(3, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 40.8){
        pixel.clear();
        pixel.setPixelColor(4, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 41){
        pixel.clear();
        pixel.setPixelColor(5, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 41.4){
        pixel.clear();
        pixel.setPixelColor(6, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 41.8){
        pixel.clear();
        pixel.setPixelColor(7, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 42.4){
        pixel.clear();
        pixel.setPixelColor(8, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 43){
        pixel.clear();
        pixel.setPixelColor(9, 255, 0, 0);
        pixel.show();
      }
      else if(freq < 43.6){
        pixel.clear();
        pixel.setPixelColor(10, 255, 0, 0);
        pixel.show();
      }
      else{
        pixel.clear();
        pixel.setPixelColor(11, 255, 0, 0);
        pixel.show();
      }
    }

    //A1=55Hz
    else if(freq > 50 && freq < 60){
      if(freq < 51.0){
        pixel.clear();
        pixel.setPixelColor(0, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 53.0){
        pixel.clear();
        pixel.setPixelColor(1, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 53.5){
        pixel.clear();
        pixel.setPixelColor(2, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 54.0){
        pixel.clear();
        pixel.setPixelColor(3, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 54.5){
        pixel.clear();
        pixel.setPixelColor(4, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 54.8){
        pixel.clear();
        pixel.setPixelColor(5, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 55.2){
        pixel.clear();
        pixel.setPixelColor(6, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 55.6){
        pixel.clear();
        pixel.setPixelColor(7, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 56.0){
        pixel.clear();
        pixel.setPixelColor(8, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 56.8){
        pixel.clear();
        pixel.setPixelColor(9, 0, 255, 0);
        pixel.show();
      }
      else if(freq < 57.5){
        pixel.clear();
        pixel.setPixelColor(10, 0, 255, 0);
        pixel.show();
      }
      else{
        pixel.clear();
        pixel.setPixelColor(11, 0, 255, 0);
        pixel.show();
      }
    }
    //D2=73.42Hz
    else if(freq > 63 && freq < 83){
      if(freq < 65){
        pixel.clear();
        pixel.setPixelColor(0, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 67.5){
        pixel.clear();
        pixel.setPixelColor(1, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 69.0){
        pixel.clear();
        pixel.setPixelColor(2, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 70){
        pixel.clear();
        pixel.setPixelColor(3, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 71.5){
        pixel.clear();
        pixel.setPixelColor(4, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 73.22){
        pixel.clear();
        pixel.setPixelColor(5, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 73.62){
        pixel.clear();
        pixel.setPixelColor(6, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 75.5){
        pixel.clear();
        pixel.setPixelColor(7, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 77.75){
        pixel.clear();
        pixel.setPixelColor(8, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 79){
        pixel.clear();
        pixel.setPixelColor(9, 0, 0, 255);
        pixel.show();
      }
      else if(freq < 81){
        pixel.clear();
        pixel.setPixelColor(10, 0, 0, 255);
        pixel.show();
      }
      else{
        pixel.clear();
        pixel.setPixelColor(11, 0, 0, 255);
        pixel.show();
      }
    }
    
    //G2=98Hz
    else if(freq > 90 && freq < 106){
      if(freq < 92.5){
        pixel.clear();
        pixel.setPixelColor(0, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 94){
        pixel.clear();
        pixel.setPixelColor(1, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 95.25){
        pixel.clear();
        pixel.setPixelColor(2, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 96.25){
        pixel.clear();
        pixel.setPixelColor(3, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 97.35){
        pixel.clear();
        pixel.setPixelColor(4, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 97.8){
        pixel.clear();
        pixel.setPixelColor(5, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 98.2){
        pixel.clear();
        pixel.setPixelColor(6, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 98.65){
        pixel.clear();
        pixel.setPixelColor(7, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 99){
        pixel.clear();
        pixel.setPixelColor(8, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 100.5){
        pixel.clear();
        pixel.setPixelColor(9, 255, 255, 255);
        pixel.show();
      }
      else if(freq < 102.5){
        pixel.clear();
        pixel.setPixelColor(10, 255, 255, 255);
        pixel.show();
      }
      else{
        pixel.clear();
        pixel.setPixelColor(11, 255, 255, 255);
        pixel.show();
      }
    }
    else{
       pixel.setBrightness(5);
       pixel.clear();
       for(int i = 0; i < PIXELCOUNT; i++){
        pixel.setPixelColor(i, 255, 0, 0);   
       }
       pixel.show();
    }
    
    if (Serial.available()) {
        Serial.readBytesUntil('\n', buffer, 10);
        handleCmds( buffer );
    }
}
