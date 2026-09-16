#include <Servo.h>

Servo servo1;

int pinServo = 2;
//int pulsoMin = 650; //En microsegundos
//int pulsoMax = 1450; //Un pulso de un milisegundos equivale a 0° y uno de 2 equivale a 180°
int pot1 = A0;
int valorPot = 0;
int angulo = 0;
float filtro = 0;
unsigned long millisInicial = 0;

void setup() {
  //servo1.attach(pinServo, pulsoMin, pulsoMax);  //Esto si queremos usar los valores min y max del servo
  servo1.attach(pinServo);
  Serial.begin(9600);
}

void loop() {

  unsigned long millisAhora = millis();

  if(millisAhora - millisInicial >= 20){
    millisInicial = millisAhora;

    for(int i = 0; i < 100; i++){
      valorPot = analogRead(pot1);
      filtro += valorPot;
    }

    float promedio = filtro/100.0;

    Serial.print(promedio);
    Serial.print("\t");

    angulo = map(promedio, 0, 1023, 0, 180);
    
    Serial.println(angulo);
    servo1.write(angulo);

    angulo = 0;
    promedio = 0;
    filtro = 0;
    
  }
 
}
