#include <MPU6050_tockn.h>
#include <Wire.h>

#include <Servo.h>
#define PIN_SERVO 3
Servo servo;

MPU6050 mpu6050(Wire);
float angleZ = 0.0;

unsigned long prevMillis = 0;

const int interval = 100;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  servo.attach(PIN_SERVO);
  Serial.println("Servo 90 setting");
  servo.write(90);
}

void loop() {
  unsigned long currMillis = millis();
  if (currMillis - prevMillis >= interval) {
    prevMillis = currMillis;

    mpu6050.update();
    float angleZ = mpu6050.getAngleZ();

    angleZ = map(int(angleZ), -90, 90, 5, 175);
    angleZ = constrain(angleZ, 5, 175);
    servo.write(angleZ);
    Serial.println(angleZ);
  }
}
