#include "ConectorCI.hpp"
#include <Arduino.h>

const char* ssid = "";
const char* password = "";
const char* token = "";

Estado ConectorCI::obtenerEstado(){
    if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
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

void ConectorCI::conectarARedWiFi(){
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network"); 
}