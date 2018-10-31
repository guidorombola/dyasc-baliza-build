#include "ControladorDeAlertas.hpp"
#include <Arduino.h>

ControladorDeAlertas::ControladorDeAlertas(){
    pinMode(2,OUTPUT);
    pinMode(12,OUTPUT);
}

void ControladorDeAlertas::comunicarEstadoOK(){
    parpadearLed(2, 5);
    digitalWrite(2, HIGH);
}

void ControladorDeAlertas::comunicarEstadoFallo(){
    parpadearLed(12, 10);
    digitalWrite(12, HIGH);
}

void ControladorDeAlertas::parpadearLed(int led, int cantidadDeParpadeos) {

    for(int i = 0; i < cantidadDeParpadeos; i++)
    {
        digitalWrite(led, HIGH);
        delay(50);
        digitalWrite(led, LOW);
        delay(50);
    }
}