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
const int maxPitch = 1500;
const int minPitch = 50;

float smoothValue = 0; 
const float smoothing_parameter = 0.9;

int melody[] = {
  // --- First Section ---
  NOTE_A3, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_D4, NOTE_A3, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_C4,
  NOTE_G3, NOTE_G3, NOTE_B3, NOTE_G3, NOTE_C4, NOTE_G3, NOTE_D4, NOTE_C4,
  NOTE_F3, NOTE_F3, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_F3, NOTE_C4, NOTE_B3,
  // --- Second Section ---
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_C4,
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_E3,
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_C4,
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3
};

int noteDurations[] = {
  // --- First Section ---
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  // --- Second Section ---
  6, 6, 6, 6, 8, 8,
  6, 6, 6, 6, 8, 8,
  6, 6, 6, 6, 8, 8,
  6, 6, 6, 16, 8, 16, 8
};


// -----------------------------
// Application Setup
// -----------------------------
void appSetup() {
  Serial.begin(9600);
  Serial.println("Let's rock.");

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
  
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
}

// -----------------------------
// Application Loop
// -----------------------------
void appLoop() {

}