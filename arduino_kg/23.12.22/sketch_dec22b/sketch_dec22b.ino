int cnt = 0;
const char input = '$';
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(cnt == 0){
    for(int i=0; i<5; i++){
      for(int j=0; j<=i; j++){
        Serial.print(input);
      }
    Serial.println();
    }
    cnt++;
  }
}
