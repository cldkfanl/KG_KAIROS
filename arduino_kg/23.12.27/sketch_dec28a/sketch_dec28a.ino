#include <SoftwareSerial.h>
#define Tx 2
#define Rx 3
char ser = 0;
char ble = 0;
SoftwareSerial HC06(Tx, Rx);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC06.begin(9600);
}
void HC06proc() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    ser = Serial.read();
    HC06.write(ser);
  }
  if(HC06.available() > 0){
    ble = HC06.read();
    Serial.write(ble);
  }
}
void loop(){
  HC06proc();
}
