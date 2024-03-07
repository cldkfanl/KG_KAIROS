#define PIN_BUZZER 13



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_BUZZER, OUTPUT);
  Serial.println("Start!");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    char tmp = Serial.read();
    if (tmp == '1') {
      digitalWrite(PIN_BUZZER, HIGH);
      delay(1000);
      digitalWrite(PIN_BUZZER, LOW);
    }
  }
}
