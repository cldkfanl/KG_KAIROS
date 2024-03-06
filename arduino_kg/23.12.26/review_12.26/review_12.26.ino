void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(5 , INPUT_PULLUP);
  int binput = digitalRead(5);
}

void loop() {
  // put your main code here, to run repeatedly:
    int binput = digitalRead(5);
    if(binput == LOW){
      digitalWrite(2,HIGH);
    }
    else if(binput == HIGH){
      digitalWrite(2,LOW);
    }
}
