# Smart Gardening System

## Overview
This project is a **Smart Gardening System** designed to automate plant care and enhance safety through environmental monitoring. The system integrates various sensors and actuators to monitor soil moisture, temperature, humidity, gas levels, and fire hazards, while also controlling an automated watering system, a door mechanism, and a humidifier for optimal plant growth conditions.

## Features
- **Automated Watering**: Uses a soil moisture sensor to detect dry soil and triggers a water pump when the water level is sufficient (checked via an ultrasonic sensor).
- **Environmental Monitoring**: Measures temperature and humidity using a DHT22 sensor.
- **Safety Alerts**: Detects gas leaks (MQ2 sensor) and fire hazards (flame sensor) with LED and buzzer alerts.
- **Automated Door System**: Controlled via an IR sensor for secure access to the garden area.
- **Humidifier Control**: Regulates air moisture and temperature using a humidifier driven by an ultrasonic fogging mechanism.
- **Real-time Feedback**: Outputs sensor data to the Serial Monitor for monitoring and debugging.

## Hardware Components
- **Arduino Board** (e.g., Arduino Uno)
- **Sensors**:
  - **DHT22**: Temperature and humidity sensor
  - **MQ2**: Gas sensor for detecting smoke or gas leaks
  - **Flame Sensor**: Detects fire hazards
  - **Soil Moisture Sensor**: Measures soil moisture levels
  - **Ultrasonic Sensor (HC-SR04)**: Measures water level or distance for door control
  - **IR Sensor**: Controls the automated door system
- **Actuators**:
  - **Water Pump**: For automated watering
  - **Humidifier**: Ultrasonic fogger for humidity and temperature control
  - **Buzzer**: Alerts for gas or fire detection
  - **LEDs**: Red, green, yellow for status indication
- **Other Components**:
  - Resistors, jumper wires, breadboard, or custom PCB

## Software Requirements
- **Arduino IDE**: For uploading code to the Arduino board
- **Libraries**:
  - `DHT.h` (DHT sensor library)
  - `Adafruit_Sensor.h` and `DHT_U.h` (Adafruit Unified Sensor library for DHT22)
- Install libraries via the Arduino Library Manager or download from:
  - [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
  - [Adafruit Unified Sensor Library](https://github.com/adafruit/Adafruit_Sensor)

## Installation and Setup
1. **Hardware Setup**:
   - Connect sensors and actuators to the Arduino as specified in the code files (refer to pin definitions in each `.ino` file).
   - Ensure proper wiring for the IR sensor (door control), MQ2, flame sensor, DHT22, soil moisture sensor, ultrasonic sensor, and humidifier.
   - Refer to `docs/setup_guide.md` for detailed wiring instructions and a schematic diagram.

2. **Software Setup**:
   - Install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software).
   - Install the required libraries (`DHT.h`, `Adafruit_Sensor.h`, `DHT_U.h`) via the Arduino Library Manager.
   - Clone or download this repository:
     ```bash
     git clone https://github.com/yourusername/SmartGardeningSystem.git
