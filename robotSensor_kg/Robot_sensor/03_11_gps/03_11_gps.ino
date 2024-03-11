#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(11,12);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start gps...");
  gpsSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(gpsSerial.available()){
    Serial.write(gpsSerial.read());
  }

}
