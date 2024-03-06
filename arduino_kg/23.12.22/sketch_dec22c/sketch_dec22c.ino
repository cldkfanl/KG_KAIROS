const char input = 'F';
int cnt = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(cnt == 0){
    for(int i=0; i<6; i++){
        for(int j=0; j<=i; j++){
          char tmp = input-j;
          Serial.print(tmp);
          }
       Serial.println();
       }
  cnt++;
  }
}
