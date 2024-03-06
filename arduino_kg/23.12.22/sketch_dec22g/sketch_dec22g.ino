//Serial통신, 버튼
const int dpin = 8;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(dpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(dpin) == LOW){  //버튼 클릭시 0표시
    Serial.println("0");
  }
  else if(digitalRead(dpin) == HIGH){  //버튼 떼면 1 표시
    Serial.println("1");
  }
}
