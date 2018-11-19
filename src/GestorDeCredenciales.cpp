#include "GestorDeCredenciales.hpp"

const char* GestorDeCredenciales::ssid = "";
const char* GestorDeCredenciales::clave = "";
bool GestorDeCredenciales::actualizar = false;

void GestorDeCredenciales::establecerSsid(const char* ssid){
    GestorDeCredenciales::ssid = ssid;
    GestorDeCredenciales::actualizar = true;
}
void GestorDeCredenciales::establecerClave(const char* clave){
    GestorDeCredenciales::clave = clave;
    GestorDeCredenciales::actualizar = true;
}
const char* GestorDeCredenciales::obtenerSsid() {
    return GestorDeCredenciales::ssid;
}
const char* GestorDeCredenciales::obtenerClave(){
    return GestorDeCredenciales::clave;
}
bool GestorDeCredenciales::hayCambios(){
    return GestorDeCredenciales::actualizar;
}