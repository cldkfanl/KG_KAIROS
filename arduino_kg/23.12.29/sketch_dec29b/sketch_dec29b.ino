#define BWHEEL 5
#define BSPEED 6
#define AWHEEL 9
#define ASPEED 10
int baseSpeed = 100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ASPEED, OUTPUT);
  pinMode(AWHEEL, OUTPUT);
  pinMode(BSPEED, OUTPUT);
  pinMode(BWHEEL, OUTPUT);
}
void Rb(){
  analogWrite(ASPEED, baseSpeed);  //앞
  analogWrite(AWHEEL, HIGH);
}
void Rf(){
  analogWrite(ASPEED, HIGH);   //뒤
  analogWrite(AWHEEL, baseSpeed);
}
void Rs(){
  analogWrite(ASPEED, 0);   //정지
  analogWrite(AWHEEL, 0);
}
void Lb(){
  analogWrite(BSPEED, baseSpeed);  //앞
  analogWrite(BWHEEL, HIGH);
}
void Lf(){
  analogWrite(BSPEED, HIGH);   //뒤
  analogWrite(BWHEEL, baseSpeed);
}
void Ls(){
  analogWrite(BSPEED, 0);  //정지
  analogWrite(BWHEEL, 0);
}
void loop() {
  // put your main code here, to run repeatedly:
  Rf();
  Lf();
  delay(3000);
  Rb();
  Lb();
  delay(3000);
//  analogWrite(ASPEED, 255);   //앞
//  analogWrite(AWHEEL, HIGH);
//  delay(2000);
//  analogWrite(ASPEED, 128);   //정지
//  analogWrite(AWHEEL, LOW);
//  delay(2000);
//  analogWrite(BSPEED, 0);  //뒤
//  analogWrite(BWHEEL, LOW);
//  delay(2000);
//  analogWrite(BSPEED, 255);   //앞
//  analogWrite(BWHEEL, HIGH);
//  delay(2000);
//  analogWrite(ASPEED, 128);   //정지
//  analogWrite(AWHEEL, HIGH);
//  delay(2000);
}
