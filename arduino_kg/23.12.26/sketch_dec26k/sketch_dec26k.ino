int SPEED = 10;
int WHEEL = 9;
int val = 130;
int ENCODER = 2;

volatile int cnt = 0;
unsigned long oldTime = 0;
unsigned long newTime = 0;

void ISRencoder(){
  cnt++;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
//  pinMode(SPEED,OUTPUT);
//  pinMode(WHEEL,OUTPUT);
//  digitalWrite(WHEEL,LOW);
//  analogWrite(SPEED, LOW);
  pinMode(ENCODER, INPUT_PULLUP);
  attachInterrupt(INT0, ISRencoder, FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  newTime = millis();
  if(newTime -oldTime > 1000){
    oldTime = newTime;
    noInterrupts();
    Serial.println(cnt);
//    cnt = 0;
//    analogWrite(SPEED, val);
    interrupts();
  }

}
