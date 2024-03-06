#include <Arduino.h>
#include "Motor.h"
#include "UltrasonicSensor.h"

#define PIN_MA1A 5
#define PIN_MA1B 6
#define PIN_MB1A 9
#define PIN_MB1B 10

#define PIN_SONIC_TRIG 14
#define PIN_SONIC_ECHO 15

int iSpeed = 150;
#define WHEEL_DIFF_VALUE 0

Motor leftMotor(PIN_MA1A, PIN_MA1B);
Motor rightMotor(PIN_MB1A, PIN_MB1B);
UltrasonicSensor sonicSensor(PIN_SONIC_TRIG, PIN_SONIC_ECHO);

void setup() {
  Serial.begin(9600);
  leftMotor.setSpeed(iSpeed);
  rightMotor.setSpeed(iSpeed + WHEEL_DIFF_VALUE);
}


void loop() {
  long distance = sonicSensor.getDistance();
  Serial.println(distance);

  if (distance < 15) {
    leftMotor.backward();
    rightMotor.backward();
    delay(500);
    rightMotor.forward();
    leftMotor.stop();
    delay(500);
  } else {
    leftMotor.forward();
    rightMotor.forward();
  }
}
