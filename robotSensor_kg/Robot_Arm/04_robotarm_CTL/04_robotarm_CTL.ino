#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//LED 관련
#include <Servo.h>

int basePin = 4;
int shoulderPin = 5;
int upperPin = 6;
int forearmPin = 7;

const int servoIntAngle = 90;

Servo base;
Servo shoulder;
Servo upperarm;
Servo forearm;

int baseAngle = 0;
int shoulderAngle = 0;
int upperAngle = 0;
int foreAngle = 0;
//서보관련

int baseStatus = 0;
int shoulderStatus = 0;
int upperStatus = 0;
int foreStatus = 0;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  base.attach(basePin);
  shoulder.attach(shoulderPin);
  upperarm.attach(upperPin);
  forearm.attach(forearmPin);

  base.write(servoIntAngle);
  shoulder.write(servoIntAngle);
  upperarm.write(servoIntAngle);
  forearm.write(servoIntAngle);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  Serial.println("oled found");
  display.clearDisplay();
  display.display();
}

int servoParallelCTR(int thePos, Servo theServo, int theSpeed) {
  int startPos = theServo.read();
  int newPos = startPos;

  if (startPos < thePos - 5) {
    newPos++;
    theServo.write(newPos);
    delay(theSpeed);
    return 0;
  } else if (newPos > thePos + 5) {
    newPos--;
    theServo.write(newPos);
    delay(theSpeed);
    return 0;
  } else {
    return 1;
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  while (Serial.available() > 0) {
    
    baseAngle = Serial.parseInt();
    shoulderAngle = Serial.parseInt();
    upperAngle = Serial.parseInt();
    foreAngle = Serial.parseInt();

    if (Serial.read() == 'd') {
      Serial.println("Received Signal");
    }

    String baseStr = "base     : " + String(baseAngle);
    String shoulderStr = "shoulder : " + String(shoulderAngle);
    String upperarmStr = "upperarm : " + String(upperAngle);
    String forearmStr = "forearm  : " + String(foreAngle);

    display.setTextSize(1.5);
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);

    display.setCursor(0, 0);
    display.println("Rovot Arm Move");
    display.setTextColor(SSD1306_WHITE);
    display.println("---------------");
    display.println(" ");
    display.setTextSize(1);

    display.println(baseStr);
    display.println(shoulderStr);
    display.println(upperarmStr);
    display.println(forearmStr);

    display.display();

    //여기서부터 서보
    int done = 0;
    while (done == 0) {
      baseStatus = servoParallelCTR(baseAngle, base, 20);
      shoulderStatus = servoParallelCTR(shoulderAngle, shoulder, 20);
      upperStatus = servoParallelCTR(upperAngle, upperarm, 20);
      foreStatus = servoParallelCTR(foreAngle, forearm, 20);

      if (baseStatus == 1 && shoulderStatus == 1 && upperStatus == 1 && foreStatus == 1) {
        done = 1;
      }
    }
    delay(100);
  }
}