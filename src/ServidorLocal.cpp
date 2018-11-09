#include "ServidorLocal.hpp"

AsyncWebServer server(80);

ServidorLocal::ServidorLocal(){};

void ServidorLocal::iniciar(){

    if(!SPIFFS.begin()){
        Serial.println("Ocurrió un error al montar SPIFFS");
        return;
    }

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });

    server.on("/ping", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "pong");
    });

    server.on("/datos/actualizar", HTTP_POST, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "Datos guardados!");
    });

    server.begin();
}