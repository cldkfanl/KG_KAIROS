const int bpin = 2;
const int lpin = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(bpin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int binput = digitalRead(bpin);
  if(binput == LOW){
    for(int i=0; i<=255; i++){
      analogWrite(ledPin, i);
      delay(4);
    }
  }
  else{
    analogWrite(ledPin, 0);
  }
  
}
