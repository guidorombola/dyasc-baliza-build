#include "ControladorDeAlertas.hpp"
#include <Arduino.h>

#define tiempoEntreParpadeo 50

ControladorDeAlertas::ControladorDeAlertas(){
    this->ledVerde = 2;
    this->ledRojo = 12;

    pinMode(this->ledVerde,OUTPUT);
    pinMode(this->ledRojo,OUTPUT);
}

void ControladorDeAlertas::comunicarEstadoOK(){
    parpadearLed(this->ledVerde, 5);
    digitalWrite(this->ledVerde, HIGH);
}

void ControladorDeAlertas::comunicarEstadoFallo(){
    parpadearLed(this->ledRojo, 10);
    digitalWrite(this->ledRojo, HIGH);
}

void ControladorDeAlertas::parpadearLed(int led, int cantidadDeParpadeos){
    digitalWrite(this->ledRojo, LOW);
    digitalWrite(this->ledVerde, LOW);

    for(int i = 0; i < cantidadDeParpadeos; i++) {
        digitalWrite(led, HIGH);
        delay(tiempoEntreParpadeo);
        digitalWrite(led, LOW);
        delay(tiempoEntreParpadeo);
    }
}