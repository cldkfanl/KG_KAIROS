const int analogPin = A0;
const int led[6] = {3,5,6,9,10,11};
void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogVal = analogRead(analogPin);
  int fir = analogVal/171;
  int sec = map(analogVal%171, 0, 170, 0, 255);

  analogWrite(led[fir], sec);
  Serial.println(sec);
  }
