#include "ConectorWiFi.hpp"
#include <Arduino.h>

#define MAX_INTENTOS_CONEXION 10

ConectorWiFi::ConectorWiFi(const char* ssid, const char* clave){
    this->ssid = ssid;
    this->clave = clave;
}

void ConectorWiFi::realizarConexion(){
    int intentosConexion = 0;
    WiFi.begin(this->ssid, this->clave);

    while (!this->estaConectado() && intentosConexion < MAX_INTENTOS_CONEXION) {
        delay(1000);
        Serial.println("Conectando al WiFi..");
        intentosConexion++;
    }
    if(this->estaConectado()){
        Serial.println("Conexión exitosa a la red!");
    } else {
        Serial.println("No se pudo conectar a red WiFi");
    }
}

bool ConectorWiFi::estaConectado(){
    return (WiFi.status() == WL_CONNECTED);
}