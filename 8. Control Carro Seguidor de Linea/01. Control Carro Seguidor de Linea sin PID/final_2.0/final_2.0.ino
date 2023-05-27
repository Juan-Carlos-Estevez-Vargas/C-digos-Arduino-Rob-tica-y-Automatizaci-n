// Incluimos librería
#include <AFMotor.h>
//////////////////////////
#define LED 13
/////////////////////////////////////////////////
///////////////////////////////////////////////////////
AF_DCMotor Motor1(3, MOTOR12_64KHZ);  //Crear objeto Motor#1, 64KHZ pwm
AF_DCMotor Motor2(4, MOTOR12_64KHZ);  //Crear objeto Motor#2, 64KHZ pwm

//----VARIABLES GLOBALES----//
//Sensores digitales
int irSensors[] = { A0, A1 };  //IR sensor pins
int s1, s2;
///Funcion de configuración //////////////////////////////////////////////////////
void setup() {
  pinMode(irSensors[0], INPUT);
  pinMode(irSensors[1], INPUT);
  //Realizar una espera de 5 segundos
  delay(5000);
}
///////////////////////////////////////////////////////////////////////////////
void adelante() {

  Motor1.setSpeed(110);  //Colocar la velocidad de Motor1 a 100  90 es bueno
  Motor2.setSpeed(110);  //Colocar la velocidad de Motor2 a 100  90 es bueno
  Motor1.run(FORWARD);   //Adelante
  Motor2.run(FORWARD);   //Atras

  //delay(5);
}

void derecha() {

  Motor1.setSpeed(30);  //85
  Motor2.setSpeed(40);  //85
  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  // delay(50);
  Motor1.setSpeed(65);
  Motor2.setSpeed(75);
  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  // delay(35);
}

void izquierda() {

  Motor2.setSpeed(45);  //85
  Motor1.setSpeed(50);  //85
  Motor2.run(BACKWARD);
  Motor1.run(FORWARD);
  // delay(50);
  Motor2.setSpeed(70);
  Motor1.setSpeed(75);
  Motor2.run(BACKWARD);
  Motor1.run(FORWARD);
  // delay(35);
}

void parar() {

  Motor1.run(RELEASE);  //Parar
  Motor2.run(RELEASE);  //Parar
}



//////////////////////////////////////////////////////////////////////////////
///Funcion Principal ////////////////////////////////////////////////////////////
void loop() {
  //INDICADOR LED
  digitalWrite(LED, HIGH);
  //Variables para lectura
  s1 = digitalRead(irSensors[0]);
  s2 = digitalRead(irSensors[1]);

  ////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////

  if (s1 == 1 && s2 == 1) {

    adelante();
    ///////////////////////////////////////////////////
  }
  /////////////////////////////////////////////////////////
  else if (s1 == 0 && s2 == 1) {

    derecha();
    ///////////////////////////////////////////////////
  }
  /////////////////////////////////////////////////////////
  else if (s1 == 1 && s2 == 0) {

    izquierda();
    ///////////////////////////////////////////////////
  }
  /////////////////////////////////////////////////////////
  else if (s1 == 0 && s2 == 0) {

    parar();
  }
}
