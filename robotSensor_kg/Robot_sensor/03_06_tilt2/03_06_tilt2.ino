#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
int stepCnt = 0;
bool isStepPeak = false;
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

  if(isStepPeak && accelY < 0){
    isStepPeak = false;
  }
  if(accelY > tiltThreshold && !isStepPeak){
    stepCnt++;
    isStepPeak = true;
    Serial.println("걸음수 :" + String(stepCnt));
  }
}
