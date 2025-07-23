-#include <Servo.h>

#define IR_PIN 11
#define SERVO_PIN 8

Servo servo;

void setup() {
  pinMode(IR_PIN, INPUT);
  servo.attach(SERVO_PIN);
  servo.write(90); // Initialize servo position to 0 degrees
}

void loop() {
  if (digitalRead(IR_PIN) == HIGH) {
    // Object detected, rotate servo to 90 degrees
    servo.write(0);
     // Hold servo at 90 degrees for 4 seconds
  } else {
    // No object detected, rotate servo back to 0 degrees
    servo.write(90);
    delay(5000);
  }
}
