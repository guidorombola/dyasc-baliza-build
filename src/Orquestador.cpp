#include "Orquestador.hpp"

Orquestador::Orquestador(VisualizadorDeEstado* conector, ComunicadorDeEventos* controlador, GestorDeConexion* conectorWiFi){
    con = conector;
    control = controlador;
    this->conectorWiFi = conectorWiFi;
    ultimoEstado = Estado::INDEFINIDO;
}

Estado Orquestador::obtenerEstado(){
    Estado estadoActual = Estado::DESCONECTADO;
    if(this->conectorWiFi->estaConectado()){
        estadoActual = con->obtenerEstado();
        if(estadoActual != ultimoEstado){
            if(estadoActual == Estado::OK){
                control->comunicarEstadoOK();
            } else {
                control->comunicarEstadoFallo();
            }
        }
    } else {
        if(estadoActual != ultimoEstado){
            control->comunicarEstadoDesconectado();
        }
    }
    ultimoEstado = estadoActual;
    
    return estadoActual;
}

void Orquestador::conectarARedWiFi(){
    this->conectorWiFi->realizarConexion();
}