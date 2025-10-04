#include <Arduino.h>
#include "pitches.h"

// pins
const int ledPin = LED_BUILTIN;
const int buzzerPin = 2;
//const int analogPin = A0;

// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;

// sound parameters
const int maxPitch = 2000;
const int minPitch = 100;

float smoothValue = 0; 
const float smoothing_parameter = 0.9;

int melody[] = {
  NOTE_A3, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_D4, NOTE_A3, NOTE_E4, NOTE_D4
};

int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8
};


// -----------------------------
// Application Setup
// -----------------------------
void appSetup() {
  Serial.begin(9600);
  Serial.println("Starting up.");
  
  delay(500);

  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  // play an initial melody
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]); thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }

  delay(500);

  Serial.println("Calibration in progress.");
  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  delay(500);

  Serial.println("Let's rock.");
  // play a final melody
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]); thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);

  delay(500);
}

// -----------------------------
// Application Loop
// -----------------------------
void appLoop() {
  int raw = analogRead(A0);

  // exponential smoothing
  smoothValue = smoothing_parameter * smoothValue + (1-smoothing_parameter) * raw;

  // linear mapping
  int pitch = map((int)smoothValue, sensorHigh, sensorLow, maxPitch, minPitch);

  // logatithmic mapping
  //float ratio = (float)(smoothValue - sensorLow) / (sensorHigh - sensorLow);
  //int pitch = 100 * pow(2, ratio * 5);  // da 100 Hz a 3200 Hz


  if (smoothValue > 0.9 * sensorLow) {
    tone(buzzerPin, pitch);
  } else {
    noTone(buzzerPin);
  }

  delay(1);
}