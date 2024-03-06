const int tr = 11;
const int ec = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tr , LOW);
  delayMicroseconds(2);
  digitalWrite(tr, HIGH);
  delayMicroseconds(2);
  digitalWrite(tr, LOW);

  long duration = pulseIn(ec, HIGH);
  long distance = (duration/2) / 29.1;

  Serial.print(distance);
  Serial.println(" cm");
}
