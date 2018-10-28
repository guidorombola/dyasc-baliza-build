#include "Orquestador.hpp"

Orquestador::Orquestador(ConectorCI* conector){
    con = conector;
}

Estado Orquestador::obtenerEstado(){
    return con->obtenerEstado();
}