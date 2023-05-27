// https://projecthub.arduino.cc/SMM2/93a4f4e5-224e-46fb-8dbb-6c975a4dcd78
//Librerias
#include <AFMotor.h>  //Control Motores
#include <PID_v1.h>   // PID

//----VARIABLES GLOBALES----//
//Motores
AF_DCMotor Motor1(1, MOTOR12_64KHZ);  //Crear objeto Motor#1, 64KHZ pwm
AF_DCMotor Motor2(2, MOTOR12_64KHZ);  //Crear objeto Motor#2, 64KHZ pwm
//Sensores digitales
int irSensors[] = { A0, A1 };  //IR sensor pins
int irReadings[2];
// Maxima velocidad
int MAX_SPEED = 100;
// Parametros iniciales PID
double Setpoint, Input, Output;
//Variables de proporcional, integral y derivativo
// Kp ----> Reacción al error presente, rapídez en llegar al valor de referencia
// Kd ----> Atenua el sobre pico de salida, sirve para predecir el futuro del error.
// Ki ----> Depende del error pasado, logra que el error sea lo mas cercano a 0.
double Kp = 2, Ki = 5, Kd = 1;
// CONFIGURA LOS VALORES DEL  PID
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
///////////////////////////////////////////////////////////////////////////////////
///Funcion de configuración //////////////////////////////////////////////////////
void setup() {
  //Lectura de sensores seguidor de linea
  for (int pin = 0; pin < 2; pin++) {
    int Input = irSensors[pin];
    pinMode(Input, INPUT);
  }

  Setpoint = 0;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);

  Motor1.setSpeed(0);  //Colocar la velocidad de Motor1 a 0
  Motor2.setSpeed(0);  //Colocar la velocidad de Motor2 a 0

  //Realizar una espera de 5 segundos
  delay(5000);
}
///////////////////////////////////////////////////////////////////////////////
void readIRSensors() {
  //Read the IR sensors and put the readings in irReadings array
  for (int pin = 0; pin < 2; pin++) {
    int Input = irSensors[pin];
    irReadings[pin] = digitalRead(Input);
  }
}
//////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////
void motores() {
  int m1Speed = MAX_SPEED + Output;
  int m2Speed = MAX_SPEED - Output;
  // Aquí restringimos las velocidades de nuestro motor para que estén entre 0 y MAX_SPEED.
  // En términos generales, un motor siempre girará a MAX_SPEED
  // y el otro estará en MAX_SPEED-|Output| si eso es positivo
  // de lo contrario será estacionario. Para algunas aplicaciones, es posible que desee
  // permita que la velocidad del motor sea negativa para que pueda girar en reversa.
  if (m1Speed < 0)
    m1Speed = 0;
  if (m2Speed < 0)
    m2Speed = 0;
  if (m1Speed > MAX_SPEED)
    m1Speed = MAX_SPEED;
  if (m2Speed > MAX_SPEED)
    m2Speed = MAX_SPEED;
  //Accion sobre motores con valor pid
  Motor1.run(m1Speed);
  Motor2.run(m2Speed);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
///Funcion Principal ////////////////////////////////////////////////////////////
void loop() {
  //Llamar funcion lectura sensores
  readIRSensors();
  // Calcula el pid
  myPID.Compute();
  //Control motores
  motores();
}
