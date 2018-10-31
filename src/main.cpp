#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Orquestador.hpp"
#include "ConectorCI.hpp"
#include "ControladorDeAlertas.hpp"

ConectorCI* conector;
ControladorDeAlertas* controlador;
Orquestador* orquestador;

void setup() {
    Serial.begin(115200);
    conector = new ConectorCI();
    conector->conectarARedWiFi();
    controlador = new ControladorDeAlertas();
    orquestador = new Orquestador(conector, controlador);
}

void loop() {
    orquestador->obtenerEstado();
    delay(5000);
}