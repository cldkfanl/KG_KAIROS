const int analogPin = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogVal = analogRead(analogPin);
  analogWrite(3, analogVal/4);
}
