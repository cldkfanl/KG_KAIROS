#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup() {
  Serial.begin(9600);
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
int Angle = 0;
void loop() {
  display.clearDisplay();
  if (Angle >= 180) Angle = 0;
  Angle += 20;
  String base = "base : " + String(Angle);
  String shoulder = "shoulder : " + String(Angle);
  String upperArm = "upperArm : " + String(Angle);
  String foreArm = "foreArm : " + String(Angle);
  display.setTextSize(1.5);
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  //좌표 이동 및 글자작성
  display.setCursor(0,0);
  display.println("RobotArm Move");
  display.setTextColor(SSD1306_WHITE);
  display.println("-------------");
  display.println(" ");
  display.setTextSize(1);
  display.println(base);
  display.println(shoulder);
  display.println(upperArm);
  display.println(foreArm);
  display.display();
  delay(500);
}