#include "ConectorCI.hpp"
#include "configuracion/local.h"
#include "configuracion/red.h"

ConectorCI::ConectorCI() {
    this->wifi = new ConectorWiFi(ssid, clave);
    this->wifi->realizarConexion();
}

Estado ConectorCI::obtenerEstado(){
    estado = Estado::DESCONECTADO;
    if (this->wifi->estaConectado()) {
        String respuesta = this->realizarPeticion();

        if(respuesta != ""){
            int inicioEstadoBuild = respuesta.indexOf("state");
            String comienzoDeIndicadorDeEstado = respuesta.substring(inicioEstadoBuild + 9);
            int finDeIndicadorDeEstado = comienzoDeIndicadorDeEstado.indexOf(",");
            String estadoActual = comienzoDeIndicadorDeEstado.substring(0, finDeIndicadorDeEstado - 1);

            if (estadoActual == "passed") {
                estado = Estado::OK;
            } else {
                estado = Estado::FALLO;
            }
        }
    }

    return estado;
}

String ConectorCI::realizarPeticion(){
    this->cliente.begin(url);
    this->cliente.addHeader("Travis-API-Version", version, false, false);
    this->cliente.addHeader("Authorization", token, false, false);

    int codigoHTTP = this->cliente.GET();

    String respuesta = "";

    if(codigoHTTP > 0){
        respuesta = this->cliente.getString();
    }

    this->cliente.end();

    return respuesta; 
}