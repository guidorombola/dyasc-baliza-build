#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Orquestador.hpp"
#include "ConectorCI.hpp"
#include "ControladorDeAlertas.hpp"
#include "ConectorWiFi.hpp"
#include "configuracion/red.h"

ConectorCI* conector;
ControladorDeAlertas* controlador;
Orquestador* orquestador;
ConectorWiFi* conectorWiFi;

void setup() {
    Serial.begin(115200);
    conector = new ConectorCI();
    controlador = new ControladorDeAlertas();
    conectorWiFi = new ConectorWiFi(ssid, clave);
    orquestador = new Orquestador(conector, controlador, conectorWiFi);
    orquestador->conectarARedWiFi();
}

void loop() {
    orquestador->obtenerEstado();
    delay(5000);
}