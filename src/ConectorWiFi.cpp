#include "ConectorWiFi.hpp"
#include <WiFi.h>

ConectorWiFi::ConectorWiFi(const char* ssid, const char* clave){
    this->ssid = ssid;
    this->clave = clave;
}

void ConectorWiFi::realizarConexion(){
    WiFi.begin(this->ssid, this->clave);

    while (!this->estaConectado()) {
        delay(1000);
        Serial.println("Conectando al WiFi..");
    }

    Serial.println("Conexión exitosa a la red!"); 
}

bool ConectorWiFi::estaConectado(){
    return (WiFi.status() == WL_CONNECTED);
}