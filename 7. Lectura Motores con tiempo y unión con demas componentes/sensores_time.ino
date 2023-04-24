// Incluimos librería
#include <ArduinoJson.h>
#include <TimeLib.h>
#include <AFMotor.h>
//////////////////////////
#define LED 13

AF_DCMotor Motor1(3, MOTOR12_64KHZ);  //Crear objeto Motor#1, 64KHZ pwm
AF_DCMotor Motor2(4, MOTOR12_64KHZ);  //Crear objeto Motor#2, 64KHZ pwm

//----VARIABLES GLOBALES----//
//Sensores digitales
int irSensors[] = { 6, 7 };  //IR sensor pins

///Funcion de configuración //////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);                 //iniciar puerto serie
  setTime(14, 34, 24, 21, 04, 2023);  /// configuaración de fecha y hora actual
  pinMode(irSensors[0], INPUT);
  pinMode(irSensors[1], INPUT);
}
///////////////////////////////////////////////////////////////////////////////
void adelante() {
  Motor1.run(FORWARD);  //Adelante
  Motor2.run(FORWARD);  //Atras
}

void atras() {
  Motor1.run(BACKWARD);  //Adelante
  Motor2.run(BACKWARD);  //Atras
}

void derecha() {
  Motor1.run(FORWARD);   //Adelante
  Motor2.run(BACKWARD);  //Atras
}

void izquierda() {
  Motor1.run(BACKWARD);   //Adelante
  Motor2.run(FORWARD);   //Atras
}

void parar() {
  Motor1.run(RELEASE);  //Parar
  Motor2.run(RELEASE);  //Parar
}

//////////////////////////////////////////////////////////////////////////////
///Funcion Principal ////////////////////////////////////////////////////////////
void loop() {
  //Realizar una espera de 5 segundos
  delay(5000);
  digitalWrite(LED, HIGH);
  //Variables para lectura
  int s1 = 1;
  int s2 = 1;
  //s1 = digitalRead(irSensors[0]);
  //s2 = digitalRead(irSensors[1]);
  Motor1.setSpeed(110);  //Colocar la velocidad de Motor1 a 100  0-255
  Motor2.setSpeed(110);  //Colocar la velocidad de Motor2 a 100
                         ////////////////////////////////////////////////
                         //////Fecha-Hora////////////////////////////////////////////////
  time_t T = now();      // Captura la fecha y hora del computador

  int d = day(T);
  int m = month(T);
  int y = year(T);

  int hr = hour(T);
  int minu = minute(T);
  int s = second(T);

  String Fecha = String(y) + "-" + String(m) + "-" + String(d);
  String Hora = String(hr) + ":" + String(minu) + ":" + String(s);
  //////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////

  if (s1 == 1 && s2 == 1) {

    adelante();
    //////JSON//////////////////////////////////////
    StaticJsonDocument<200> doc;

    doc["IR1"] = s1;
    doc["IR2"] = s2;
    doc["Mensaje"] = "Adelante";
    doc["Fecha"] = Fecha;
    doc["Hora"] = Hora;

    ///Imprimir datos formato JSON ////////////////////7
    serializeJsonPretty(doc, Serial);
    ///////////////////////////////////////////////////
  } else if (s1 == 0 && s2 == 0) {

    atras();
    //////JSON//////////////////////////////////////
    StaticJsonDocument<200> doc;

    doc["IR1"] = s1;
    doc["IR2"] = s2;
    doc["Mensaje"] = "Atras";
    doc["Fecha"] = Fecha;
    doc["Hora"] = Hora;

    ///Imprimir datos formato JSON ////////////////////7
    serializeJsonPretty(doc, Serial);
    ///////////////////////////////////////////////////
  } else if (s1 == 0 && s2 == 1) {

    izquierda();
    //////JSON//////////////////////////////////////
    StaticJsonDocument<200> doc;

    doc["IR1"] = s1;
    doc["IR2"] = s2;
    doc["Mensaje"] = "Izquierda";
    doc["Fecha"] = Fecha;
    doc["Hora"] = Hora;

    ///Imprimir datos formato JSON ////////////////////7
    serializeJsonPretty(doc, Serial);
    ///////////////////////////////////////////////////
  } else if (s1 == 1 && s2 == 0) {

    derecha();
    //////JSON//////////////////////////////////////
    StaticJsonDocument<200> doc;

    doc["IR1"] = s1;
    doc["IR2"] = s2;
    doc["Mensaje"] = "Derecha";
    doc["Fecha"] = Fecha;
    doc["Hora"] = Hora;

    ///Imprimir datos formato JSON ////////////////////7
    serializeJsonPretty(doc, Serial);
    ///////////////////////////////////////////////////
  } else {

    parar();
    //////JSON//////////////////////////////////////
    StaticJsonDocument<200> doc;

    doc["IR1"] = s1;
    doc["IR2"] = s2;
    doc["Mensaje"] = "Parar";
    doc["Fecha"] = Fecha;
    doc["Hora"] = Hora;

    ///Imprimir datos formato JSON ////////////////////7
    serializeJsonPretty(doc, Serial);
    ///////////////////////////////////////////////////
  }
}