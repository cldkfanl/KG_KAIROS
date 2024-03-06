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
  debouncer.attach(btn);
  debouncer.interval(5);
  MsTimer2::set(10,aa);
  MsTimer2::start();

}
void aa(){
    debouncer.update();
    if(debouncer.fell()){
      state = true;
    }
    if(debouncer.rose()){
      state = false;
      Serial.println("Released");
    }
    if(state){
      Serial.println("Pressed");
      delay(10);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
}
