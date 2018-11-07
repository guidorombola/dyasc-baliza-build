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
            switch (estadoActual)
            {
                case Estado::OK:
                    control->comunicarEstadoOK();
                    break;
                case Estado::FALLO:
                    control->comunicarEstadoFallo();
                    break;
                case Estado::DESCONECTADO:
                    control->comunicarEstadoDesconectado();
                    break;
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
