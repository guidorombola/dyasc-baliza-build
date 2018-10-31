#include "ConectorCI.hpp"
#include <HTTPClient.h>

const char* ssid = "Yoda";
const char* clave = "gonzalono";
const char* token = "token cy6bhRQXA54L7iVFkfAWfQ";

ConectorCI::ConectorCI() {
    this->wifi = new ConectorWiFi(ssid, clave);
    this->wifi->realizarConexion();
}

Estado ConectorCI::obtenerEstado(){
    if (this->wifi->estaConectado()) {
        HTTPClient http;
        String estadoActual;
        http.begin("https://api.travis-ci.com/repo/guidorombola%2Fdyasc-2018/branch/master");
        http.addHeader("Travis-API-Version", "3", false, false);
        http.addHeader("Authorization", token, false, false);
        int httpCode = http.GET();
        if (httpCode > 0) {
            String payload = http.getString();
            int inicioEstadoBuild = payload.indexOf("state");
            String aux = payload.substring(inicioEstadoBuild+9);
            int finEstadoBuild = aux.indexOf(",");
            estadoActual = aux.substring(0, finEstadoBuild-1);
        } else {
            Serial.println("Error en peticion HTTP");
        }
        http.end();
        if(estadoActual == "passed"){
            estado = Estado::OK;
        } else {
            estado = Estado::FALLO;
        }
    }
    return estado;
}