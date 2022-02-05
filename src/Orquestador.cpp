#include "Orquestador.hpp"

Orquestador::Orquestador(VisualizadorDeEstado* conector, 
                         ComunicadorDeEventos* controlador, 
                         GestorDeConexion* conectorWiFi, 
                         Servidor* servidor){
    this->conector = conector;
    this->control = controlador;
    this->conectorWiFi = conectorWiFi;
    this->servidor = servidor;
    this->ultimoEstado = Estado::INDEFINIDO;
}

Estado Orquestador::obtenerEstado(){
    Estado estadoActual = Estado::DESCONECTADO;

    if(this->conectorWiFi->estaConectado()){
        estadoActual = this->conector->obtenerEstado();
        if(estadoActual != this->ultimoEstado){
            switch (estadoActual)
            {
                case Estado::OK:
                    this->control->comunicarEstadoOK();
                    break;
                case Estado::FALLO:
                    this->control->comunicarEstadoFallo();
                    break;
                case Estado::DESCONECTADO:
                    this->control->comunicarEstadoDesconectado();
                    break;
            }
        }
    } else {
        if(estadoActual != ultimoEstado){
            this->control->comunicarEstadoDesconectado();
        }
    }
    this->ultimoEstado = estadoActual;
    
    return estadoActual;
}

void Orquestador::manejarModo(){
    if (this->primeraConexion) {
        this->conectorWiFi->realizarConexion();
        this->primeraConexion = false;
    }

    this->obtenerEstado();
}

void Orquestador::iniciarConexiones(){
    this->conectorWiFi->iniciarAP();
    this->servidor->iniciar();
}
