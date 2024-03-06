#include <SoftwareSerial.h>


#define TX 2
#define RX 3
#define LED 7

#define BWHEEL 5
#define BSPEED 6
#define AWHEEL 9
#define ASPEED 10

#define tr 11
#define ec 12

SoftwareSerial HC06(2,3);
char ser = 0;
char ble = 0;
int baseSpeed = 100;

void setup() {
  Serial.begin(9600);
  while(!Serial){;}
  HC06.begin(9600);
  pinMode(ASPEED, OUTPUT);
  pinMode(AWHEEL, OUTPUT);
  pinMode(BSPEED, OUTPUT);
  pinMode(BWHEEL, OUTPUT);
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);
  pinMode(LED, OUTPUT);
}
void Rb(){
  analogWrite(ASPEED, baseSpeed);  //앞
  analogWrite(AWHEEL, HIGH);
}
void Rf(){
  analogWrite(ASPEED, HIGH);   //뒤
  analogWrite(AWHEEL, baseSpeed);
}
void Rs(){
  analogWrite(ASPEED, 0);   //정지
  analogWrite(AWHEEL, 0);
}
void Lb(){
  analogWrite(BSPEED, baseSpeed);  //앞
  analogWrite(BWHEEL, HIGH);
}
void Lf(){
  analogWrite(BSPEED, HIGH);   //뒤
  analogWrite(BWHEEL, baseSpeed);
}
void Ls(){
  analogWrite(BSPEED, 0);  //정지
  analogWrite(BWHEEL, 0);
}
void HC06proc(){
  if(Serial.available() > 0){
    ser = Serial.read();
    HC06.write(ser);
  }
  if(HC06.available()>0){
    ble = HC06.read();
    Serial.write(ble);
    switch(ble){
      case 'l':
      Lb();
      Rf();
      break;
      case 'r':
      Lf();
      Rb();
      break;
      case 'u' :
      Rf();
      Lf();
      break;
      case 'd' :
      Rb();
      Lb();
      break;
      case 's' :
      Ls();
      Rs();
      break;
      case 'z' :
      if(baseSpeed < 200){
        baseSpeed += 10;
      }
      break;
      case 'x' :
      if(baseSpeed >50 ){
        baseSpeed -= 10;
      }
      break;
    }
  }
}
void USSensor(){
  digitalWrite(tr, LOW);
  delayMicroseconds(2);
  digitalWrite(tr, HIGH);
  delayMicroseconds(2);
  digitalWrite(tr, LOW);
  long duration = pulseIn(ec, HIGH);
  long distance = (duration / 2) / 29.1;
  Serial.println(distance);
  if(distance < 50){
    digitalWrite(LED, HIGH);
    Serial.println('w');
    HC06.println('w');
    delay(500);
  }
  else{
    digitalWrite(LED, LOW);
    Serial.println('s');
    HC06.println('s');
    delay(500);
  }
}
void loop() {
  HC06proc();
  USSensor();
}
