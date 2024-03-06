#include <SoftwareSerial.h>

#define Tx 2
#define Rx 3
char ser = 0;   //PC입력데이터
char ble = 0;   //PC출력데이터

int led = 10;   //LED
int data = A5;  //가변저항
SoftwareSerial HC06(Tx, Rx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC06.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(data, INPUT);
}

void HC06proc() {
  // 모바일에서 메세지 전송 시 LED 꺼짐
  if(Serial.available()>0){
    ser = Serial.read();
    HC06.write(ser);
  }
  if(HC06.available() > 0){
    ble = HC06.read();
    Serial.write(ble);
    if(ble == 'a'){
      digitalWrite(led, HIGH);
    }
    else{
      digitalWrite(led, LOW);
    }
  }
}
/*void HC06proc() {
  // 모바일은 끄고 pc에선 LED 켬
  if(Serial.available()>0){
    ser = Serial.read();
    HC06.write(ser);
    if(ser == 'a'){
      digitalWrite(led, LOW);
    }
  }
  if(HC06.available() > 0){
    ble = HC06.read();
    Serial.write(ble);
    if(ble == 'a'){
      digitalWrite(led, HIGH);
    }
  }
}*/
/*void HC06proc() {
  // 가변저항 값을 블루투스 연결되어있는 기기에 전송, Serial창에 등록
  int tmp = analogRead(data);
  HC06.println(tmp);
  Serial.println(tmp);
  delay(100);
}*/
void loop(){
  HC06proc();
}
