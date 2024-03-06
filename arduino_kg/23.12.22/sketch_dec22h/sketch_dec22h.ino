const int dpin = 8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(dpin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dval = digitalRead(dpin);
  Serial.println(dval);
}
