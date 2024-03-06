const unsigned int led[6] = {3,5,6,9,10,11};
const int bpin = 2;

boolean gstate = false;
int lastled = 0;
void setup() {
  for(int i=0; i<=5; i++){
    pinMode(led[i],  OUTPUT);
  }
  pinMode(bpin , INPUT_PULLUP);
  int binput = digitalRead(bpin);
}
void onled(int num){
  digitalWrite(led[num], HIGH);
}
void offled(int num){
    digitalWrite(led[num], LOW);
}
void game(int state){
    for(int i=state; i<=5; i+=2){
    onled(i);
    lastled = i;
    delay(100);      


    if(binput == HIGH){
      gstate = true;
      break;
      }
     offled(i);
  }
}
void alloff(int num){
  for(int i=0; i<6; i++){
    if(i != num){
      offled(i);
    }
  }
}
void loop() {
  binput = digitalRead(bpin);
  while(binput == LOW){
    if(gstate){
      offled(lastled);
      gstate = false;
    }
    game(0);
    game(1);
  }
}
