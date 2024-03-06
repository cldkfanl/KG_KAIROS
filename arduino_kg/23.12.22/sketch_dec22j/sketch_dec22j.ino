const int dpin = 2;
const int dpin2 = 8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(dpin, INPUT_PULLUP);
  pinMode(dpin2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dval = digitalRead(dpin);
  int dval2 = digitalRead(dpin2);
  if(dval == LOW && dval2 == LOW){
    Serial.println(1);
  }
}
