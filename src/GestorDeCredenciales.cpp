#include "GestorDeCredenciales.hpp"

GestorDeCredenciales::GestorDeCredenciales(){};

void GestorDeCredenciales::establecerSsid(const char* ssid){
    this->ssid = ssid;
}
void GestorDeCredenciales::establecerClave(const char* clave){
    this->clave = clave;
}
const char* GestorDeCredenciales::obtenerSsid() {
    return this->ssid;
}
const char* GestorDeCredenciales::obtenerClave(){
    return this->clave;
}