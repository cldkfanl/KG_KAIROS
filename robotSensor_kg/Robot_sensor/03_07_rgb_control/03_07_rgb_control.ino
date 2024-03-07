#define PIN_LED_R 3
#define PIN_LED_G 5
#define PIN_LED_B 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
}
void ledCntrol(int r, int g, int b){
  analogWrite(PIN_LED_R, r);
  analogWrite(PIN_LED_G, g);
  analogWrite(PIN_LED_B, b);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    char data = Serial.read();
    switch(data){
      case 'R' :
      ledCntrol(255, 0, 0);
      break;
      case 'G' :
      ledCntrol(0, 255, 0);
      break;
      case 'B' :
      ledCntrol(0, 0, 255);
      break;
      case 'Y' :
      ledCntrol(255, 228, 0);
      break;
      case 'X' :
      ledCntrol(0, 0, 0);
      break;
    }
  }
}
