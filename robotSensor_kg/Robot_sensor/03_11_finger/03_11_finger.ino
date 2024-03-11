#define PIN_LED 9
#define BUZZER 7

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int ledBrightness = Serial.read();

    ledBrightness = constrain(ledBrightness, 0, 255);
    analogWrite(PIN_LED, ledBrightness);
    if (ledBrightness > 127) {
      digitalWrite(BUZZER, HIGH);
    } else {
      digitalWrite(BUZZER, LOW);
    }
  }
}
