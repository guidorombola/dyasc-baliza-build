#include "Orquestador.hpp"

Orquestador::Orquestador(VisualizadorDeEstado* conector, ComunicadorDeEventos* controlador){
    con = conector;
    control = controlador;
    ultimoEstado = Estado::INDEFINIDO;
}

Estado Orquestador::obtenerEstado(){
    Estado estadoActual = con->obtenerEstado();
    if(estadoActual != ultimoEstado){
        switch(estadoActual){
            case Estado::OK:
                control->comunicarEstadoOK();
                break;
            case Estado::FALLO:
                control->comunicarEstadoFallo();
                break;
            case Estado::DESCONECTADO:
                control->comunicarEstadoDesconectado();
                break;
            default:
                break;
        }
    }

    ultimoEstado = estadoActual;
    
    return estadoActual;
}