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


// -----------------------------
// Application Setup
// -----------------------------
void appSetup() {
  Serial.begin(9600);
  Serial.println("Let's rock.");

  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

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
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
}

// -----------------------------
// Application Loop
// -----------------------------
void appLoop() {
  int raw = analogRead(A0);
  Serial.println(raw);
  delay(100);
}