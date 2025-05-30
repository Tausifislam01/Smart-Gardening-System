int sensor_pin = A0;
int pump_pin = 7; // Connect water pump to digital pin 7
const int trigPin = 9; // Trigger pin of ultrasonic sensor
const int echoPin = 10; // Echo pin of ultrasonic sensor
const int greenLedPin = 4; // Green LED pin
const int yellowLedPin = 3; // Yellow LED pin
const int redLedPin = 2; // Red LED pin

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(pump_pin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  int sensor_data = analogRead(sensor_pin);
  Serial.print("Sensor_data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (sensor_data > 950) {
    Serial.println("No moisture, Soil is dry");

    if (distance <= 10) {
      digitalWrite(pump_pin, HIGH);
      delay(5000);
      digitalWrite(pump_pin, LOW);
      Serial.println("Watering done");
    } else {
      Serial.println("Distance greater than 10 cm, not watering");
    }
  } else if (sensor_data >= 400 && sensor_data <= 950) {
    Serial.println("There is some moisture, Soil is medium");
  } else if (sensor_data < 400) {
    Serial.println("Soil is wet");
  }

  // LED indications based on distance
  if (distance < 4) {
    // Green LED
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  } else if (distance >= 4 && distance <= 7) {
    // Yellow LED
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  } else if (distance > 10) {
    // Red LED
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  } else {
    // Turn off all LEDs if distance is between 4 and 10 cm
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }

  delay(1000); // Adjust delay as necessary
}

 
