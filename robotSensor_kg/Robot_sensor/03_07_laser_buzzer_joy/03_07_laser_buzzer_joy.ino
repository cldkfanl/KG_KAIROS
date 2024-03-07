#include "Adafruit_VL53L0X.h"
#include <Servo.h>
#define PIN_BUZZER 13
#define PIN_JX A0
#define PIN_JY A1


Servo myServo;
const int servoPin = 11;

int pos = 15;

const int min_angle = 15;
const int max_angle = 165;
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_BUZZER, OUTPUT);
  while (!Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1)
      ;
  }
  // power
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));

  // start continuous ranging
  lox.startRangeContinuous();
  myServo.attach(servoPin);
  myServo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xVal = analogRead(PIN_JX);
  xVal = map(xVal, 0, 1023, -10, 10);
  int distance;
  if (xVal > 0) {
    pos++;
  } else if (xVal < 0) {
    pos--;
  }
  if (pos >= max_angle) {
    pos--;
  } else if (pos <= min_angle) {
    pos++;
  }
  myServo.write(pos);

  distance = getDistance();

  if (distance < 10) {
    digitalWrite(PIN_BUZZER, HIGH);
  } else {
    digitalWrite(PIN_BUZZER, LOW);
  }

  Serial.print(pos);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");

  delay(30);
}

int getDistance() {
  if (lox.isRangeComplete()) {
    return (lox.readRange() / 10);
  }
  return 0;
}
