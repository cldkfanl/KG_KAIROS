#define PIN_JX A0
#define PIN_JY A1
#define PIN_JSW 2

#define CMP_VAL 3

volatile bool isbtnPressed = false; // 무결성 유지 위해 사용

void ISRbtn(){
  isbtnPressed = true;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  pinMode(PIN_JSW, INPUT_PULLUP);
  attachInterrupt(INT0, ISRbtn, FALLING);
}

void loop() {
  int xVal = analogRead(PIN_JX);
  int yVal = analogRead(PIN_JY);
  int btnVal = digitalRead(PIN_JSW);
  Serial.println("X = " + String(xVal) + ", Y = " + String(yVal));

  if(isbtnPressed){
    isbtnPressed = false;
    Serial.println("btn Press!");
    delay(500);
  }
}
