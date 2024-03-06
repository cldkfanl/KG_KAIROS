//Serial통신, LED
int RED = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){
    int Input = Serial.parseInt();
    if(Serial.read() == '\n'){
      int light = constrain(Input*20, 0, 255);  //입력값에 따라서 LED 밝기 조절
      analogWrite(RED, light);
      Serial.println(light);
    }
  }
}
