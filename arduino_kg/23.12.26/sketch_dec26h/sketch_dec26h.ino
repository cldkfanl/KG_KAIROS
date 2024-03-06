#include <DHT.h>
#include <DHT_U.h>

int dhtpin = 2;
int dhttype = DHT11;
int led = 13;

DHT dht(dhtpin, dhttype);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if(isnan(h) || isnan(t)){
    Serial.println("Failed to read");
    return;
  }

  Serial.print("Tem:");
  Serial.print(t);
  Serial.print(" C");
  Serial.print("     ");
  Serial.print("Hum:");
  Serial.print(h);
  Serial.println(" %");
  delay(200);

  if(t>=30) digitalWrite(led, HIGH);
  else{
    digitalWrite(led, LOW);
  }
}
