#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
Adafruit_MPU6050 mpu;

//left_motor
#define PIN_MA1A 5
#define PIN_MA1B 6
//right_motor
#define PIN_MB1A 9
#define PIN_MB1B 10
//sonic_sensor
#define PIN_SONIC_TRTG 14
#define PIN_SONIC_ECHO 15

#define WHEEL_DIFF_VALUE 0


int err;
int iSpeed = 150;
int leftWheelSpeed = iSpeed;
int rightWheelSpeed = leftWheelSpeed + WHEEL_DIFF_VALUE + err;

#define SONIC_DISTANCE 15



void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_MA1A, OUTPUT);
  pinMode(PIN_MA1B, OUTPUT);
  pinMode(PIN_MB1A, OUTPUT);
  pinMode(PIN_MB1B, OUTPUT);

  pinMode(PIN_SONIC_TRTG, OUTPUT);
  pinMode(PIN_SONIC_ECHO, INPUT);

  Serial.begin(9600);

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  long er=g.gyro.z*1200;
  err=er;
  Serial.print("GyroZ:");
  Serial.print(er);
  Serial.println("");
}

void sonicCar(){
  long distance = getDistance();
  Serial.println(String(distance)+ " cm") ;
  
  if (distance < SONIC_DISTANCE) {
  backward();
  delay(500);
  left();
  delay(500);

  }else{
    forward();
  }
}

//sonic_distance

long getDistance(){
  digitalWrite(PIN_SONIC_TRTG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_SONIC_TRTG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_SONIC_TRTG, LOW);

  long duration = pulseIn(PIN_SONIC_ECHO, HIGH);
  long distance = (duration / 2) / 29.1;

  return distance;
  
}

//move_car
void carMove(int aa, int ab, int ba, int bb){
  analogWrite(PIN_MA1A, aa);
  analogWrite(PIN_MA1B, ab);
  analogWrite(PIN_MB1A, ba);
  analogWrite(PIN_MB1B, bb);
}

void forward(){
  carMove(leftWheelSpeed, 0, rightWheelSpeed, 0);
}
void backward(){
  carMove(0, leftWheelSpeed, 0, rightWheelSpeed);
}
void left(){
  carMove(0,0,rightWheelSpeed,0);
}
void right(){
  carMove(leftWheelSpeed,0,0,0);
}
void stop(){
  carMove(0,0,0,0);
}