#include "ConectorCI.hpp"
#include <HTTPClient.h>
#include "configuracion/remota.h"
#include "configuracion/red.h"

ConectorCI::ConectorCI() {
    this->wifi = new ConectorWiFi(ssid, clave);
    this->wifi->realizarConexion();
}

Estado ConectorCI::obtenerEstado(){
    if (this->wifi->estaConectado()) {
        HTTPClient http;
        String estadoActual;

        http.begin(url);
        http.addHeader("Travis-API-Version", version, false, false);
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