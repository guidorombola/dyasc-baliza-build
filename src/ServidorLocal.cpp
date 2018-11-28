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

        AsyncWebParameter* ssidParametro = request->getParam(0);
        AsyncWebParameter* claveParametro = request->getParam(1);
        AsyncWebParameter* urlServidorDeIntegracionContinuaParametro = request->getParam(2);
        AsyncWebParameter* autenticacionServidorDeIntegracionContinuaParametro = request->getParam(3);

        const char* ssidNuevo = ssidParametro->value().c_str();
        const char* claveNueva = claveParametro->value().c_str();
        const char* urlServidorDeIntegracionContinuaNuevo = urlServidorDeIntegracionContinuaParametro->value().c_str();
        const char* autenticacionServidorDeIntegracionContinuaNueva = autenticacionServidorDeIntegracionContinuaParametro->value().c_str();

        GestorDeCredenciales::establecerSsid(ssidNuevo);
        GestorDeCredenciales::establecerClave(claveNueva);
        GestorDeCredenciales::establecerUrlServidorDeIntegracionContinua(urlServidorDeIntegracionContinuaNuevo);
        GestorDeCredenciales::establecerAutenticacionServidorDeIntegracionContinua(autenticacionServidorDeIntegracionContinuaNueva);

        request->send(200, "text/plain", "¡Datos guardados!");
    });

    server.begin();
}