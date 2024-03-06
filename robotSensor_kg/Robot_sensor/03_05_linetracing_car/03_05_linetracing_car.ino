#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define PIN_MA1A 5
#define PIN_MA1B 6

#define PIN_MB1A 9
#define PIN_MB1B 10

#define PIN_IR_L 7
#define PIN_IR_R 8

#define LINE 1
#define NoLINE 0

#define GET_IR_L digitalRead(PIN_IR_L)
#define GET_IR_R digitalRead(PIN_IR_R)


int Speed = 115;
int rSpeed = 100;


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_IR_L, INPUT);
  pinMode(PIN_IR_R, INPUT);

  pinMode(PIN_MA1A, OUTPUT);
  pinMode(PIN_MA1B, OUTPUT);
  pinMode(PIN_MB1A, OUTPUT);
  pinMode(PIN_MB1B, OUTPUT);


  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("");

  if (GET_IR_L == NoLINE && GET_IR_R == NoLINE) {
    forward();
  } else if (GET_IR_R == LINE && GET_IR_L == NoLINE) {
    right();
  } else if (GET_IR_R == NoLINE && GET_IR_L == LINE) {
    left();
  } else if (GET_IR_R == LINE && GET_IR_L == LINE) {
    stop();
  }
  delay(5);
}

void carMove(int aa, int ab, int ba, int bb) {
  analogWrite(PIN_MA1A, aa);
  analogWrite(PIN_MA1B, ab);
  analogWrite(PIN_MB1A, ba);
  analogWrite(PIN_MB1B, bb);
}
void forward() {
  carMove(Speed, 0, rSpeed, 0);
}
void left() {
  carMove(0, Speed * 0.5 , rSpeed, 0);
}
void right() {
  carMove(Speed, 0, 0, rSpeed * 0.5);
}
void stop() {
  carMove(0, 0, 0, 0);
}