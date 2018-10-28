#include "Orquestador.hpp"

Orquestador::Orquestador(ConectorCI* conector){
    con = conector;
}

bool Orquestador::obtenerEstado(){
    return con->obtenerEstado();
}