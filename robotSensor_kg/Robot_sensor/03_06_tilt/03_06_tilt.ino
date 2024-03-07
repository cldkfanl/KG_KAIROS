#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

const float tiltThreshold = 0.6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  mpu6050.update();

  float accelY = mpu6050.getAccY();
  Serial.print("taccY : ");
  Serial.println(accelY);

  if(accelY > tiltThreshold){
    Serial.println("위쪽 기울임");
  }
  else if (accelY < -tiltThreshold) {
    Serial.println("아래쪽 기울임");
  }
}
