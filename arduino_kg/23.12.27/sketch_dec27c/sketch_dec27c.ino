const int led = 8;
int btn = 2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  attachInterrupt(INT0, aaa, RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, !digitalRead(led));
  delay(1000);
}

void aaa(){
    Serial.println("Pressed");
}
