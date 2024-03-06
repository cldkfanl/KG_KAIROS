#include <Servo.h>
 
const int SERVO = 10;
Servo servo;
const int btn = 2;

int servo_state = 30;
boolean servo_state_changed = false; 

void btnPressed(){
  servo_state = (servo_state == 30)?150:30;
  servo_state_changed = true;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(btn, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(btn), btnPressed, FALLING);
  servo.attach(SERVO);
  servo.write(0);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(servo_state_changed){
    servo_state_changed = false;
    servo.write(servo_state);
  }
}
