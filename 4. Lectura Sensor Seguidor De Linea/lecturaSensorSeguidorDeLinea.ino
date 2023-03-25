const int sensorPin = 2; // pin digital en el que está conectado el sensor
int sensorValue = 0; // variable para almacenar el valor del sensor

void setup() {
  pinMode(sensorPin, INPUT); // configurar el pin del sensor como entrada
  Serial.begin(9600); // iniciar la comunicación serial a 9600 baudios
}

void loop() {
  sensorValue = digitalRead(sensorPin); // leer el valor del sensor
  Serial.println(sensorValue); // enviar el valor a través de la comunicación serial
  delay(1000); // esperar un tiempo breve para evitar lecturas rápidas
}