const int btnpin = 2;
const int ledpin = 3;

int ledState = HIGH;
int btnState = HIGH;
int lastbtnState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:

  pinMode(btnpin, INPUT_PULLUP);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, ledState);

}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(btnpin);

  if(reading != lastDebounceTime){
    lastDebounceTime = millis();
  }

  if( (millis() - lastDebounceTime) > debounceDelay){
    if(reading != btnState){
      btnState = reading;
      if(btnState == LOW){
        ledState = !ledState;
      }
    }
  }

  digitalWrite(ledpin, ledState);
  lastDebounceTime = reading;
}
