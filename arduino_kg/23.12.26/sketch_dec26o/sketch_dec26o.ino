int SPEED = 10;
int WHEEL = 9;
int tr = 11;
int ec = 12;
int val = 127;
int BTN = 2;
int state = true;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);
  
  pinMode(SPEED, OUTPUT);
  pinMode(WHEEL, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  digitalWrite(WHEEL, LOW);
  analogWrite(SPEED, 0);

}

void loop() {
  if (digitalRead(BTN) == LOW) {
    state = false;

  }else{
    state = true;
  }
  if(!state){
    int speed = writelen();
    digitalWrite(WHEEL, LOW);
    analogWrite(SPEED, speed);
  }
  else{
    digitalWrite(WHEEL, HIGH);
    analogWrite(SPEED, 80);
  }
}
int writelen(){
   digitalWrite(tr, LOW);
  delayMicroseconds(2);
  digitalWrite(tr, HIGH);
  delayMicroseconds(2);
  digitalWrite(tr, LOW);

  long duration = pulseIn(ec, HIGH);
  long distance = (duration / 2) / 29.1;
  Serial.println(distance);

  int tmp = map(distance, 5, 120, 1, 255);
  return tmp;
}
