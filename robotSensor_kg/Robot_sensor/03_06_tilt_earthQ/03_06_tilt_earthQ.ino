#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

#define PIN_BUZZER 13
#define CMP_VAL 3


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  pinMode(PIN_BUZZER, OUTPUT);
  Serial.println("Start!");
  digitalWrite(PIN_BUZZER, LOW);
}

void loop() {

  mpu6050.update();
  signed int GyroX = mpu6050.getGyroX();
  signed int GyroY = mpu6050.getGyroY();
  signed int GyroZ = mpu6050.getGyroZ();

  if (abs(GyroX) > 3 && abs(GyroY) > 3 && abs(GyroZ) > 3) {
    digitalWrite(PIN_BUZZER, HIGH);
    Serial.println(String(GyroX) + " " + String(GyroY) + " " + String(GyroX));
    delay(1000);
    digitalWrite(PIN_BUZZER, LOW);
  }
}
