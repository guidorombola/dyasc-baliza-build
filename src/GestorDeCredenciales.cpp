#include "GestorDeCredenciales.hpp"

const char* GestorDeCredenciales::ssid = "";
const char* GestorDeCredenciales::clave = "";

void GestorDeCredenciales::establecerSsid(const char* ssid){
    GestorDeCredenciales::ssid = ssid;
}
void GestorDeCredenciales::establecerClave(const char* clave){
    GestorDeCredenciales::clave = clave;
}
const char* GestorDeCredenciales::obtenerSsid() {
    return GestorDeCredenciales::ssid;
}
const char* GestorDeCredenciales::obtenerClave(){
    return GestorDeCredenciales::clave;
}