#include <SoftwareSerial.h>
//블루투스 시리얼
SoftwareSerial mySerial(4, 3);

//왼쪽모터
#define PIN_MA1A 5
#define PIN_MA1B 6

//오른쪽모터
#define PIN_MB1A 9
#define PIN_MB1B 10

//속도변수 : 좌측바퀴 기준
#define WHEEL_DIFF_VALUE -30

int iSpeed = 170;
int leftWheelSpeed = iSpeed;
int rightWheelSpeed = leftWheelSpeed + WHEEL_DIFF_VALUE;

void setup() {
  Serial.begin(9600);
  //블루투스 시리얼 begin
  mySerial.begin(9600);

  // put your setup code here, to run once:
  pinMode(PIN_MA1A, OUTPUT);
  pinMode(PIN_MA1B, OUTPUT);
  pinMode(PIN_MB1A, OUTPUT);
  pinMode(PIN_MB1B, OUTPUT);
}

void loop() {
  char data = ' ';
  if (mySerial.available() > 0) {
    data = mySerial.read();
  }
  if (Serial.available() > 0) {
    data = Serial.read();
  }

  if (data != ' ') {
    Serial.println(data);
    // 전송값에 따라 액션
    if (data == 'F') {
      forward();
    } else if (data == 'B') {
      backward();
    } else if (data == 'R') {
      right();
    } else if (data == 'L') {
      left();
    } else if (data == 'S' || data == 'D' || data == 'x') {  //멈출 조건 S,D
      stop();
    }
  }
}

// 블루투스 자동차 속도 조절 함수
void setSpeed(int newSpeed) {
  //두 바퀴 속도 차이 : 왼쪽바퀴 기준
  leftWheelSpeed = newSpeed;
  rightWheelSpeed = leftWheelSpeed + WHEEL_DIFF_VALUE;  //기준속도보정

  rightWheelSpeed = (rightWheelSpeed > 255) ? 255 : rightWheelSpeed;
  rightWheelSpeed = (rightWheelSpeed < 0) ? 0 : rightWheelSpeed;

  Serial.println("LeftWSpeed: " + String(leftWheelSpeed) + " RightWSpeed: " + String(rightWheelSpeed));
}

void carMove(int aa, int ab, int ba, int bb) {
  analogWrite(PIN_MA1A, aa);
  analogWrite(PIN_MA1B, ab);

  analogWrite(PIN_MB1A, ba);
  analogWrite(PIN_MB1B, bb);
}

void forward() {
  carMove(leftWheelSpeed, 0, rightWheelSpeed, 0);
}

void backward() {
  carMove(0, leftWheelSpeed, 0, rightWheelSpeed);
}
void left() {
  carMove(0, 0, rightWheelSpeed, 0);
}
void right() {
  carMove(leftWheelSpeed, 0, 0, 0);
}
void stop() {
  carMove(0, 0, 0, 0);
}
