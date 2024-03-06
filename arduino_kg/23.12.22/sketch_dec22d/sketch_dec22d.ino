//3색 LED

int RED = 9;
int GREEN = 10;
int BLUE = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(RED, OUTPUT);
pinMode(GREEN , OUTPUT);
pinMode(BLUE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<255; i++){
    analogWrite(RED, i);        //R
    analogWrite(GREEN , 254-i); //G
    analogWrite(BLUE , i);      //B 값 변경
    delay(50);
    
  }
}
