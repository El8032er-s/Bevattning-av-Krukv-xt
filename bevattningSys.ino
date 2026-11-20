#include <dht11.h>
#include <LiquidCrystal.h>
#define soilPin 0
#define airTempHumidityPin 7
#define grnLedPin 10
#define redLedPin 9
#define displayBtn 13

#define rs 12
#define enable 11
#define db4 5
#define db5 4
#define db6 3
#define db7 2
int maxSoilMoisture = 630;
int minSoilMoisture = 200;

dht11 DHT11;
LiquidCrystal lcd(rs,enable, db4, db5, db6, db7);
int currentState = 3;

/*
100% mätnade i kranvatten ger ~630
100% mätnade i blöt jord ger 580
Torr jord ger 200

Att Göra
Lägg till display funktioner
Lägg till funktion för led (200<m<630)
Testa kod
*/

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(displayBtn, INPUT);
  pinMode(soilPin, INPUT);
  pinMode(grnLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}
void loop() {
  if (displayBtn == HIGH){
    if (currentState < 3){
      currentState += 1
    }
    else{
      currentState = 1;
    }
  }

  //Display & innehälls val

  //led indekation

}


float soilRead(){
  int value= analogRead(soilPin);
  value= value;
  float soilMoisture = value/maxSoilMoisture;
  delay(1000);
  return soilMoisture;
}

float airHumidityRead() {
  int read = DHT11.read(airTempHumidityPin);
  float value = (float)DHT11.humidity;
  return value;
}

float airTempRead(){
  int read = DHT11.read(airTempHumidityPin);
  float value = (float)DHT11.temperature;
  return value;
}
