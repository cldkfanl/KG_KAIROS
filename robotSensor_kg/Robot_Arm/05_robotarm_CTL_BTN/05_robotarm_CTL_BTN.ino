#define PIN_SERVO_READ_BUTTON 8

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//서보
#include <Servo.h>

const int basePin = 4;
const int shoulderPin = 5;
const int upperarmPin = 6;
const int forearmPin = 7;

const int servoInitAngle = 90;

Servo base;
Servo shoulder;
Servo upperarm;
Servo forearm;


int baseAngle = 0;
int shoulderAngle = 0;
int upperarmAngle = 0;
int forearmAngle = 0;

int baseStatus = 0;
int shoulderStatus = 0;
int upperarmStatus = 0;
int forearmStatus = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_SERVO_READ_BUTTON, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  //서보모터
  base.attach(basePin);
  shoulder.attach(shoulderPin);
  upperarm.attach(upperarmPin);
  forearm.attach(forearmPin);

  base.write(servoInitAngle);
  shoulder.write(servoInitAngle);
  upperarm.write(servoInitAngle);
  forearm.write(servoInitAngle);

  //OLED
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  Serial.println("oled found");
  // Clear the buffer
  display.clearDisplay();
  display.display();
}

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

void readServoAngle() {
  if (digitalRead(PIN_SERVO_READ_BUTTON) == LOW) {
    baseAngle = base.read();
    shoulderAngle = shoulder.read();
    upperarmAngle = upperarm.read();
    forearmAngle = forearm.read();
    digitalWrite(13, HIGH);
    displayOLED();
  }
  else{
    digitalWrite(13, LOW);
  }
}

void displayOLED() {
  String baseStr = "base     : " + String(baseAngle);
  String shoulderStr = "shoulder : " + String(shoulderAngle);
  String upperarmStr = "upperarm : " + String(upperarmAngle);
  String forearmStr = "forearm  : " + String(forearmAngle);

  display.setTextSize(1.5);
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("Robot Arm Move");
  display.setTextColor(SSD1306_WHITE);
  display.println("---------------");
  display.println(" ");

  display.setTextSize(1);
  display.println(baseStr);
  display.println(shoulderStr);
  display.println(upperarmStr);
  display.println(forearmStr);
  display.println(" ");

  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  readServoAngle();

  while (Serial.available() > 0) {
    //85,45,100,45d

    baseAngle = Serial.parseInt();
    shoulderAngle = Serial.parseInt();
    upperarmAngle = Serial.parseInt();
    forearmAngle = Serial.parseInt();

    if (Serial.read() == 'd') {
      Serial.println("Received Signal");
    }

    // displayOLED();

    int done = 0;
    while (done == 0) {
      baseStatus = servoParallelControl(baseAngle, base, 20);
      shoulderStatus = servoParallelControl(shoulderAngle, shoulder, 20);
      upperarmStatus = servoParallelControl(upperarmAngle, upperarm, 20);
      forearmStatus = servoParallelControl(forearmAngle, forearm, 20);

      if (baseStatus == 1 && shoulderStatus == 1 && upperarmStatus == 1 && forearmStatus == 1) {
        done = 1;
      }
    }
    delay(100);
  }
}
