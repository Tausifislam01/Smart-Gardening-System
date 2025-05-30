#include <DHT.h>            // Include the DHT library

#define DHTPIN 2            // Define the pin for DHT11
#define DHTTYPE DHT11       // DHT type is DHT11

DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT object

int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
int flamePin = 3; // Assuming the flame sensor is connected to digital pin 3

// Your threshold values
int gasThres = 11;

void setup() {
  Serial.begin(9600);       // Start serial communication
  dht.begin();              // Start DHT sensor
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(flamePin, INPUT); // Set flame sensor pin as input
}

void loop() {
  // Read temperature and humidity from DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int analogGas = analogRead(smokeA0);
  int digitalFlame = digitalRead(flamePin);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Gas Sensor Value: ");
  Serial.println(analogGas);

  Serial.print("Flame Sensor Value: ");
  Serial.println(digitalFlame);

  // Checks if gas sensor value has reached the threshold value
  if (analogGas > gasThres || digitalFlame == LOW) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, LOW);
  }

  delay(100);
}
