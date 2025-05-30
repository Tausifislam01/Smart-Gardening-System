Smart Gardening System
Overview
This project is a Smart Gardening System designed to automate plant care and enhance safety through environmental monitoring. The system integrates various sensors and actuators to monitor soil moisture, temperature, humidity, gas levels, and fire hazards, while also controlling an automated watering system, a door mechanism, and a humidifier for optimal plant growth conditions.
Features

Automated Watering: Uses a soil moisture sensor to detect dry soil and triggers a water pump when the water level is sufficient (checked via an ultrasonic sensor).
Environmental Monitoring: Measures temperature and humidity using a DHT22 sensor.
Safety Alerts: Detects gas leaks (MQ2 sensor) and fire hazards (flame sensor) with LED and buzzer alerts.
Automated Door System: Controlled via an IR sensor for secure access to the garden area.
Humidifier Control: Regulates air moisture and temperature using a humidifier driven by an ultrasonic fogging mechanism.
Real-time Feedback: Outputs sensor data to the Serial Monitor for monitoring and debugging.

Hardware Components

Arduino Board (e.g., Arduino Uno)
Sensors:
DHT22: Temperature and humidity sensor
MQ2: Gas sensor for detecting smoke or gas leaks
Flame Sensor: Detects fire hazards
Soil Moisture Sensor: Measures soil moisture levels
Ultrasonic Sensor (HC-SR04): Measures water level or distance for door control
IR Sensor: Controls the automated door system


Actuators:
Water Pump: For automated watering
Humidifier: Ultrasonic fogger for humidity and temperature control
Buzzer: Alerts for gas or fire detection
LEDs: Red, green, yellow for status indication


Other Components:
Resistors, jumper wires, breadboard, or custom PCB



Software Requirements

Arduino IDE: For uploading code to the Arduino board
Libraries:
DHT.h (DHT sensor library)
Adafruit_Sensor.h and DHT_U.h (Adafruit Unified Sensor library for DHT22)


Install libraries via the Arduino Library Manager or download from:
DHT Sensor Library
Adafruit Unified Sensor Library



Installation and Setup

Hardware Setup:

Connect sensors and actuators to the Arduino as specified in the code files (refer to pin definitions in each .ino file).
Ensure proper wiring for the IR sensor (door control), MQ2, flame sensor, DHT22, soil moisture sensor, ultrasonic sensor, and humidifier.
Refer to docs/setup_guide.md for detailed wiring instructions and a schematic diagram.


Software Setup:

Install the Arduino IDE from arduino.cc.
Install the required libraries (DHT.h, Adafruit_Sensor.h, DHT_U.h) via the Arduino Library Manager.
Clone or download this repository:git clone https://github.com/yourusername/SmartGardeningSystem.git


Open the .ino files in the Arduino IDE.


Upload Code:

Connect your Arduino board to your computer via USB.
Select the correct board and port in the Arduino IDE.
Upload each .ino file to the Arduino. Note: You may need to combine the code into a single sketch or use multiple Arduino boards depending on your setup.


Testing:

Open the Serial Monitor (9600 baud) to view sensor readings and system status.
Test each module (watering, door, humidifier, safety alerts) to ensure proper functionality.



Usage

Watering System: The soil moisture sensor triggers the water pump if the soil is dry (value > 950) and the water level is sufficient (ultrasonic sensor distance ≤ 10 cm).
Safety System: The MQ2 gas sensor and flame sensor trigger a buzzer and red LED if gas levels exceed the threshold (11) or a flame is detected.
Door System: The IR sensor controls the automated door (logic not fully provided in the code; assumes external mechanism).
Humidifier: The ultrasonic fogger maintains humidity and temperature, controlled via ultrasonicfog.ino.
Monitoring: Temperature, humidity, gas, flame, and soil moisture data are printed to the Serial Monitor.

Pin Configuration



Component
Pin(s)



DHT22
D2


MQ2 Gas Sensor
A5


Flame Sensor
D3


Soil Moisture Sensor
A0


Ultrasonic (Trig/Echo)
D9, D10


Water Pump
D7


Humidifier
PORTC (custom)


IR Sensor
Not specified


LEDs (Red/Green)
D12, D11


LEDs (Green/Yellow/Red)
D4, D3, D2


Buzzer
D10


Notes

The IR sensor and door system logic are not fully detailed in the provided code. You may need to add an additional .ino file or extend existing code for complete door automation.
The ultrasonicfog.ino uses low-level register manipulation for the humidifier; ensure compatibility with your Arduino board.
Adjust thresholds (e.g., gasThres, soil moisture levels) based on your environment and sensor calibration.
For a single Arduino setup, combine the code into one sketch, ensuring no pin conflicts.

Contributing
Contributions are welcome! Please:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Commit your changes (git commit -m 'Add new feature').
Push to the branch (git push origin feature-branch).
Open a Pull Request.

License
This project is licensed under the MIT License. See the LICENSE file for details.
Acknowledgments

Thanks to Adafruit for the DHT and Unified Sensor libraries.
Inspired by various Arduino-based smart gardening projects.

Contact
For questions or suggestions, open an issue or contact [yourusername] on GitHub.
