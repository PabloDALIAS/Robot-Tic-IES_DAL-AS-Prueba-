#include <Servo.h>
Servo Horizontal;
Servo Vertical;
#define PinBoton 2;
#define PinPotenciometro A3;
 

//DEFINE EL PIN INPUT PARA EL BOTÓN (DIGITAL)  0, 1, 2, 3, 4, 5, ...
//ENTRADA ANALÓGICA DEL POTENCIÓMETRO (ANALÓGICO) A0, A1.....



//int angulo;

void setup() {
  Horizontal.attach(2);
  Vertical.attach(4);

CONFIGURAS EL PIN COMO DE ENTRADA (Botón/Potenciómetro)

  
  Serial.begin(9600);
}

void loop() {

//IF BOTON PULSADO ARRANCAS LO DE DENTRO
//haces lectuta del potenciómetro

 int LecturaPotenciometro= analogRead(PinPotenciometro);


 delay(LecturaPotenciometro);

 
 
 
 
 
 
 
 
 
 
 
 
 //arribaizquierda(angulo);


}
  
 





void arribaizquierda(int angulo1) {
  miradaarriba(angulo);
  miradaderecha(angulo);

}

void miradacentro1(int angulo1) {

  angulo = 90;
  altura.write(angulo);

}
void miradaarriba(int angulo1) {

  angulo = 120;
  altura.write(angulo);

}
void miradaabajo(int angulo1) {

  angulo = 60;
  altura.write(angulo);

}



void miradaizquierda(int angulo1) {

  angulo = 120;
  direccion.write(angulo);

}


void miradaderecha(int angulo1) {

  angulo = 60;
  direccion.write(angulo);

}

void miradacentro(int angulo1) {

  angulo = 90;
  direccion.write(angulo);

}
