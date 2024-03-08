void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int baseA, shoulderA, upperA, foreA;

  while (Serial.available() > 0) {
    baseA = Serial.parseInt();
    shoulderA = Serial.parseInt();
    upperA = Serial.parseInt();
    foreA = Serial.parseInt();

    if (Serial.read() == 'd') {
      Serial.println("Received Signal");
    }

    String base = "base     : " + String(baseA);
    String shoulder = "shoulder : " + String(shoulderA);
    String upperarm = "upperarm : " + String(upperA);
    String forearm = "forearm  : " + String(foreA);

    display.println(base);
    display.println(shoulder);
    display.println(upperarm);
    display.println(forearm);

  }
}
