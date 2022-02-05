#include <Arduino.h>

#include "Orquestador.hpp"
#include "ConectorCI.hpp"
#include "ControladorDeAlertas.hpp"
#include "ConectorWiFi.hpp"
#include "ServidorLocal.hpp"

ConectorCI* conector;
ControladorDeAlertas* controlador;
Orquestador* orquestador;
ConectorWiFi* conectorWiFi;
ServidorLocal* servidor;

void setup() {
    Serial.begin(115200);

    conector = new ConectorCI();
    controlador = new ControladorDeAlertas();
    conectorWiFi = new ConectorWiFi();
    servidor = new ServidorLocal();

    orquestador = new Orquestador(conector, controlador, conectorWiFi, servidor);
}

void loop() {
    orquestador->manejarModo();
    delay(2000);
}