#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <Servo.h>

int basePin = 4;
int shoulderPin = 5;
int upperarmPin = 6;
int forearmPin = 7;

const int servoInitAngle = 90;

int baseAngle = servoInitAngle;
int shoulderAngle = servoInitAngle;
int upperarmAngle = servoInitAngle;
int forearmAngle = servoInitAngle;

Servo base;
Servo shoulder;
Servo upperarm;
Servo forearm;

int baseStatus = 1;
int shoulderStatus = 1;
int upperarmStatus = 1;
int forearmStatus = 1;

#define PIN_JOINT_READ_BUTTON 8
#define PIN_JOINT_JOYSTICK_MODE 2
#define PIN_MODE_LED 13

bool isJointJoystickMode = false;
int done = 0;

int servoParallelControl(int thePos, Servo theServo, int speed) {
  int startPos = theServo.read();
  int newPos = startPos;

  if (startPos < (thePos)) {
    newPos = newPos + 1;
    theServo.write(newPos);
    delay(speed);
    return 0;
  } else if (newPos > (thePos)) {
    newPos = newPos - 1;
    theServo.write(newPos);
    delay(speed);
    return 0;
  } else {
    return 1;
  }
}


void setup() {
  Serial.begin(115200);
  pinMode(PIN_JOINT_READ_BUTTON, INPUT_PULLUP);
  pinMode(PIN_JOINT_JOYSTICK_MODE, INPUT_PULLUP);
  pinMode(PIN_MODE_LED, OUTPUT);

  attachInterrupt(INT0, ISRJoystickMode, LOW);

  base.attach(basePin);
  shoulder.attach(shoulderPin);
  upperarm.attach(upperarmPin);
  forearm.attach(forearmPin);

  base.write(servoInitAngle);
  shoulder.write(servoInitAngle);
  upperarm.write(servoInitAngle);
  forearm.write(servoInitAngle);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  // Clear the buffer
  Serial.println("oled found!");
  displayOLED();
}

void ISRJoystickMode() {
  static unsigned long prev = 0;
  if (millis() - prev > 50 && digitalRead(PIN_JOINT_JOYSTICK_MODE) == LOW) {
    prev = millis();
    isJointJoystickMode = !isJointJoystickMode;
  }
  if (isJointJoystickMode) digitalWrite(PIN_MODE_LED, HIGH);
  else digitalWrite(PIN_MODE_LED, LOW);
}



void checkJoystickMove() {
  if (isJointJoystickMode) {
    baseAngle = map(analogRead(A2), 1023, 0, 5, 175);
    shoulderAngle = map(analogRead(A3), 0, 1023, 175, 5);
    upperarmAngle = map(analogRead(A0), 0, 1023, 5, 175);
    forearmAngle = map(analogRead(A1), 0, 1023, 5, 175);

    done = 0;
  }
}


void checkJointReadButton() {
  if (digitalRead(PIN_JOINT_READ_BUTTON) == LOW) {
    isJointJoystickMode = false;

    baseAngle = base.read();
    shoulderAngle = shoulder.read();
    upperarmAngle = upperarm.read();
    forearmAngle = forearm.read();

    displayOLED();
    while (!digitalRead(PIN_JOINT_READ_BUTTON))
      ;
  }
}

void displayOLED() {
  display.clearDisplay();
  display.display();

  String baseStr = " base     : " + String(baseAngle);
  String shoulderStr = " shoulder : " + String(shoulderAngle);
  String upperarmStr = " upperarm : " + String(upperarmAngle);
  String forearmStr = " forearm  : " + String(forearmAngle);

  display.setTextSize(1);                              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);  // Draw 'inverse' text

  display.setCursor(0, 0);  // Start at top-left corner
  display.println(" Robot Arm Move");
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.println(" --------------");
  display.println(" ");
  display.setTextSize(1);  // Normal 1:1 pixel scale
  display.println(baseStr);
  display.println(shoulderStr);
  display.println(upperarmStr);
  display.println(forearmStr);
  display.println("\n"); // OLED 에 마지막 줄이 안 보여서 넣어준 것임

  display.setCursor(0, 0);  // Start at top-left corner
  display.display();
  delay(100);
}

void moveJoints() {
  // 조이스틱 모드라면, 매 순간이 하나의 작업임
  if (isJointJoystickMode) {
    baseStatus = servoParallelControl(baseAngle, base, 20);
    shoulderStatus = servoParallelControl(shoulderAngle, shoulder, 20);
    upperarmStatus = servoParallelControl(upperarmAngle, upperarm, 20);
    forearmStatus = servoParallelControl(forearmAngle, forearm, 20);
  } else {
    // 통신 모드라면, 받은 값들이 하나의 작업 단위이므로, 모두 끝나야 함
    while (done == 0) {
      baseStatus = servoParallelControl(baseAngle, base, 20);
      shoulderStatus = servoParallelControl(shoulderAngle, shoulder, 20);
      upperarmStatus = servoParallelControl(upperarmAngle, upperarm, 20);
      forearmStatus = servoParallelControl(forearmAngle, forearm, 20);

      if (baseStatus == 1 && shoulderStatus == 1 && upperarmStatus == 1 && forearmStatus == 1)
        done = 1;
    }
  }
}
void loop() {
  checkJoystickMove();
  checkJointReadButton();

  if (Serial.available() > 0) {
    //10,20,30,40d
    //90,90,90,90d
    //45,75,75,75d

    baseAngle = Serial.parseInt();
    shoulderAngle = Serial.parseInt();
    upperarmAngle = Serial.parseInt();
    forearmAngle = Serial.parseInt();

    if (Serial.read() == 'd') {
      // Serial.flush(); //flush 를 하면, client에서 보내온 여러 자료가 사라짐
      Serial.println("d");
    }

    displayOLED();
    done = 0; //하나의 작업이 시작되어, 끝나지 않았음을 의미
  }
  moveJoints();
  // delay(100);
}