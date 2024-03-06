#define PIN_MA1A 5
#define PIN_MA1B 6

#define PIN_MB1A 9
#define PIN_MB1B 10

#define PIN_SONIC_TRIG 14
#define PIN_SONIC_ECHO 15

#define WHEEL_DIFF_VALUE 0;


int iSpeed = 150;
int leftWheelSpeed = iSpeed;
int rightWheelSpeed = leftWheelSpeed -15 + WHEEL_DIFF_VALUE;

#define SONIC_DISTANCE 15

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_MA1A, OUTPUT);
  pinMode(PIN_MA1B, OUTPUT);
  pinMode(PIN_MB1A, OUTPUT);
  pinMode(PIN_MB1B, OUTPUT);

  pinMode(PIN_SONIC_TRIG, OUTPUT);
  pinMode(PIN_SONIC_ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long distance = getDistance();
  Serial.println(String(distance) + " cm");

  if (distance < SONIC_DISTANCE) {
    backward();
    delay(500);
    right();
    delay(500);
  }
  else{
    forward();
  }
}
long getDistance() {
  digitalWrite(PIN_SONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_SONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_SONIC_TRIG, LOW);


  long duration = pulseIn(PIN_SONIC_ECHO, HIGH);
  long distance = (duration / 2) / 29.1;

  return distance;
}
void carMove(int aa, int ab, int ba, int bb) {
  analogWrite(PIN_MA1A, aa);
  analogWrite(PIN_MA1B, ab);
  analogWrite(PIN_MB1A, ba);
  analogWrite(PIN_MB1B, bb);
}
void forward() {
  carMove(leftWheelSpeed, 0, rightWheelSpeed, 0);
}
void backward() {
  carMove(0, leftWheelSpeed, 0, rightWheelSpeed);
}
void left() {
  carMove(0, 0, 0, rightWheelSpeed);
}
void right() {
  carMove(leftWheelSpeed, 0, 0, 0);
}
void stop() {
  carMove(0, 0, 0, 0);
}