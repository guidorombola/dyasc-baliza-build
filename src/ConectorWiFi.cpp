#include "ConectorWiFi.hpp"

#define MAX_INTENTOS_CONEXION 10

ConectorWiFi::ConectorWiFi(){}

void ConectorWiFi::realizarConexion(){
    int intentosConexion = 0;
    WiFi.begin(GestorDeCredenciales::obtenerSsid(), GestorDeCredenciales::obtenerClave());

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

void ConectorWiFi::iniciarAP(){
    WiFi.softAP("balizaCI", "integracioncontinua");

    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
}