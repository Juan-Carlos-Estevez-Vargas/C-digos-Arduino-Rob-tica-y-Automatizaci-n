// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

//#define ledPin 9 
#define TRIGGER_PIN  7  
#define ECHO_PIN     8  
#define MAX_DISTANCE 200 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  delayMicroseconds(315);        
  Serial.print(sonar.ping_cm());
}