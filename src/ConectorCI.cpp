#include "ConectorCI.hpp"
//#include "configuracion/local.h"

ConectorCI::ConectorCI() {}

Estado ConectorCI::obtenerEstado(){
    estado = Estado::DESCONECTADO;
    String respuesta = this->realizarPeticion();

    if(respuesta != ""){
        int inicioEstadoBuild = respuesta.indexOf("state");
        String comienzoDeIndicadorDeEstado = respuesta.substring(inicioEstadoBuild + 9);
        int finDeIndicadorDeEstado = comienzoDeIndicadorDeEstado.indexOf(",");
        String estadoActual = comienzoDeIndicadorDeEstado.substring(0, finDeIndicadorDeEstado - 1);

        estado = Estado::FALLO;
        if (estadoActual == "passed") {
            estado = Estado::OK;
        }
    }
    
    return estado;
}

String ConectorCI::realizarPeticion(){
    this->cliente.begin(GestorDeCredenciales::obtenerUrlServidorDeIntegracionContinua());
    this->cliente.addHeader("Travis-API-Version", "3", false, false);
    this->cliente.addHeader("Authorization", GestorDeCredenciales::obtenerAutenticacionServidorDeIntegracionContinua(), false, false);

    int codigoHTTP = this->cliente.GET();

    String respuesta = "";

    if(codigoHTTP >= 200 && codigoHTTP < 300){
        respuesta = this->cliente.getString();
    }

    this->cliente.end();

    return respuesta; 
}