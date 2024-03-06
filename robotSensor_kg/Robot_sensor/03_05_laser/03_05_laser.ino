#define PIN_IR_L 7
#define PIN_IR_R 8
void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_IR_L, INPUT);
  pinMode(PIN_IR_R, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("IR : " + String(digitalRead(PIN_IR_L)) + String(digitalRead(PIN_IR_R)));
  delay(500);
}
