#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
const int scl = A5;
const int sda = A4;
const int snt = 2;
sensors_event_t a, g, tmp;
void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial){
    delay(10);
  }
  Serial.println("Adafruit MPU6050 test");
  if(!mpu.begin()){
    Serial.println("Failed to find MPU6050 chip");
    while(1){
      delay(10);
    }
  }
  int sensorscl = analogRead(scl);
  int sensorsda = analogRead(sda);
  int sensorsnt = analogRead(snt);
  Serial.println("MPU found!");

}

void loop() {
  // put your main code here, to run repeatedly:

}
