#include "Orquestador.hpp"

Orquestador::Orquestador(ConectorCI* conector, ControladorDeAlertas* controlador){
    con = conector;
    control = controlador;
    ultimoEstado = Estado::OK;
}

Estado Orquestador::obtenerEstado(){
    Estado estadoActual = con->obtenerEstado();
    if(estadoActual != ultimoEstado){
        if(estadoActual == Estado::FALLO){
            control -> comunicarEstadoFallo();
        } else {
            control -> comunicarEstadoOK();  
        }
    }
    ultimoEstado = estadoActual;
    
    return estadoActual;
}