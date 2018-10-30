#include "Orquestador.hpp"

Orquestador::Orquestador(VisualizadorDeEstado* conector, ComunicadorDeEventos* controlador){
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
    //if(estadoActual == Estado::OK) control->comunicarEstadoOK(); //Esto es una prueba. Luego eliminar

    ultimoEstado = estadoActual;
    
    return estadoActual;
}