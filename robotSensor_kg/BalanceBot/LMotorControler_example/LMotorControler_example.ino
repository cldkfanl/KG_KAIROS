#include "LMotorController.h"

#define MIN_ABS_SPEED 20

//MOTOR CONTROLLER
int ENA = 3;
int IN1 = 4;
int IN2 = 5;
int IN3 = 7;
int IN4 = 8;
int ENB = 9;

LMotorController motorController(ENA, IN1, IN2, ENB, IN3, IN4, 1, 1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start...");

}

void loop() {
  // put your main code here, to run repeatedly:
  motorController.move(200);
  Serial.println("move");
  delay(10000);

  motorController.stopMoving();  
  Serial.println("stop");
  delay(1000);

  motorController.move(-200);  
  Serial.println("move back");
  delay(1000);

  motorController.turnLeft(200, false);  
  Serial.println("turn left");
  delay(1000);

}
