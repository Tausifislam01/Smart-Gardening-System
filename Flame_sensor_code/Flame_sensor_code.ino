/*
Analog input, analog output, serial output

Reads an analog input pin, maps the result to a range from 0 to 255 and uses
the result to set the pulse width modulation (PWM) of an output pin.
Also prints the results to the Serial Monitor.

The circuit:
- Flame Sensor connected to analog pin 0. Analog Signal pin of the Flame Sensor goes to the analog pin A0
- LED connected from digital pin 9 to ground

by Tom, Tomson Electronics

This example code is in the public domain.

  © Tomsonelectronics
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0; // Analog input pin that the Flame Sensor is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0; // value read from the sensor
int outputValue = 0; // value output to the PWM (analog out)

void setup() {
// initialize serial communications at 9600 bps:
Serial.begin(9600);
}

void loop() {
// read the analog in value:
sensorValue = analogRead(analogInPin);
// map it to the range of the analog out:
outputValue = map(sensorValue, 0, 1023, 0, 255);
// change the analog out value:
analogWrite(analogOutPin, outputValue);

// print the results to the Serial Monitor:
Serial.print("sensor = ");
Serial.print(sensorValue);
Serial.print("\t output = ");
Serial.println(outputValue);

// wait 2 milliseconds before the next loop for the analog-to-digital
// converter to settle after the last reading:
delay(2);
}
