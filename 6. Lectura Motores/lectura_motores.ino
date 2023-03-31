// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

// Definiendo los motores
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  
  // Asignación de velocidad a motores
  motor1.setSpeed(200);
  motor2.setSpeed(75);
 
  // Inicialización de los motores a un estado quieto.
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  atras();
}

// Dirige los motores hacia adelante
void adelante() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);  
}

// Dirige los motores hacia atras
void atras() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);  
}

// Dirige los motores hacia un giro derecho
void girarDerecha() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);  
}

// Dirige los motores hacia un giro izquierdo
void girarIzquierda() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);  
}
