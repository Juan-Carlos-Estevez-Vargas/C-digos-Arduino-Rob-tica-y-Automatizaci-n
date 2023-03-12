#define LED 9
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  
  delay(100);                        
  digitalWrite(LED, LOW);  
  delay(100);   
  digitalWrite(LED, HIGH);  
  delay(1000);                       
  digitalWrite(LED, LOW);  
  delay(1000);  
}
