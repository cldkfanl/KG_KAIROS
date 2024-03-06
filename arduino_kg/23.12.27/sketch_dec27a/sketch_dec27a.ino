#include <MsTimer2.h>
#include <Bounce2.h>
#define led 2
#define btnL 8
#define scr 9
#define btnR 10


boolean Lstate = false;
boolean Rstate = false;
int scrsize[3] = {4000, 8000, 16000};
int scrsizeNum = 0;

Bounce debouncerL = Bounce();
Bounce debouncerR = Bounce();
Bounce debouncerS = Bounce();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led , OUTPUT);
  pinMode(btnL, INPUT_PULLUP);
  pinMode(scr, INPUT_PULLUP);
  pinMode(btnR, INPUT_PULLUP);
  debouncerL.attach(btnL);
  debouncerL.interval(5);
  debouncerR.attach(btnR);
  debouncerR.interval(5);
  debouncerS.attach(scr);
  debouncerS.interval(5);
  MsTimer2::set(10,aa);
  MsTimer2::start();
}
void onled(int num){
  digitalWrite(num, HIGH);
}
void offled(int num){
  digitalWrite(num, LOW);
}
void aa(){
    debouncerL.update();
    debouncerR.update();
    debouncerS.update();
    if(debouncerL.fell()){
      Lstate = true;
    }
    if(debouncerL.rose()){
      Lstate = false;
    }
    if(Lstate){
      Serial.println("Left click");
      delay(1000);
    }

    
    if(debouncerR.fell()){
      Rstate = true;
    }
    if(debouncerR.rose()){
      Rstate = false;
    }
    if(Rstate){
      Serial.println("Right click");
      delay(1000);
    }


    if(debouncerS.fell()){
    Serial.println(scrsize[scrsizeNum]);
    }
    if(debouncerS.rose()){
      scrsizeNum++;
      if(scrsizeNum == 3){
        scrsizeNum = 0;
      }
    }
}
void loop() {
  // put your main code here, to run repeatedly:

  if(Lstate || Rstate){
    onled(led);
  }
  else if(!(Lstate && Rstate)){
    offled(led);
  }
}
