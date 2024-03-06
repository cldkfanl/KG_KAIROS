const unsigned int led[6] = {3,5,6,9,10,11};
const int bpin = 2;
boolean gstate = false;
int lastled = 0;
void setup() {
  for(int i=0; i<=5; i++){
    pinMode(led[i],  OUTPUT);
  }
  pinMode(bpin , INPUT_PULLUP);
  
}
void onled(int num){
  digitalWrite(led[num], HIGH);
}
void offled(int num){
    digitalWrite(led[num], LOW);
}

void loop() {
  int binput = digitalRead(bpin);
  while(binput == LOW){
    if(gstate){
      offled(lastled);
      gstate = false;
    }
    for(int i=0; i<=5; i++){
      onled(i);
      delay(100);      

      binput = digitalRead(bpin);
      if(binput == HIGH){
        gstate = true;
        lastled = i;
        break;
        }

              offled(i);
    }
  }
}
