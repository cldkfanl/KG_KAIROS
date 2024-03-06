#include <MsTimer2.h>
#include <Bounce2.h>
#define led 8
#define btn 2

Bounce debouncer = Bounce();
boolean state = false;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  attachInterrupt(INT0, ris, RISING);
  attachInterrupt(INT0, fall, FALLING);

}
void ris(){
  state = false;
  Serial.println("Pressed");
}
void fall(){
  state = true;
}


void loop() {
  if(state){
    Serial.println("Released");
    delay(10);
  }
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
}
