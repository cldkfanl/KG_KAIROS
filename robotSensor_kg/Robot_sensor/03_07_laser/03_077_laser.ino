#include "Adafruit_VL53L0X.h"
#include <Servo.h>
Servo myServo;
const int servoPin = 11;

int pos = 15;
int direction = 1;

const int min_angle = 15;
const int max_angle = 165;
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
  int distance;

  pos += direction;
  myServo.write(pos);
  if (pos >= max_angle) {
    pos = 165;
    direction = -1;
  } else if (pos <= min_angle) {
    pos = 15;
    direction = 1;
  }
  myServo.write(pos);

  distance = getDistance();
  Serial.print(pos);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");

  delay(30);
}

int getDistance(){
  if(lox.isRangeComplete()){
    return (lox.readRange()/10);
  }
  return 0;
}
