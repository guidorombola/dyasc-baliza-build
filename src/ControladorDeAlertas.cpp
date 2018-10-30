#include "ControladorDeAlertas.hpp"
#include <Arduino.h>

ControladorDeAlertas::ControladorDeAlertas(){
    pinMode(2,OUTPUT);
}

void ControladorDeAlertas::comunicarEstadoOK(){
    digitalWrite(2, HIGH);
    delay(3000);
    digitalWrite(2, LOW);
    return;
}

void ControladorDeAlertas::comunicarEstadoFallo(){
    return;
}