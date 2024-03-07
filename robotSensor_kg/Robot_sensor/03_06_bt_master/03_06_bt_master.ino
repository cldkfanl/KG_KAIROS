#include <SoftwareSerial.h>

SoftwareSerial mySerial(4, 3);  // RX, TX


char prev_data = '5';
char curr_data;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {

  int LR_xAxis;
  int FB_yAxis;

  LR_xAxis = analogRead(A0);  // Read Joysticks X-axis
  FB_yAxis = analogRead(A1);  // Read Joysticks y-axis


  if (0 <= FB_yAxis && FB_yAxis < 200) {
    curr_data = 'F';
  } else if (800 <= FB_yAxis && FB_yAxis < 1024) {
    curr_data = 'B';
  } else if (0 <= LR_xAxis && LR_xAxis < 200) {
    curr_data = 'L';
  } else if (800 <= LR_xAxis && LR_xAxis < 1024) {
    curr_data = 'R';
  } else if ((200 <= FB_yAxis && FB_yAxis < 800) && (200 <= LR_xAxis && LR_xAxis < 800)) {
    curr_data = 'S';
  }

  if (prev_data != curr_data) {
    if (curr_data == 'S') {
      Serial.println(String(FB_yAxis) + " : " + String(LR_xAxis));
      mySerial.write(curr_data);
      delay(200);
      Serial.println(curr_data);
      prev_data = curr_data;
    } else {
      if (prev_data == 'S') {
        Serial.println(String(FB_yAxis) + " : " + String(LR_xAxis));
        mySerial.write(curr_data);
        delay(200);
        Serial.println(curr_data);
        prev_data = curr_data;
      }
    }
  }
}
