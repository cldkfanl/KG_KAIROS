// C++ code
//


int numDec[10] = {252, 96, 218, 242, 102, 182,
                  190, 224, 254, 246};

int datapin = 7;
int latchpin = 6;
int shiftpin = 5;
void setup()
{
  pinMode(datapin, OUTPUT);
  pinMode(latchpin, OUTPUT);
  pinMode(shiftpin, OUTPUT);
}

void loop()
{
  for(int i=0; i<=9; i++){
    digitalWrite(latchpin, LOW);
    shiftOut(datapin, shiftpin, LSBFIRST, numDec[i]);
    digitalWrite(latchpin, HIGH);
    delay(1000);
  }
}
