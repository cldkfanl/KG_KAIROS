#include <TimerOne.h>
const int led = 8;
int btn = 10;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(aaa);
  Timer1.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, !digitalRead(led));
  delay(1000);
}

void aaa(){
  if(digitalRead(btn) == LOW){
    Serial.println("Pressed");
  }
}
