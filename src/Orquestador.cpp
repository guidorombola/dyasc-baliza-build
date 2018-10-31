#include "Orquestador.hpp"

Orquestador::Orquestador(VisualizadorDeEstado* conector, ComunicadorDeEventos* controlador){
    con = conector;
    control = controlador;
    ultimoEstado = Estado::INDEFINIDO;
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