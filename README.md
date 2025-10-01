# Arduino Light Theremin

A DIY **photoresistor-based theremin** built with an Arduino Nano and a piezo buzzer.  
Move your hand over the LDR to change the pitch — just like a classic theremin, but with light!
Heavily inspired from the classic [Arduino example](https://projecthub.arduino.cc/SBR/light-theremin-1d63fe).

---

## Features

- Real-time pitch control using a photoresistor
- Automatic calibration on startup (adapts to ambient light)
- Exponential smoothing to reduce noise and jitter
- Linear pitch mapping
- Plays a short melody on startup/shutdown

---

## Hardware Required

- Arduino Nano (or compatible board)
- 1x Photoresistor
- 1x 10kΩ resistor (for voltage divider)
- 1x Piezo buzzer
- Jumper wires

---

## Circuit Connections

- **Buzzer** → Digital pin D2  
- **Photoresistor + 10kΩ resistor** → Voltage divider into Analog pin A0  
- **LED (optional)** → Built-in LED on pin 13 (used during calibration)

---

## Installation

1. Install [Arduino CLI](https://arduino.github.io/arduino-cli/latest/) or Arduino IDE.
2. Clone this repository:
   ```bash
   git clone https://github.com/amberlab-eclettica/theremin.git
   cd theremin
   ```
3. Compile and upload your repository to the arduino:
   ```bash
   make
   make upload
   ```
   
---

## How To Use

- **Startup melody**: On power-up, the theremin plays a short tune (familiar to some).  
- **Calibration phase**: For the next **5 seconds**, the photoresistor automatically calibrates to the ambient light.  
  > Move your hand over the theremin during this time to set the sensitivity range.  
- **Ready to play**: After calibration, the melody plays again, signaling that the theremin is ready.  
  Wave your hand over the sensor to control the pitch!
