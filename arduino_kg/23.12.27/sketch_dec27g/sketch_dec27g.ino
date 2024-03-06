#include <MsTimer2.h>
#include <Bounce2.h>

int SPEED = 10;
int WHEEL = 9;
int tr = 11;
int ec = 12;
int val = 127;
int btn1 = 2;
int btn2 = 7;
int state = 1;
int nowSpeed = 250;
boolean upspeedstatus = false;
Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);
  
  pinMode(SPEED, OUTPUT);
  pinMode(WHEEL, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  
  debouncer1.attach(btn1);
  debouncer1.interval(5);
  debouncer2.attach(btn2);
  debouncer2.interval(5);
  MsTimer2::set(10,mStatus);
  MsTimer2::start();
}

void loop() {
  Serial.println(state);
  if(!state){
    int speed = writelen();
    digitalWrite(WHEEL, LOW);
    analogWrite(SPEED, speed);
  }
  else{
    digitalWrite(WHEEL, HIGH);
    analogWrite(SPEED, nowSpeed);
  }
}
void mStatus(){
    debouncer1.update();
    debouncer2.update();
    if(debouncer1.fell()){
      state = 1-state;
      nowSpeed = 250;
    }

    if(debouncer2.fell()){
       upspeedstatus = true;
    }
    if(debouncer2.rose()){
       upspeedstatus = false;
    }
    if(upspeedstatus && nowSpeed != 0 ){
    nowSpeed--;
    delay(10);
    }
}
int writelen(){
  digitalWrite(tr, LOW);
  delayMicroseconds(2);
  digitalWrite(tr, HIGH);
  delayMicroseconds(2);
  digitalWrite(tr, LOW);

  long duration = pulseIn(ec, HIGH);
  long distance = (duration / 2) / 29.1;
  Serial.println(distance);

  int tmp = map(distance, 5, 120, 1, 255);
  return tmp;
}
