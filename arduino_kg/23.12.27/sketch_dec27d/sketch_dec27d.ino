int rakamlar[10][8] = {
  {1,1,1,1,1,1,0,0},  // 0
  {0,1,1,0,0,0,0,0},  // 1
  {1,1,0,1,1,0,1,0},  // 2
  {1,1,1,1,0,0,1,0},  // 3
  {0,1,1,0,0,1,1,0},  // 4
  {1,0,1,1,0,1,1,0},  // 5
  {1,0,1,1,1,1,1,0},  // 6
  {1,1,1,0,0,0,0,0},  // 7
  {1,1,1,1,1,1,1,0},  // 8
  {1,1,1,1,0,1,1,0}   // 9
};

int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int num = 0;
unsigned long preMillis = 0;
const long interval = 1000; 

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);
  }
}

void loop() {
  unsigned long curMillis = millis();

  if (curMillis - preMillis >= interval) {
    preMillis = curMillis;

    for (int i = 0; i < 8; i++) {
      digitalWrite(ledPins[i], !rakamlar[num][i]);
    }

    num+=2;
    if (num == 10) {
      num = 0;
    }
  }
}
