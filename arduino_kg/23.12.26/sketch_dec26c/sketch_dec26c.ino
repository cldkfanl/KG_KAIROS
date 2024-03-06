#include <Bounce2.h>

int btn1 = 2;
int btn2 = 3;
Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();

void setup() {
  // put your setup code here, to run once:
  pinMode(btn1, INPUT_PULLUP);
  debouncer1.attach(btn1);
  debouncer1.interval(5);

  pinMode(btn2, INPUT_PULLUP);
  debouncer2.attach(btn2);
  debouncer2.interval(5);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  debouncer1.update();
  debouncer2.update();

  if(debouncer1.fell() || debouncer2.fell()){
    Serial.println("Single Pressed");
  }
  else if(debouncer1.fell() && debouncer2.fell()){
        Serial.println("Double Pressed");
  }
  else if(debouncer1.rose() && debouncer2.rose()){
    Serial.println("Released");
  }

}
