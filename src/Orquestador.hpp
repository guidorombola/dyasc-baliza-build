#ifndef ORQUESTADOR_H
#define ORQUESTADOR_H

#include "ConectorCI.hpp"
#include "ControladorDeAlertas.hpp"
#include "Estado.cpp"

class Orquestador{
    public:
        Orquestador(ConectorCI* conector, ControladorDeAlertas* controlador);
        Estado obtenerEstado();
    private:
        ConectorCI* con;
        ControladorDeAlertas* control;
        Estado ultimoEstado;
};

#endif
