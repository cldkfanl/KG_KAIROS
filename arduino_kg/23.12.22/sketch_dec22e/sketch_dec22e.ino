//Serial통신, 입력값에 따라 출력값 변경

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char userInput = Serial.read();
    switch(userInput){
      case '1':
      Serial.print(1);
      break;

      case '2':
      Serial.print(2);
      break;

      case '3':
      Serial.print(3);
      break;

      default :
      Serial.println(userInput);
      break;
    }
  }
}
