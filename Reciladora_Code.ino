#include "PID.h"

//Variables:
float Kp = 1.0, Ki = 1.0, Kd = 1.0;     //Constantes de PID
float input, output;
float setPoint = 450.0;                   //Set Point que dependera del sensor
int controlPin = 10;
//Objetos
PID pid(setPoint, Kp, Ki, Kd);

void setup(){
	Serial.begin(115200);
    //Serial.print("--\tMomento de calentar el asunto\t--\nKp = ");
    float* patata = pid.get_K();
    //Serial.println(patata[0]);
    //Serial.print("Ki = ");
    //Serial.println(patata[1]);
    //Serial.print("Kd = ");
    //Serial.print(patata[2]);
    pinMode(controlPin, OUTPUT);
    Serial.println("INPUT");
    Serial.println("OUTPUT");
}

void loop(){
	  input = analogRead(A4);
    output = pid.calc_PID(input) * -1;
      if (output >=255){output = 255;}
      if (output <= 0){output = 0;}
      analogWrite(controlPin, int(output));
    //Imprimir variables en serial para verlo en el Serial Plotter
    Serial.print(input);
    Serial.print(",");
    Serial.println(output);
}
