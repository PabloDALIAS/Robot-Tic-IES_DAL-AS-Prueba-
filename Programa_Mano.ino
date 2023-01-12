//AQUÍ PODEMOS MODIFICAR/AÑADIR/ETC LO QUE VEAMOS OPORTUNO


//Conecto la PCA9685 a la placa Arduino MEGA
// VCC -> +5v
// GND -> GND
// SDA -> A20
// SCL -> A21

//Conecto el acelerómetro GY-61 a la placa Arduino MEGA
// VCC -> +5v
// GND -> GND
// X_Out -> A5
// Y_Out -> A6
// Z_Out -> A7

//Conecto las resistencias del guante
// Dedo 1 -> A1
// Dedo 2 -> A2
// Dedo 3 -> A3
// Dedo 4 -> A4
// Dedo 5 -> A5

//Agrego las librerías necesarias para el proyecto
//Librería PCA9685: https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Configuro los pines y variables
#define pinMuneca A0
#define pinDedo1 A1
#define pinDedo2 A2
#define pinDedo3 A3
#define pinDedo3 A4
#define pinDedo3 A5
#define pinEjeX A6
#define pinEjeY A7
#define pinEjeX A8

int valorMuneca = 0;
int valorDedo1 = 0;
int valorDedo2 = 0;
int valorDedo3 = 0;
int valorDedo4 = 0;
int valorDedo5 = 0;
int valorEjeX = 0;
int valorEjeY = 0;
int valorEjeZ = 0;

// Declaro el objeto y configuro la PCA9685
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);
unsigned int pos0 = 172;  // Configuro el ancho de pulso asociado a la posición de 0 grados
unsigned int pos180 = 565; // Configuro el ancho de pulso asociado a la posición de 180 grados

void setup() {
  //Inicializo el objeto creado
  servos.begin();
  //Configuro la frecuencia del PWM (igual para los 16 pines)
  servos.setPWMFreq(60);
  pinMode(pinMuneca, INPUT)
	pinMode(pinDedo1, INPUT);
	pinMode(pinDedo2, INPUT);
	pinMode(pinDedo3, INPUT);
	pinMode(pinDedo4, INPUT);
	pinMode(pinDedo5, INPUT);
}

void configuracionServo(uint8_t numeroServo, int anguloServo) {
  int cicloTrabajo;
  cicloTrabajo = map(anguloServo, 0, 180, pos0, pos180);
  servos.setPWM(numeroServo, 0, cicloTrabajo);
}

void loop() {
	valorMuneca =analogRead(pinEjeY); //esto ajustarlo al eje correspondiente en función del diseño del guante
	valorDedo1 = analogRead(pinDedo1);
	valorDedo2 = analogRead(pinDedo2);
	valorDedo3 = analogRead(pinDedo3);
	valorDedo4 = analogRead(pinDedo4);
	valorDedo5 = analogRead(pinDedo5);

//TODO ESTO ESTÁ SIN MAPEAR. CUANDO TENGAMOS EL GUANTE HAY QUE AJUSTAR EL MOVIMIENTO DE LOS SENSORES A LOS SERVOS

configuracionServo(0, valorDedo1);
configuracionServo(1, valorDedo2);
configuracionServo(2, valorDedo3);
configuracionServo(3, valorDedo4);
configuracionServo(4, valorDedo5);
