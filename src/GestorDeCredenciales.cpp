#include "GestorDeCredenciales.hpp"

const char* GestorDeCredenciales::ssid = "";
const char* GestorDeCredenciales::clave = "";
const char* GestorDeCredenciales::urlServidorDeIntegracionContinua = "";
const char* GestorDeCredenciales::autenticacionServidorDeIntegracionContinua = "";
bool GestorDeCredenciales::actualizar = false;

void GestorDeCredenciales::establecerSsid(const char* ssid){
    GestorDeCredenciales::ssid = ssid;
    GestorDeCredenciales::actualizar = true;
}
void GestorDeCredenciales::establecerClave(const char* clave){
    GestorDeCredenciales::clave = clave;
    GestorDeCredenciales::actualizar = true;
}

void GestorDeCredenciales::establecerUrlServidorDeIntegracionContinua(const char* urlServidorDeIntegracionContinua){
    GestorDeCredenciales::urlServidorDeIntegracionContinua = urlServidorDeIntegracionContinua;
    GestorDeCredenciales::actualizar = true;
}

void GestorDeCredenciales::establecerAutenticacionServidorDeIntegracionContinua(const char* autenticacionServidorDeIntegracionContinua){
    GestorDeCredenciales::autenticacionServidorDeIntegracionContinua = autenticacionServidorDeIntegracionContinua;
    GestorDeCredenciales::actualizar = true;
}

const char* GestorDeCredenciales::obtenerSsid() {
    return GestorDeCredenciales::ssid;
}

const char* GestorDeCredenciales::obtenerClave(){
    return GestorDeCredenciales::clave;
}

const char* GestorDeCredenciales::obtenerUrlServidorDeIntegracionContinua(){
    return GestorDeCredenciales::urlServidorDeIntegracionContinua;
}

const char* GestorDeCredenciales::obtenerAutenticacionServidorDeIntegracionContinua(){
    return GestorDeCredenciales::autenticacionServidorDeIntegracionContinua;
}

bool GestorDeCredenciales::hayCambios(){
    return GestorDeCredenciales::actualizar;
}