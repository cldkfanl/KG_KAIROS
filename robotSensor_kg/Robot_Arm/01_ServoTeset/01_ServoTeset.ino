#include <Servo.h>

int basePin = 4;
int shoulderPin = 5;
int upperPin = 6;
int forearmPin = 7;

const int servoIntAngle = 90;

Servo base;
Servo shoulder;
Servo upperarm;
Servo forearm;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  base.attach(basePin);
  shoulder.attach(shoulderPin);
  upperarm.attach(upperPin);
  forearm.attach(forearmPin);

  base.write(servoIntAngle);
  shoulder.write(servoIntAngle);
  upperarm.write(servoIntAngle);
  forearm.write(servoIntAngle);
}

void loop() {
  // put your main code here, to run repeatedly:9
  
  for (int i = 80; i <= 100; i++) {
    base.write(i);
    shoulder.write(i);
    upperarm.write(i);
    forearm.write(i);
    delay(30);
  }
  for (int i = 100; i >=80; i--) {
    base.write(i);
    shoulder.write(i);
    upperarm.write(i);
    forearm.write(i);
    delay(30);
  }
}
