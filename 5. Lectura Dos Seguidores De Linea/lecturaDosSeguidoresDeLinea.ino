#include <ArduinoJson.h>

int irSensors[] = {6, 7};

void setup() {
  delay(4000);
  Serial.begin(9600); 
  pinMode(irSensors[0], INPUT);
  pinMode(irSensors[1], INPUT);
}

void loop() {
  int s1 = 1;
  int s2 = 0;
delay(1000);  
  //s1 = digitalRead(irSensors[0]);
  //s2 = digitalRead(irSensors[1]);

  StaticJsonDocument<200> doc;

  doc["IR1"] = s1;
  doc["IR2"] = s2;
  doc["Materia"] = "Robotica UNISANGIL";

  serializeJsonPretty(doc, Serial);
}