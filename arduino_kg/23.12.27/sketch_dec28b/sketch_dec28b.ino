#include <SoftwareSerial.h>
#include <DHT.h>

#define tx 2;
#define rx 3;

DHT myDHT (A0, DHT11);
SoftwareSerial myBlue(2,3);
void setup() {
  Serial.begin(9600);
  myBlue.begin(9600);
  myDHT.begin();

}

void loop() {
  float temper = myDHT.readTemperature();
  myBlue.println("t" + String(temper));
  delay(1000);
  float humid = myDHT.readHumidity();
  myBlue.println("h" + String(humid));
  delay(1000);
/*  if(myBlue.available()){
    Serial.write(myBlue.read());
  }
  if(Serial.available()){
    myBlue.write(Serial.read());
  }*/
}
