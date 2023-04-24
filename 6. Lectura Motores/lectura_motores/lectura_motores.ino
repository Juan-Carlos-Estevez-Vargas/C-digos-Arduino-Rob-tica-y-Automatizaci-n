// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

// Definiendo los motores
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  
  // Asignación de velocidad a motores
  motor3.setSpeed(200);
  motor4.setSpeed(200);
 
  // Inicialización de los motores a un estado quieto.
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  girarIzquierda();
}

// Dirige los motores hacia adelante
void adelante() {
  motor3.run(FORWARD);
  motor4.run(FORWARD);  
}

// Dirige los motores hacia atras
void atras() {
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);  
}

// Dirige los motores hacia un giro derecho
void girarDerecha() {
  motor3.run(FORWARD);
  motor4.run(BACKWARD);  
}

// Dirige los motores hacia un giro izquierdo
void girarIzquierda() {
  motor3.run(BACKWARD);
  motor4.run(FORWARD);  
}
